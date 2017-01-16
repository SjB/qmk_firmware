#ifndef LCD_BACKLIGHT_ENABLE
#error This visualizer needs that LCD backlight is enabled
#endif

#ifndef LCD_ENABLE
#error This visualizer needs that LCD is enabled
#endif

#include "config.h"
#include "version.h"
#include "visualizer.h"
#include "util.h"

static const char* welcome_text = "Ergodox Infinity";
static const char* revision_text = "QMK Rev: " GIT_REV;
static const char* keymap_text = "Keymap: " QMK_KEYMAP;
static const char* suspend_text = "ZZZZzzzz....";

static const uint8_t default_brightness_level = 0x50;
static const uint32_t boot_lcd_color = LCD_COLOR(0x00, 0x00, 0xFF); // initial color setting during boot sequence
static const uint32_t startup_animation_lcd_color = LCD_COLOR(0x10, 0xFF, 0xFF);

bool display_welcome(keyframe_animation_t* animation, visualizer_state_t* state) {
  (void)animation;

  gdispClear(White);
  gdispDrawString(0, 3, welcome_text, state->font_dejavusansbold12, Black);
  gdispDrawString(0, 15, revision_text, state->font_dejavusansbold12, Black);
  gdispFlush(); 

  return false;
}

bool display_layer(keyframe_animation_t* animation, visualizer_state_t* state) {
  (void)animation;

  gdispClear(White);
  gdispDrawString(0, 3, state->layer_text, state->font_dejavusansbold12, Black);
  gdispDrawString(0, 15,keymap_text, state->font_dejavusansbold12, Black);
  gdispFlush(); 

  return false;
}

bool display_suspend(keyframe_animation_t* animation, visualizer_state_t* state) {
  (void)animation;

  gdispClear(White);
  gdispDrawString(0, 3, suspend_text, state->font_dejavusansbold12, Black);
  gdispFlush(); 

  return false;
}

static keyframe_animation_t startup_animation = {
  .num_frames = 4,
  .loop = false,
  .frame_lengths = {0, MS2ST(1000), MS2ST(5000), 0},
  .frame_functions = {display_welcome, keyframe_animate_backlight_color, keyframe_no_operation, enable_visualization},
};

// The color animation animates the LCD color when you change layers
static keyframe_animation_t color_animation = {
    .num_frames = 2,
    .loop = false,
    // Note that there's a 200 ms no-operation frame,
    // this prevents the color from changing when activating the layer
    // momentarily
    .frame_lengths = {MS2ST(200), MS2ST(500)},
    .frame_functions = {keyframe_no_operation, keyframe_animate_backlight_color},
};

// The LCD animation alternates between the layer name display and a
// bitmap that displays all active layers
static keyframe_animation_t lcd_animation = {
    .num_frames = 2,
    .loop = true,
    .frame_lengths = {MS2ST(2000), MS2ST(2000)},
    .frame_functions = {display_welcome, display_layer},
};

static keyframe_animation_t suspend_animation = {
  .num_frames = 2,
  .loop = false,
  .frame_lengths = {MS2ST(2000), 0},
  .frame_functions = {display_suspend, keyframe_disable_lcd_and_backlight},
};

static keyframe_animation_t resume_animation = {
  .num_frames = 5,
  .loop = false,
  .frame_lengths = {0, 0, MS2ST(1000), MS2ST(5000), 0},
  .frame_functions = {keyframe_enable_lcd_and_backlight, display_welcome, keyframe_animate_backlight_color, keyframe_no_operation, enable_visualization},
};

void initialize_user_visualizer(visualizer_state_t* state) {
    // The brightness will be dynamically adjustable in the future
    // But for now, change it here.
    lcd_backlight_brightness(default_brightness_level);
    state->current_lcd_color = boot_lcd_color;
    state->target_lcd_color = startup_animation_lcd_color;
    start_keyframe_animation(&startup_animation);
}

void update_user_visualizer_state(visualizer_state_t* state) {

  uint8_t layer = biton32(state->status.layer);
  switch(layer) {
    case 1:
      state->target_lcd_color = LCD_COLOR(0xA0, 0xB0, 0xFF);
      state->layer_text = "Layer: 1 ";
      break;
    case 2:
      state->target_lcd_color = LCD_COLOR(0xC0, 0xB0, 0xFF);
      state->layer_text = "Layer: 2 ";
      break;
    case 3:
      state->target_lcd_color = LCD_COLOR(0x50, 0x30, 0xFF);
      state->layer_text = "Leave Now";
      break;
    default:
      state->target_lcd_color = LCD_COLOR(0x50, 0xB0, 0xFF);
      state->layer_text = "Layer: Default ";
      break;
  }
  start_keyframe_animation(&lcd_animation);
  start_keyframe_animation(&color_animation);
};

void user_visualizer_suspend(visualizer_state_t* state) {
  start_keyframe_animation(&suspend_animation);
};

void user_visualizer_resume(visualizer_state_t* state) {
  // Need to reset brightness level to default
  lcd_backlight_brightness(default_brightness_level);
  state->current_lcd_color = boot_lcd_color;
  state->target_lcd_color = startup_animation_lcd_color;
  start_keyframe_animation(&resume_animation);
};
