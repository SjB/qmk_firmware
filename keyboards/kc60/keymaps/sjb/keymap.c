// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "kc60.h"
#include "action_layer.h"
#include "action_util.h"
#include "backlight.h"
#include "debug.h"
#include "eeconfig.h"
#include "version.h"

#ifdef TAP_DANCE_ENABLE
#include "tap_dance_extra.h"
#endif

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

#define OSL_NAV OSL(NAV)
#define OSL_FNx OSL(FNx)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_HYPR OSM(MOD_HYPR)
#define MT_TAB MT(MOD_RALT, KC_TAB)

#else

#define OSL_NAV KC_FN0
#define OSL_FNx KC_FN1
#define OSM_LSFT KC_FN2
#define OSM_LCTL KC_FN3
#define OSM_LALT KC_FN4
#define OSM_MEH KC_FN5
#define OSM_HYPR KC_FN6
#define MT_TAB KC_FN7

#endif

#define F_BROWSER M(BROWSER)

#ifdef TAP_DANCE_ENABLE
#define TD_TSKSWCH TD(0)
#else
#define TD_TSKSWCH M(TSKSWCH)
#endif

enum keymaps_layers {
  BASE = 0, // default layer
  FNx,
  NAV,      // Mouse and keyboard motion keys
};

enum custom_keycodes {
  PLACE_HOLDER = 0, // can always be here
  VRSN,
  KDBG,
  CMD,
  BROWSER,
  TSKSWCH,
  EDITOR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = KEYMAP(
      KC_GRV,    KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
      MT_TAB,    KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
      KC_ESC,    KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   \
      OSM_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    OSM_LSFT, \
      KC_LGUI,   OSM_LALT, OSM_LCTL,                    KC_SPC,                             KC_NO,    OSM_LCTL, OSM_LALT, OSL_FNx,  OSL_NAV   \
                     ),
  [FNx] = KEYMAP(
      RESET,    KC_MPLY,  KC_MNXT,  KC_MUTE, KC_VOLD,  KC_VOLU,  KC_MYCM,   F_TERM,    KC_CALC, KC_WSCH,  KC_MAIL,   F_BROWSER, M(EDITOR), KC_DELT, \
      F_MAX,    KC_F1,    KC_F2,    KC_F3,   KC_F4,    KC_F5,    KC_F6,     KC_F7,     KC_F8,   KC_F9,    KC_F10,    KC_F11,    KC_F12,    KC_PWR,  \
      KC_TRNS,  S(KC_1),  S(KC_2),  S(KC_3), S(KC_4),  S(KC_5),  S(KC_6),   S(KC_7),   S(KC_8), S(KC_9),  S(KC_0),   KC_TRNS,   KC_NO,     KC_TRNS,   \
      KC_TRNS,  KC_NO,    KC_TILD,  KC_GRV,  KC_PIPE,  KC_LCBR,  KC_RCBR,   KC_PLUS,   KC_EQUAL,KC_MINS,  KC_UNDS,   KC_NO,     KC_NO,     KC_TRNS, \
      KC_TRNS,  KC_TRNS,  KC_TRNS,                     KC_BSPC,                                 KC_NO,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS \
                 ),
  [NAV] = KEYMAP(
      M(VRSN),  KC_F1,    KC_F2,    KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,    KC_F11,    KC_F12,    KC_TRNS, \
      KC_TRNS,  KC_BTN1,  KC_MS_U,  KC_BTN2, KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_INS,  KC_NO,    KC_PSCR,   KC_NO,     KC_NO,     M(CMD), \
      KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R, KC_NO,    KC_NO,    KC_LEFT,  KC_UP,   KC_DOWN, KC_RGHT,  KC_HOME,   KC_PGUP,   KC_NO,     KC_TRNS, \
      KC_TRNS,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_END,    KC_PGDN,   KC_NO,     KC_TRNS, \
      KC_TRNS,  KC_TRNS,  KC_TRNS,                     KC_SPC,                               KC_NO,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS \
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
    case KDBG:
      if (record->event.pressed) { // For resetting EEPROM
        debug_keyboard = true;
      }
      break;
    case CMD:
      if (record->event.pressed) { // For resetting EEPROM
          register_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
      } else {
          unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
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
  }

  return MACRO_NONE;
};

#ifdef TAP_DANCE_ENABLE

qk_tap_dance_action_t tap_dance_actions[] = {
  [0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tskswch_on_finished, td_tskswch_on_reset),  // switch application / switch windows (gnome)
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
