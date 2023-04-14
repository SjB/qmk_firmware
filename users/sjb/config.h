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

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif

//#define ENABLE_HOME_ROW 1
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200 // default 200
// #define RETRO_TAPPPING
//#define PERMISSIVE_HOLD

#define COMBO_TERM 60
#define COMBO_ONLY_FROM_LAYER 0
//#define COMBO_MUST_HOLD_MODS
//#define COMBO_HOLD_TERM 175

// Mouse Settings: Smoothing out mouse movement on keypress
#define MK_COMBINED
#ifndef MOUSEKEY_INTERVAL
    #undef MOUSEKEY_INTERVAL
    #define MOUSEKEY_INTERVAL 16
#endif
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

 #define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.

#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 5000

#define FORCE_NKRO
