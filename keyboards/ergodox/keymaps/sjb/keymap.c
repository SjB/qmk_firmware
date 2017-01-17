#include "ergodox.h"
#include "debug.h"
#include "led.h"
#include "action_layer.h"
#include "action_util.h"
#include "eeconfig.h"
#include "version.h"

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
#define F_MAX  LALT(KC_F10)  // Toggle maximazation state

#ifdef TAP_DANCE_ENABLE

#define TD_TERM F_TERM
#define TD_MYCM KC_MYCM
#define TD_LBRC TD(2)
#define TD_RBRC TD(3)
#define TD_BSLS TD(4)
#define TD_GRV  TD(5)
#define TD_RGHT TD(6)
#define TD_LEFT TD(7)
#define TD_TGAPP TD(8)
#define TD_SCLN TD(9)

#else

#define TD_TERM F_TERM
#define TD_MYCM KC_MYCM
#define TD_LBRC KC_LBRC
#define TD_RBRC KC_RBRC
#define TD_BSLS KC_BSLS
#define TD_GRV  KC_GRV
#define TD_RGHT KC_RGHT
#define TD_LEFT KC_LEFT
#define TD_TGAPP LALT(KC_F6)
#define TD_SCLN KC_SCLN

#endif


#ifdef QMK_MOD_SHORTCUT_ENABLED

#define LCA_T(kc) MT((MOD_LCTL | MOD_LALT), kc)
#define LSS_T(kc) MT((MOD_LSFT | MOD_LGUI), kc)  // Shift-Super
#define LCS_T(kc) MT((MOD_LCTL | MOD_LGUI), kc)  // Ctrl-Super

#define F_MOTION OSL(MOTION)
#define F_NUMPAD OSL(NUMPAD)
#define F_FNx OSL(FNx)
#define F_LSFT OSM(MOD_LSFT)
#define F_RSFT OSM(MOD_RSFT)
#define F_LCTL OSM(MOD_LCTL)
#define F_LALT OSM(MOD_LALT)
#define F_ENT LCS_T(KC_ENT)
#define F_SPC LALT_T(KC_SPC)
#define F_BSPC LSS_T(KC_BSPC)
#define F_DELT LSS_T(KC_DELT)
#define LT_UP  LT(DBG, KC_UP)
#define LT_DOWN  LT(DBG, KC_DOWN)
#define F_HYPR OSM(MOD_HYPR)
#define F_MEH  OSM(MOD_MEH)

#else

#define F_MOTION KC_FN0
#define F_NUMPAD KC_FN1
#define F_FNx KC_FN2
#define F_LSFT KC_FN3
#define F_RSFT KC_FN4
#define F_LCTL KC_FN5
#define F_LALT KC_FN6
#define F_ENT KC_FN7
#define F_SPC KC_FN8
#define F_BSPC KC_FN9
#define F_DELT KC_FN10
#define LT_UP  KC_FN11
#define LT_DOWN KC_FN12
#define F_MEH KC_FN13
#define F_HYPR KC_FN14

#endif

#define F_BROWSER M(BROWSER)

#define TAP_ONCE_CONSUMER_HID_CODE(code) \
  host_consumer_send(code); \
  host_consumer_send(0)

#define TAP_ONCE(code) \
  register_code(code); \
  unregister_code(code)

enum keymaps_layers {
  BASE = 0, // default layer
  MOTION,   // Mouse and keyboard motion keys
  NUMPAD,   // numpad 
  FNx,
};

enum custom_keycodes {
  PLACE_HOLDER = 0, // can always be here
  FLSH,
  VRSN,
  KDBG,
  BROWSER,
  TSKSWCH,
  EDITOR,
};

