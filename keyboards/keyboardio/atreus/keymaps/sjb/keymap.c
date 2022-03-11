// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
   LEFT_QW_ROW_1                    , RIGHT_QW_ROW_1 ,
   LEFT_QW_ROW_2                    , RIGHT_QW_ROW_2 ,
   LEFT_QW_ROW_3 , OSM(MOD_LCTL), OSM(MOD_LALT), RIGHT_QW_ROW_3 ,
   KC_LBRC, KC_GRV, KC_BSLS , LEFT_PRIMARY_THUMB_CLUSTER , RIGHT_PRIMARY_THUMB_CLUSTER, KC_MINS, KC_QUOT, KC_RBRC
    ),
  [_LOWER] = LAYOUT_wrapper(
     LEFT_SYMBOL_ROW                       , RIGHT_SYMBOL_ROW ,
     LEFT_NUM_ROW                          , RIGHT_NUM_ROW    ,
     LEFT_FUNC_ROW , _______ , _______   , RIGHT_FUNC_ROW   ,
     TO(_LOWER), KC_PGUP, KC_PGDN , LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY), RIGHT_TRANSPARENT_THUMB_CLUSTER, KC_MINS, S(KC_EQL), KC_EQL
    ),
  [_RAISE] = LAYOUT_wrapper(
    MOUSE_ROW_1                         , BLANK_ROW,
    MOUSE_ROW_2                          , NAV_ROW  ,
    MOUSE_ROW_3, _______ , _______    , BLANK_ROW,
    TO(_RAISE), KC_PGUP, KC_PGDN , LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY), RIGHT_TRANSPARENT_THUMB_CLUSTER, KC_NO, KC_NO, KC_NO
                            ),
    [_NUMPAD] = LAYOUT_wrapper(
    FUNCPAD_ROW_1                    , NUMPAD_ROW_1 ,
    FUNCPAD_ROW_2                    , NUMPAD_ROW_2 ,
    FUNCPAD_ROW_3 , _______, _______ , NUMPAD_ROW_3 ,
    S(KC_PSCR) , KC_PGUP, KC_PGDN, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY), RIGHT_TRANSPARENT_THUMB_CLUSTER, KC_DEL,KC_P0, KC_PEQL
                               )

};
