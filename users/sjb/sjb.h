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

#include QMK_KEYBOARD_H

#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

enum custom_keycodes {
  SB_LLOCK = SAFE_RANGE,
  SB_RSTL,
#ifdef CALLUM_ONESHOT
  OS_CTL,
  OS_ALT,
  OS_GUI,
  OS_RALT,
  OS_MEH,
#endif
  NEW_SAFE_RANGE
};


#define _QWERTY 0
#define _RAISE 1
#define _NAV 2
#define _NUMPAD 3
#define _MOUSE 4
#define _RHR 5
#define _LHR 6

#define OSL_RSE OSL(_RAISE)
#define OSL_NUM OSL(_NUMPAD)
#define OSL_NAV OSL(_NAV)

#define LT_RSE(_key) LT(_RAISE, _key)
#define LT_NUM(_key) LT(_NUMPAD, _key)
#define LT_NAV(_key) LT(_NAV, _key)

#ifdef LAYER_LOCK_ENABLE
#define LK_LSFT LSFT_T(SB_LLOCK)
#endif

#define NAV(_key) LT(_NAV, _key)
#define RSE(_key) LT(_RAISE, _key)

#define ENT_SFT LSFT_T(KC_ENT)
#define ENT_GUI LGUI_T(KC_ENT)
#define ENT_CTL CTL_T(KC_ENT)
#define ESC_CTL CTL_T(KC_ESC)
#define ESC_GUI LGUI_T(KC_ESC)
#define ESC_SFT LSFT_T(KC_ESC)
#define EQL_SFT LSFT_T(KC_EQL)

#define TAB_SFT LSFT_T(KC_TAB)
#define ENT_ALT ALT_T(KC_ENT)
#define TAB_ALT ALT_T(KC_TAB)
#define TAB_RALT RALT_T(KC_TAB)

#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_HYPR OSM(MOD_HYPR)

#ifdef SB_HRL

#define HR_G LT(_LHR, KC_G)
#define HR_H LT(_RHR, KC_H)



#define HR_A KC_A
#define HR_S KC_S
#define HR_D KC_D
#define HR_F KC_F
#define HR_J KC_J
#define HR_K KC_K
#define HR_L KC_L
#define HR_SCLN KC_SCLN

#endif

#else

#define HR_A KC_A
#define HR_S KC_S
#define HR_D KC_D
#define HR_F KC_F
#define HR_G KC_G
#define HR_H KC_H
#define HR_J KC_J
#define HR_K KC_K
#define HR_L KC_L
#define HR_SCLN KC_SCLN

#endif

#ifdef KEY_LOCK_ENABLE
#define SB_EXTRA  QK_LOCK
#else
#define SB_EXTRA  QK_BOOT
#endif

#define SB_LHRL HR_G
#define SB_RHRL HR_H
#define SB_RSE RSE(KC_SPC)
#define SB_NAV NAV(KC_BSPC)
#define SB_BSPC SB_NAV
#define SB_TAB ESC_CTL
#define SB_SFT ENT_SFT
#define SB_CTL ESC_CTL

#ifndef CAPS_WORD_ENABLE
#define CW_TOGG  KC_CAPS
#endif

#ifndef REPEAT_KEY_ENABLE
#define QK_REP KC_APP
#endif

#define TRANS_ROW _______, _______, _______, _______, _______
#define BLANK_ROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define LEFT_HOME_ROW  OSM_ALT , OSM_GUI, OSM_CTL, OSM_SFT, CW_TOGG
#define RIGHT_HOME_ROW CW_TOGG , OSM_SFT, OSM_CTL, OSM_GUI, OSM_ALT

#define LEFT_HOME_ROW_A   _______, _______, _______, _______, SB_LHRL
#define RIGHT_HOME_ROW_A  SB_RHRL, _______, _______, _______, _______

#define LEFT_HOME_ROW_THUMB_CLUSTER  _______, TG(_NUMPAD), SB_RSTL
#define RIGHT_HOME_ROW_THUMB_CLUSTER KC_TAB, TG(_MOUSE) , _______

#define LEFT_FUNC_ROW KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define RIGHT_FUNC_ROW KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define LEFT_NUM_ROW KC_1, KC_2, KC_3, KC_4, KC_5
#define RIGHT_NUM_ROW KC_6, KC_7, KC_8, KC_9, KC_0

#define LEFT_QW_ROW_1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define LEFT_QW_ROW_2 HR_A, HR_S, HR_D, HR_F, HR_G
#define LEFT_QW_ROW_3 KC_Z, KC_X, KC_C, KC_V, KC_B

