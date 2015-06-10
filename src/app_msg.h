#pragma once

#include <pebble.h>

void app_msg_init();
void app_msg_deinit();

bool app_msg_get_egg(uint32_t egg_id);
