#include <pebble.h>

typedef struct {
	Window *window;
	Layer  *layer;
} RankWindow;

static void layer_update_callback(Layer *me, GContext* ctx) {
	GRect bounds = layer_get_bounds(me);
	GRect cursor = bounds;
	cursor.size.h = 22;
	graphics_draw_text(ctx,"Your rank is",fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21),
		cursor,
		GTextOverflowModeFill,GTextAlignmentCenter,0);
	cursor.origin.y += cursor.size.h;

	cursor.size.h = 48;
	graphics_draw_text(ctx,"123",fonts_get_system_font(FONT_KEY_LECO_36_BOLD_NUMBERS),
		(GRect){.origin={0,22},.size={144,48}},
		GTextOverflowModeFill,GTextAlignmentCenter,0);
	cursor.origin.y += cursor.size.h;

	cursor.size.h = 22;
	graphics_draw_text(ctx,"of 31234 players",fonts_get_system_font(FONT_KEY_GOTHIC_24),
		(GRect){.origin={0,62},.size={144,22}},
		GTextOverflowModeFill,GTextAlignmentCenter,0);
	cursor.origin.y += cursor.size.h;
}

static void window_load(Window *window) {
  RankWindow* rw = window_get_user_data(window);
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  rw->layer = layer_create(bounds);
  layer_set_update_proc(rw->layer, layer_update_callback);
  layer_add_child(window_layer, rw->layer);
}

static void window_unload(Window *window) {
  RankWindow* rw = window_get_user_data(window);
  layer_destroy(rw->layer);
  window_destroy(window);
  free(rw);
}

void show_rank_window(){
  RankWindow* rw = malloc(sizeof(RankWindow));
  memset(rw, 0, sizeof(RankWindow));
  rw->window = window_create();
  window_set_user_data(rw->window, rw);
  window_set_window_handlers(rw->window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_set_background_color(rw->window,GColorBlue);
  window_stack_push(rw->window, true);
}