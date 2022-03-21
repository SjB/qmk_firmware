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

__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_keymap(state);

    if (IS_LAYER_ON_STATE(state, _NUMPAD)
        && IS_LAYER_OFF_STATE(state, _LOWER)
        && IS_LAYER_OFF_STATE(state, _RAISE)) {
        return state;
    }

    return update_tri_layer_state(state, _LOWER,  _RAISE, _NUMPAD);
}
