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
    KC_BSLS , LEFT_QW_ROW_1 , MO(_NUMPAD)   , LAG(KC_B)  , RIGHT_QW_ROW_1 , KC_MINS ,
    KC_GRV  , LEFT_QW_ROW_2 , MO(_LOWER)    , MO(_RAISE) , RIGHT_QW_ROW_2 , KC_QUOT ,
    KC_LBRC , LEFT_QW_ROW_3 , OSM(MOD_LGUI) , LGUI(KC_T) , RIGHT_QW_ROW_3 , KC_RBRC ,

      OSM(MOD_LCTL) , LEFT_PRIMARY_THUMB_CLUSTER ,
    RIGHT_PRIMARY_THUMB_CLUSTER, OSM(MOD_RALT)
    ),
    [_LOWER] = LAYOUT_wrapper(
      KC_BSLS    , LEFT_SYMBOL_ROW_1 , _______ , _______ , RIGHT_SYMBOL_ROW_1 , KC_MINS   ,
      KC_GRV     , LEFT_NUM_ROW      , _______ , _______ , RIGHT_NUM_ROW      , S(KC_EQL) ,
      TO(_RAISE) , LEFT_SYMBOL_ROW_2 , _______ , _______ , RIGHT_SYMBOL_ROW_2 , KC_EQL    ,

      _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY),
      RIGHT_TRANSPARENT_THUMB_CLUSTER, _______
    ),
    [_RAISE] = LAYOUT_wrapper(
      KC_NO      , MOUSE_ROW_1 , _______ , _______ , NAV_ROW_1 , KC_NO ,
      KC_NO      , MOUSE_ROW_2 , _______ , _______ , NAV_ROW_2 , KC_NO ,
      TO(_LOWER) , MOUSE_ROW_3 , _______ , _______ , NAV_ROW_3 , KC_NO ,

      _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY),
      RIGHT_TRANSPARENT_THUMB_CLUSTER, _______
    ),
    [_NUMPAD] = LAYOUT_wrapper(
      KC_SLEP , FUNCPAD_ROW_1 , _______ , _______ , NUMPAD_ROW_1 , KC_DEL  ,
      KC_NO   , FUNCPAD_ROW_2 , _______ , _______ , NUMPAD_ROW_2 , KC_INS  ,
      KC_NO   , FUNCPAD_ROW_3 , _______ , _______ , NUMPAD_ROW_3 , KC_PEQL ,

      _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY),
      RIGHT_TRANSPARENT_THUMB_CLUSTER, _______
    )
};
