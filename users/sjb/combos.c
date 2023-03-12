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

#include "action_code.h"
#include "quantum_keycodes.h"
#include "sjb.h"

#ifdef COMBO_ENABLE
#define COMBO_ONLY_FROM_LAYER _QWERTY

#define SJB_DEFINE_KEY(func, args...) const uint16_t PROGMEM combo_##func[] = {args, COMBO_END}
#define SJB_COMBO(func, action) COMBO(combo_##func, action)

#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

SJB_DEFINE_KEY(CK_LBOOT, KC_Q, KC_T);
SJB_DEFINE_KEY(CK_RBOOT, KC_P, KC_Y);
SJB_DEFINE_KEY(CK_CAPS, KC_Q, KC_W);

SJB_DEFINE_KEY(CK_LSFT, KC_A, KC_S);
SJB_DEFINE_KEY(CK_RSFT, KC_L, KC_SCLN);

SJB_DEFINE_KEY(CK_LAPP, BSPC_RS, KC_B);
SJB_DEFINE_KEY(CK_RAPP, SPC_RS, KC_N);
SJB_DEFINE_KEY(CK_NRAPP, KC_K, KC_L);
SJB_DEFINE_KEY(CK_NLAPP, KC_D, KC_S);

SJB_DEFINE_KEY(CK_TG_MOUSE, BSPC_RS, KC_F);
SJB_DEFINE_KEY(CK_TG_NUM, SPC_RS, KC_J);

SJB_DEFINE_KEY(CK_TG_NAV, KC_F, G_NUM);
SJB_DEFINE_KEY(CK_TG_RSE, KC_J, H_NUM);

SJB_DEFINE_KEY(CK_LALT, KC_F, KC_A);
SJB_DEFINE_KEY(CK_LGUI, KC_F, KC_S);
SJB_DEFINE_KEY(CK_LCTL, KC_F, KC_D);
SJB_DEFINE_KEY(CK_LCG , KC_F, KC_D, KC_S);
SJB_DEFINE_KEY(CK_LCGA , KC_F, KC_D, KC_S, KC_A);

SJB_DEFINE_KEY(CK_RALT, KC_J, KC_SCLN);
SJB_DEFINE_KEY(CK_RGUI, KC_J, KC_L);
SJB_DEFINE_KEY(CK_RCTL, KC_J, KC_K);
SJB_DEFINE_KEY(CK_RCG , KC_J, KC_K, KC_L);
SJB_DEFINE_KEY(CK_RCGA , KC_J, KC_K, KC_L, KC_SCLN);

combo_t key_combos[] = {
    SJB_COMBO(CK_LBOOT, QK_BOOT),
    SJB_COMBO(CK_RBOOT, QK_BOOT),
    SJB_COMBO(CK_CAPS, KC_CAPS),

    SJB_COMBO(CK_LALT, OSM(MOD_LALT)),
    SJB_COMBO(CK_LGUI, OSM(MOD_LGUI)),
    SJB_COMBO(CK_LCTL, OSM(MOD_LCTL)),
    SJB_COMBO(CK_LCG , OSM(MOD_LCTL | MOD_LGUI)),
    SJB_COMBO(CK_LCGA , OSM(MOD_LCTL | MOD_LGUI | MOD_LALT)),

    SJB_COMBO(CK_RALT, OSM(MOD_LALT)),
    SJB_COMBO(CK_RGUI, OSM(MOD_RGUI)),
    SJB_COMBO(CK_RCTL, OSM(MOD_RCTL)),
    SJB_COMBO(CK_RCG , OSM(MOD_RCTL | MOD_RGUI)),
    SJB_COMBO(CK_RCGA , OSM(MOD_RCTL | MOD_RGUI | MOD_LALT)),

    SJB_COMBO(CK_LSFT, OSM_SFT),
    SJB_COMBO(CK_RSFT, OSM_SFT),

    SJB_COMBO(CK_LAPP, KC_APP),
    SJB_COMBO(CK_RAPP, KC_APP),
    SJB_COMBO(CK_NLAPP, KC_APP),
    SJB_COMBO(CK_NRAPP, KC_APP),

    SJB_COMBO(CK_TG_RSE, TG(_RAISE)),
    SJB_COMBO(CK_TG_NAV, TG(_NAV)),

    SJB_COMBO(CK_TG_NUM, TG(_NUMPAD)),
    SJB_COMBO(CK_TG_MOUSE, TG(_MOUSE)),
};

const uint16_t COMBO_LEN = ARRAYSIZE(key_combos);

#endif
