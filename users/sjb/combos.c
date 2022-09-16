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
    C_TO_MOUSE,
    C_TO_NAV,
    C_LSBR,
    C_RSBR,
    C_LBRC,
    C_RBRC,
    C_LSBRC,
    C_RSBRC,
    C_MINS,
    C_EQUAL,
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
const uint16_t PROGMEM caplock_combo[]     = {TAB_ALT, OSM_SFT, COMBO_END};

const uint16_t PROGMEM tg_raise_combo[]    = {BSPC_RS, SPC_RS, COMBO_END};
const uint16_t PROGMEM tg_numpad_combo[]   = {G_NUM, H_NUM, COMBO_END};

const uint16_t PROGMEM to_mouse_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM to_nav_combo[] = {KC_N, KC_M, COMBO_END};

const uint16_t PROGMEM lbrc_combo[] = {KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM lsbr_combo[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM lsbrc_combo[] = {KC_E, KC_W, COMBO_END};

const uint16_t PROGMEM rbrc_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM rsbr_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM rsbrc_combo[] = {KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM mins_combo[]  = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM equal_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

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
    [C_TG_RAISE]    = COMBO(tg_raise_combo, TO(_RAISE)),
    [C_TG_NUMPAD]   = COMBO(tg_numpad_combo, TO(_NUMPAD)),
    [C_TO_MOUSE]    = COMBO(to_mouse_combo, TO(_MOUSE)),
    [C_TO_NAV]      = COMBO(to_nav_combo, TO(_NAV)),

    [C_LSBR]  = COMBO(lsbr_combo, S(KC_9)),
    [C_RSBR]  = COMBO(rsbr_combo, S(KC_0)),

    [C_LBRC]  = COMBO(lbrc_combo, KC_LBRC),
    [C_RBRC]  = COMBO(rbrc_combo, KC_RBRC),

    [C_LSBRC] = COMBO(lsbrc_combo, S(KC_LBRC)),
    [C_RSBRC] = COMBO(rsbrc_combo, S(KC_RBRC)),

    [C_MINS]  = COMBO(mins_combo, KC_MINS),
    [C_EQUAL] = COMBO(equal_combo, KC_EQL),

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
