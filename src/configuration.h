#ifndef SHR_TOOLS_CONFIGURATION_H
# define SHR_TOOLS_CONFIGURATION_H

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include <string.h>

#if defined(WIN32) || defined(_WIN32)
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

#define CONFIG_FILE_PATH

struct _host_detail {
  const char *url_req;
  char *resp;
  char *domain;
  const char *headers[10];
  int headers_count;
};

struct _config_info {
  struct _host_detail servers[20];
  int servers_count;
} config_info;

config_t cfg;
config_setting_t *setting;


int load_configuration();
int destroy_configuration();
// char *get_configuration_file();
char concat_with_separator(char *dest, char const *src);


int load_configuration()
{
  config_setting_t *setting;

  config_init(&cfg);

  char *config_file = getenv("HOME");
  strcat(config_file, "/.config/shr_tools");

  if(! config_read_file(&cfg, config_file)) {
    fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg), config_error_line(&cfg), config_error_text(&cfg));
    config_destroy(&cfg);
    return(EXIT_FAILURE);
  }

  /* Output a list of all books in the inventory. */
  setting = config_lookup(&cfg, "servers_scan");
  if(setting != NULL) {
    int count = config_setting_length(setting);
    int i;
    const char *url;
    const char *header;

    config_info.servers_count = count;

    for(i = 0; i < count; ++i) {
      url = "";
      header = "";
      config_setting_t *host = config_setting_get_elem(setting, i);

      if (!config_setting_lookup_string(host, "url", &url))
        continue;

      config_info.servers[i].url_req = url;

      host = config_setting_get_member(host, "headers");
      if (!host)
        continue;

      int hdr_qty = config_setting_length(host);
      config_info.servers[i].headers_count = hdr_qty;

      for (int m = 0; m < hdr_qty; m++) {
        header = config_setting_get_string_elem(host, m);
        config_info.servers[i].headers[m] = header;
      }
    }
  }

  return 0;
}

int destroy_configuration()
{
  config_destroy(&cfg);

  return 0;
}

/* char *get_configuration_file() */
/* { */
/*   char *homedir = getenv("HOME"); */
/*   char *path = ""; */

/*   concat_with_separator(path, homedir); */
/*   concat_with_separator(path, ".config"); */
/*   concat_with_separator(path, "shr_tools_configs"); */

/*   return path; */
/* } */

char concat_with_separator(char *dest, char const *src)
{
  //char *aux = malloc(strlen(src)+strlen(PATH_SEPARATOR)+1);
  strcat(dest, src);
  strcat(dest, PATH_SEPARATOR);

  return 0;
}

#endif
