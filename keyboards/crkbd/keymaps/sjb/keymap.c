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

#include "version.h"
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT_wrapper(
    OSM_CTL , LEFT_QW_ROW_1            , RIGHT_QW_ROW_1 , OSM_HYPR ,
    KC_TAB  , LEFT_QW_ROW_2            , RIGHT_QW_ROW_2 , OSM_SFT  ,
    OSM_GUI , LEFT_QW_ROW_3            , RIGHT_QW_ROW_3 , OSM_MEH  ,

    LEFT_PRIMARY_THUMB_CLUSTER ,
    RIGHT_PRIMARY_THUMB_CLUSTER
  ),
  [_RAISE] = LAYOUT_wrapper(
    _______ , LEFT_RAISE_ROW_1          , RIGHT_RAISE_ROW_1 , _______ ,
    _______ , LEFT_RAISE_ROW_2          , RIGHT_RAISE_ROW_2 , _______ ,
    _______ , LEFT_RAISE_ROW_3          , RIGHT_RAISE_ROW_3 , _______ ,

    LEFT_RAISE_THUMB_CLUSTER ,
    RIGHT_RAISE_THUMB_CLUSTER
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    _______ , FUNCPAD_ROW_1              , NUMPAD_ROW_1 , _______ ,
    _______ , FUNCPAD_ROW_2              , NUMPAD_ROW_2 , _______ ,
    _______ , FUNCPAD_ROW_3              , NUMPAD_ROW_3 , _______ ,

    LEFT_NUMPAD_THUMB_CLUSTER ,
    RIGHT_NUMPAD_THUMB_CLUSTER
  ),
  [_NAV] = LAYOUT_wrapper(
    RGB_TOG , LEFT_NAV_ROW_1 ,  RIGHT_SYS_ROW_1 , RGB_HUI ,
    RGB_MOD , LEFT_NAV_ROW_2 ,  RIGHT_SYS_ROW_2 , RGB_SAI ,
    NK_TOGG , LEFT_NAV_ROW_3 ,  RIGHT_SYS_ROW_3 , RGB_VAI ,

    LEFT_NAV_THUMB_CLUSTER,
    RIGHT_NAV_THUMB_CLUSTER
  ),
  [_MOUSE] = LAYOUT_wrapper(
    _______ , LEFT_MOUSE_ROW_1 , RIGHT_MOUSE_ROW_1 , _______ ,
    _______ , LEFT_MOUSE_ROW_2 , RIGHT_MOUSE_ROW_2 , _______ ,
    _______ , LEFT_MOUSE_ROW_3 , RIGHT_MOUSE_ROW_3 , _______ ,

    LEFT_MOUSE_THUMB_CLUSTER ,
    RIGHT_MOUSE_THUMB_CLUSTER
  ),
  [_RHR] = LAYOUT_wrapper(
    _______, TRANS_ROW, TRANS_ROW, _______,
    _______, LEFT_HOME_ROW, RIGHT_HOME_ROW_A, _______,
    _______, TRANS_ROW, TRANS_ROW, _______,
    LEFT_HOME_ROW_THUMB_CLUSTER,
    RIGHT_HOME_ROW_THUMB_CLUSTER
  ),
  [_LHR] = LAYOUT_wrapper(
    _______, TRANS_ROW, TRANS_ROW, _______,
    _______, RIGHT_HOME_ROW_A, RIGHT_HOME_ROW, _______,
    _______, TRANS_ROW, TRANS_ROW, _______,
    LEFT_HOME_ROW_THUMB_CLUSTER,
    RIGHT_HOME_ROW_THUMB_CLUSTER
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

/*
void set_keylog(uint16_t keycode, keyrecord_t *record);

bool process_record_sjb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
*/

const char *read_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, '\n',
        0,
    };
    return logo;
}
const char *build_information(void) {
    return PSTR(QMK_VERSION);
}

const char *oled_layer_state_text(void) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            return PSTR("RAI");
        case _NUMPAD:
            return PSTR("NUM");
        case _NAV:
            return PSTR("NAV");
        case _MOUSE:
            return PSTR("MOU");
        default:
            return PSTR("DEF");
    }
}

bool oled_task_user(void) {
    oled_write_ln_P(read_logo(), false);
    if (is_keyboard_master()) {
        oled_write_ln_P(oled_layer_state_text(), false);

        oled_advance_page(true);
        oled_advance_page(true);
        oled_advance_page(true);
        oled_write_ln_P(build_information(), false);
//        oled_render_keylog();
    }
    return false;
}
#endif // OLED_ENABLE
