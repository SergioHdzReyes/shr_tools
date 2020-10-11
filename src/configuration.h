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

struct _config_info {
  const char *default_server;
} config_info;

config_t cfg;
config_setting_t *setting;


int load_configuration();
int destroy_configuration();
// char *get_configuration_file();
char concat_with_separator(char *dest, char const *src);


int load_configuration()
{
  const char *cfg_item;

  config_init(&cfg);

  char *config_file = "/home/sergio/.config/shr_tools_config";

  if(! config_read_file(&cfg, config_file)) {
    fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg), config_error_line(&cfg), config_error_text(&cfg));
    config_destroy(&cfg);
    return(EXIT_FAILURE);
  }

  if (config_lookup_string(&cfg, "default_server", &cfg_item))
    config_info.default_server = cfg_item;
  else
    fprintf(stderr, "No se encontro el valor 'default_server' en el archivo de configuracion\n");

  return 1;
}

int destroy_configuration()
{
  config_destroy(&cfg);
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
}

#endif
