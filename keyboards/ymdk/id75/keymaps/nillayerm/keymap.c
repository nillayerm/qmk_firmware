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

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FUNC,
    _SYST,
    _LOCK
};

enum custom_macros {
    MACRO_1 = SAFE_RANGE,
    MACRO_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap _BASE: Base Layer (Default Layer) */
    [_BASE] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,  KC_END,   KC_6,             KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP,  KC_PGDN,  KC_Y,             KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,  KC_BSLS,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F5,    KC_PSCR,  KC_H,             KC_J,    KC_K,     KC_L,     KC_RSFT,  KC_QUOT,  KC_ENT,
        KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_B,     KC_N,             KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    KC_RBRC,
        KC_LCTL, KC_LGUI, KC_LALT, KC_GRV,  KC_SPC,  MO(1),   KC_VOLD,  KC_VOLU,  LT(1, KC_RALT),   KC_SPC,  KC_SCLN,  KC_LBRC,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
 
    /* Keymap _FUNC: Function Layer */
    [_FUNC] = LAYOUT_ortho_5x15(
        TG(3),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        _______, _______, MACRO_1, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG,  KC_DEL,  KC_INS,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, MO(2),   _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, MACRO_2, QK_LOCK, KC_MPLY, _______, _______, _______, _______, _______, _______,  RGB_VAI, _______,
        _______, _______, _______, _______, _______, KC_TRNS, KC_MPRV, KC_MNXT, _______, _______, _______, _______, RGB_RMOD, RGB_VAD, RGB_MOD
    ),

    /* Keymap _SYST: System Layer */
    [_SYST] = LAYOUT_ortho_5x15(
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Keymap _LOCK: All Key Disabled Layer */
    [_LOCK] = LAYOUT_ortho_5x15(
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < 15; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 3:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            default:
                break;
        }
    }
    return false;
}

//Custom macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG(3):
            if (!record->event.pressed) { // When release after keypress
                for (uint8_t i = 0; i < 15; i++) {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case KC_CAPS:
            if (!record->event.pressed) { // When release after keypress
                for (uint8_t i = 0; i < 7; i++) {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case MACRO_1:
            if (record->event.pressed) {
                    SEND_STRING(
                        SS_DOWN(X_W)
                        );
            }
            break;
        case MACRO_2:
            if (record->event.pressed) {
                    SEND_STRING(SS_LCTL("w"));
            }
            break;
        }
    return true;
}
