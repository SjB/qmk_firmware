#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    OSM(KC_LGUI) , LEFT_NUM_ROW                     , RIGHT_NUM_ROW  , LGUI(KC_T) ,
    KC_GRV       , LEFT_QW_ROW_1                    , RIGHT_QW_ROW_1 , KC_MINS    ,
    KC_BSLS      , LEFT_QW_ROW_2                    , RIGHT_QW_ROW_2 , KC_QUOT    ,
    KC_LBRC      , LEFT_QW_ROW_3 , KC_MUTE, KC_MPLY , RIGHT_QW_ROW_3 , KC_RBRC    ,

    MO(_LOWER) , OSM(MOD_LCTL) , LEFT_PRIMARY_THUMB_CLUSTER ,
    RIGHT_PRIMARY_THUMB_CLUSTER , OSM(MOD_LALT) ,  MO(_RAISE)
  ),
  [_LOWER] = LAYOUT_wrapper(
    _______    , LEFT_FUNC_ROW                         , RIGHT_FUNC_ROW      , _______    ,
    S(KC_GRV)  , LEFT_SYMBOL_ROW_1                     , RIGHT_SYMBOL_ROW_1  , KC_COMM    ,
    S(KC_BSLS) , LEFT_NUM_ROW                          , RIGHT_NUM_ROW       , KC_DOT     ,
    S(KC_LBRC) , LEFT_SYMBOL_ROW_2 , _______ , _______ , RIGHT_SYMBOL_ROW_2  , S(KC_RBRC) ,

    _______ , _______ , LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_TRANSPARENT_THUMB_CLUSTER(OSM(MOD_RALT)) , _______ , _______
  ),
  [_RAISE] = LAYOUT_wrapper(
    _______    , LEFT_NUM_ROW                    , RIGHT_NUM_ROW , _______ ,
    KC_NO      , MOUSE_ROW_1                     , NAV_ROW_1     , KC_NO   ,
    KC_NO      , MOUSE_ROW_2                     , NAV_ROW_2     , KC_NO   ,
    TO(_LOWER) , MOUSE_ROW_3 , _______ , _______ , NAV_ROW_3     , KC_NO   ,

    _______, _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY),
    TRANSPARENT_THUMB_CLUSTER, _______, _______
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    _______ , BLANK_ROW                        , BLANK_ROW    , _______ ,
    KC_SLEP , FUNCPAD_ROW_1                    , NUMPAD_ROW_1 , KC_DEL  ,
    NK_TOGG , FUNCPAD_ROW_2                    , NUMPAD_ROW_2 , KC_INS  ,
    KC_NO   , FUNCPAD_ROW_3 , _______, _______ , NUMPAD_ROW_3 , KC_PEQL ,

    _______ , _______ , LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER , _______ , _______
  )
};
