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
      KC_GRV  , LEFT_QW_ROW_1 , LGUI(KC_SPC) , LGUI(KC_T)    , RIGHT_QW_ROW_1 , KC_MINS ,
      KC_BSLS , LEFT_QW_ROW_2 , OSL_NUM      , OSM_ALT       , RIGHT_QW_ROW_2 , KC_QUOT ,
      OSM_SFT , LEFT_QW_ROW_3 , OSL_RSE      , OSM_CTL       , RIGHT_QW_ROW_3 , EQL_SFT ,

      LEFT_PRIMARY_THUMB_CLUSTER  ,
      OSM_GUI ,
      OSM_ALT ,
      RIGHT_PRIMARY_THUMB_CLUSTER
    ),
    [_RAISE] = LAYOUT_wrapper(
      _______ , LEFT_RAISE_ROW_1 , _______ , _______ , RIGHT_RAISE_ROW_1 , _______ ,
      _______ , LEFT_RAISE_ROW_2 , _______ , _______ , RIGHT_RAISE_ROW_2 , _______ ,
      _______ , LEFT_RAISE_ROW_3 , _______ , _______ , RIGHT_RAISE_ROW_3 , _______ ,

      LEFT_RAISE_THUMB_CLUSTER(_QWERTY) ,
      _______ ,
      _______ ,
      TRANSPARENT_THUMB_CLUSTER
    ),

    [_NUMPAD] = LAYOUT_wrapper(
      OSM_CTL , FUNCPAD_ROW_1 , _______ , _______ , NUMPAD_ROW_1 , _______ ,
      OSM_ALT , FUNCPAD_ROW_2 , _______ , _______ , NUMPAD_ROW_2 , _______ ,
      OSM_SFT , FUNCPAD_ROW_3 , _______ , _______ , NUMPAD_ROW_3 , _______ ,

      LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
      _______ ,
      _______ ,
      RIGHT_NUMPAD_THUMB_CLUSTER
    ),
    [_NAV] = LAYOUT_wrapper(
      RGB_TOG , TRANS_ROW , _______ , _______ , NAV_ROW_1 , RGB_HUI ,
      RGB_MOD , TRANS_ROW , _______ , _______ , NAV_ROW_2 , RGB_SAI ,
      KC_SLEP , TRANS_ROW , _______ , _______ , NAV_ROW_3 , RGB_VAI ,

      LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
      _______ ,
      _______ ,
      TRANSPARENT_THUMB_CLUSTER
    ),
    [_MOUSE] = LAYOUT_wrapper(
      NK_TOGG , LEFT_MOUSE_ROW_1 , _______ , _______ , RIGHT_MOUSE_ROW_1 , KC_NO ,
      KC_NO   , LEFT_MOUSE_ROW_2 , _______ , _______ , RIGHT_MOUSE_ROW_2 , KC_NO ,
      KC_NO   , LEFT_MOUSE_ROW_3 , _______ , _______ , RIGHT_MOUSE_ROW_3 , KC_NO ,

      LEFT_MOUSE_THUMB_CLUSTER(_QWERTY) ,
      _______ ,
      _______ ,
      RIGHT_MOUSE_THUMB_CLUSTER
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
