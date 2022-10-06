// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want
// to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
   LEFT_QW_ROW_1                     , RIGHT_QW_ROW_1 ,
   LEFT_QW_ROW_2                     , RIGHT_QW_ROW_2 ,
   LEFT_QW_ROW_3 , OSL_NUM , OSM_CTL , RIGHT_QW_ROW_3 ,

   OSM_SFT, KC_BSLS , KC_GRV ,
   LEFT_PRIMARY_THUMB_CLUSTER ,
   RIGHT_PRIMARY_THUMB_CLUSTER ,
   KC_MINS , KC_QUOT , KC_EQL
  ),
  [_RAISE] = LAYOUT_wrapper(
     LEFT_RAISE_ROW_1                     , RIGHT_RAISE_ROW_1 ,
     LEFT_RAISE_ROW_2                     , RIGHT_RAISE_ROW_2 ,
     LEFT_RAISE_ROW_3 , _______ , _______ , RIGHT_RAISE_ROW_3 ,

     KC_LBRC , S(KC_LBRC) , S(KC_9) ,
     LEFT_RAISE_THUMB_CLUSTER(_QWERTY) ,
     TRANSPARENT_THUMB_CLUSTER ,
     S(KC_0) , S(KC_RBRC) , KC_RBRC
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    FUNCPAD_ROW_1                    , NUMPAD_ROW_1 ,
    FUNCPAD_ROW_2                    , NUMPAD_ROW_2 ,
    FUNCPAD_ROW_3 , _______, _______ , NUMPAD_ROW_3 ,

    OSM_SFT , OSM_ALT , OSM_CTL ,
    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_NUMPAD_THUMB_CLUSTER ,
    KC_DEL , KC_INS , KC_EQL
  ),
  [_NAV] = LAYOUT_wrapper(
    TRANS_ROW                       , NAV_ROW_1 ,
    TRANS_ROW                       , NAV_ROW_2 ,
    TRANS_ROW , _______ , _______   , NAV_ROW_3 ,

    KC_NO , KC_NO , KC_SLEP ,
    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    KC_NO , KC_NO , KC_NO
  ),
  [_MOUSE] = LAYOUT_wrapper(
    LEFT_MOUSE_ROW_1 ,                     RIGHT_MOUSE_ROW_1 ,
    LEFT_MOUSE_ROW_2 ,                     RIGHT_MOUSE_ROW_2 ,
    LEFT_MOUSE_ROW_3 , _______ , _______ , RIGHT_MOUSE_ROW_3 ,

    KC_SLEP , NK_TOGG , KC_NO ,
    LEFT_MOUSE_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_MOUSE_THUMB_CLUSTER ,
    KC_NO , KC_NO , KC_NO
  ),
};
