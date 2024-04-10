/* Copyright 2022 Sagacity Solutions Inc. All right reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "sjb.h"

#ifdef ACHORDION_ENABLE
#include "achordion.h"
#endif

#ifdef LAYER_LOCK_ENABLE
#include "layer_lock.h"
#endif

__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _NAV, _NUMPAD);
    return layer_state_set_keymap(state);
}

static uint8_t mod_state;
bool process_special_keys(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

#ifdef SB_THUMB_TAB
    if (keycode == SB_THUMB_TAB) {
        static bool thumb_tab_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_TAB);
                thumb_tab_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (thumb_tab_registered) {
                unregister_code(KC_TAB);
                thumb_tab_registered = false;
                return false;
            }
        }
    }
#endif

#ifdef SB_THUMB_SUPER
    if (keycode == SB_THUMB_SUPER) {
        static bool thumb_super_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_CTRL) {
                del_mods(MOD_MASK_CTRL);
                add_mods(MOD_MASK_GUI);
                send_keyboard_report();
                thumb_super_registered = true;
                return false;
            }
        } else {
            if (thumb_super_registered) {
                del_mods(MOD_MASK_GUI);
                send_keyboard_report();
                thumb_super_registered = false;
                return false;
            }
        }
    }
#endif
    return true;
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    // If you quickly hold a tap-hold key after tapping it, the tap action is
    // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
    // lead to missed triggers in fast typing. Here, returning 0 means we
    // instead want to "force hold" and disable key repeating.
    if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
        switch (keycode & 0xff) {  // strip mod tap
        case KC_H:
        case KC_J:
        case KC_K:
        case KC_L:
        case KC_BSPC:
        case KC_SPC:
            return QUICK_TAP_TERM;
        }
    }
    return 0;  // Otherwise, force hold and disable key repeating.
}

#ifdef ACHORDION_ENABLE

/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // Increase the tapping term a little for slower ring and pinky fingers.
    case HR_A:
    case HR_S:
    case HR_D:
    case HR_F:
    case HR_G:
    case HR_H:
    case HR_J:
    case HR_K:
    case HR_L:
    case HR_SCLN:
      return TAPPING_TERM + 15;
    default:
      return TAPPING_TERM;
  }
}
*/

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
  case SB_NAV:
  case SB_RSE:
  case SB_MOUSE:
  case SB_BHRL:
      return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 800;  // Use a timeout of 800 ms.
}

uint16_t achordion_streak_timeout(uint16_t tap_hold_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode) || IS_QK_MOD_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  /*
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 50;  // Disable is 0 for Shift mod-tap keys.
  }
  */
  return 100;
}
#endif

__attribute__ ((weak))
void matrix_scan_sjb(void) {
    return;
}

void matrix_scan_user(void) {
#ifdef ACHORDION_ENABLE
    achordion_task();
#endif

#ifdef LAYER_LOCK_ENABLE
    layer_lock_task();
#endif

    matrix_scan_sjb();
}

__attribute__  ((weak))
bool process_record_sjb(uint16_t keycode, keyrecord_t* record) {
    return true;
}

#ifdef SB_RSTL_ENABLE
bool process_reset_layer(uint16_t keycode, keyrecord_t* record) {
    if (keycode == SB_RSTL) {
        if (record->event.pressed) {
            layer_clear();
            clear_oneshot_locked_mods();
            clear_oneshot_mods();
            clear_mods();
            clear_weak_mods();
            return false;
        }
    }
    return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

#ifdef ACHORDION_ENABLE
    if (!process_achordion(keycode, record)) { return false; }
#endif

#ifdef LAYER_LOCK_ENABLE
    if (!process_layer_lock(keycode, record, SB_LLOCK)) { return false; }
#endif

#ifdef SB_RSTL_ENABLE
    if (!process_reset_layer(keycode, record)) { return false; }
#endif

    if (!process_special_keys(keycode, record)) { return false; }

    if (!process_record_sjb(keycode, record)) { return false; }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_LAYER_TAP(keycode)) {
        return true;
    }

    return false;
}
