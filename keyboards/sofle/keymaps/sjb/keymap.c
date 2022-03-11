#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    LGUI(KC_T) , LEFT_NUM_ROW                     , RIGHT_NUM_ROW  , LGUI(KC_B) ,
    KC_BSLS    , LEFT_QW_ROW_1                    , RIGHT_QW_ROW_1 , KC_MINS    ,
    KC_GRV     , LEFT_QW_ROW_2                    , RIGHT_QW_ROW_2 , KC_QUOT    ,
    KC_LBRC    , LEFT_QW_ROW_3 , KC_MUTE, KC_MPLY , RIGHT_QW_ROW_3 , KC_RBRC    ,

    MO(_LOWER) , OSM(MOD_LCTL) , LEFT_PRIMARY_THUMB_CLUSTER ,
    RIGHT_PRIMARY_THUMB_CLUSTER , OSM(MOD_LALT) ,  MO(_RAISE)
  ),
  [_LOWER] = LAYOUT_wrapper(
    _______    , LEFT_FUNC_ROW                       , RIGHT_FUNC_ROW   , _______   ,
    KC_PGUP    , LEFT_SYMBOL_ROW                     , RIGHT_SYMBOL_ROW , KC_MINS   ,
    KC_PGDN    , LEFT_NUM_ROW                        , RIGHT_NUM_ROW    , S(KC_EQL) ,
    TO(_RAISE) , LEFT_FUNC_ROW   , _______ , _______ , RIGHT_FUNC_ROW   , KC_EQL    ,

    _______ , _______ , LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_TRANSPARENT_THUMB_CLUSTER , _______ , _______
  ),
  [_RAISE] = LAYOUT_wrapper(
    _______    , LEFT_NUM_ROW                    , RIGHT_NUM_ROW , _______ ,
    KC_PGUP    , MOUSE_ROW_1                     , BLANK_ROW     , KC_NO   ,
    KC_PGDN    , MOUSE_ROW_2                     , NAV_VI_ROW    , KC_NO   ,
    TO(_LOWER) , MOUSE_ROW_3 , _______ , _______ , BLANK_ROW     , KC_NO   ,

    _______, _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY),
    RIGHT_TRANSPARENT_THUMB_CLUSTER, _______, _______
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    _______    , BLANK_ROW                        , BLANK_ROW    , _______ ,
    KC_PGUP    , FUNCPAD_ROW_1                    , NUMPAD_ROW_1 , KC_DEL  ,
    KC_PGDN    , FUNCPAD_ROW_2                    , NUMPAD_ROW_2 , KC_P0   ,
    S(KC_PSCR) , FUNCPAD_ROW_3 , _______, _______ , NUMPAD_ROW_3 , KC_PEQL ,

    _______ , _______ , LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_TRANSPARENT_THUMB_CLUSTER , _______ , _______
  )
};
