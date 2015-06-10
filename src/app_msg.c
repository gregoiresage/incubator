#include <pebble.h>

#include "app_msg.h"

#define EGG_TUPLE 			2000

#define RANK_TUPLE 			1000
#define PLAYERSCOUNT_TUPLE 	1001

static void received_callback(DictionaryIterator *iter, void *context) {
	APP_LOG(0, "received_callback");
	Tuple *tuple;
	if ((tuple = dict_find(iter, RANK_TUPLE))) {
		APP_LOG(0, "RANK_TUPLE %ld", tuple->value->int32);
	} 
	if ((tuple = dict_find(iter, PLAYERSCOUNT_TUPLE))) {
		APP_LOG(0, "PLAYERSCOUNT_TUPLE %ld", tuple->value->int32);
	} 

	// just for test
	app_msg_get_egg(123456);
}

static void failed_callback(DictionaryIterator *iter, AppMessageResult reason, void *context) {
	APP_LOG(0, "failed_callback %d", reason);
}

void app_msg_init() {
	const uint32_t size_inbound 	= 100;
	const uint32_t size_outbound 	= 100;
	app_message_open(size_inbound, size_outbound);

	app_message_register_inbox_received(received_callback);
	app_message_register_outbox_failed(failed_callback);
}

void app_msg_deinit(void) {
	app_message_deregister_callbacks();
}

bool app_msg_get_egg(uint32_t egg_id){
	DictionaryIterator *iter = NULL;
	if (app_message_outbox_begin(&iter) != APP_MSG_OK) {
	  return false;
	}

	dict_write_uint32(iter, EGG_TUPLE, egg_id);

	return (app_message_outbox_send() == APP_MSG_OK);
}