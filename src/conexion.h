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

  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);

  for (int i=0; i < config_info.servers_count; i++) {
    data.data[0] = '\0';
    curl = curl_easy_init();

    if(curl) {
      struct curl_slist *chunk = NULL;

      for (int a=0; a < config_info.servers[i].headers_count; a++) {
        chunk = curl_slist_append(chunk, config_info.servers[i].headers[a]);
      }

      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
      curl_easy_setopt(curl, CURLOPT_URL, config_info.servers[i].url_req);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

      /* Now specify the POST data */
      //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
      res = curl_easy_perform(curl);

      if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

      config_info.servers[i].resp = malloc(strlen(data.data) + 1);
      strcpy(config_info.servers[i].resp, data.data);

      /* always cleanup */
      curl_easy_cleanup(curl);
    }
  }
}

#endif
