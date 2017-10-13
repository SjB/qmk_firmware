#include "action_layer.h"
#include "action_util.h"
#include "debug.h"
#include "eeconfig.h"
#include "ergodox.h"
#include "led.h"
#include "version.h"

#ifdef TAP_DANCE_ENABLE
#include "tap_dance_extra.h"
#endif

#ifdef SUBPROJECT_infinity
#include "infinity.h"
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

#define MT_TAB MT(MOD_RALT, KC_TAB)
#define MT_ESC MT(MOD_LALT, KC_ESC)

#define MT_Z MT(MOD_LSFT, KC_Z)
#define MT_SLSH MT(MOD_LSFT, KC_SLSH)
#define MT_LBRC MT(MOD_LSFT, KC_LBRC)
#define MT_BSLS MT(MOD_LSFT, KC_BSLS)


#define OSL_NAV OSL(NAV)
#define OSL_NUM OSL(NUMPAD)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_HYPR OSM(MOD_HYPR)
#define MT_TAB MT(MOD_RALT, KC_TAB)
#define TG_ADORE TG(ADORE)
#define TG_NORMAN TG(NORMAN)

#define F_BROWSER M(BROWSER)

#ifdef TAP_DANCE_ENABLE

#define TD_LBRC TD(0)
#define TD_RBRC TD(1)
#define TD_BSLS TD(2)
#define TD_GRV  TD(3)
#define TD_RGHT TD(4)
#define TD_LEFT TD(5)
#define TD_TSKSWCH TD(6)
#define TD_LGUI TD(7)
#define TD_ESC  TD(8)
#define TD_TERM TD(9)
#define TD_Q TD(10)
#define TD_QUOT TD(11)

#else

#define TD_LBRC KC_LBRC
#define TD_RBRC KC_RBRC
#define TD_BSLS KC_BSLS
#define TD_GRV  KC_GRV
#define TD_RGHT KC_RGHT
#define TD_LEFT KC_LEFT
#define TD_TAB  KC_TAB
#define TD_TSKSWCH M(TSKSWCH)
#define TD_LGUI KC_LGUI
#define TD_Q KC_Q
#define TD_TERM F_TERM
#define TD_ESC  KC_ESC
#define TD_QUOT KC_QUOT


#endif

enum keymaps_layers {
  BASE = 0, // default layer
  NAV,   // Mouse and keyboard motion keys
  NUMPAD,   // numpad
  ADORE,
  NORMAN,
};

