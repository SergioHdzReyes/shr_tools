#ifndef SHR_TOOLS_CONEXION_H
# define SHR_TOOLS_CONEXION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <curl/curl.h>

struct url_data {
  size_t size;
  char* data;
};

char *send_request();

size_t write_data(void *ptr, size_t size, size_t nmemb, struct url_data *data) {
  size_t index = data->size;
  size_t n = (size * nmemb);
  char* tmp;

  data->size += (size * nmemb);
  tmp = realloc(data->data, data->size + 1); /* +1 for '\0' */

  if(tmp) {
    data->data = tmp;
  } else {
    if(data->data) {
      free(data->data);
    }
    fprintf(stderr, "Failed to allocate memory.\n");
    return 0;
  }

  memcpy((data->data + index), ptr, n);
  data->data[data->size] = '\0';

  return size * nmemb;
}

char *send_request()
{
  CURL *curl;
  CURLcode res;

  struct url_data data;
  data.size = 0;
  data.data = malloc(4096); /* reasonable size initial buffer */
  if(NULL == data.data) {
    fprintf(stderr, "Failed to allocate memory.\n");
    return NULL;
  }

  data.data[0] = '\0';

  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
    curl_easy_setopt(curl, CURLOPT_URL, config_info.default_server);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

    /* Now specify the POST data */
    //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return data.data;
}

#endif
