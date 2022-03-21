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

const uint16_t PROGMEM combo_seq1[] = {KC_ENT, LT_LW(KC_SPC), COMBO_END};
const uint16_t PROGMEM combo_seq2[] = {KC_ESC, LT_LW(KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo_seq3[] = {LT_LW(KC_BSPC), LT_LW(KC_SPC), COMBO_END};
const uint16_t PROGMEM combo_seq4[] = {LT_RS(KC_G), LT_RS(KC_H), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_seq1, KC_CAPS),
    COMBO(combo_seq2, TG(_NUMPAD)),
    COMBO(combo_seq3, TG(_LOWER)),
    COMBO(combo_seq4, TG(_RAISE))
};

#endif
