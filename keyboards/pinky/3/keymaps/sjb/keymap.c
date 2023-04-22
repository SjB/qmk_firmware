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
      OSM_CTL , LEFT_QW_ROW_1 , G(KC_SPC)   , CW_TOGG    , RIGHT_QW_ROW_1 , OSM_HYPR,
      KC_TAB  , LEFT_QW_ROW_2 , TG(_NUMPAD) , TG(_MOUSE) , RIGHT_QW_ROW_2 , OSM_SFT ,
      OSM_GUI , LEFT_QW_ROW_3 , QK_LOCK     , SB_LLOCK   , RIGHT_QW_ROW_3 , OSM_MEH ,

      OSM_MEH,
      LEFT_PRIMARY_THUMB_CLUSTER  ,
      RIGHT_PRIMARY_THUMB_CLUSTER ,
      OSM_CTL
    ),
    [_RAISE] = LAYOUT_wrapper(
      _______ , LEFT_RAISE_ROW_1 , _______ , _______ , RIGHT_RAISE_ROW_1 , _______ ,
      _______ , LEFT_RAISE_ROW_2 , _______ , _______ , RIGHT_RAISE_ROW_2 , _______ ,
      _______ , LEFT_RAISE_ROW_3 , _______ , _______ , RIGHT_RAISE_ROW_3 , _______ ,

      _______ ,
      LEFT_RAISE_THUMB_CLUSTER ,
      RIGHT_RAISE_THUMB_CLUSTER ,
      _______
    ),

    [_NUMPAD] = LAYOUT_wrapper(
      OSM_CTL , FUNCPAD_ROW_1 , _______ , _______ , NUMPAD_ROW_1 , _______ ,
      OSM_ALT , FUNCPAD_ROW_2 , _______ , _______ , NUMPAD_ROW_2 , _______ ,
      OSM_SFT , FUNCPAD_ROW_3 , _______ , _______ , NUMPAD_ROW_3 , _______ ,

      _______ ,
      LEFT_NUMPAD_THUMB_CLUSTER ,
      RIGHT_NUMPAD_THUMB_CLUSTER ,
      _______
    ),
    [_NAV] = LAYOUT_wrapper(
      RGB_TOG , LEFT_NAV_ROW_1 , _______ , _______ , RIGHT_SYS_ROW_1 , RGB_HUI ,
      RGB_MOD , LEFT_NAV_ROW_2 , _______ , _______ , RIGHT_SYS_ROW_2 , RGB_SAI ,
      NK_TOGG , LEFT_NAV_ROW_3 , _______ , _______ , RIGHT_SYS_ROW_3 , RGB_VAI ,

      _______ ,
      LEFT_NAV_THUMB_CLUSTER ,
      RIGHT_NAV_THUMB_CLUSTER ,
      _______
    ),
    [_MOUSE] = LAYOUT_wrapper(
      _______ , LEFT_MOUSE_ROW_1 , _______ , _______ , RIGHT_MOUSE_ROW_1 , _______ ,
      _______ , LEFT_MOUSE_ROW_2 , _______ , _______ , RIGHT_MOUSE_ROW_2 , _______ ,
      _______ , LEFT_MOUSE_ROW_3 , _______ , _______ , RIGHT_MOUSE_ROW_3 , _______ ,

      _______ ,
      LEFT_MOUSE_THUMB_CLUSTER ,
      RIGHT_MOUSE_THUMB_CLUSTER ,
      _______
    ),
    [_RHR] = LAYOUT_wrapper(
      _______, TRANS_ROW,     _______ , _______ , TRANS_ROW,        _______,
      _______, LEFT_HOME_ROW, _______ , _______ , RIGHT_HOME_ROW_A, _______,
      _______, TRANS_ROW,     _______ , _______ , TRANS_ROW,        _______,
      _______ ,
      LEFT_HOME_ROW_THUMB_CLUSTER,
      RIGHT_HOME_ROW_THUMB_CLUSTER,
      _______
    ),
    [_LHR] = LAYOUT_wrapper(
      _______, TRANS_ROW,        _______ , _______ , TRANS_ROW,      _______,
      _______, RIGHT_HOME_ROW_A, _______ , _______ , RIGHT_HOME_ROW, _______,
      _______, TRANS_ROW,        _______ , _______ , TRANS_ROW,      _______,
      _______ ,
      LEFT_HOME_ROW_THUMB_CLUSTER,
      RIGHT_HOME_ROW_THUMB_CLUSTER,
      _______
    ),

};

#ifdef RGBLIGHT_LAYERS

#define _NLAYERS 6
const rgblight_segment_t PROGMEM ll_0[] = RGBLIGHT_LAYER_SEGMENTS({0,1,HSV_OFF},
                                                                  {2,1,HSV_OFF});
const rgblight_segment_t PROGMEM ll_1[] = RGBLIGHT_LAYER_SEGMENTS( {0,1,HSV_BLUE},
                                                                   {2,1,HSV_BLUE});
const rgblight_segment_t PROGMEM ll_2[] = RGBLIGHT_LAYER_SEGMENTS( {0,1,HSV_PURPLE},
                                                                   {2,1,HSV_PURPLE});
const rgblight_segment_t PROGMEM ll_3[] = RGBLIGHT_LAYER_SEGMENTS( {0,1,HSV_GREEN},
                                                                   {2,1,HSV_GREEN});
const rgblight_segment_t PROGMEM ll_4[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW},
                                                                  {2, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM ll_5[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE},
                                                                  {2, 1, HSV_WHITE});

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
