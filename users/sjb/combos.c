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

#include "quantum_keycodes.h"
#include "sjb.h"

#ifdef COMBO_ENABLE
#define COMBO_ONLY_FROM_LAYER _QWERTY

#define DEFINE_TWO_KEY(a, b) const uint16_t PROGMEM combo_##a ##b[] = {a, b, COMBO_END}
#define TWO_KEY_COMBO(a, b, action) COMBO(combo_##a ##b, action)
#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

DEFINE_TWO_KEY(KC_Q, KC_T);
DEFINE_TWO_KEY(KC_P, KC_Y);
DEFINE_TWO_KEY(KC_Z, KC_X);

DEFINE_TWO_KEY(BSPC_RS, KC_B);
DEFINE_TWO_KEY(SPC_RS, KC_N);

DEFINE_TWO_KEY(BSPC_RS, KC_V);
DEFINE_TWO_KEY(SPC_RS, KC_M);

DEFINE_TWO_KEY(KC_A, KC_S);
DEFINE_TWO_KEY(KC_S, KC_D);
DEFINE_TWO_KEY(KC_D, KC_F);

DEFINE_TWO_KEY(KC_SCLN, KC_L);
DEFINE_TWO_KEY(KC_L, KC_K);
DEFINE_TWO_KEY(KC_K, KC_J);

combo_t key_combos[] = {
    TWO_KEY_COMBO(KC_Q, KC_T, QK_BOOT),
    TWO_KEY_COMBO(KC_P, KC_Y, QK_BOOT),

    TWO_KEY_COMBO(KC_Z, KC_X, KC_CAPS),

    TWO_KEY_COMBO(KC_A, KC_S, OSM(MOD_LGUI)),
    TWO_KEY_COMBO(KC_S, KC_D, OSM(MOD_LALT)),
    TWO_KEY_COMBO(KC_D, KC_F, OSM(MOD_LCTL)),

    TWO_KEY_COMBO(KC_SCLN, KC_L, OSM(MOD_RGUI)),
    TWO_KEY_COMBO(KC_L, KC_K, OSM(MOD_LALT)),
    TWO_KEY_COMBO(KC_K, KC_J, OSM(MOD_RCTL)),

    TWO_KEY_COMBO(BSPC_RS, KC_B, OSL_RSE),
    TWO_KEY_COMBO(SPC_RS, KC_N, OSL_NAV),

    TWO_KEY_COMBO(BSPC_RS, KC_V, OSL_NUM),
    TWO_KEY_COMBO(SPC_RS, KC_M, TG(_MOUSE)),
};

const uint16_t COMBO_LEN = ARRAYSIZE(key_combos);

#endif
