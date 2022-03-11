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
#define TAPPING_TERM 190

#define PERMISSIVE_HOLD
#define RETRO_TAPPPING
#define IGNORE_MOD_TAP_INTERRUPT

// Mouse Settings: Smoothing out mouse movement on keypress
#ifndef MOUSEKEY_INTERVAL
    #undef MOUSEKEY_INTERVAL
    #define MOUSEKEY_INTERVAL 16
#endif
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

#ifdef COMBO_ENABLE
    #undef COMBO_COUNT
    #undef COMBO_TERM
    #define COMBO_COUNT 2
    #define COMBO_TERM 60
#endif

#define ONESHOT_TAP_TOGGLE 2
