// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "infinity60.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"
#include "backlight.h"
#include "eeconfig.h"
#include "version.h"

#define DEFAULT_EDITOR "emacs"

// unsupported hid comsumer id
#define AL_INTERNET_BROWSER 0x0196
#define AL_EDITOR 0x185

#define LCA(kc) (kc | QK_LCTL | QK_LALT)
#define LSS(kc) (kc | QK_LSFT | QK_LGUI)

#define F_RALT KC_RALT
#define F_RCTL KC_RCTL
#define F_TERM LCA(KC_T)
#define F_LOCK LGUI(KC_L)
#define F_MAX  LALT(KC_F10)  // Toggle maximazation state

#ifdef USING_QK_FUNCTION

#define OSL_NAV OSL(Nav)
#define OSL_FNx OSL(FNx)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_HYPR OSM(MOD_HYPR)
#define MT_TAB MT(MOD_RALT, KC_TAB)
#define MT_SPC MT(MOD_LCTL, KC_SPC)

#else

#define OSL_NAV KC_FN0
#define OSL_FNx KC_FN1
#define OSM_LSFT KC_FN2
#define OSM_LCTL KC_FN3
#define OSM_LALT KC_FN4
#define OSM_MEH KC_FN5
#define OSM_HYPR KC_FN6
#define MT_TAB KC_FN7
#define MT_SPC KC_FN8

#endif

#define F_BROWSER M(BROWSER)

#ifdef TAP_DANCE_ENABLE

#define TD_LBRC TD(0)
#define TD_RBRC TD(1)
#define TD_BSLS TD(2)
#define TD_QUOT TD(3)
#define TD_RGHT TD(4)
#define TD_LEFT TD(5)
#define TD_SCLN TD(6)
#define TD_TSKSWCH TD(7)
#define TD_LGUI TD(8)
#define TD_ESC  TD(9)
#else

#define TD_LBRC KC_LBRC
#define TD_RBRC KC_RBRC
#define TD_BSLS KC_BSLS
#define TD_QUOT KC_QUOT
#define TD_RGHT KC_RGHT
#define TD_LEFT KC_LEFT
#define TD_TAB  KC_TAB
#define TD_SCLN KC_SCLN
#define TD_TSKSWCH M(TSKSWCH)
#define TD_LGUI KC_LGUI
#define TD_ESC  KC_ESC

#endif

enum keymaps_layers {
  BASE = 0, // default layer
  FNx,
  NAV,      // Mouse and keyboard motion keys
};

enum custom_keycodes {
  PLACE_HOLDER = 0, // can always be here
  FLSH,
  VRSN,
  KDBG,
  BROWSER,
  TSKSWCH,
  EDITOR,
  BESC,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = KEYMAP(
      TD_ESC,    KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,  KC_BSPC,  \
      MT_TAB,    KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      TD_LBRC,   TD_RBRC,   TD_BSLS,  \
      OSM_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     TD_SCLN,   TD_QUOT,   KC_ENT,    \
      OSM_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   OSM_LSFT,  M(BESC),   \
      OSL_NAV,   OSM_MEH,  TD_LGUI,                     MT_SPC,                                           OSM_LALT,  OSM_HYPR,  OSL_FNx,   TD_TSKSWCH \
                     ),
  [FNx] = KEYMAP(
      M(FLSH),  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MYCM,  F_TERM,   KC_CALC,  KC_WSCH,  KC_MAIL,   F_BROWSER, M(EDITOR), KC_DELT, KC_DELT,  \
      F_MAX,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,    KC_PWR,  \
      KC_TRNS,  S(KC_1),  S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),  S(KC_6),  S(KC_7),  S(KC_8),  S(KC_9),  S(KC_0),   KC_TRNS,   KC_TRNS,   \
      KC_TRNS,  KC_TILD,  KC_GRV,   KC_PIPE,  KC_LCBR,  KC_RCBR,  KC_PLUS,  KC_EQUAL, KC_MINS,  KC_UNDS,  KC_NO,     KC_TRNS,   KC_TRNS,   \
      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_BSPC,                                          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS \
                 ),
  [NAV] = KEYMAP(
      M(VRSN),  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,    KC_TRNS, KC_TRNS,  \
      KC_TRNS,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_INS,   KC_NO,    KC_PSCR,   KC_NO,     KC_NO,     KC_TRNS, \
      KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,    KC_NO,    TD_LEFT,  KC_UP,    KC_DOWN,  TD_RGHT,  KC_HOME,   KC_PGUP,   KC_TRNS,   \
      KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_END,   KC_PGDN,   KC_TRNS,   KC_TRNS,   \
      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_SPC,                                           KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS \
)
};

#ifndef USING_QK_FUNCTION
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_ONESHOT(NAV),
  [1] = ACTION_LAYER_ONESHOT(FNx),
  [2] = ACTION_MODS_ONESHOT(MOD_LSFT),
  [3] = ACTION_MODS_ONESHOT(MOD_LCTL),
  [4] = ACTION_MODS_ONESHOT(MOD_LALT),
  [5] = ACTION_MODS_ONESHOT(MOD_MEH),
  [6] = ACTION_MODS_ONESHOT(MOD_HYPR),
  [7] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_TAB),
  [8] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_SPC),
};
#endif

#define TAP_CONSUMER_HID_CODE(code) \
  host_consumer_send(code); \
  host_consumer_send(0)

#define TAP_KEY(code) \
  register_code(code); \
  unregister_code(code)

