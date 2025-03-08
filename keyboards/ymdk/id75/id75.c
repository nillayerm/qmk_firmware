/* Copyright 2021 MT
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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) { // dedicated per-key light zone for Capslock
        rgb_matrix_set_color(21, 6, 255, 65);
        rgb_matrix_set_color(22, 6, 255, 65); 
        rgb_matrix_set_color(23, 6, 255, 65); 
        rgb_matrix_set_color(24, 6, 255, 65); 
        rgb_matrix_set_color(25, 6, 255, 65); 

        rgb_matrix_set_color(36, 6, 255, 65); 
        rgb_matrix_set_color(37, 6, 255, 65); 
        rgb_matrix_set_color(38, 6, 255, 65); 
        rgb_matrix_set_color(39, 6, 255, 65); 
        rgb_matrix_set_color(40, 6, 255, 65);

        rgb_matrix_set_color(51, 6, 255, 65); 
        rgb_matrix_set_color(52, 6, 255, 65); 
        rgb_matrix_set_color(53, 6, 255, 65); 
        rgb_matrix_set_color(54, 6, 255, 65); 
        rgb_matrix_set_color(55, 6, 255, 65);

        rgb_matrix_set_color(26, RGB_OFF);
    }
    else{
        rgb_matrix_set_color(26, 6, 255, 65);
    }
    return true;
}
#endif
