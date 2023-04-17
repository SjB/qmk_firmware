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

#include "action_util.h"
#include "quantum.h"
#include "sjb.h"
#include "layer_lock.h"
#include "oneshot.h"


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

__attribute__ ((weak))
void matrix_scan_sjb(void) {
    return;
}

void matrix_scan_user(void) {
    layer_lock_task();
    matrix_scan_sjb();
}

__attribute__  ((weak))
bool process_record_sjb(uint16_t keycode, keyrecord_t* record) {
    return true;
}

#ifdef SB_SPECIAL_KEY
bool process_special_keys(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed){
        switch (keycode) {
        case SB_TCM:
            SEND_STRING(SS_LCTL("b") SS_TAP(X_LBRC));
            return false;
        case SB_RSTL:
            layer_clear();
            clear_oneshot_locked_mods();
            clear_oneshot_mods();
            return false;
        }
    }
    return true;
}
#endif

#ifdef CALLUM_ONESHOT
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
    if (!(
          process_layer_lock(keycode, record, SB_LLOCK) &&

#ifdef CALLUM_ONESHOT
          process_callum_oneshot(keycode, record) &&
#endif

#ifdef SB_SPECIAL_KEY
          process_special_keys(keycode, record) &&
#endif

#ifdef SB_THUMB_SUPER
          process_thumb_super(keycode, record) &&
#endif

#ifdef SB_THUMB_TAB
          process_thumb_tab(keycode, record) &&
#endif

#ifdef SB_SHIFTED_BACKSPACE
          process_shifted_backspace(keycode, record) &&
#endif
          process_record_sjb(keycode, record) &&
          true)) {
        return false;
    }
    return true;
}
