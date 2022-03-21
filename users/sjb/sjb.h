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

#pragma once

#include "quantum.h"
#include "version.h"
#include "eeprom.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3

#define LT_LW(_key) LT(_LOWER, _key)
#define LT_RS(_key) LT(_RAISE, _key)
#define LT_NUM(_key) LT(_NUMPAD, _key)

#define LEFT_NUM_ROW   KC_1 , KC_2, KC_3, KC_4, KC_5
#define RIGHT_NUM_ROW  KC_6 , KC_7, KC_8, KC_9, KC_0

#define LEFT_QW_ROW_1  KC_Q , KC_W , KC_E , KC_R , KC_T
#define LEFT_QW_ROW_2  GUI_T(KC_A) , ALT_T(KC_S) , CTL_T(KC_D) , SFT_T(KC_F) , LT_RS(KC_G)
#define LEFT_QW_ROW_3  KC_Z , KC_X , KC_C , KC_V , KC_B

#define RIGHT_QW_ROW_1 KC_Y , KC_U , KC_I , KC_O , KC_P
#define RIGHT_QW_ROW_2 LT_RS(KC_H) , SFT_T(KC_J) , CTL_T(KC_K) , ALT_T(KC_L) , GUI_T(KC_SCLN)
#define RIGHT_QW_ROW_3 KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH

#define LEFT_FUNC_ROW  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define RIGHT_FUNC_ROW KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define LEFT_SYMBOL_ROW S(KC_1) , S(KC_2) , S(KC_3) , S(KC_4)  , S(KC_5)
#define LEFT_SYMBOL_ROW_1 LEFT_SYMBOL_ROW
#define LEFT_SYMBOL_ROW_2 S(KC_EQL), KC_BSLS, S(KC_BSLS), KC_GRV, S(KC_GRV)

#define RIGHT_SYMBOL_ROW S(KC_6) , S(KC_7) , S(KC_8) , S(KC_9)  , S(KC_0)
#define RIGHT_SYMBOL_ROW_1 RIGHT_SYMBOL_ROW
#define RIGHT_SYMBOL_ROW_2 S(KC_QUOT), KC_QUOT, S(KC_MINS), KC_MINS, KC_EQL

#define NUMPAD_ROW_1 KC_PSLS , KC_7 , KC_8 , KC_9 , KC_PMNS
#define NUMPAD_ROW_2 KC_PAST, KC_4, KC_5, KC_6, KC_PPLS
#define NUMPAD_ROW_3 KC_DOT, KC_1, KC_2, KC_3, KC_0

#define MOUSE_ROW_1 KC_VOLU , KC_MS_BTN1 , KC_MS_U    , KC_MS_BTN2 , KC_NO
#define MOUSE_ROW_2 KC_VOLD , KC_MS_L    , KC_MS_D    , KC_MS_R    , KC_WH_U
#define MOUSE_ROW_3 KC_MUTE , KC_WH_L    , KC_MS_BTN3 , KC_WH_R    , KC_WH_D

#define TRANS_ROW _______, _______, _______, _______, _______
#define BLANK_ROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define NAV_ROW_1 KC_HOME , KC_PGUP , KC_NO , KC_NO    , KC_MPRV
#define NAV_ROW_2 KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT , KC_MNXT
#define NAV_ROW_3 KC_END  , KC_PGDN , KC_NO , KC_NO    , KC_MPLY

#define FUNCPAD_ROW_1 KC_F12 , KC_F7 , KC_F8 , KC_F9 , KC_NO
#define FUNCPAD_ROW_2 KC_F11 , KC_F4 , KC_F5 , KC_F6 , KC_NO
#define FUNCPAD_ROW_3 KC_F10 , KC_F1  , KC_F2 , KC_F3 , KC_PSCR

#define LEFT_PRIMARY_THUMB_CLUSTER  KC_TAB , LT_LW(KC_BSPC)  , KC_ESC
#define RIGHT_PRIMARY_THUMB_CLUSTER LT_NUM(KC_ENT) , LT_LW(KC_SPC) , OSM(MOD_LSFT)

#define LEFT_TRANSPARENT_THUMB_CLUSTER(LAYER) _______, _______, TO(LAYER)
#define RIGHT_TRANSPARENT_THUMB_CLUSTER _______, _______, _______

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
