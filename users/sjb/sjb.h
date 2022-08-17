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
#define _RAISE 1
#define _NUMPAD 2
#define _NAV 3
#define _MOUSE 4

#define LT_RS(_key) LT(_RAISE, _key)
#define LT_NUM(_key) LT(_NUMPAD, _key)
#define LT_NAV(_key) LT(_NAV, _key)

#if defined(ENABLE_HOME_ROW)
#    define A_GUI LGUI_T(KC_A)
#    define S_ALT ALT_T(KC_S)
#    define D_SFT LSFT_T(KC_D)
#    define F_CTL CTL_T(KC_F)
#    define J_CTL CTL_T(KC_J)
#    define K_SFT RSFT_T(KC_K)
#    define L_ALT ALT_T(KC_L)
#    define SCLN_GUI LGUI_T(KC_SCLN)
#else
#    define A_GUI KC_A
#    define S_ALT KC_S
#    define D_SFT KC_D
#    define F_CTL KC_F
#    define J_CTL KC_J
#    define K_SFT KC_K
#    define L_ALT KC_L
#    define SCLN_GUI KC_SCLN
#endif

#define G_NUM LT_NUM(KC_G)
#define H_NUM LT_NUM(KC_H)

#define ENT_SFT LSFT_T(KC_ENT)
#define ENT_GUI LGUI_T(KC_ENT)
#define ESC_CTL CTL_T(KC_ESC)

#define TAB_ALT ALT_T(KC_TAB)
#define BSPC_RS LT_RS(KC_BSPC)
#define SPC_RS LT_RS(KC_SPC)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)

#define LEFT_NUM_ROW KC_1, KC_2, KC_3, KC_4, KC_5
#define RIGHT_NUM_ROW KC_6, KC_7, KC_8, KC_9, KC_0

#define LEFT_QW_ROW_1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define LEFT_QW_ROW_2 A_GUI, S_ALT, D_SFT, F_CTL, G_NUM
#define LEFT_QW_ROW_3 KC_Z, KC_X, KC_C, KC_V, KC_B

#define RIGHT_QW_ROW_1 KC_Y, KC_U, KC_I, KC_O, KC_P
#define RIGHT_QW_ROW_2 H_NUM, J_CTL, K_SFT, L_ALT, SCLN_GUI
#define RIGHT_QW_ROW_3 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define LEFT_FUNC_ROW KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define RIGHT_FUNC_ROW KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define LEFT_SYMBOL_ROW_1 S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5)
#define LEFT_SYMBOL_ROW_2 KC_BSLS, S(KC_BSLS), KC_GRV, S(KC_GRV), KC_QUOT
#define LEFT_SYMBOL_ROW LEFT_SYMBOL_ROW_1

#define RIGHT_SYMBOL_ROW_1 S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0)
#define RIGHT_SYMBOL_ROW_2 S(KC_QUOT), S(KC_MINS), KC_MINS, S(KC_EQL), KC_EQL
#define RIGHT_SYMBOL_ROW RIGHT_SYMBOL_ROW_1

#define NUMPAD_ROW_1 KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS
#define NUMPAD_ROW_2 KC_PAST, KC_4, KC_5, KC_6, KC_PPLS
#define NUMPAD_ROW_3 KC_DOT, KC_1, KC_2, KC_3, KC_0

#define MOUSE_ROW_RIGHT_1 KC_BTN7, KC_BTN4, KC_MS_U, KC_BTN5, KC_BTN6
#define MOUSE_ROW_RIGHT_2 KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0
#define MOUSE_ROW_RIGHT_3 KC_WH_D, KC_WH_L, KC_BTN3, KC_WH_R, KC_ACL1

#define MOUSE_ROW_1 MOUSE_ROW_RIGHT_1
#define MOUSE_ROW_2 MOUSE_ROW_RIGHT_2
#define MOUSE_ROW_3 MOUSE_ROW_RIGHT_3

#define MOUSE_ROW_LEFT_1 KC_BTN7, KC_BTN4, KC_MS_U, KC_BTN5, KC_BTN6
#define MOUSE_ROW_LEFT_2 KC_ACL0, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U
#define MOUSE_ROW_LEFT_3 KC_ACL1, KC_WH_L, KC_BTN3, KC_WH_R, KC_WH_D

#define TRANS_ROW _______, _______, _______, _______, _______
#define BLANK_ROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define NAV_ROW_1 KC_HOME, KC_PGUP, KC_NO, KC_VOLU, KC_MPRV
#define NAV_ROW_2 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_MNXT
#define NAV_ROW_3 KC_END, KC_PGDN, KC_MUTE, KC_VOLD, KC_MPLY

#define FUNCPAD_ROW_1 KC_F12, KC_F7, KC_F8, KC_F9, TO(_NAV)
#define FUNCPAD_ROW_2 KC_F11, KC_F4, KC_F5, KC_F6, TO(_MOUSE)
#define FUNCPAD_ROW_3 KC_F10, KC_F1, KC_F2, KC_F3, KC_PSCR

#define LEFT_PRIMARY_THUMB_CLUSTER TAB_ALT, BSPC_RS, ESC_CTL
#define RIGHT_PRIMARY_THUMB_CLUSTER ENT_GUI, SPC_RS, OSM_SFT

#define LEFT_TRANSPARENT_THUMB_CLUSTER(LAYER) _______, _______, TO(LAYER)
#define TRANSPARENT_THUMB_CLUSTER _______, _______, _______

#define LEFT_MOUSE_THUMB_CLUSTER(LAYER) KC_MS_BTN2, LT_RS(KC_MS_BTN1), TO(LAYER)
#define MOUSE_THUMB_CLUSTER KC_ENT, KC_MS_BTN1, KC_MS_BTN2

#define RIGHT_TRANSPARENT_THUMB_CLUSTER(_key) _______, _______, _key

#define RAISE_THUMB_CLUSTER(LAYER) _______, LT_RS(KC_DEL), TO(LAYER)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
