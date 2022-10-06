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
#    define COMBO_ONLY_FROM_LAYER _QWERTY

enum combo_events {
    C_LBOOTLOADER,
    C_RBOOTLOADER,
    C_CAPS,
    C_LEFT_RAISE,
    C_RIGHT_RAISE,
    C_LEFT_NUMPAD,
    C_RIGHT_NUMPAD,
    C_MOUSE,
    C_NAV,
    C_LCTL,
    C_RCTL,
    C_LALT,
    C_RALT,
    C_LSFT,
    C_RSFT,
    C_LGUI,
    C_RGUI,
    COMBO_LENGTH,
};


const uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM lbootloader_combo[] = {KC_Q, KC_T, COMBO_END};
const uint16_t PROGMEM rbootloader_combo[] = {KC_P, KC_Y, COMBO_END};

const uint16_t PROGMEM caplock_combo[]     = {KC_Z, KC_X, COMBO_END};

const uint16_t PROGMEM left_raise_combo[]  = {BSPC_RS, KC_B, COMBO_END};
const uint16_t PROGMEM right_raise_combo[] = {SPC_RS, KC_N, COMBO_END};

const uint16_t PROGMEM left_numpad_combo[]  = {BSPC_RS, KC_V, COMBO_END};
const uint16_t PROGMEM right_numpad_combo[] = {SPC_RS, KC_M, COMBO_END};

const uint16_t PROGMEM mouse_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM nav_combo[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM lctl_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM rctl_combo[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM lalt_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM ralt_combo[] = {KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM lsft_combo[] = {KC_F, G_NUM, COMBO_END};
const uint16_t PROGMEM rsft_combo[] = {H_NUM, KC_J, COMBO_END};

const uint16_t PROGMEM lgui_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_S, KC_A, COMBO_END};

combo_t key_combos[] = {
    [C_LBOOTLOADER] = COMBO(lbootloader_combo, RESET),
    [C_RBOOTLOADER] = COMBO(rbootloader_combo, RESET),
    [C_CAPS]        = COMBO(caplock_combo, KC_CAPS),

    [C_LEFT_RAISE]    = COMBO(left_raise_combo, OSL_RSE),
    [C_RIGHT_RAISE]   = COMBO(right_raise_combo, OSL_RSE),
    [C_LEFT_NUMPAD]   = COMBO(left_numpad_combo, OSL_NUM),
    [C_RIGHT_NUMPAD]  = COMBO(right_numpad_combo, OSL_NUM),

    [C_MOUSE]    = COMBO(mouse_combo, TG(_MOUSE)),
    [C_NAV]      = COMBO(nav_combo, OSL(_NAV)),

    [C_LCTL]  = COMBO(lctl_combo, OSM(MOD_LCTL)),
    [C_RCTL]  = COMBO(rctl_combo, OSM(MOD_RCTL)),
    [C_LALT]  = COMBO(lalt_combo, OSM(MOD_LALT)),
    [C_RALT]  = COMBO(ralt_combo, OSM(MOD_LALT)),
    [C_LSFT]  = COMBO(lsft_combo, OSM(MOD_LSFT)),
    [C_RSFT]  = COMBO(rsft_combo, OSM(MOD_RSFT)),
    [C_LGUI]  = COMBO(lgui_combo, OSM(MOD_LGUI)),
    [C_RGUI]  = COMBO(rgui_combo, OSM(MOD_RGUI)),
};
#endif
