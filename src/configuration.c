#include "configuration.h"

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

  config_lookup_string(&cfg, "company", &config_info.company);
  config_lookup_string(&cfg, "description", &config_info.description);

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

  load_screen_info();

  return 0;
}

int destroy_configuration()
{
  config_destroy(&cfg);

  return 0;
}
