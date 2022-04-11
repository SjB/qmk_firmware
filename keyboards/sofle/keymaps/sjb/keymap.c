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

    _______ , _______ ,
    LOWER_THUMB_CLUSTER(_QWERTY) ,
    RIGHT_TRANSPARENT_THUMB_CLUSTER(OSM(MOD_RALT)) ,
    _______ , _______
  ),
  [_RAISE] = LAYOUT_wrapper(
    _______    , LEFT_NUM_ROW                    , RIGHT_NUM_ROW , _______ ,

    RGB_TOG    , MOUSE_ROW_1                     , NAV_ROW_1     , RGB_HUI ,
    RGB_MOD    , MOUSE_ROW_2                     , NAV_ROW_2     , RGB_SAI ,
    TO(_LOWER) , MOUSE_ROW_3 , _______ , _______ , NAV_ROW_3     , RGB_VAI,

    _______, _______,
    LEFT_MOUSE_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    _______, _______
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    _______ , BLANK_ROW                        , BLANK_ROW    , _______ ,
    KC_SLEP , FUNCPAD_ROW_1                    , NUMPAD_ROW_1 , KC_DEL  ,
    NK_TOGG , FUNCPAD_ROW_2                    , NUMPAD_ROW_2 , KC_INS  ,
    KC_NO   , FUNCPAD_ROW_3 , _______, _______ , NUMPAD_ROW_3 , KC_PEQL ,

    _______ , _______ ,
    LEFT_TRANSPARENT_THUMB_CLUSTER(_QWERTY) ,
    TRANSPARENT_THUMB_CLUSTER ,
    _______ , _______
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
