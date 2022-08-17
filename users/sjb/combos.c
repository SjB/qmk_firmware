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
    C_TG_RAISE,
    C_TG_NUMPAD,
    C_LSBR,
    C_RSBR,
    C_PLUS,
    C_EQUAL,
    C_LCTL,
    C_RCTL,
    C_LALT,
    C_RALT,
    C_LSFT,
    C_RSFT,
    COMBO_LENGTH,
};

const uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM lbootloader_combo[] = {KC_Q, KC_T, COMBO_END};
const uint16_t PROGMEM rbootloader_combo[] = {KC_P, KC_Y, COMBO_END};
const uint16_t PROGMEM caplock_combo[]     = {TAB_ALT, OSM_SFT, COMBO_END};
const uint16_t PROGMEM tg_raise_combo[]    = {BSPC_RS, SPC_RS, COMBO_END};
const uint16_t PROGMEM tg_numpad_combo[]   = {G_NUM, H_NUM, COMBO_END};

const uint16_t PROGMEM lsbr_combo[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM rsbr_combo[] = {KC_U, KC_I, COMBO_END};

const uint16_t PROGMEM plus_combo[]  = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM equal_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

const uint16_t PROGMEM lctl_combo[] = {F_CTL, D_SFT, COMBO_END};
const uint16_t PROGMEM rctl_combo[] = {J_CTL, K_SFT, COMBO_END};

const uint16_t PROGMEM lalt_combo[] = {D_SFT, S_ALT, COMBO_END};
const uint16_t PROGMEM ralt_combo[] = {K_SFT, L_ALT, COMBO_END};

const uint16_t PROGMEM lsft_combo[] = {F_CTL, G_NUM, COMBO_END};
const uint16_t PROGMEM rsft_combo[] = {H_NUM, J_CTL, COMBO_END};

combo_t key_combos[] = {
    [C_LBOOTLOADER] = COMBO(lbootloader_combo, QK_BOOTLOADER),
    [C_RBOOTLOADER] = COMBO(rbootloader_combo, QK_BOOTLOADER),
    [C_CAPS]        = COMBO(caplock_combo, KC_CAPS),
    [C_TG_RAISE]    = COMBO(tg_raise_combo, TO(_RAISE)),
    [C_TG_NUMPAD]   = COMBO(tg_numpad_combo, TO(_NUMPAD)),

    [C_LSBR]  = COMBO(lsbr_combo, S(KC_9)),
    [C_RSBR]  = COMBO(rsbr_combo, S(KC_0)),
    [C_PLUS]  = COMBO(plus_combo, KC_PLUS),
    [C_EQUAL] = COMBO(equal_combo, KC_EQL),
    [C_LCTL]  = COMBO(lctl_combo, OSM(MOD_LCTL)),
    [C_RCTL]  = COMBO(rctl_combo, OSM(MOD_RCTL)),
    [C_LALT]  = COMBO(lalt_combo, OSM(MOD_LALT)),
    [C_RALT]  = COMBO(ralt_combo, OSM(MOD_LALT)),
    [C_LSFT]  = COMBO(lsft_combo, OSM(MOD_LSFT)),
    [C_RSFT]  = COMBO(rsft_combo, OSM(MOD_RSFT)),
};
#endif
