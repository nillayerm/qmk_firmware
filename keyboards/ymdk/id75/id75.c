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
        rgb_matrix_set_color(29, RGB_OFF);

        // left side of alpha keys of the keyboard
        // B to Z  per-key LED
        rgb_matrix_set_color(24, 6, 255, 65); // B
        rgb_matrix_set_color(25, 6, 255, 65); // V
        rgb_matrix_set_color(26, 6, 255, 65); // C
        rgb_matrix_set_color(27, 6, 255, 65); // X
        rgb_matrix_set_color(28, 6, 255, 65); // Z
        // G to A  per-key LED
        rgb_matrix_set_color(39, 6, 255, 65); // G
        rgb_matrix_set_color(40, 6, 255, 65); // F
        rgb_matrix_set_color(41, 6, 255, 65); // D
        rgb_matrix_set_color(42, 6, 255, 65); // S
        rgb_matrix_set_color(43, 6, 255, 65); // A
        // T to Q  per-key LED
        rgb_matrix_set_color(54, 6, 255, 65); // T
        rgb_matrix_set_color(55, 6, 255, 65); // R
        rgb_matrix_set_color(56, 6, 255, 65); // E
        rgb_matrix_set_color(57, 6, 255, 65); // W
        rgb_matrix_set_color(58, 6, 255, 65); // Q

        // right side of alpha keys of the keyboard
        // M and N  per-key LED
        rgb_matrix_set_color(19, 6, 255, 65); // M
        rgb_matrix_set_color(20, 6, 255, 65); // N
        // L to H  per-key LED
        rgb_matrix_set_color(32, 6, 255, 65); // L
        rgb_matrix_set_color(33, 6, 255, 65); // K
        rgb_matrix_set_color(34, 6, 255, 65); // J
        rgb_matrix_set_color(35, 6, 255, 65); // H
        // P to Y  per-key LED
        rgb_matrix_set_color(46, 6, 255, 65); // P
        rgb_matrix_set_color(47, 6, 255, 65); // O
        rgb_matrix_set_color(48, 6, 255, 65); // I
        rgb_matrix_set_color(49, 6, 255, 65); // U
        rgb_matrix_set_color(50, 6, 255, 65); // Y
    }
    else{
        rgb_matrix_set_color(29, 6, 255, 65);
    }
    return true;
}
#endif
