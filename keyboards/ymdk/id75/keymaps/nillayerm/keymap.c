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
    _FN1,
    _FN2,
    _SYST,
    _LOCK,
};

 // customized macro keys
enum custom_macros {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5,
    MACRO_6,
};

// Tap Dance keycodes
enum td_keycodes {
    DM_MUPL,
    DM_VDPR,
    DM_VUNX,
};

// various actions for Tap Dance
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer (Default Layer) */
    [_BASE] = LAYOUT_ortho_5x15(
        KC_INS,  KC_PSCR,  KC_DEL,   QK_GESC,       KC_1,     KC_2,    KC_3,     KC_4,               KC_5,              KC_HOME,           KC_SLSH,  KC_ASTR,  TD(DM_MUPL), TD(DM_VDPR), TD(DM_VUNX),
        KC_F1,   KC_F5,    KC_F9,    KC_TAB,        KC_Q,     KC_W,    KC_E,     KC_R,               KC_T,              KC_PGUP,           KC_7,     KC_8,     KC_9,       KC_MINS,  KC_BSPC,
        KC_F2,   KC_F6,    KC_F10,   KC_LSFT,       KC_A,     KC_S,    KC_D,     KC_F,               KC_G,              KC_PGDN,           KC_4,     KC_5,     KC_6,       KC_PLUS,  KC_ENT,
        KC_F3,   KC_F7,    KC_F11,   KC_CAPS,       KC_Z,     KC_X,    KC_C,     KC_V,               KC_B,              KC_END,            KC_1,     KC_2,     KC_3,       KC_UP,    KC_BSLS,
        KC_F4,   KC_F8,    KC_F12,   KC_LCTL,       KC_LGUI,  KC_LALT, KC_RALT,  KC_SPC,             LT(_FN1, KC_BSPC), LT(_FN2, KC_ENT),  KC_0,     KC_DOT,   KC_LEFT,    KC_DOWN,  KC_RGHT
    ),

    /* FN1 Layer */
    [_FN1] = LAYOUT_ortho_5x15(
        _______, _______, _______, TG(_LOCK), _______, _______, _______, _______,   _______,   _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______,   _______, MACRO_1, _______, _______,   _______,   _______, _______, _______, _______,  _______, RGB_TOG,
        _______, _______, _______, _______,   _______, _______, _______, _______,   MO(_SYST), _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______,   _______, _______, _______, _______,   QK_LOCK,   _______, _______, _______, _______,  RGB_VAI, _______,
        _______, _______, _______, _______,   _______, _______, _______, _______,   KC_TRNS,   _______, _______, _______, RGB_RMOD, RGB_VAD, RGB_MOD
    ),

    /* FN2 Layer */
    [_FN2] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, MACRO_4, MACRO_3, MACRO_2, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, MACRO_6, MACRO_5, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______,  _______, _______
    ),

    /* System Layer */
    [_SYST] = LAYOUT_ortho_5x15(
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* All Key Lock Layer */
    [_LOCK] = LAYOUT_ortho_5x15(
        XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// custom per-key LED setting for All Key Lock Layer
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < 15; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _LOCK:
                rgb_matrix_set_color(i, 255, 30, 0);
                break;
            default:
                break;
        }
    }
    return false;
}

// when tap-hold for tap dance gets finished
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
    #ifndef PERMISSIVE_HOLD
            && !state->interrupted
    #endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}
// when tap-hold for tap dance gets reset
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}
// Tap Dance tap-hold actions finalization
#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

// Key assignment for Tap Dance keycodes
tap_dance_action_t tap_dance_actions[] = {
    [DM_MUPL] = ACTION_TAP_DANCE_TAP_HOLD(KC_MUTE, KC_MPLY),
    [DM_VDPR] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLD, KC_MPRV),
    [DM_VUNX] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLU, KC_MNXT),
};

/*
 1. special Tap Dance keys for tap-hold function
 2. turn LED off when toggled back
 3. customized macro keys
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        // 1. Tap Dance for tap-hold
        case TD(DM_MUPL):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(DM_VDPR):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(DM_VUNX):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        // 2. LED off for light indication
        case TG(_LOCK):
            if (!record->event.pressed) { // When released after keypress
                for (uint8_t i = 0; i < 15; i++) { // per-key LED for the first row with all of the underglow
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case KC_CAPS:
            if (!record->event.pressed) {
                // B to Z  per-key LED
                rgb_matrix_set_color(21, RGB_OFF); // B
                rgb_matrix_set_color(22, RGB_OFF); // V
                rgb_matrix_set_color(23, RGB_OFF); // C
                rgb_matrix_set_color(24, RGB_OFF); // X
                rgb_matrix_set_color(25, RGB_OFF); // Z
                // G to A  per-key LED
                rgb_matrix_set_color(36, RGB_OFF); // G
                rgb_matrix_set_color(37, RGB_OFF); // F
                rgb_matrix_set_color(38, RGB_OFF); // D
                rgb_matrix_set_color(39, RGB_OFF); // S
                rgb_matrix_set_color(40, RGB_OFF); // A
                // T to Q  per-key LED
                rgb_matrix_set_color(51, RGB_OFF); // T
                rgb_matrix_set_color(52, RGB_OFF); // R
                rgb_matrix_set_color(53, RGB_OFF); // E
                rgb_matrix_set_color(54, RGB_OFF); // W
                rgb_matrix_set_color(55, RGB_OFF); // Q
            }
            break;
        // 3. customized macros
        case MACRO_1: // keep running
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_W)
                );
            }
            break;
        case MACRO_2: // close current tab
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w"));
            }
            break;
        case MACRO_3: // paste
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
            break;
        case MACRO_4: // copy
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
            break;
        case MACRO_5: // save
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("s"));
            }
            break;
        case MACRO_6: // undo
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("z"));
            }
            break;
    }
    return true;
}

// tapping term adjustment here
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_FN2, KC_ENT):
            return 145;
        case LT(_FN1, KC_BSPC):
            return 155;
        case TD(DM_MUPL):
            return 200;
        case TD(DM_VDPR):
            return 275;
        case TD(DM_VUNX):
            return 275;
        default:
            return TAPPING_TERM;
    }
}
