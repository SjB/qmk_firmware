#ifndef LCD_BACKLIGHT_ENABLE
#error This visualizer needs that LCD backlight is enabled
#endif

#ifndef LCD_ENABLE
#error This visualizer needs that LCD is enabled
#endif

#include <string.h>
#include "config.h"
#include "version.h"
#include "visualizer.h"
#include "util.h"
#include "action_util.h"
#include "quantum.h"
#include "serial_link/system/serial_link.h"

static const char* welcome_text = "Ergodox Infinity";
static const char* revision_text = "QMK Rev: " GIT_REV;
static const char* keymap_text = "Keymap: " QMK_KEYMAP;
static const char* suspend_text = "ZZZZzzzz....";

static const uint8_t default_brightness_level = 0x50;
static const uint32_t boot_lcd_color = LCD_COLOR(0x00, 0x00, 0x25); // initial color setting during boot sequence
static const uint32_t startup_animation_lcd_color = LCD_COLOR(0x00, 0x90, 0x50);

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
    .frame_lengths = {MS2ST(2000), MS2ST(3000)},
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

#define IS_MOD_ACTIVE(mods_state, kc)  (mods_state & MOD_BIT(kc))
#define IS_EITHER_MOD_ACTIVE(mods_state, kc1, kc2)  (mods_state & (MOD_BIT(kc1) | MOD_BIT(kc2)))

#define IS_LAYER_ACTIVE(state, layer)  (state & (1UL << (layer)))

void update_user_visualizer_state(visualizer_state_t* state) {

    static char status[16];
    static char blank_status[16] = "L:    M:       ";
    int hue = 0x20;
    int sat = 0x90;
    int intensity = 0x50;

    strcpy(status, blank_status);

    if (IS_LAYER_ACTIVE(state->status.layer, 1)) {
        status[2] = '1';
        hue = 0x60;
        intensity += 0x20;
    }

    if (IS_LAYER_ACTIVE(state->status.layer, 2)) {
        status[3] = '2';
        intensity += 0x20;
        hue = 0x90;
    }

    if (IS_LAYER_ACTIVE(state->status.layer, 3)) {
        status[4] = '3';
        intensity += 0x20;
        hue = 0xC0;
    }

    if (IS_MOD_ACTIVE(state->status.mods, KC_LGUI)) {
        status[8] = 'G';
        intensity -= 0x20;
    }

    if (IS_MOD_ACTIVE(state->status.mods, KC_LALT)) {
        status[9] = 'A';
        sat += 0x20;
    }

    if (IS_EITHER_MOD_ACTIVE(state->status.mods, KC_LSHIFT, KC_RSHIFT)) {
        status[10] = 'S';
        sat += 0x20;
    }

    if (IS_EITHER_MOD_ACTIVE(state->status.mods, KC_LCTL, KC_RCTL)) {
        status[11] = 'C';
        sat += 0x20;
    }

    if (IS_MOD_ACTIVE(state->status.mods, KC_RALT)) {
        status[13] = 'A';
        status[14] = 'r';
        sat += 0x20;
    }

    state->target_lcd_color = LCD_COLOR(hue, sat, intensity);
    state->layer_text = status;

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