#define TAP_KEY16(code) \
  register_code16(code); \
  unregister_code16(code)

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case FLSH:
      if (record->event.pressed) { // For resetting EEPROM
        reset_keyboard();
      }
      break;
    case KDBG:
      if (record->event.pressed) { // For resetting EEPROM
        debug_keyboard = true;
      }
      break;
    case BROWSER:
      if (record->event.pressed) { // send AL_INTERNET_BROWSER to OS
        TAP_CONSUMER_HID_CODE(AL_INTERNET_BROWSER);
      }
      break;
    case EDITOR:
      if (record->event.pressed) {
        TAP_KEY(KC_LGUI);
        wait_ms(250);
        SEND_STRING(DEFAULT_EDITOR "\n");
      }
      break;
    case BESC:
      if (record->event.pressed) {
        set_mods(0x00);
        send_keyboard_report();
        layer_clear();
        layer_on(BASE);
      }
      break;
  }

  return MACRO_NONE;
};

#ifdef TAP_DANCE_ENABLE

#define TD_PRESSED_EVENT 10

#define ACTION_TAP_DANCE_MOD_TAP(kc1, kc2) { \
    .fn = { NULL, td_mod_tap_on_finished, td_mod_tap_on_reset },    \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }), \
  }

static void td_mod_tap_on_finished(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->pressed) {
    register_mods(pair->kc2);
    state->count = TD_PRESSED_EVENT; // magic number for reset
  } else if (state->count == 1) {
    register_code(pair->kc1);
  } else if (state->count == ONESHOT_TAP_TOGGLE) {
    register_mods(pair->kc2);
  }
}

static void td_mod_tap_on_reset(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  if (state->count == ONESHOT_TAP_TOGGLE) {
    return;
  }

  if (state->count == 1) {
    unregister_code(pair->kc1);
    unregister_mods(pair->kc2);
  }

  if (state->count == TD_PRESSED_EVENT) {
    unregister_mods(pair->kc2);
  }
}

static void td_tskswch_on_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->pressed) {
    TAP_KEY(KC_LGUI);
    wait_ms(250);
    register_code(KC_LALT);
    state->count = 3;
  } else {
    switch (state->count) {
      case 1:
        register_code16(LGUI(KC_TAB));
        break;
      case 2:
        register_code16(LALT(KC_F6));
        break;
    }
  }
}

static void td_tskswch_on_reset(qk_tap_dance_state_t *state, void *user_data) {
   switch (state->count) {
      case 1:
        unregister_code16(LGUI(KC_TAB));
        break;
      case 2:
        unregister_code16(LALT(KC_F6));
        break;
      case 3:
        unregister_mods(MOD_BIT(KC_LALT));
        break;
    }
}

#define ACTION_TAP_DANCE_LAYER_TAP(kc1, kc2) { \
    .fn = { NULL, td_layer_toggle_on_finished, NULL },    \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }), \
  }

void td_layer_toggle_on_finished (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->count == 1) {
    TAP_KEY16(pair->kc1);
  } else if (state->count == 2) {
    if (IS_LAYER_ON(pair->kc2)) {
      layer_off(pair->kc2);
    } else {
      layer_on(pair->kc2);
    }
  }
}

#define ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(kc1, kc2) { \
    .fn = { NULL, td_pair_restore_mods_finished, NULL}, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),  \
  }

void td_pair_restore_mods_finished(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  uint8_t mods = get_mods();
  if (state->count == 1) {
    TAP_KEY16(pair->kc1);
  } else if (state->count == 2) {
    TAP_KEY16(pair->kc2);
  }
  set_mods(mods);
}

#define ACTION_TAP_DANCE_SHIFT_WITH_DOUBLE(kc) ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(kc, LSFT(kc))

qk_tap_dance_action_t tap_dance_actions[] = {
  [0] = ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(KC_LBRC, KC_LPRN),
  [1] = ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(KC_RBRC, KC_RPRN),
  [2] = ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(KC_BSLS, KC_TILD),
  [3] = ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(KC_QUOT, KC_GRV),
  [4] = ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(KC_RGHT, LSS(KC_RGHT)),
  [5] = ACTION_TAP_DANCE_DOUBLE_RESTORE_MODS(KC_LEFT, LSS(KC_LEFT)),
  [6] = ACTION_TAP_DANCE_SHIFT_WITH_DOUBLE(KC_SCLN),
  [7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tskswch_on_finished, td_tskswch_on_reset),  // switch application / switch windows (gnome)
  [8] = ACTION_TAP_DANCE_MOD_TAP(KC_LGUI, MOD_LGUI | MOD_LSFT),
  [9] = ACTION_TAP_DANCE_MOD_TAP(KC_ESC, F_LOCK),
};
#endif

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

#define IS_MOD_ACTIVE(kc) (get_mods() & MOD_BIT(kc) \
                           || ((get_oneshot_mods() & MOD_BIT(kc)) && !has_oneshot_mods_timed_out()))


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
#ifdef BACKLIGHT_ENABLE
  
  uint8_t level = 0;
  if (IS_MOD_ACTIVE(KC_LCTL) || IS_MOD_ACTIVE(KC_LALT))
    level = 0x03;

  if (IS_MOD_ACTIVE(KC_LSFT))
    level = 0x04;

  if (IS_LAYER_ON(1) || IS_LAYER_ON(2))
    level = 0x05;

  backlight_level(level ^ get_backlight_level());
#endif

}
