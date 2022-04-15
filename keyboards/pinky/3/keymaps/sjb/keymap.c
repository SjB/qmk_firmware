/* Copyright 2022 Sagacity Solutions Inc. All right reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
      KC_GRV  , LEFT_QW_ROW_1 , LGUI(KC_TAB)  , LAG_T(KC_B)  , RIGHT_QW_ROW_1 , KC_MINS ,
      KC_BSLS , LEFT_QW_ROW_2 , MO(_RAISE)    , MO(_NUMPAD) , RIGHT_QW_ROW_2 , KC_QUOT ,
      KC_LBRC , LEFT_QW_ROW_3 , OSM(MOD_LGUI) , LGUI(KC_T) , RIGHT_QW_ROW_3 , KC_RBRC ,

      OSM(MOD_LCTL) ,
      LEFT_PRIMARY_THUMB_CLUSTER  ,
      RIGHT_PRIMARY_THUMB_CLUSTER ,
      OSM(MOD_RALT)
    ),
    [_RAISE] = LAYOUT_wrapper(
      S(KC_GRV)  , LEFT_SYMBOL_ROW_1 , _______ , _______ , RIGHT_SYMBOL_ROW_1 , KC_COMM    ,
      S(KC_BSLS) , LEFT_NUM_ROW      , _______ , _______ , RIGHT_NUM_ROW      , KC_DOT     ,
      S(KC_LBRC) , LEFT_SYMBOL_ROW_2 , ______ , _______ , RIGHT_SYMBOL_ROW_2 , S(KC_RBRC) ,

      _______ ,
      LOWER_THUMB_CLUSTER(_QWERTY) ,
      RIGHT_TRANSPARENT_THUMB_CLUSTER(OSM(MOD_RALT)) ,
      _______
    ),

    [_NUMPAD] = LAYOUT_wrapper(
      KC_SLEP    , FUNCPAD_ROW_1 , _______ , _______ , NUMPAD_ROW_1 , KC_DEL  ,
      NK_TOGG    , FUNCPAD_ROW_2 , _______ , _______ , NUMPAD_ROW_2 , KC_INS  ,
      TO(_RAISE) , FUNCPAD_ROW_3 , _______ , _______ , NUMPAD_ROW_3 , KC_PEQL ,

      _______ ,
      LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
      TRANSPARENT_THUMB_CLUSTER ,
      _______
    ),
    [_NAV] = LAYOUT_wrapper(
      RGB_TOG , TRANS_ROW , _______ , _______ , NAV_ROW_1 , RGB_HUI ,
      RGB_MOD , TRANS_ROW , _______ , _______ , NAV_ROW_2 , RGB_SAI ,
      KC_NO   , TRANS_ROW , _______ , _______ , NAV_ROW_3 , RGB_VAI ,

      _______ ,
      LEFT_MOUSE_THUMB_CLUSTER(_QWERTY) ,
      TRANSPARENT_THUMB_CLUSTER ,
      _______
    ),
    [_MOUSE] = LAYOUT_wrapper(
      RGB_TOG , TRANS_ROW , _______ , _______ , MOUSE_ROW_1 , RGB_HUI ,
      RGB_MOD , TRANS_ROW , _______ , _______ , MOUSE_ROW_2 , RGB_SAI ,
      KC_NO   , TRANS_ROW , _______ , _______ , MOUSE_ROW_3 , RGB_VAI ,

      _______ ,
      LEFT_MOUSE_THUMB_CLUSTER(_QWERTY) ,
      MOUSE_THUMB_CLUSTER ,
      _______
    )
};

#ifdef RGBLIGHT_LAYERS

#define _NLAYERS 4
const rgblight_segment_t PROGMEM ll_0[] = RGBLIGHT_LAYER_SEGMENTS({0,1,HSV_PURPLE},
                                                                  {2,1,HSV_PURPLE});
const rgblight_segment_t PROGMEM ll_1[] = RGBLIGHT_LAYER_SEGMENTS( {0,1,HSV_BLUE},
                                                                   {2,1,HSV_BLUE});
const rgblight_segment_t PROGMEM ll_2[] = RGBLIGHT_LAYER_SEGMENTS( {0,1,HSV_CYAN},
                                                                   {2,1,HSV_CYAN});
const rgblight_segment_t PROGMEM ll_3[] = RGBLIGHT_LAYER_SEGMENTS( {0,1,HSV_GREEN},
                                                                   {2,1,HSV_GREEN});
const rgblight_segment_t PROGMEM ll_4[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_RED},
                                                                  {3, 1, HSV_RED});
const rgblight_segment_t PROGMEM ll_5[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_YELLOW},
                                                                  {3, 1, HSV_YELLOW});

const rgblight_segment_t* const PROGMEM ll_layers[] =
    RGBLIGHT_LAYERS_LIST(ll_0,ll_1,ll_2,ll_3, ll_4, ll_5);

layer_state_t layer_state_set_keymap(layer_state_t state) {
    for (uint8_t i=0 ; i < _NLAYERS; i++)
        rgblight_set_layer_state(i, layer_state_cmp(state, i));

    return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case NK_TOGG:
    case NK_ON:
    case NK_OFF:
        rgblight_blink_layer_repeat(keymap_config.nkro ? 5 : 4, 500, 5);
        break;
    }
}

#endif

void keyboard_post_init_user(void) {

#ifdef RGBLIGHT_LAYERS
    rgblight_layers = ll_layers;
    rgblight_set_layer_state(0, 1);
#endif

}
