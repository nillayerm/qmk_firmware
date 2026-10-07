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

/* Prototypes for tap-dance helpers used in this file */
#include "quantum/keymap_introspection.h"
#include "quantum/process_keycode/process_tap_dance.h"


enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _SYST,
};

 // customized macro keys
enum custom_macros {
    QM_TGFW = SAFE_RANGE, // hold down 'w'
    QM_TGWE,              // hold down 'w' and 'e'
    QM_TGSC,              // hold down ';'
    QM_CLST,              // focus on current window with a left click, then close tab
    QM_TGLL,              // hold down 'left' after tapping it once
};

// Tap Dance keycodes
enum td_keycodes {
    KC9_LBR,
    KC0_RBR,
};

// various actions for Tap Dance
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

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
#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
    }

const key_override_t backspace_key_override1 = ko_make_basic(MOD_MASK_CTRL, KC_VOLU, KC_MUTE);
const key_override_t backspace_key_override2 = ko_make_basic(MOD_MASK_CTRL, KC_VOLD, KC_MPLY);
const key_override_t backspace_key_override3 = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_ENT);


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &backspace_key_override1,
    &backspace_key_override2,
    &backspace_key_override3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer (Default Layer) */
    [_BASE] = LAYOUT_ortho_5x15(
        QK_GESC, KC_1,    KC_2,    KC_3,              KC_4,   KC_5,     KC_6,   KC_7,   KC_8,    TD(KC9_LBR),    TD(KC0_RBR),        KC_MINS, KC_EQL,  KC_PGUP,    KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,              KC_R,   KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,        KC_BSPC,    KC_UP,    KC_PGDN,    KC_VOLD,
        KC_LSFT, KC_A,    KC_S,    KC_D,              KC_F,   KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_RSFT, KC_LEFT,    KC_DOWN,   KC_RGHT,    KC_9,
        KC_QUOT, KC_BSPC, KC_Z,    KC_X,              KC_C,   KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_6, KC_7, KC_8,
        KC_LCTL, KC_LGUI, KC_LALT, LT(_FN2, KC_SCLN), KC_SPC, MO(_FN1), KC_ENT, KC_SPC, KC_RALT, KC_0, KC_1,     KC_2,    KC_3, KC_4, KC_5
    ),

    /* FN1 Layer */
    [_FN1] = LAYOUT_ortho_5x15(
        RM_TOGG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   _______,  G(KC_PSCR),
        _______, C(KC_Q), QM_CLST, C(KC_E), C(KC_R), C(S(KC_T)), C(KC_T), _______, _______, _______, _______, _______, _______, _______,  _______,
        KC_CAPS, C(KC_A), C(KC_S), C(KC_D), C(KC_F), MO(_SYST),  _______, _______, _______, _______, _______, _______, RM_VALU, _______,  _______,
        _______, _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),    KC_VOLU, KC_MPLY, KC_MUTE, _______, _______, RM_PREV, RM_VALD, RM_NEXT,  KC_INS,
        _______, _______, _______, QM_TGSC, KC_BSLS, KC_TRNS,    KC_VOLD, _______, KC_RCTL, _______, _______, _______, _______, _______,  KC_DEL
    ),

    /* FN2 Layer */
    [_FN2] = LAYOUT_ortho_5x15(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______, _______, _______,
        KC_GRV,  _______, QM_TGFW, QM_TGWE, _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______, _______, _______,
        KC_CAPS, _______, KC_PGUP, QM_TGLL, _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______, _______, _______,
        _______, _______, KC_PGDN, QK_LOCK, MS_BTN1, _______, _______, _______, _______,  _______,  _______,  _______,  _______, _______, _______,
        _______, _______, _______, KC_TRNS, _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______, _______, _______
    ),

    /* System Layer */
    [_SYST] = LAYOUT_ortho_5x15(
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// --- LED index groups ---
static const uint8_t caps_leds[] = {3, 4, 5, 44};

// --- Helper to set a group of LEDs ---
static void set_led_group(const uint8_t *leds, uint8_t count, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < count; i++) {
        rgb_matrix_set_color(leds[i], r, g, b);
    }
}

bool rgb_matrix_indicators_user(void) {
    static bool prev_caps = false;

    bool caps = host_keyboard_led_state().caps_lock;

    // --- Caps Lock ---
    // ON → always enforce solid color
    // OFF → only update when state changes, release back to effect
    if (caps) {
        set_led_group(caps_leds, 4, 6, 255, 65);   // solid greenish ON
    } else if (caps != prev_caps) {
        set_led_group(caps_leds, 4, 0, 0, 0);      // release OFF
    }
    prev_caps = caps;

    return false; // allow other effects for non-indicator LEDs
}

// Key assignment for Tap Dance keycodes
tap_dance_action_t tap_dance_actions[] = {
    [KC9_LBR] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_LBRC),
    [KC0_RBR] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_RBRC),  
};

void handle_tap_dance(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
    tap_dance_state_t *state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
    if (!record->event.pressed && state && state->count && !state->finished) {
        tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
        tap_code16(tap_hold->tap);
    }
}


/*
 - special Tap Dance keys for tap-hold function
 - customized macro keys
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Tap Dance for tap-hold
            case TD(KC9_LBR): case TD(KC0_RBR):
            handle_tap_dance(keycode, record);
            break;

        // customized macros
        case QM_TGFW:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_W)            // hold down 'w'
                );
            }
            break;
        case QM_TGWE:
            if (record->event.pressed) {
                register_code(KC_W);     // Hold down 'w'
                register_code(KC_E);     // Hold down 'e'
            }
            break;
        case QM_TGSC:
            if (record->event.pressed) {
                register_code(KC_SCLN);     // Hold down ';'
            }
            break;
        case QM_CLST:
            if (record->event.pressed) {
                tap_code(MS_BTN1);          // Left click
                wait_ms(10);                // Delay 10 ms
                SEND_STRING(SS_LCTL("w"));  // Send Ctrl+W
            }
            break;
        case QM_TGLL:
            if (record->event.pressed) {
                register_code(KC_LEFT);     // Hold down l
                wait_ms(10);
                unregister_code(KC_LEFT);   // release l
                wait_ms(10);            // Delay 300 ms
                register_code(KC_LEFT);     // Hold down l
            }
            break;
    }
    return true;
}

// tapping term adjustment here
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(KC9_LBR):
            return 160;
        case TD(KC0_RBR):
            return 160;
        default:
            return TAPPING_TERM;
    }
}
