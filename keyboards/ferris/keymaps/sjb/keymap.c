// Copyright (c) 2023 Sagacity Solutions Inc. All right reserved.

#include QMK_KEYBOARD_H
#include "sjb.h"

#define SWEEP_THUMB_TRIM(...) _SWEEP_THUMB_TRIM(__VA_ARGS__)
#define _SWEEP_THUMB_TRIM(a, b, c) b, c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
   LEFT_QW_ROW_1 , RIGHT_QW_ROW_1 ,
   LEFT_QW_ROW_2 , RIGHT_QW_ROW_2 ,
   LEFT_QW_ROW_3 , RIGHT_QW_ROW_3 ,

   SWEEP_THUMB_TRIM(LEFT_PRIMARY_THUMB_CLUSTER) ,
   SWEEP_THUMB_TRIM(RIGHT_PRIMARY_THUMB_CLUSTER)
  ),
  [_APTV3] = LAYOUT_wrapper(
    LEFT_APTV3_ROW_1 , RIGHT_APTV3_ROW_1 ,
    LEFT_APTV3_ROW_2 , RIGHT_APTV3_ROW_2 ,
    LEFT_APTV3_ROW_3 , RIGHT_APTV3_ROW_3 ,

    SWEEP_THUMB_TRIM(LEFT_PRIMARY_THUMB_CLUSTER) ,
    SWEEP_THUMB_TRIM(RIGHT_PRIMARY_THUMB_CLUSTER)
  ),
  [_RAISE] = LAYOUT_wrapper(
    LEFT_RAISE_ROW_1 , RIGHT_RAISE_ROW_1 ,
    LEFT_RAISE_ROW_2 , RIGHT_RAISE_ROW_2 ,
    LEFT_RAISE_ROW_3 , RIGHT_RAISE_ROW_3 ,

    SWEEP_THUMB_TRIM(LEFT_RAISE_THUMB_CLUSTER) ,
    SWEEP_THUMB_TRIM(RIGHT_RAISE_THUMB_CLUSTER)
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    FUNCPAD_ROW_1 , NUMPAD_ROW_1 ,
    FUNCPAD_ROW_2 , NUMPAD_ROW_2 ,
    FUNCPAD_ROW_3 , NUMPAD_ROW_3 ,

    SWEEP_THUMB_TRIM(LEFT_NUMPAD_THUMB_CLUSTER) ,
    SWEEP_THUMB_TRIM(RIGHT_NUMPAD_THUMB_CLUSTER)
  ),
  [_NAV] = LAYOUT_wrapper(
    LEFT_SYS_ROW_1 , NAV_ROW_1 ,
    LEFT_SYS_ROW_2 , NAV_ROW_2 ,
    LEFT_SYS_ROW_3 , NAV_ROW_3 ,

    SWEEP_THUMB_TRIM(LEFT_NAV_THUMB_CLUSTER) ,
    SWEEP_THUMB_TRIM(RIGHT_NAV_THUMB_CLUSTER)
  ),
  [_MOUSE] = LAYOUT_wrapper(
    LEFT_MOUSE_ROW_1 , RIGHT_MOUSE_ROW_1 ,
    LEFT_MOUSE_ROW_2 , RIGHT_MOUSE_ROW_2 ,
    LEFT_MOUSE_ROW_3 , RIGHT_MOUSE_ROW_3 ,

    SWEEP_THUMB_TRIM(LEFT_MOUSE_THUMB_CLUSTER) ,
    SWEEP_THUMB_TRIM(RIGHT_MOUSE_THUMB_CLUSTER)
  ),
};
