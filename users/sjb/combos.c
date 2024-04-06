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

#ifdef COMBO_ENABLE

#include QMK_KEYBOARD_H

#include "sjb.h"

#define SJB_DEFINE_KEY(name, args...) const uint16_t PROGMEM combo_##name[] = {args, COMBO_END}
#define SJB_COMBO(name, action) COMBO(combo_##name, action)
#define CB_LLEADER SB_NAV
#define CB_RLEADER SB_RSE

SJB_DEFINE_KEY(CK_LBOOT,  KC_Q, KC_T);
SJB_DEFINE_KEY(CK_RBOOT,  KC_P, KC_Y);
SJB_DEFINE_KEY(CK_POWER,  KC_Q, KC_Z);

#ifdef LAYER_LOCK_ENABLE
SJB_DEFINE_KEY(CK_LAYER_LOCK,    KC_M, KC_COMM);
#endif

#ifdef CAPS_WORD_ENABLE
SJB_DEFINE_KEY(CK_CWTOGG,  HR_D, HR_S);
#endif

#ifdef REPEAT_KEY_ENABLE
SJB_DEFINE_KEY(CK_KEY_RREP,   HR_J, HR_K);
SJB_DEFINE_KEY(CK_KEY_LREP,   HR_F, HR_D);
#endif

#ifdef KEY_LOCK_ENABLE
SJB_DEFINE_KEY(CK_KEY_LOCK,   KC_V, KC_C);
#endif

#ifdef SB_HR_COMBO_KEY
//SJB_DEFINE_KEY(CK_LSFT,  KC_C, KC_X);
//SJB_DEFINE_KEY(CK_RSFT,  KC_COMM, KC_DOT);
SJB_DEFINE_KEY(CK_LSFT, CB_LLEADER, HR_F);
SJB_DEFINE_KEY(CK_RSFT, CB_RLEADER, HR_J);

SJB_DEFINE_KEY(CK_LALT, CB_LLEADER, HR_A);
SJB_DEFINE_KEY(CK_LGUI, CB_LLEADER, HR_S);
SJB_DEFINE_KEY(CK_LCTL, CB_LLEADER, HR_D);
SJB_DEFINE_KEY(CK_LCG , CB_LLEADER, HR_D, HR_S);
SJB_DEFINE_KEY(CK_LCA , CB_LLEADER, HR_D, HR_A);
SJB_DEFINE_KEY(CK_LGA , CB_LLEADER, HR_S, HR_A);
SJB_DEFINE_KEY(CK_LCGA, CB_LLEADER, HR_D, HR_S, HR_A);

SJB_DEFINE_KEY(CK_RALT, CB_RLEADER, HR_SCLN);
SJB_DEFINE_KEY(CK_RGUI, CB_RLEADER, HR_L);
SJB_DEFINE_KEY(CK_RCTL, CB_RLEADER, HR_K);
SJB_DEFINE_KEY(CK_RCG , CB_RLEADER, HR_K, HR_L);
SJB_DEFINE_KEY(CK_RCA , CB_RLEADER, HR_K, HR_SCLN);
SJB_DEFINE_KEY(CK_RGA , CB_RLEADER, HR_L, HR_SCLN);
SJB_DEFINE_KEY(CK_RCGA, CB_RLEADER, HR_K, HR_L, HR_SCLN);
#endif

#ifdef SB_LAYER_SWITCH_COMBO_KEY
SJB_DEFINE_KEY(CK_TG_NUM,   CB_LLEADER, HR_G);
SJB_DEFINE_KEY(CK_TG_MOUSE, CB_RLEADER, HR_H);
#endif

combo_t key_combos[] = {

    SJB_COMBO(CK_LBOOT, QK_BOOT),
    SJB_COMBO(CK_RBOOT, QK_BOOT),
    SJB_COMBO(CK_POWER, KC_PWR),

#ifdef LAYER_LOCK_ENABLE
    SJB_COMBO(CK_LAYER_LOCK, SB_LLOCK),
#endif

#ifdef REPEAT_KEY_ENABLE
    SJB_COMBO(CK_KEY_RREP,   QK_REP),
    SJB_COMBO(CK_KEY_LREP,   QK_AREP),
#endif

#ifdef KEY_LOCK_ENABLE
    SJB_COMBO(CK_KEY_LOCK,   QK_LOCK),
#endif

#ifdef CAPS_WORD_ENABLE
    SJB_COMBO(CK_CWTOGG, CW_TOGG),
#endif

#ifdef SB_HR_COMBO_KEY
    SJB_COMBO(CK_LALT, OSM(MOD_LALT)),
    SJB_COMBO(CK_LGUI, OSM(MOD_LGUI)),
    SJB_COMBO(CK_LCTL, OSM(MOD_LCTL)),
    SJB_COMBO(CK_LCG , OSM(MOD_LCTL | MOD_LGUI)),
    SJB_COMBO(CK_LCA , OSM(MOD_LCTL | MOD_LALT)),
    SJB_COMBO(CK_LGA , OSM(MOD_LGUI | MOD_LALT)),
    SJB_COMBO(CK_LCGA, OSM(MOD_LCTL | MOD_LGUI | MOD_LALT)),

    SJB_COMBO(CK_RALT, OSM(MOD_LALT)),
    SJB_COMBO(CK_RGUI, OSM(MOD_RGUI)),
    SJB_COMBO(CK_RCTL, OSM(MOD_RCTL)),
    SJB_COMBO(CK_RCG , OSM(MOD_RCTL | MOD_RGUI)),
    SJB_COMBO(CK_RCA , OSM(MOD_RCTL | MOD_LALT)),
    SJB_COMBO(CK_RGA , OSM(MOD_RGUI | MOD_LALT)),
    SJB_COMBO(CK_RCGA, OSM(MOD_RCTL | MOD_RGUI | MOD_LALT)),

    SJB_COMBO(CK_LSFT, OSM(MOD_LSFT)),
    SJB_COMBO(CK_RSFT, OSM(MOD_LSFT)),
#endif

#ifdef SB_LAYER_SWITCH_COMBO_KEY
    SJB_COMBO(CK_TG_NUM, TG(_NUMPAD)),
    SJB_COMBO(CK_TG_MOUSE, TG(_MOUSE)),
#endif
};

#endif
