// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "atreus.h"
#include "action_layer.h"
#include "action_util.h"
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

#define OSL_NAV OSL(NAV)
#define OSL_FNx OSL(FNx)
#define OSM_LCTL OSM(MOD_LCTL)

#define MT_TAB MT(MOD_RALT, KC_TAB)
#define MT_ESC MT(MOD_LALT, KC_ESC)

#define MT_Z MT(MOD_LSFT, KC_Z)
#define MT_SLSH MT(MOD_LSFT, KC_SLSH)

#define F_BROWSER M(BROWSER)

#ifdef TAP_DANCE_ENABLE

#define TD_LBRC TD(0)
#define TD_RBRC TD(1)
#define TD_QUOT TD(2)
#define TD_TSKSWCH TD(3)
#define TD_F9 TD(4)
#define TD_F10 TD(5)
#define TD_Q TD(6)
#else

#define TD_LBRC KC_LBRC
#define TD_RBRC KC_RBRC
#define TD_QUOT KC_QUOT
#define TD_TSKSWCH M(TSKSWCH)
#define TD_F9  KC_F9
#define TD_F10 KC_F10
#define TD_Q KC_Q
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
  BESC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = { /* Qwerty */
  {TD_Q,     KC_W,    KC_E,       KC_R,     KC_T,     KC_TRNS,  KC_Y,      KC_U,      KC_I,      KC_O,    KC_P    },
  {KC_A,     KC_S,    KC_D,       KC_F,     KC_G,     KC_TRNS,  KC_H,      KC_J,      KC_K,      KC_L,    KC_SCLN },
  {MT_Z,     KC_X,    KC_C,       KC_V,     KC_B,     KC_BSPC,  KC_N,      KC_M,      KC_COMM,   KC_DOT,  MT_SLSH },
  {OSL_FNx,  MT_TAB,  TD_LBRC,    MT_ESC,   OSM_LCTL, KC_ENT,   KC_SPC,    KC_LGUI,   TD_RBRC,   TD_QUOT, OSL_NAV}
},
[FNx] = { /* [> FNx <] */
  {KC_F1,    KC_F2,   KC_F3,      KC_F4,    KC_F5,    KC_TRNS,  KC_F6,     KC_F7,     KC_F8,     TD_F9,    TD_F10 },
  {KC_1,     KC_2,    KC_3,       KC_4,     KC_5,     KC_TRNS,  KC_6,      KC_7,      KC_8,      KC_9,     KC_0},
  {S(KC_1),  S(KC_2), S(KC_3),    S(KC_4),  S(KC_5),  KC_TRNS,  S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9),  S(KC_0)},
  {KC_TRNS,  KC_MINS, KC_BSLS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_GRV,    KC_EQUAL, KC_TRNS}
},
[NAV] = { /* [> NAV <] */
  {KC_BTN1,  KC_MS_U, KC_BTN2,    KC_MUTE,  KC_VOLU,  KC_TRNS,  KC_NO,     KC_NO,     KC_INS,    KC_NO,    KC_PSCR},
  {KC_MS_L,  KC_MS_D, KC_MS_R,    KC_NO,    KC_VOLD,  KC_TRNS,  KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,  KC_NO},
  {KC_MYCM,  F_TERM,  KC_CALC,    KC_WSCH,  KC_MAIL,  KC_DELT,  F_BROWSER, M(EDITOR), KC_HOME,   KC_PGUP,  RESET},
  {KC_TRNS,  KC_TRNS, TD_TSKSWCH, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_END,    KC_PGDN,  KC_TRNS}
}};


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

qk_tap_dance_action_t tap_dance_actions[] = {
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
  [1] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
  [2] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_MINS),
  [3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tskswch_on_finished, td_tskswch_on_reset),  // switch application / switch windows (gnome)
  [4] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F11),
  [5] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F12),
  [6] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
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
