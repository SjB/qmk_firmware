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
#define _BHRL 5
#define _RHRL 6
#define _LHRL 7

#define OSL_RSE OSL(_RAISE)
#define OSL_NUM OSL(_NUMPAD)
#define OSL_NAV OSL(_NAV)
#define OSL_MOUSE OSL(_MOUSE)

#define NAV(_key) LT(_NAV, _key)
#define RSE(_key) LT(_RAISE, _key)
#define MOUSE(_key) LT(_MOUSE, _key)

#ifdef SB_LR_HOMEROW_LAYER
#define SB_RHRL(_key) LT(_RHRL, _key)
#define SB_LHRL(_key) LT(_LHRL, _key)
#else
#define SB_RHRL(_key) _key
#define SB_LHRL(_key) _key
#endif

#ifdef SB_HOMEROW_LAYER
#define BHRL(_key) LT(_BHRL, _key)
#else
#define BHRL(_key) _key
#endif

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

#ifdef ACHORDION_ENABLE
#define LHRM(k1, k2, k3, k4, k5) LALT_T(k1), LGUI_T(k2), LCTL_T(k3), LSFT_T(k4), SB_LHRL(k5)
#define RHRM(k1, k2, k3, k4, k5) SB_RHRL(k1), RSFT_T(k2), RCTL_T(k3), RGUI_T(k4), LALT_T(k5)
#else
#define LHRM(k1, k2, k3, k4, k5) k1, k2, k3, k4, k5
#define RHRM(k1, k2, k3, k4, k5) k1, k2, k3, k4, k5
#endif

#define SB_HRM_K1(k1, k2, k3, k4, k5) k1
#define SB_HRM_K2(k1, k2, k3, k4, k5) k2
#define SB_HRM_K3(k1, k2, k3, k4, k5) k3
#define SB_HRM_K4(k1, k2, k3, k4, k5) k4
#define SB_HRM_K5(k1, k2, k3, k4, k5) k5

#define HRM_COL1(...) SB_HRM_K1(__VA_ARGS__)
#define HRM_COL2(...) SB_HRM_K2(__VA_ARGS__)
#define HRM_COL3(...) SB_HRM_K3(__VA_ARGS__)
#define HRM_COL4(...) SB_HRM_K4(__VA_ARGS__)
#define HRM_COL5(...) SB_HRM_K5(__VA_ARGS__)

#ifdef KEY_LOCK_ENABLE
#define SB_EXTRA  QK_LOCK
#else
#define SB_EXTRA  TO(_NUMPAD)
#endif

#define SB_RSE  RSE(KC_SPC)
#define SB_NAV  NAV(KC_BSPC)
#define SB_BHRL  BHRL(KC_ESC)
#define SB_MOUSE MOUSE(KC_ENT)

#define CB_LLEADER SB_NAV
#define CB_RLEADER SB_RSE

// #define SB_SFT_BSPC SB_NAV
// #define SB_THUMB_TAB ESC_CTL
// #define SB_THUMB_SUPER ESC_GUI

#ifdef CAPS_WORD_ENABLE
#define SB_CWTG CW_TOGG
#else
#define SB_CWTG KC_CAPS
#endif

#define TRANS_ROW _______, _______, _______, _______, _______
#define BLANK_ROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define LEFT_HOME_ROW  OSM_ALT  , OSM_GUI, OSM_CTL, OSM_SFT, SB_CWTG
#define RIGHT_HOME_ROW OSM_HYPR , OSM_SFT, OSM_CTL, OSM_GUI, OSM_ALT

#define LEFT_FUNC_ROW KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define RIGHT_FUNC_ROW KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define LEFT_NUM_ROW KC_1, KC_2, KC_3, KC_4, KC_5
#define RIGHT_NUM_ROW KC_6, KC_7, KC_8, KC_9, KC_0

#define LEFT_QW_ROW_1 KC_Q, KC_W, KC_E, KC_R, KC_T
#define LEFT_QW_ROW_2 LHRM(KC_A, KC_S, KC_D, KC_F, KC_G)
#define LEFT_QW_ROW_3 KC_Z, KC_X, KC_C, KC_V, KC_B

#define RIGHT_QW_ROW_1 KC_Y, KC_U, KC_I   , KC_O  , KC_P
#define RIGHT_QW_ROW_2 RHRM(KC_H, KC_J, KC_K, KC_L, KC_SCLN)
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

#define LEFT_MOUSE_ROW_1 OSM_RALT, KC_DEL, OSM_MEH , C(KC_C), C(KC_X)
#define LEFT_MOUSE_ROW_2 LEFT_HOME_ROW
#define LEFT_MOUSE_ROW_3 OSM_SFT, SB_CWTG, OSM_HYPR, C(KC_V), G(KC_SPC)

#define LEFT_SYS_ROW_1 OSM_RALT , KC_DEL  , OSM_MEH  , KC_LBRC, KC_RBRC
#define LEFT_SYS_ROW_2 OSM_ALT  , OSM_GUI , OSM_CTL  , KC_LPRN, KC_RPRN
#define LEFT_SYS_ROW_3 OSM_SFT  , SB_CWTG , OSM_HYPR , KC_LCBR, KC_RCBR

#define RIGHT_SYS_ROW_1 KC_LBRC , KC_RBRC , OSM_MEH  , KC_DEL  , OSM_RALT
#define RIGHT_SYS_ROW_2 KC_LPRN , KC_RPRN , OSM_CTL  , OSM_GUI , OSM_ALT
#define RIGHT_SYS_ROW_3 KC_LCBR , KC_RCBR , OSM_HYPR , SB_CWTG , OSM_SFT

#define TRANSPARENT_THUMB_CLUSTER _______, _______, _______
#define RIGHT_TRANSPARENT_THUMB_CLUSTER(_key) _______, _______, _key

#define LEFT_HOME_ROW_THUMB_CLUSTER  _______, TG(_NUMPAD), SB_RSTL
#define RIGHT_HOME_ROW_THUMB_CLUSTER KC_TAB, TG(_MOUSE) , _______

#define LEFT_RSTL_THUMB_CLUSTER  _______,  _______, SB_RSTL
#define RIGHT_RSTL_THUMB_CLUSTER SB_RSTL, _______, _______

#define LEFT_PRIMARY_THUMB_CLUSTER  OSM_SFT, SB_NAV, SB_BHRL
#define RIGHT_PRIMARY_THUMB_CLUSTER SB_MOUSE , SB_RSE, OSM_GUI

#define LEFT_RAISE_THUMB_CLUSTER  _______, _______, SB_RSTL
#define RIGHT_RAISE_THUMB_CLUSTER _______, _______, _______

#define LEFT_NAV_THUMB_CLUSTER  _______, _______, SB_RSTL
#define RIGHT_NAV_THUMB_CLUSTER _______, _______, _______

#define LEFT_NUMPAD_THUMB_CLUSTER  _______,  _______, SB_RSTL
#define RIGHT_NUMPAD_THUMB_CLUSTER _______, KC_EQL, _______

#define LEFT_MOUSE_THUMB_CLUSTER  _______   , _______   , SB_RSTL
#define RIGHT_MOUSE_THUMB_CLUSTER KC_MS_BTN1, KC_MS_BTN2, _______

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