#define RIGHT_QW_ROW_1 KC_Y, KC_U, KC_I   , KC_O  , KC_P
#define RIGHT_QW_ROW_2 HR_H, HR_J, HR_K   , HR_L  , HR_SCLN
#define RIGHT_QW_ROW_3 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define LEFT_RAISE_ROW_1 S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5)
#define LEFT_RAISE_ROW_2 KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define LEFT_RAISE_ROW_3 KC_BSLS, KC_PIPE, KC_GRV,  KC_TILD, KC_DQUO

#define RIGHT_RAISE_ROW_1 S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0)
#define RIGHT_RAISE_ROW_2 KC_6   , KC_7   , KC_8   , KC_9   , KC_0
#define RIGHT_RAISE_ROW_3 KC_QUOT, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL

#define NUMPAD_ROW_1 KC_PSLS , KC_7, KC_8, KC_9, KC_PMNS
#define NUMPAD_ROW_2 KC_DOT  , KC_4, KC_5, KC_6, KC_0
#define NUMPAD_ROW_3 KC_PAST , KC_1, KC_2, KC_3, KC_PPLS

#define FUNCPAD_ROW_1 KC_F1, KC_F2 , KC_F3 , KC_F4 , KC_PSCR
#define FUNCPAD_ROW_2 KC_F5, KC_F6 , KC_F7 , KC_F8 , KC_INS
#define FUNCPAD_ROW_3 KC_F9, KC_F10, KC_F11, KC_F12, SB_EXTRA

#define RIGHT_MOUSE_ROW_1 KC_BTN7, KC_BTN4, KC_MS_U, KC_BTN5, KC_BTN6
#define RIGHT_MOUSE_ROW_2 KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0
#define RIGHT_MOUSE_ROW_3 KC_WH_D, KC_WH_L, KC_BTN3, KC_WH_R, KC_ACL1

#define RIGHT_NAV_ROW_1 KC_HOME , KC_PGUP, KC_UP  , KC_VOLU , KC_MPRV
#define RIGHT_NAV_ROW_2 KC_TAB  , KC_LEFT, KC_DOWN, KC_RIGHT, KC_MPLY
#define RIGHT_NAV_ROW_3 KC_END  , KC_PGDN, KC_MUTE, KC_VOLD , KC_MNXT

#define LEFT_MOUSE_ROW_1 _______, _______, OSM_HYPR, C(KC_C), C(KC_X)
#define LEFT_MOUSE_ROW_2 LEFT_HOME_ROW
#define LEFT_MOUSE_ROW_3 _______, _______, OSM_MEH , C(KC_V), G(KC_SPC)

#define LEFT_SYS_ROW_1 OSM_RALT , QK_REP  , OSM_MEH  , KC_LBRC, KC_RBRC
#define LEFT_SYS_ROW_2 OSM_ALT  , OSM_GUI , OSM_CTL  , KC_LPRN, KC_RPRN
#define LEFT_SYS_ROW_3 OSM_SFT  , CW_TOGG , OSM_HYPR , KC_LCBR, KC_RCBR

#define RIGHT_SYS_ROW_1 KC_LBRC , KC_RBRC , OSM_MEH  , KC_APP  , OSM_RALT
#define RIGHT_SYS_ROW_2 KC_LPRN , KC_RPRN , OSM_CTL  , OSM_GUI , OSM_ALT
#define RIGHT_SYS_ROW_3 KC_LCBR , KC_RCBR , OSM_HYPR , CW_TOGG , OSM_SFT

#define TRANSPARENT_THUMB_CLUSTER _______, _______, _______
#define RIGHT_TRANSPARENT_THUMB_CLUSTER(_key) _______, _______, _key

#define LEFT_RSTL_THUMB_CLUSTER  _______,  _______, SB_RSTL
#define RIGHT_RSTL_THUMB_CLUSTER RSTL_SFT, _______, _______

#define LEFT_PRIMARY_THUMB_CLUSTER  OSM_SFT, SB_NAV, SB_CTL
#define RIGHT_PRIMARY_THUMB_CLUSTER SB_SFT , SB_RSE, OSM_GUI

#define LEFT_RAISE_THUMB_CLUSTER  _______, _______, SB_RSTL
#define RIGHT_RAISE_THUMB_CLUSTER _______, _______, _______

#define LEFT_NAV_THUMB_CLUSTER  _______, _______, SB_RSTL
#define RIGHT_NAV_THUMB_CLUSTER _______, _______, _______

#define LEFT_NUMPAD_THUMB_CLUSTER  _______,  _______, SB_RSTL
#define RIGHT_NUMPAD_THUMB_CLUSTER _______, KC_EQL, _______

#define LEFT_MOUSE_THUMB_CLUSTER  _______   , _______   , SB_RSTL
#define RIGHT_MOUSE_THUMB_CLUSTER KC_MS_BTN1, KC_MS_BTN2, _______

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
