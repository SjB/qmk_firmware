#include QMK_KEYBOARD_H
#include "sjb.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
  LGUI(KC_T) , LEFT_NUM_ROW                     , RIGHT_NUM_ROW  , LGUI(KC_B) ,
  KC_BSLS    , LEFT_QW_ROW_1                    , RIGHT_QW_ROW_1 , KC_MINS ,
  KC_GRV     , LEFT_QW_ROW_2                    , RIGHT_QW_ROW_2 , KC_QUOT ,
  KC_LBRC    , LEFT_QW_ROW_3 , KC_MUTE, KC_MPLY , RIGHT_QW_ROW_3 , KC_RBRC ,
  MO(_LOWER) , OSM(MOD_LCTL) , LEFT_PRIMARY_THUMB_CLUSTER , RIGHT_PRIMARY_THUMB_CLUSTER, OSM(MOD_LALT),  MO(_RAISE)
    ),
  [_LOWER] = LAYOUT_wrapper(
    _______, LEFT_FUNC_ROW                         , RIGHT_FUNC_ROW     , _______ ,
    _______, LEFT_SYMBOL_ROW_1                     , RIGHT_NUMPAD_ROW_1 , KC_BSLS ,
    KC_DEL , LEFT_SYMBOL_ROW_2                     , RIGHT_NUMPAD_ROW_2 , S(KC_EQL),
    TO(_RAISE), LEFT_SYMBOL_ROW_3 , _______ , _______ , RIGHT_NUMPAD_ROW_3 , KC_EQL,
    _______, _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY), RIGHT_TRANSPARENT_THUMB_CLUSTER, _______, _______
    ),
  [_RAISE] = LAYOUT_wrapper(
  _______ , LEFT_NUM_ROW                        , RIGHT_NUM_ROW , _______,
  _______ , LEFT_MOUSE_ROW_1                    , RIGHT_FUNCPAD_ROW_1, S(KC_PSCR),
  KC_DEL  , LEFT_MOUSE_ROW_2                    , RIGHT_FUNCPAD_ROW_2, KC_PSCR,
  TO(_LOWER) , LEFT_MOUSE_ROW_3, _______, _______  , RIGHT_FUNCPAD_ROW_3, KC_EQL,
  _______, _______, LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY), RIGHT_TRANSPARENT_THUMB_CLUSTER, _______, _______

    )
};
