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
    _LOCK,
};

 // customized macro keys
enum custom_macros {
    QM_TGFW = SAFE_RANGE, // hold down 'w'
    QM_TGED,              // hold down 'end'
};

// Tap Dance keycodes
enum td_keycodes {
    MU_PL, // 'mute' and 'play'
    VD_PR, // 'volume down' and 'previous track'
    VU_NX, // 'volume up' and 'next track'
    NL_EC, // 'numlock' and 'escape'
    PL_EQ, // 'plus' and 'asterisk'
    MN_SL, // 'minus' and 'slash'
    PD_PA, // 'numpad dot' and 'numpad asterisk'
    KM_CO, // 'm' and 'comma'
    BK_ET, // 'backspace' and 'enter'
    N9_LB, // '9' and 'left bracket'
    N0_RB, // '0' and 'right bracket'
    PS_BS, // 'Print Screen' and 'backslash'
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

const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_MINS);
const key_override_t pscr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSCR, KC_UNDS);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &backspace_key_override,
    &pscr_key_override,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer (Default Layer) */
    [_BASE] = LAYOUT_ortho_5x15(
        QK_GESC,  KC_1,     KC_2,     KC_3,               KC_4,    KC_5,      TD(NL_EC),  TD(PL_EQ),  TD(MN_SL),  KC_6,    KC_7,    KC_8,      TD(N9_LB),  TD(N0_RB),  TD(PS_BS),
        KC_TAB,   KC_Q,     KC_W,     KC_E,               KC_R,    KC_T,      KC_P7,      KC_P8,      KC_P9,      KC_Y,    KC_U,    KC_I,      KC_O,       KC_P,       KC_BSPC,
        KC_LSFT,  KC_A,     KC_S,     KC_D,               KC_F,    KC_G,      KC_P4,      KC_P5,      KC_P6,      KC_H,    KC_J,    KC_K,      KC_L,       KC_RSFT,    XXXXXXX,
        XXXXXXX,  KC_SLSH,  KC_Z,     KC_X,               KC_C,    KC_V,      KC_P1,      KC_P2,      KC_P3,      KC_B,    KC_N,    TD(KM_CO), KC_DOT,     KC_UP,      KC_ENT,
        KC_LCTL,  KC_LGUI,  KC_LALT,  LT(_FN2, KC_SCLN),  KC_SPC,  MO(_FN1),  TD(BK_ET),  KC_P0,      TD(PD_PA),  KC_QUOT, KC_SPC,  KC_RALT,   KC_LEFT,    KC_DOWN,    KC_RGHT
    ),

    /* FN1 Layer */
    [_FN1] = LAYOUT_ortho_5x15(
        KC_F12,    KC_F1,      KC_F2,     KC_F3,    KC_F4,    KC_F5,      _______,    _______,    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,   KC_F11,
        KC_CAPS,   C(KC_Q),    C(KC_W),   C(KC_E),  C(KC_R),  C(KC_T),    _______,    _______,    _______,  _______,  _______,  _______,  _______,    _______,  RM_TOGG,
        KC_ENT,    C(KC_A),    C(KC_S),   C(KC_D),  C(KC_F),  MO(_SYST),  _______,    _______,    _______,  _______,  _______,  _______,  TG(_LOCK),  _______,  XXXXXXX,
        XXXXXXX,   C(S(KC_T)), C(KC_Z),   C(KC_X),  C(KC_C),  C(KC_V),    TD(VU_NX),  _______,    _______,  _______,  _______,  _______,  _______,    RM_VALU,  _______,
        _______,   _______,    _______,   _______,  _______,  KC_TRNS,    TD(VD_PR),  TD(MU_PL),  _______,  _______,  _______,  KC_RCTL,  RM_PREV,    RM_VALD,  RM_NEXT
    ),

    /* FN2 Layer */
    [_FN2] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,    _______,
        KC_CAPS, _______, QM_TGFW, QM_TGED, _______, _______, _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,    _______,
        KC_ENT,  _______, _______, _______, _______, _______, _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,    XXXXXXX,
        XXXXXXX, _______, _______, QK_LOCK, _______, _______, TD(VU_NX),  _______,    _______,  _______,  _______,  _______,  _______,  TD(VU_NX),  _______,
        _______, _______, _______, KC_TRNS, _______, _______, TD(VD_PR),  TD(MU_PL),  _______,  _______,  _______,  _______,  _______,  TD(VD_PR),  TD(MU_PL)
    ),

    /* System Layer */
    [_SYST] = LAYOUT_ortho_5x15(
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* All Key Lock Layer */
    [_LOCK] = LAYOUT_ortho_5x15(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// custom per-key LED setting for All Key Lock Layer
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(68, 255, 128, 0);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(68, 0, 0, 0);
    }
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _LOCK:
            rgb_matrix_set_color(0, 255, 30, 0);
            rgb_matrix_set_color(1, 255, 30, 0);
            rgb_matrix_set_color(5, 255, 30, 0);
            rgb_matrix_set_color(6, 255, 30, 0);
            break;
        default:
            break;
    }
    return false;
}