enum custom_keycodes {
  PLACE_HOLDER = 0, // can always be here
  VRSN,
  KDBG,
  BROWSER,
  TSKSWCH,
  EDITOR,
  CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | Term |           | MYCM |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  \   |           |  `   |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTRL  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | NAV  |  TAB | SWCH |  ESC |  Alt |                                       | LGUI |   -  |   '  |  MEH | NUM  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME | END  |       | PGUP | PGDN |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | NRMN |       | ADORE|        |      |
 *                                 | LCTRL| BKSP |------|       |------|  ENTER | [ ]  |
 *                                 |      |      | Esc  |       | SWCH |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,      KC_2,       KC_3,    KC_4,       KC_5,     TD_TERM,
        MT_TAB,   TD_Q,      KC_W,       KC_E,    KC_R,       KC_T,     KC_BSLS,
        OSM_LCTL, KC_A,      KC_S,       KC_D,    KC_F,       KC_G,
        OSM_LSFT, MT_Z,      KC_X,       KC_C,    KC_V,       KC_B,     KC_LBRC,
        OSL_NAV,  MT_TAB,    TD_TSKSWCH, MT_ESC, OSM_LALT,
                                                              KC_HOME,  KC_END,
                                                                        TG_NORMAN,
                                                   OSM_LCTL,  KC_BSPC,  TD_ESC,
        // right hand
        KC_MYCM,  KC_6,      KC_7,       KC_8,      KC_9,      KC_0,     KC_MINS,
        KC_GRV,   KC_Y,      KC_U,       KC_I,      KC_O,      KC_P,     KC_EQL,
                  KC_H,      KC_J,       KC_K,      KC_L,      KC_SCLN,  KC_QUOT,
        KC_RBRC,  KC_N,      KC_M,       KC_COMM,   KC_DOT,    MT_SLSH,  OSM_RSFT,
                             KC_LGUI,    KC_MINS,   TD_QUOT,   OSM_MEH,  OSL_NUM,
        KC_PGUP,  KC_PGDN,
        TG_ADORE,
        TD_TSKSWCH,   KC_ENT,    KC_SPC
    ),
/* Keymap 1: Motion Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | Mute |           | App  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  F1  |  F2  |  F3  |  F4  | Mute | Vol+ |           | Dbg  | Home | PGDN | PGUP |  END | PRSC |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPSLCK |  F5  |  F6  |  F7  |  F8  | Vol+ |------|           |------| Left | Down |  Up| Rght | INS  |        |
 * |---------+------+------+------+------+------| Vol- |           | KDBG |------+------+------+------+------+--------|
 * |         |  F9  |  F10 |  F11 |  F12 | Vol- |      |           |      | Calc | SRCH | Mail | WWW  | RESET|        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MPLY | MNXT |       | Pwr  | Slp  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Navigation
[NAV] = KEYMAP(
       // left hand
       RESET,     KC_F1,    KC_F2,       KC_F3,     KC_F4,      KC_F5,          KC_TRNS,
       F_MAX,     KC_F1,    KC_F2,       KC_F3,     KC_F4,      KC_MUTE,        KC_TRNS,
       KC_CAPS,   KC_F5,    KC_F6,       KC_F7,     KC_F8,      KC_VOLU,
       KC_TRNS,   KC_F9,    KC_F10,      KC_F11,    KC_F12,     KC_VOLD,        KC_TRNS,
       KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,
                                                                KC_MPLY,        KC_MNXT,
                                                                                KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,        KC_TRNS,
       // right hand
       KC_APP,    KC_F6,     KC_F7,      KC_F8,     KC_F9,      KC_F10,     KC_F11,
       DEBUG,     KC_HOME,   KC_PGDN,    KC_PGUP,   KC_END,     KC_PSCR,    KC_F12,
                  KC_LEFT,   KC_DOWN,    KC_UP,     KC_RGHT,    KC_INS,     KC_NO,
       M(KDBG),   KC_CALC,   KC_WSCH,    KC_MAIL,   F_BROWSER,  RESET,      KC_TRNS,
                             KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_PWR,    KC_SLEP,
       KC_TRNS,
       KC_TRNS,   KC_TRNS,   KC_TRNS
       ),
/* Keymap 2: Symbol and Numpad
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |      |           |      |  ~   |   7  |   8  |   9  |  *   |   "    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPSLCK |   ^  |   &  |   *  |   (  |   )  |------|           |------|  /   |   4  |   5  |   6  |  +   |   '    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   `  |   /  |   |   |  [  |   ]  |      |           |      |  -   |   1  |   2  |   3  |  \   |        |
 * `---------+------+------+------+------+------+------'           `------+------+------+------+------+------+--------'
 *    |      |      |      |      |      |                                       |      |   0  |   .  |  =   |      |
 *    `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Symbol and Numpad
[NUMPAD] = KEYMAP(
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE,
       KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_VOLU,
       KC_CAPS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
       KC_TRNS, KC_GRV,  KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, KC_VOLD,
                KC_TRNS, F_MAX,   KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_DELT, KC_TRNS,
       // right hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
       KC_NO,   KC_TILD, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_DQT,
                KC_SLSH, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_QUOT,
       KC_NO,   KC_MINS, KC_1,    KC_2,    KC_3,    KC_EQL,  KC_TRNS,
                         KC_TRNS, KC_0,    KC_DOT,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap ADORE:
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   9  |   7  |   5  |   3  |   1  | Term |           | MYCM |   0  |   2  |   4  |   6  |   8  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   X  |   W  |   C  |   H  |   F  |  \   |           |  `   |   M  |   G  |   L  |   P  |   /  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTRL  |   A  |   O  |   E  |   I  |   U  |------|           |------|   D  |   R  |   T  |   N  |   S  |   ;    |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   Q  |   '  |   ,  |   .  |      |           |      |   B  |   K  |   V  |   Y  |   J  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME | END  |       | PGUP | PGDN |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | LCTRL| BKSP |------|       |------|  ENTER | [ ]  |
 *                                 |      |      | LGUI |       | Esc  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[ADORE] = KEYMAP(
        // left hand
        KC_TRNS,  KC_9,      KC_7,    KC_5,    KC_3,       KC_1,     KC_TRNS,
        KC_TRNS,  KC_X,      KC_W,    KC_C,    KC_H,       KC_F,     KC_TRNS,
        KC_TRNS,  KC_A,      KC_O,    KC_E,    KC_I,       KC_U,
        KC_TRNS,  KC_Z,      KC_Q,    KC_QUOT, KC_COMM,    KC_DOT,   KC_TRNS,
        KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
                                                           KC_TRNS,  KC_TRNS,
                                                                     KC_TRNS,
                                               KC_TRNS,    KC_TRNS,  KC_TRNS,

        // right hand
        KC_TRNS,  KC_0,      KC_2,     KC_4,      KC_6,      KC_8,     KC_MINS,
        KC_TRNS,  KC_M,      KC_G,     KC_L,      KC_P,      KC_SLSH,  KC_EQL,
                  KC_D,      KC_R,     KC_T,      KC_N,      KC_S,     KC_SCLN,
        KC_TRNS,  KC_B,      KC_K,     KC_V,      KC_Y,      KC_J,     KC_TRNS,
                             KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,
        KC_TRNS,
        KC_TRNS,  KC_TRNS,   KC_TRNS
                 ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | Term |           | MYCM |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   D  |   F  |   K  |  \   |           |  `   |   J  |   U  |   R  |   L  |   ;  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTRL  |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |   '    |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME | END  |       | PGUP | PGDN |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | LCTRL| BKSP |------|       |------|  ENTER | [ ]  |
 *                                 |      |      | LGUI |       | Esc  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[NORMAN] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,  KC_1,      KC_2,    KC_3,    KC_4,       KC_5,     KC_TRNS,
        KC_TRNS,  KC_Q,      KC_W,    KC_D,    KC_F,       KC_K,     KC_TRNS,
        KC_TRNS,  KC_A,      KC_S,    KC_E,    KC_T,       KC_G,
        KC_TRNS,  KC_Z,      KC_X,    KC_C,    KC_V,       KC_B,     KC_TRNS,
        KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
                                                           KC_TRNS,  KC_TRNS,
                                                                     KC_TRNS,
                                               KC_TRNS,    KC_TRNS,  KC_TRNS,
        // right hand
        KC_TRNS,  KC_6,      KC_7,     KC_8,      KC_9,      KC_0,     KC_MINS,
        KC_TRNS,  KC_J,      KC_U,     KC_R,      KC_L,      KC_SCLN,  KC_EQL,
                  KC_Y,      KC_N,     KC_I,      KC_O,      KC_H,     KC_QUOT,
        KC_TRNS,  KC_P,      KC_M,     KC_COMM,   KC_DOT,    KC_SLSH,  KC_TRNS,
                             KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,
        KC_TRNS,
        KC_TRNS,  KC_TRNS,   KC_TRNS
    ),
};

#define TAP_CONSUMER_HID_CODE(code) \
  host_consumer_send(code);         \
  host_consumer_send(0)

#define TAP_KEY(code)                           \
  register_code(code);                          \
  unregister_code(code)

#define TAP_KEY16(code)                         \
  register_code16(code);                        \
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
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
  [1] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
  [2] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_UNDS),
  [3] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_MINS),
  [4] = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, LSS(KC_RGHT)),
  [5] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, LSS(KC_LEFT)),
  [6] = ACTION_TAP_DANCE_TSKSWCH(),  // switch application / switch windows (gnome)
  [7] = ACTION_TAP_DANCE_MOD_TAP_LOCK(MOD_LGUI | MOD_LSFT, KC_LGUI),
  [8] = ACTION_TAP_DANCE_MOD_TAP_LOCK(MOD_LGUI | MOD_LCTL, KC_ESC),
  [9] = ACTION_TAP_DANCE_DOUBLE(F_TERM, F_LOCK),        // TAB / switch windows (gnome)
  [10] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [11] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_MINS),
};

#endif

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

#define IS_MOD_ACTIVE(kc) (get_mods() & MOD_BIT(kc) \
                           || ((get_oneshot_mods() & MOD_BIT(kc)) && !has_oneshot_mods_timed_out()))

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if (IS_LAYER_ON(1)) {
        ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_1_on();
    }

    if (IS_LAYER_ON(2)) {
        ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_2_on();
    }

    if (IS_LAYER_ON(3)) {
        ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_3_on();
    }

    if (IS_MOD_ACTIVE(KC_LCTL) || IS_MOD_ACTIVE(KC_RCTL)) {
        ergodox_right_led_1_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_1_on();
    }

    if (IS_MOD_ACTIVE(KC_LSFT) || IS_MOD_ACTIVE(KC_RSFT)) {
        ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_2_on();
    }

    if (IS_MOD_ACTIVE(KC_LALT) || IS_MOD_ACTIVE(KC_RALT)) {
        ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_3_on();
    }

};
