#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include "utils.h"

#define PROGRAM_NAME "servers"
//#define _(STRING) gettext(STRING)

int
main (void)
{
  char* data;

  load_configuration();
  data = send_request();

  if(data) {
    printf("%s\n", data);
    free(data);
  }

  destroy_configuration();
  return EXIT_SUCCESS;
}