#if KEYLOGGER_ENABLE
# ifdef AUTOLOG_ENABLE
bool log_enable = true;
# else
bool log_enable = false;
# endif
#endif

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
 *   | MAX  | LALT | LEFT |  UP  |  ~L1 |                                       | ~L2  | DOWN | RGHT | RALT | SWCH |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME | END  |       | PGUP | PGDN |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | HYPR |       | MEH  |        |      |
 *                                 | LCTRL| BKSP |------|       |------|  ENTER | [ ]  |
 *                                 |      |      | LGUI |       | FNx  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,    KC_2,    KC_3,  KC_4,       KC_5,     F_TERM,
        KC_TAB,   KC_Q,    KC_W,    KC_E,  KC_R,       KC_T,     TD_BSLS,
        F_LCTL,   KC_A,    KC_S,    KC_D,  KC_F,       KC_G,
        F_LSFT,   KC_Z,    KC_X,    KC_C,  KC_V,       KC_B,     TD_LBRC,
        TD_TGAPP, F_LALT,  TD_LEFT, LT_UP, F_MOTION,
                                                       KC_HOME,  KC_END,
                                                                 F_HYPR,
                                           F_LCTL,     F_BSPC,   KC_LGUI,
        // right hand
        KC_MYCM,  KC_6,    KC_7,     KC_8,      KC_9,      KC_0,     KC_MINS,
        TD_GRV,   KC_Y,    KC_U,     KC_I,      KC_O,      KC_P,     KC_EQL,
                  KC_H,    KC_J,     KC_K,      KC_L,      TD_SCLN,  KC_QUOT,
        TD_RBRC,  KC_N,    KC_M,     KC_COMM,   KC_DOT,    KC_SLSH,  F_RSFT,
                           F_NUMPAD, LT_DOWN,   TD_RGHT,   F_RALT,   M(TSKSWCH),
        KC_PGUP,  KC_PGDN,
        F_MEH,
        F_FNx,   F_ENT, F_SPC
    ),
