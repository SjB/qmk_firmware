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

#include "action.h"
#include "action_tapping.h"

#include "sjb.h"

#ifdef ACHORDION_ENABLE
#include "achordion.h"
#endif

#ifdef LAYER_LOCK_ENABLE
#include "layer_lock.h"
#endif

#ifdef CALLUM_ONESHOT_ENABLE
#include "oneshot.h"
#endif


__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, _NUMPAD)
        && IS_LAYER_OFF_STATE(state, _RAISE)
        && IS_LAYER_OFF_STATE(state, _NAV)) {
        return layer_state_set_keymap(state);
    }

    state = update_tri_layer_state(state, _RAISE, _NAV, _NUMPAD);
    return layer_state_set_keymap(state);
}

static uint8_t mod_state;
#ifdef SB_SHIFTED_BACKSPACE
bool process_shifted_backspace(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    if (keycode == SB_BSPC) {
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
    }
    return true;
};
#endif

#ifdef SB_THUMB_TAB
bool process_thumb_tab(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SB_TAB) {
        mod_state = get_mods();
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
    return true;
}
#endif

#ifdef SB_THUMB_SUPER
bool process_thumb_super(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SB_GUI) {
        mod_state = get_mods();
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
    return true;
}
#endif

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

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case HR_H:
    // Repeating is useful for Vim navigation keys.
    case HR_J:
    case HR_K:
    case HR_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
  case SB_NAV:
  case SB_RSE:
  case SB_SFT:
  case SB_CTL:
      return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 800;  // Use a timeout of 800 ms.
}

uint16_t achordion_streak_timeout(uint16_t tap_hold_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 0;  // Disable for Shift mod-tap keys.
  } else {
    return 100;
  }
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

#ifdef FLOW_ENABLE
    flow_matrix_scan();
#endif

    matrix_scan_sjb();
}

__attribute__  ((weak))
bool process_record_sjb(uint16_t keycode, keyrecord_t* record) {
    return true;
}

#ifdef SB_SPECIAL_KEY
bool process_special_keys(uint16_t keycode, keyrecord_t* record) {
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

#ifdef CALLUM_ONESHOT_ENABLE
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case SB_ESC:
    case SB_RSTL:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case SB_RSE:
    case SB_NAV:
    case KC_LSFT:
    case OS_CTL:
    case OS_ALT:
    case OS_GUI:
    case OS_RALT:
    case OS_MEH:
        return true;
    default:
        return false;
    }
}

oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_ralt_state = os_up_unqueued;
oneshot_state os_meh_state = os_up_unqueued;

bool process_callum_oneshot(uint16_t keycode, keyrecord_t* record) {
    update_oneshot(
        &os_ralt_state, KC_RALT, OS_RALT,
        keycode, record
    );
    update_oneshot(
        &os_meh_state, KC_MEH, OS_MEH,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, OS_GUI,
        keycode, record
    );
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

#ifdef CALLUM_ONESHOT_ENABLE
    if (!process_callum_oneshot(keycode, record)) { return false; }
#endif

#ifdef SB_SPECIAL_KEY
    if (!process_special_keys(keycode, record)) { return false; }
#endif

#ifdef SB_THUMB_SUPER
    if (!process_thumb_super(keycode, record)) { return false; }
#endif

#ifdef SB_THUMB_TAB
    if (!process_thumb_tab(keycode, record)) { return false; }
#endif

#ifdef SB_SHIFTED_BACKSPACE
    if (!process_shifted_backspace(keycode, record)) { return false; }
#endif

    if (!process_record_sjb(keycode, record)) { return false; }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SB_RSE:
    case SB_NAV:
#ifdef SB_HRL
    case SB_LHRL:
    case SB_RHRL:
#endif
        return true;
    }
    return false;
}
