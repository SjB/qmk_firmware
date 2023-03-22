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
enum custom_keycodes {
  SJB_LLOCK = SAFE_RANGE,
};

#define _QWERTY 0
#define _RAISE 1
#define _NAV 2
#define _NUMPAD 3
#define _MOUSE 4
#define _MODS 5

#define OSL_RSE OSL(_RAISE)
#define OSL_NUM OSL(_NUMPAD)
#define OSL_NAV OSL(_NAV)

#define LT_RSE(_key) LT(_RAISE, _key)
#define LT_NUM(_key) LT(_NUMPAD, _key)
#define LT_NAV(_key) LT(_NAV, _key)
#define LT_MOD(_key) LT(_MODS, _key)

#define LK_LSFT LSFT_T(SJB_LLOCK);

#define LT_G LT_NAV(KC_G)
#define LT_H LT_NAV(KC_H)

#define LT_BSPC LT_RSE(KC_BSPC)
#define LT_SPC  LT_RSE(KC_SPC)

#define MOD_J LT_MOD(KC_J)
#define MOD_F LT_MOD(KC_F)

#define ENT_SFT LSFT_T(KC_ENT)
#define ENT_GUI LGUI_T(KC_ENT)
#define ESC_CTL CTL_T(KC_ESC)
#define EQL_SFT LSFT_T(KC_EQL)

#define TAB_ALT ALT_T(KC_TAB)
#define TAB_RALT RALT_T(KC_TAB)

#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)

#define LEFT_FUNC_ROW KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define RIGHT_FUNC_ROW KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define LEFT_NUM_ROW KC_1, KC_2, KC_3, KC_4, KC_5
#define RIGHT_NUM_ROW KC_6, KC_7, KC_8, KC_9, KC_0

#define LEFT_QW_ROW_1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define LEFT_QW_ROW_2 KC_A, KC_S, KC_D, KC_F, LT_G
#define LEFT_QW_ROW_3 KC_Z, KC_X, KC_C, KC_V, KC_B

#define RIGHT_QW_ROW_1 KC_Y, KC_U, KC_I, KC_O, KC_P
#define RIGHT_QW_ROW_2 LT_H, KC_J, KC_K, KC_L, KC_SCLN
#define RIGHT_QW_ROW_3 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define LEFT_RAISE_ROW_1 S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5)
#define LEFT_RAISE_ROW_2 KC_1, KC_2, KC_3, KC_4, LT_NAV(KC_5)
#define LEFT_RAISE_ROW_3 KC_BSLS, KC_GRV, KC_LBRC, S(KC_LBRC), KC_QUOT

#define RIGHT_RAISE_ROW_1 S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0)
#define RIGHT_RAISE_ROW_2 LT_NAV(KC_6), KC_7, KC_8, KC_9, KC_0
#define RIGHT_RAISE_ROW_3 S(KC_QUOT), S(KC_RBRC), KC_RBRC, KC_MINS, KC_EQL

#define NUMPAD_ROW_1 KC_PSLS , KC_7, KC_8, KC_9, KC_PMNS
#define NUMPAD_ROW_2 KC_DOT  , KC_4, KC_5, KC_6, KC_0
#define NUMPAD_ROW_3 KC_PAST , KC_1, KC_2, KC_3, KC_PPLS

#define RIGHT_MOUSE_ROW_1 KC_BTN7, KC_BTN4, KC_MS_U, KC_BTN5, KC_BTN6
#define RIGHT_MOUSE_ROW_2 KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0
#define RIGHT_MOUSE_ROW_3 KC_WH_D, KC_WH_L, KC_BTN3, KC_WH_R, KC_ACL1

#define MOUSE_ROW_1 MOUSE_ROW_RIGHT_1
#define MOUSE_ROW_2 MOUSE_ROW_RIGHT_2
#define MOUSE_ROW_3 MOUSE_ROW_RIGHT_3

#define LEFT_MOUSE_ROW_1 KC_BTN7, KC_BTN4, KC_MS_U, KC_BTN5, KC_BTN6
#define LEFT_MOUSE_ROW_2 KC_ACL0, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U
#define LEFT_MOUSE_ROW_3 KC_ACL1, KC_WH_L, KC_BTN3, KC_WH_R, KC_WH_D

#define TRANS_ROW _______, _______, _______, _______, _______
#define BLANK_ROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define NAV_ROW_1 KC_HOME, KC_PGUP, KC_NO,   KC_VOLU,  KC_MPRV
#define NAV_ROW_2 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_MNXT
#define NAV_ROW_3 KC_END,  KC_PGDN, KC_MUTE, KC_VOLD,  KC_MPLY

#define FUNCPAD_ROW_1 KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_PSCR
#define FUNCPAD_ROW_2 KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_INS
#define FUNCPAD_ROW_3 KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL

#define LEFT_MOD_ROW OSM_ALT, OSM_GUI, OSM_CTL, _______, KC_NO
#define RIGHT_MOD_ROW KC_NO, _______, OSM_CTL, OSM_GUI, OSM_ALT

#define TRANSPARENT_THUMB_CLUSTER _______, _______, _______
#define LEFT_TRANSPARENT_THUMB_CLUSTER(LAYER) _______, _______, TO(LAYER)

#define LEFT_PRIMARY_THUMB_CLUSTER  TAB_ALT, LT_BSPC, ESC_CTL
#define RIGHT_PRIMARY_THUMB_CLUSTER ENT_GUI, LT_SPC,  OSM_SFT

#define LEFT_RAISE_THUMB_CLUSTER(LAYER) TAB_RALT, LT_RSE(KC_DEL), TO(LAYER)
#define LEFT_MOUSE_THUMB_CLUSTER(LAYER) KC_MS_BTN2, LT_RSE(KC_MS_BTN1), TO(LAYER)

#define RIGHT_NUMPAD_THUMB_CLUSTER _______, _______ , KC_EQL
#define RIGHT_MOUSE_THUMB_CLUSTER KC_ENT, KC_MS_BTN1, KC_MS_BTN2
#define RIGHT_TRANSPARENT_THUMB_CLUSTER(_key) _______, _______, _key

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
