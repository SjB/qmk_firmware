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

#include "quantum.h"
#include "sjb.h"
#include "layer_lock.h"


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

bool process_special_keys(uint16_t keycode, keyrecord_t* record) {

    if (record->event.pressed){
        switch (keycode) {
        case SJB_TCM:
            SEND_STRING(SS_LCTL("a") SS_TAP(X_LBRC));
            return false;
        case SJB_RSTL:
            layer_clear();
            return false;
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, SJB_LLOCK)) { return false; }
  if (!process_special_keys(keycode, record)) { return false; }

  return process_record_sjb(keycode, record);
}
