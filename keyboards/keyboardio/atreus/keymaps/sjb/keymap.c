// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want
// to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
   LEFT_QW_ROW_1                                , RIGHT_QW_ROW_1 ,
   LEFT_QW_ROW_2                                , RIGHT_QW_ROW_2 ,
   LEFT_QW_ROW_3 , OSM(MOD_LSFT), OSM(MOD_RCTL) , RIGHT_QW_ROW_3 ,

   KC_LBRC , KC_BSLS , KC_GRV ,
   LEFT_PRIMARY_THUMB_CLUSTER ,
   RIGHT_PRIMARY_THUMB_CLUSTER ,
   KC_MINS , KC_QUOT , KC_RBRC
  ),
  [_RAISE] = LAYOUT_wrapper(
     LEFT_SYMBOL_ROW_1                     , RIGHT_SYMBOL_ROW_1 ,
     LEFT_NUM_ROW                          , RIGHT_NUM_ROW    ,
     LEFT_SYMBOL_ROW_2 , _______ , _______ , RIGHT_SYMBOL_ROW_2 ,

     S(KC_9) , OSM(MOD_LSFT) , OSM(MOD_LGUI) ,
     RAISE_THUMB_CLUSTER(_QWERTY) ,
     RIGHT_TRANSPARENT_THUMB_CLUSTER(OSM(MOD_RALT)),
     OSM(MOD_RCTL) , OSM(MOD_LALT) , S(KC_0)
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    FUNCPAD_ROW_1                    , NUMPAD_ROW_1 ,
    FUNCPAD_ROW_2                    , NUMPAD_ROW_2 ,
    FUNCPAD_ROW_3 , _______, _______ , NUMPAD_ROW_3 ,

    OSM(MOD_LALT) , OSM(MOD_LSFT) , OSM(MOD_LGUI) ,
    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    KC_DEL , KC_INS , KC_PEQL
  ),
  [_NAV] = LAYOUT_wrapper(
    TRANS_ROW                       , NAV_ROW_1 ,
    TRANS_ROW                       , NAV_ROW_2 ,
    TRANS_ROW , _______ , _______   , NAV_ROW_3 ,

    KC_NO , KC_NO , KC_SLEP ,
    LEFT_MOUSE_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    KC_NO , KC_NO , KC_NO
  ),
  [_MOUSE] = LAYOUT_wrapper(
    TRANS_ROW ,                     MOUSE_ROW_1 ,
    TRANS_ROW ,                     MOUSE_ROW_2 ,
    TRANS_ROW , _______ , _______ , MOUSE_ROW_3 ,

    KC_SLEP , NK_TOGG , KC_NO ,
    LEFT_MOUSE_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    KC_NO , KC_NO , KC_NO
  ),
  };
