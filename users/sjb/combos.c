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

#include "sjb.h"

#ifdef COMBO_ENABLE
#define COMBO_ONLY_FROM_LAYER _QWERTY

enum combo_events {
    C_CAPS,
    C_LAYER_NUMPAD,
    C_LAYER_LOWER,
    C_LAYER_RAISE,
    COMBO_LENGTH,
};

const uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caplock_combo[]   = { KC_ENT, LT_LW(KC_SPC), COMBO_END };
const uint16_t PROGMEM tg_numpad_combo[] = { KC_ESC, LT_LW(KC_BSPC), COMBO_END };
const uint16_t PROGMEM tg_lower_combo[]  = { LT_LW(KC_BSPC), LT_LW(KC_SPC), COMBO_END };
const uint16_t PROGMEM tg_raise_combo[]  = { LT_RS(KC_G), LT_RS(KC_H), COMBO_END };

combo_t key_combos[] = {
    [C_CAPS]         = COMBO(caplock_combo, KC_CAPS),
    [C_LAYER_NUMPAD] = COMBO(tg_numpad_combo, TG(_NUMPAD)),
    [C_LAYER_LOWER]  = COMBO(tg_lower_combo, TG(_LOWER)),
    [C_LAYER_RAISE]  = COMBO(tg_raise_combo, TG(_RAISE)),
};
#endif
