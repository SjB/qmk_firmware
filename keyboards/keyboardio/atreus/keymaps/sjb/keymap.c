// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want
// to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
   LEFT_QW_ROW_1                            , RIGHT_QW_ROW_1 ,
   LEFT_QW_ROW_2                            , RIGHT_QW_ROW_2 ,
   LEFT_QW_ROW_3 , TG(_NUMPAD) , TG(_MOUSE) , RIGHT_QW_ROW_3 ,

   OSM_SFT, KC_TAB , OSM_SFT ,
   LEFT_PRIMARY_THUMB_CLUSTER ,
   RIGHT_PRIMARY_THUMB_CLUSTER ,
   OSM_MEH, OSM_HYPR, OSM_SFT
  ),
  [_RAISE] = LAYOUT_wrapper(
     LEFT_RAISE_ROW_1                     , RIGHT_RAISE_ROW_1 ,
     LEFT_RAISE_ROW_2                     , RIGHT_RAISE_ROW_2 ,
     LEFT_RAISE_ROW_3 , _______ , _______ , RIGHT_RAISE_ROW_3 ,

     _______ , _______ , _______ ,
     LEFT_RAISE_THUMB_CLUSTER ,
     RIGHT_RAISE_THUMB_CLUSTER ,
     _______ , _______ , _______
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    FUNCPAD_ROW_1                     , NUMPAD_ROW_1 ,
    FUNCPAD_ROW_2                     , NUMPAD_ROW_2 ,
    FUNCPAD_ROW_3 , _______ , _______ , NUMPAD_ROW_3 ,

    _______ , _______ , _______ ,
    LEFT_NUMPAD_THUMB_CLUSTER ,
    RIGHT_NUMPAD_THUMB_CLUSTER ,
    _______ , _______ , _______
  ),
  [_NAV] = LAYOUT_wrapper(
    LEFT_SYS_ROW_1                       , NAV_ROW_1 ,
    LEFT_SYS_ROW_2                       , NAV_ROW_2 ,
    LEFT_SYS_ROW_3 , _______ , _______   , NAV_ROW_3 ,

    KC_NO , KC_NO , NK_TOGG ,
    LEFT_NAV_THUMB_CLUSTER ,
    RIGHT_NAV_THUMB_CLUSTER ,
    KC_NO , KC_NO , KC_NO
  ),
  [_MOUSE] = LAYOUT_wrapper(
    LEFT_MOUSE_ROW_1 ,                     RIGHT_MOUSE_ROW_1 ,
    LEFT_MOUSE_ROW_2 ,                     RIGHT_MOUSE_ROW_2 ,
    LEFT_MOUSE_ROW_3 , _______ , _______ , RIGHT_MOUSE_ROW_3 ,

    _______ , _______, _______ ,
    LEFT_MOUSE_THUMB_CLUSTER ,
    RIGHT_MOUSE_THUMB_CLUSTER ,
    _______ , _______ , _______
  ),
};
