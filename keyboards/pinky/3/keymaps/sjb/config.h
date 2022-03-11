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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define EE_HANDS

#define USE_SERIAL_PD2

//#define TAPPING_FORCE_HOLD // removes the double tap to repeat key
#define TAPPING_TERM 190
#define PERMISSIVE_HOLD
#define RETRO_TAPPPING
#define IGNORE_MOD_TAP_INTERRUPT

#define ONESHOT_TAP_TOGGLE 2
