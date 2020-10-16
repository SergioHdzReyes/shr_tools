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
  const char *company;
  const char *description;
} config_info;

config_t cfg;
config_setting_t *setting;


int load_configuration();
int destroy_configuration();

#endif
