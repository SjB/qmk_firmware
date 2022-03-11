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

enum layer_names {
    _QW,
    _LW,
    _RS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_wrapper(
    KC_BSLS , LEFT_QW_ROW_1 , LGUI(KC_T) , LGUI(KC_B) , RIGHT_QW_ROW_1 , KC_MINS,
    KC_GRV  , LEFT_QW_ROW_2 , C(KC_SPC)  , C(KC_SPC)  , RIGHT_QW_ROW_2 , KC_QUOT,
    KC_LBRC , LEFT_QW_ROW_3 , MO(_LW)    , MO(_RS)    , RIGHT_QW_ROW_3 , KC_RBRC ,
    OSM(MOD_LCTL) , LEFT_PRIMARY_THUMB_CLUSTER , RIGHT_PRIMARY_THUMB_CLUSTER, OSM(MOD_RALT)
    ),
    [_LW] = LAYOUT_wrapper(
    _______, LEFT_SYMBOL_ROW_1 , _______ , _______ , RIGHT_NUMPAD_ROW_1 , KC_BSLS ,
    KC_DEL , LEFT_SYMBOL_ROW_2 , _______ , _______ , RIGHT_NUMPAD_ROW_2 , S(KC_EQL),
    TO(_RS), LEFT_SYMBOL_ROW_3 , _______ , _______ , RIGHT_NUMPAD_ROW_3 , KC_EQL,
    _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QW), RIGHT_TRANSPARENT_THUMB_CLUSTER, _______

    ),
    [_RS] = LAYOUT_wrapper(
    _______ , LEFT_MOUSE_ROW_1 , _______ , _______ , RIGHT_FUNCPAD_ROW_1 , S(KC_PSCR) ,
    KC_DEL  , LEFT_MOUSE_ROW_2 , _______, _______ , RIGHT_FUNCPAD_ROW_2 , KC_PSCR ,
    TO(_LW) , LEFT_MOUSE_ROW_3 , _______, _______ , RIGHT_FUNCPAD_ROW_3 , KC_EQL ,
    _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QW), RIGHT_TRANSPARENT_THUMB_CLUSTER, _______
    )
};