// Key assignment for Tap Dance keycodes
tap_dance_action_t tap_dance_actions[] = {
    [MU_PL] = ACTION_TAP_DANCE_TAP_HOLD(KC_MUTE, KC_MPLY),
    [VD_PR] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLD, KC_MPRV),
    [VU_NX] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLU, KC_MNXT),
    [NL_EC] = ACTION_TAP_DANCE_TAP_HOLD(KC_NUM, KC_ESC),
    [PL_EQ] = ACTION_TAP_DANCE_TAP_HOLD(KC_PPLS, KC_EQL),
    [MN_SL] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_SLSH),
    [PD_PA] = ACTION_TAP_DANCE_TAP_HOLD(KC_PDOT, KC_PAST),
    [KM_CO] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_COMM),
    [BK_ET] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, KC_ENT),
    [N9_LB] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_LBRC),
    [N0_RB] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_RBRC),
    [PS_BS] = ACTION_TAP_DANCE_TAP_HOLD(KC_PSCR, KC_BSLS),
};

/*
 - special Tap Dance keys for tap-hold function
 - turn LED off when toggled back
 - customized macro keys
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;
    tap_dance_state_t* state;

    switch (keycode) {
        // Tap Dance for tap-hold
        case TD(MU_PL):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(VD_PR):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(VU_NX):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(NL_EC):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(PL_EQ):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(MN_SL):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(PD_PA):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(KM_CO):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(BK_ET):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(N9_LB):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(N0_RB):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(PS_BS):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;

        // Turn LEDs off to indicate current status
        case TG(_LOCK): // turn LEDs back off when All Key Lock layer is turned off
            if (!record->event.pressed) {
                rgb_matrix_set_color(0, RGB_OFF);
                rgb_matrix_set_color(1, RGB_OFF);
                rgb_matrix_set_color(5, RGB_OFF);
                rgb_matrix_set_color(6, RGB_OFF);
            }
            break;
        case KC_CAPS: // turn LEDs back off when All Key Lock layer is turned off
            if (!record->event.pressed) {
                rgb_matrix_set_color(2, RGB_OFF);
                rgb_matrix_set_color(3, RGB_OFF);
                rgb_matrix_set_color(4, RGB_OFF);
            }
            break;
        // customized macros
        case QM_TGED:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_END)
                );
            }
            break;
        case QM_TGFW:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_W)
                );
            }
            break;
    }
    return true;
}

// tapping term adjustment here
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(MU_PL):
            return 190;
        case TD(VD_PR):
            return 225;
        case TD(VU_NX):
            return 225;
        case TD(PS_BS):
            return 225;
        case TD(N0_RB):
            return 200;
        case TD(N9_LB):
            return 200;
        default:
            return TAPPING_TERM;
    }
}
