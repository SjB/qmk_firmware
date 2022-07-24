/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "sjb.h"

#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT_wrapper(
    KC_GRV  , LEFT_QW_ROW_1            , RIGHT_QW_ROW_1 , KC_MINS    ,
    KC_BSLS , LEFT_QW_ROW_2            , RIGHT_QW_ROW_2 , KC_QUOT    ,
    KC_LBRC , LEFT_QW_ROW_3            , RIGHT_QW_ROW_3 , KC_RBRC    ,

    LEFT_PRIMARY_THUMB_CLUSTER ,
    RIGHT_PRIMARY_THUMB_CLUSTER
  ),
  [_RAISE] = LAYOUT_wrapper(
    S(KC_GRV)  , LEFT_SYMBOL_ROW_1          , RIGHT_SYMBOL_ROW_1 , KC_COMM ,
    S(KC_BSLS) , LEFT_NUM_ROW               , RIGHT_NUM_ROW      , KC_DOT  ,
    S(KC_9)    , LEFT_SYMBOL_ROW_2          , RIGHT_SYMBOL_ROW_2 , S(KC_0) ,
    RAISE_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_TRANSPARENT_THUMB_CLUSTER(OSM(MOD_RALT))
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    KC_SLEP    , FUNCPAD_ROW_1              , NUMPAD_ROW_1 , KC_DEL  ,
    NK_TOGG    , FUNCPAD_ROW_2              , NUMPAD_ROW_2 , KC_INS  ,
    TO(_RAISE) , FUNCPAD_ROW_3              , NUMPAD_ROW_3 , KC_PEQL ,

    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER
  ),
  [_NAV] = LAYOUT_wrapper(
    RGB_TOG , TRANS_ROW , NAV_ROW_1 , RGB_HUI ,
    RGB_MOD , TRANS_ROW , NAV_ROW_2 , RGB_SAI ,
    KC_NO   , TRANS_ROW , NAV_ROW_3 , RGB_VAI ,

    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER
  ),
  [_MOUSE] = LAYOUT_wrapper(
    RGB_TOG , TRANS_ROW , MOUSE_ROW_1 , RGB_HUI ,
    RGB_MOD , TRANS_ROW , MOUSE_ROW_2 , RGB_SAI ,
    KC_NO   , TRANS_ROW , MOUSE_ROW_3 , RGB_VAI ,

    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    MOUSE_THUMB_CLUSTER
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

char keylog_str[16] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "\n\n%dx%d\n\nk%2d %c\n",
             record->event.key.row, record->event.key.col,
             keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, '\n',
        'c', 'o', 'r', 'n', 'e', 0,
    };
    oled_write_ln_P(corne_logo, false);
}

const char *oled_layer_state_text(void) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            return PSTR("R");
        case _NUMPAD:
            return PSTR("NU");
        case _NAV:
            return PSTR("NA");
        case _MOUSE:
            return PSTR("M");
        default:
            return PSTR("QW");
    }
}

void oled_render_layer_state(void) {

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("C ") :  PSTR("  "), false);

    oled_write_ln_P(oled_layer_state_text(), false);
}

bool oled_task_user(void) {
    oled_render_logo();
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
