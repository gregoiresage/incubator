#include <pebble.h>

#include "app_msg.h"
#include "rank_window.h"

int main(void) {

  app_msg_init();

  switch(launch_get_args()){
    case 0 : show_rank_window(); break;
  }

  app_event_loop();

  app_msg_deinit();
}
