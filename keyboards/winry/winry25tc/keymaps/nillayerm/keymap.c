/* Copyright 2022 Nikolay N
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

#include QMK_KEYBOARD_H

enum my_layers {
    _BASE,
    _FUNC,
    _GAME,
    _SYST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Default Layer */
    [_BASE] = LAYOUT(
        KC_6,           KC_7,           KC_8,      KC_9,     KC_0,
        KC_Y,           KC_U,           KC_I,      KC_O,     KC_P,
        KC_H,           KC_J,           KC_K,      KC_L,     RSFT_T(KC_BSPC),
        KC_N,           KC_M,           KC_COMM,   KC_DOT,   KC_SLSH,
        KC_SPC,         LT(1, KC_QUOT), KC_SCLN,   KC_LBRC,  KC_RBRC
    ),

    /* Function Layer */
    [_FUNC] = LAYOUT(
        TG(2),     _______,   _______,   KC_MINS,   KC_EQL,
        DT_PRNT,   _______,   KC_UP,     _______,   _______,
        DT_UP,     KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_ENT,
        DT_DOWN,   QK_LOCK,   _______,   _______,   KC_RALT,
        _______,   KC_TRNS,   MO(3),     _______,   _______
    ),

    /* Customized Game Layer */
    [_GAME] = LAYOUT(
        KC_TRNS,    KC_G,       KC_M,       KC_J,     KC_ESC,
        KC_I,       KC_Q,       KC_W,       KC_E,     KC_R,
        KC_LCTL,    KC_A,       KC_S,       KC_D,     KC_F,
        KC_F2,      KC_Z,       KC_X,       KC_C,     KC_V,
        KC_LGUI,    KC_TRNS,    KC_BSPC,    KC_LSFT,  KC_SPC
    ),


    /* System Layer */
    [_SYST] = LAYOUT(
        XXXXXXX,   XXXXXXX,   NK_TOGG,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        EE_CLR,    XXXXXXX,   QK_BOOT,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   KC_TRNS,   KC_TRNS,   XXXXXXX,   KC_SLEP
    )
};

#define RGBLIGHT_LAYERS

const rgblight_segment_t PROGMEM my_layer_caps[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 88, 230, 255},
    {1, 1, 88, 230, 255},
    {4, 1, 88, 230, 255},
    {5, 1, 88, 230, 255},
    {6, 1, 88, 230, 255},
    {7, 1, 88, 230, 255},
    {8, 1, 88, 230, 255},
    {9, 1, 88, 230, 255},
    {17, 1, 88, 230, 255},
    {18, 1, 88, 230, 255},
    {19, 1, 88, 230, 255}
);

enum rgb_layer_index {
    L_CAPSLOCK
};

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [L_CAPSLOCK]=my_layer_caps
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// This _function is called when Caps lock state is changed/toggled/updated
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(L_CAPSLOCK, led_state.caps_lock);
    return true;
}

// tapping term adjustment here
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_BSPC):
            return 105;
        default:
            return TAPPING_TERM;
    }
}