/* Keymap 1: Motion Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | Mute |           | App  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         | Lclk | MsUp | Rclk |      |      | Vol+ |           |      |      |      | INS  |      | PRSC |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPSLCK |MsLeft|MsDown|MsRght|      |      |------|           |------| Left |  Up  | Down | Rght |      |        |
 * |---------+------+------+------+------+------| Vol- |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Calc | SRCH | Mail | WWW  | Edit |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MPLY | MNXT |       | Pwr  | Slp  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | Del  |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Motion
[MOTION] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,    KC_F2,       KC_F3,     KC_F4,      KC_F5,          KC_MUTE,
       KC_TRNS,   KC_BTN1,  KC_MS_U,     KC_BTN2,   KC_TRNS,    KC_TRNS,        KC_VOLU,
       KC_CAPS,   KC_MS_L,  KC_MS_D,     KC_MS_R,   KC_TRNS,    KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,        KC_VOLD,
       KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS,
                                                                KC_MPLY,        KC_MNXT,
                                                                                KC_TRNS,
                                                    KC_TRNS,    F_DELT,         KC_TRNS,
       // right hand
       KC_APP,    KC_F6,     KC_F7,      KC_F8,     KC_F9,      KC_F10,     KC_F11,
       KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_INS,    KC_TRNS,    KC_PSCR,    KC_F12,
                  KC_LEFT,   KC_UP,      KC_DOWN,   KC_RGHT,    KC_TRNS,    KC_TRNS,
       KC_TRNS,   KC_CALC,   KC_WSCH,    KC_MAIL,   F_BROWSER,  M(EDITOR),  KC_TRNS,
                             KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_PWR,    KC_SLEP,
       KC_TRNS,
       KC_TRNS,   KC_TRNS,   KC_TRNS
       ),
/* Keymap 2: Symbol and Numpad
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      | NMLK |  P/  |  P*  |  P-  |        |
 * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |  \   |  P7  |  P8  |  P9  |  P+  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPSLCK |   #  |   $  |   (  |   )  |   `  |------|           |------|  *   |  P4  |  P5  |  P6  |  P+  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [   |  ]  |   ~  |      |           |      |  &   |  P1  |  P2  |  P3  | PEnt |        |
 * `---------+------+------+------+------+------+------'           `------+------+------+------+------+------+--------'
 *    |      |      |      |      |      |                                       |      |  P0  |  P.  |      |      |
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
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
       KC_CAPS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_TRNS,
                KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
                         KC_TRNS, KC_P0,   KC_PDOT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |      |      |      |      |      | FLSH |           | FLSH |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | KDBG    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FNx] = KEYMAP(
       // left hand
       M(VRSN),   KC_NO,    KC_NO,       KC_NO,     KC_NO,      KC_NO,   M(FLSH),
       M(KDBG),   KC_F1,    KC_F2,       KC_F3,     KC_F4,      KC_F5,   KC_NO,
       KC_TRNS,   KC_1,     KC_2,        KC_3,      KC_4,       KC_5,
       KC_TRNS,   KC_NO,    KC_NO,       KC_NO,     KC_NO,      KC_NO,   KC_NO,
       F_MAX,     KC_TRNS,  KC_NO,       KC_TRNS,   KC_NO,
                                                                KC_TRNS, KC_TRNS,
                                                                         KC_TRNS,
                                                    KC_TRNS,    KC_TRNS, KC_TRNS,
       // right hand
       M(FLSH),   KC_NO,    KC_NO,       KC_NO,     KC_NO,      KC_NO,   KC_F12,
       KC_NO,     KC_F6,    KC_F7,       KC_F8,     KC_F9,      KC_F10,  KC_F11,
                  KC_6,     KC_7,        KC_8,      KC_9,       KC_0,    KC_NO,
       KC_NO,     KC_NO,    KC_NO,       KC_NO,     KC_NO,      KC_NO,   KC_TRNS,
                            KC_NO,       KC_TRNS,   KC_NO,      KC_TRNS, KC_NO,
       KC_TRNS,   KC_TRNS,
       KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS
       ),
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_ONESHOT(MOTION),
  [1] = ACTION_LAYER_ONESHOT(NUMPAD),
  [2] = ACTION_LAYER_ONESHOT(FNx),
  [3] = ACTION_MODS_ONESHOT(MOD_LSFT),
  [4] = ACTION_MODS_ONESHOT(MOD_RSFT),
  [5] = ACTION_MODS_ONESHOT(MOD_LCTL),
  [6] = ACTION_MODS_ONESHOT(MOD_LALT),
  [7] = ACTION_MODS_TAP_KEY(MOD_LGUI | MOD_LCTL, KC_ENT),
  [8] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_SPC),
  [9] = ACTION_MODS_TAP_KEY(MOD_LGUI | MOD_LSFT, KC_BSPC),
  [10] = ACTION_MODS_TAP_KEY(MOD_LGUI | MOD_LSFT, KC_DELT),
  [11] = ACTION_LAYER_TAP_KEY(FNx, KC_UP),    // used for flashing
  [12] = ACTION_LAYER_TAP_KEY(FNx, KC_DOWN),  // used for flashing
  [13] = ACTION_MODS_ONESHOT(MOD_MEH),
  [14] = ACTION_MODS_ONESHOT(MOD_HYPR)
};

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
        TAP_ONCE_CONSUMER_HID_CODE(AL_INTERNET_BROWSER);
      }
      break;
    case TSKSWCH: 
      if (record->event.pressed) { 
        TAP_ONCE(KC_LGUI);
        wait_ms(250); 
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      break;
    case EDITOR:
      if (record->event.pressed) {
        TAP_ONCE(KC_LGUI);
        wait_ms(250);
        SEND_STRING(DEFAULT_EDITOR "\n");
      }
      break;
  }
  return MACRO_NONE;
};

#ifdef TAP_DANCE_ENABLE

#define ACTION_TAP_DANCE_SHIFT_WITH_DOUBLE(kc) ACTION_TAP_DANCE_DOUBLE(kc, LSFT(kc))

qk_tap_dance_action_t tap_dance_actions[] = {
  [0] = ACTION_TAP_DANCE_DOUBLE(F_TERM, KC_NO),      // start term
  [1] = ACTION_TAP_DANCE_DOUBLE(KC_MYCM, KC_NO),     // my files
  [2] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
  [3] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
  [4] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_UNDS),
  [5] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_MINS),
  [6] = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, LSS(KC_RGHT)),
  [7] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, LSS(KC_LEFT)),
  [8] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_TAB), LALT(KC_F6)), // switch application / switch windows (gnome)
  [9] = ACTION_TAP_DANCE_SHIFT_WITH_DOUBLE(KC_SCLN)
};
#endif

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            break;
    }
};
