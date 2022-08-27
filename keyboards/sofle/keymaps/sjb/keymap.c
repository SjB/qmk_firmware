#include QMK_KEYBOARD_H
#include "sjb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    LGUI(KC_SPC) , LEFT_NUM_ROW                      , RIGHT_NUM_ROW  , LGUI(KC_T) ,
    KC_GRV       , LEFT_QW_ROW_1                     , RIGHT_QW_ROW_1 , KC_MINS    ,
    KC_BSLS      , LEFT_QW_ROW_2                     , RIGHT_QW_ROW_2 , KC_QUOT    ,
    OSM_SFT      , LEFT_QW_ROW_3 , KC_MUTE , KC_MPLY , RIGHT_QW_ROW_3 , KC_EQL     ,

    OSL_NUM , OSL_RSE,
    LEFT_PRIMARY_THUMB_CLUSTER  ,
    RIGHT_PRIMARY_THUMB_CLUSTER ,
    OSM_CTL , OSM_ALT
  ),
  [_RAISE] = LAYOUT_wrapper(
    _______    , LEFT_FUNC_ROW                        , RIGHT_FUNC_ROW     , _______    ,
    S(KC_9)    , LEFT_RAISE_ROW_1                     , RIGHT_RAISE_ROW_1  , S(KC_0)    ,
    S(KC_LBRC) , LEFT_RAISE_ROW_2                     , RIGHT_RAISE_ROW_2  , S(KC_RBRC) ,
    KC_LBRC    , LEFT_RAISE_ROW_3 , _______ , _______ , RIGHT_RAISE_ROW_3  , KC_RBRC    ,

    _______ , _______ ,
    LEFT_RAISE_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    _______ , _______
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    _______ , TRANS_ROW                        , TRANS_ROW    , _______ ,
    OSM_CTL , FUNCPAD_ROW_1                    , NUMPAD_ROW_1 , KC_DEL  ,
    OSM_ALT , FUNCPAD_ROW_2                    , NUMPAD_ROW_2 , KC_INS  ,
    OSM_SFT , FUNCPAD_ROW_3 , _______, _______ , NUMPAD_ROW_3 , KC_SPC  ,

    _______ , _______ ,
    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_NUMPAD_THUMB_CLUSTER ,
    _______ , _______
  ),
  [_NAV] = LAYOUT_wrapper(
    _______ , TRANS_ROW                        , TRANS_ROW     , _______ ,
    RGB_TOG , TRANS_ROW                        , NAV_ROW_1     , RGB_HUI ,
    RGB_MOD , TRANS_ROW                        , NAV_ROW_2     , RGB_SAI ,
    KC_SLEP , TRANS_ROW    , _______ , _______ , NAV_ROW_3     , RGB_VAI ,

    _______, _______ ,
    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    _______, _______
  ),
  [_MOUSE] = LAYOUT_wrapper(
    _______ , TRANS_ROW                            , TRANS_ROW         , _______ ,
    NK_TOGG , LEFT_MOUSE_ROW_1                     , RIGHT_MOUSE_ROW_1 , KC_NO   ,
    KC_NO   , LEFT_MOUSE_ROW_2                     , RIGHT_MOUSE_ROW_2 , KC_NO   ,
    KC_NO   , LEFT_MOUSE_ROW_3 , _______ , _______ , RIGHT_MOUSE_ROW_3 , KC_NO   ,

    _______, _______,
    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_MOUSE_THUMB_CLUSTER ,
    _______, _______
  )
};

#ifdef RGBLIGHT_LAYERS

#define _NLAYERS 4
#define INDICATOR_LEFT_LED 0
#define INDICATOR_RIGHT_LED 36

const rgblight_segment_t PROGMEM ll_0[] = RGBLIGHT_LAYER_SEGMENTS({INDICATOR_LEFT_LED  , 1 , HSV_PURPLE},
                                                                  {INDICATOR_RIGHT_LED , 1 , HSV_PURPLE});
const rgblight_segment_t PROGMEM ll_1[] = RGBLIGHT_LAYER_SEGMENTS( {INDICATOR_LEFT_LED , 1 , HSV_BLUE},
                                                                   {INDICATOR_RIGHT_LED , 1 , HSV_BLUE});
const rgblight_segment_t PROGMEM ll_2[] = RGBLIGHT_LAYER_SEGMENTS( {INDICATOR_LEFT_LED  , 1 , HSV_CYAN},
                                                                   {INDICATOR_RIGHT_LED , 1 , HSV_CYAN});
const rgblight_segment_t PROGMEM ll_3[] = RGBLIGHT_LAYER_SEGMENTS( {INDICATOR_LEFT_LED  , 1 , HSV_GREEN},
                                                                   {INDICATOR_RIGHT_LED , 1 , HSV_GREEN});

const rgblight_segment_t PROGMEM ll_4[] = RGBLIGHT_LAYER_SEGMENTS({INDICATOR_LEFT_LED + 1 , 6 , HSV_RED},
                                                                  {INDICATOR_RIGHT_LED + 1 , 6, HSV_RED});
const rgblight_segment_t PROGMEM ll_5[] = RGBLIGHT_LAYER_SEGMENTS({INDICATOR_LEFT_LED + 1, 6, HSV_YELLOW},
                                                                  {INDICATOR_RIGHT_LED + 1 , 6, HSV_YELLOW});

const rgblight_segment_t* const PROGMEM ll_layers[] =
    RGBLIGHT_LAYERS_LIST(ll_0,ll_1,ll_2,ll_3, ll_4, ll_5);

layer_state_t layer_state_set_keymap(layer_state_t state) {
    for (uint8_t i=0 ; i < _NLAYERS; i++)
        rgblight_set_layer_state(i, layer_state_cmp(state, i));

    return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case NK_TOGG:
    case NK_ON:
    case NK_OFF:
        rgblight_blink_layer_repeat(keymap_config.nkro ? 5 : 4, 500, 5);
        break;
    }
}

#endif

void keyboard_post_init_user(void) {

#ifdef RGBLIGHT_LAYERS
    rgblight_layers = ll_layers;
    rgblight_set_layer_state(0, 1);
#endif

}
