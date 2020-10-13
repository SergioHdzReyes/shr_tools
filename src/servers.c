#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include "utils.h"

#define PROGRAM_NAME "servers"
//#define _(STRING) gettext(STRING)

int
main (void)
{
  load_configuration();

  send_request();

  for (int i=0; i<config_info.servers_count; i++) {
    printf("HOST: %s\nRESPONSE: %s\n\n", config_info.servers[i].url_req, config_info.servers[i].resp);
  }

  destroy_configuration();
  return EXIT_SUCCESS;
}
