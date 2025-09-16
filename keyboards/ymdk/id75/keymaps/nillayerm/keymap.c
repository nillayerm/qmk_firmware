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
    // gaming macros
    QM_TGFW = SAFE_RANGE, // hold down 'w' to continuously moving forward in game
    QM_TGED,              // hold down 'end' to toggle melee attack
};

// Tap Dance keycodes
enum td_keycodes {
    MU_PL, // mute and play
    VD_PR, // volume down and previous track
    VU_NX, // volume up and next track
    SP_RA, // space and right alt
    N5_F5, // 5 and F5
    BS_ES, // backspace and escape
    PL_AS, // plus and asterisk
    MN_SL, // minus and slash
    K9_LB, // o and left bracket
    K0_RB, // p and right bracket
    EN_BS, // enter and backslash
};

// various actions for Tap Dance
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_MINS);
const key_override_t pscr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSCR, KC_UNDS);


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &backspace_key_override,
    &pscr_key_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer (Default Layer) */
    [_BASE] = LAYOUT_ortho_5x15(
        QK_GESC,           KC_1,    KC_2,    KC_3,              KC_4,   KC_5,     TD(BS_ES), TD(PL_AS), TD(MN_SL),        KC_6,    KC_7,   KC_8,    TD(K9_LB), TD(K0_RB), KC_PSCR,
        KC_TAB,            KC_Q,    KC_W,    KC_E,              KC_R,   KC_T,     KC_7,      KC_8,      KC_9,             KC_Y,    KC_U,   KC_I,    KC_O,      KC_P,      KC_BSPC,
        KC_LSFT,           KC_A,    KC_S,    KC_D,              KC_F,   KC_G,     KC_4,      KC_5,      KC_6,             KC_H,    KC_J,   KC_K,    KC_L,      KC_RSFT,   KC_ENT,
        LT(_FN2, KC_CAPS), KC_SLSH, KC_Z,    KC_X,              KC_C,   KC_V,     KC_1,      KC_2,      KC_3,             KC_B,    KC_N,   KC_M,    KC_COMM,   KC_UP,     KC_DOT,
        KC_LCTL,           KC_LGUI, KC_LALT, LT(_FN2, KC_SCLN), KC_SPC, MO(_FN1), TD(EN_BS), KC_0,      LT(_FN2, KC_DOT), KC_QUOT, KC_SPC, KC_RALT, KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    /* FN1 Layer */
    [_FN1] = LAYOUT_ortho_5x15(
        TG(_LOCK), _______, G(S(KC_S)), _______, C(S(KC_V)), C(S(KC_T)), _______,   _______,   _______, _______, _______, _______, _______,  _______, _______,
        _______,   C(KC_Q), C(KC_W),    C(KC_E), C(KC_R), C(KC_T),       _______,   _______,   _______, _______, _______, _______, _______,  _______, RM_TOGG,
        _______,   C(KC_A), C(KC_S),    C(KC_D), C(KC_F), MO(_SYST),     _______,   _______,   _______, _______, _______, _______, _______,  _______, _______,
        TG(_FN2),  _______, C(KC_Z),    C(KC_X), C(KC_C), C(KC_V),       TD(MU_PL), _______,   _______, _______, _______, _______, _______,  RM_VALU, _______,
        _______,   _______, _______,    _______, _______, KC_TRNS,       TD(VD_PR), TD(VU_NX), _______, _______, _______, KC_RCTL, RM_PREV,  RM_VALD, RM_NEXT
    ),

    /* FN2 Layer */
    [_FN2] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, KC_F11,  KC_EQL, KC_F12,  _______,   _______,   _______, _______,  _______, _______,
        KC_MPRV, _______, KC_END,  QM_TGED, _______, _______, KC_F7,   KC_F8,  KC_F9,   _______,   _______,   _______, _______,  _______, _______,
        KC_MNXT, _______, _______, _______, KC_PGDN, KC_PGUP, KC_F4,   KC_F5,  KC_F6,   _______,   _______,   _______, _______,  _______, _______,
        KC_TRNS, _______, _______, QK_LOCK, _______, _______, KC_F1,   KC_F2,  KC_F3,   _______,   TD(MU_PL), _______, _______,  _______, _______,
        KC_MPLY, _______, _______, KC_TRNS, _______, _______, _______, KC_F10, KC_TRNS, TD(VD_PR), TD(VU_NX), _______, _______,  _______, _______
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
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// custom per-key LED setting for All Key Lock Layer
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _LOCK:
            rgb_matrix_set_color(0, 255, 30, 0);
            rgb_matrix_set_color(1, 255, 30, 0);
            rgb_matrix_set_color(5, 255, 30, 0);
            rgb_matrix_set_color(6, 255, 30, 0);
            break;
        case _FN2:
            rgb_matrix_set_color(1, RGB_ORANGE);
            rgb_matrix_set_color(5, RGB_ORANGE);
            break;
        default:
            break;
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
    [MU_PL] = ACTION_TAP_DANCE_TAP_HOLD(KC_MUTE, KC_MPLY),
    [VD_PR] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLD, KC_MPRV),
    [VU_NX] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLU, KC_MNXT),
    [SP_RA] = ACTION_TAP_DANCE_TAP_HOLD(KC_SPC, KC_RALT),
    [N5_F5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_F5),
    [BS_ES] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, KC_ESC),
    [PL_AS] = ACTION_TAP_DANCE_TAP_HOLD(KC_PLUS, KC_PAST),
    [MN_SL] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_SLSH),
    [K9_LB] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_LBRC),
    [K0_RB] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_RBRC),
    [EN_BS] = ACTION_TAP_DANCE_TAP_HOLD(KC_ENT, KC_BSLS),
};

/*
 - special Tap Dance keys for tap-hold function
 - turn LED off when toggled back
 - customized macro keys
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        // Tap Dance for tap-hold
        case TD(MU_PL):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(VD_PR):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(VU_NX):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(SP_RA):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(N5_F5):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(BS_ES):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(PL_AS):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(MN_SL):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(K9_LB):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(K0_RB):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        case TD(EN_BS):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
            }
            break;
        // Turn LEDs off to indicate current status
        case TG(_LOCK): // turn LEDs back off when All Key Lock layer is turend off
            if (!record->event.pressed) {
                rgb_matrix_set_color(0, RGB_OFF);
                rgb_matrix_set_color(1, RGB_OFF);
                rgb_matrix_set_color(5, RGB_OFF);
                rgb_matrix_set_color(6, RGB_OFF);
            }
            break;
        case TG(_FN2): // turn LEDs back off when _FN2 layer is turned off
            if (!record->event.pressed) {
                rgb_matrix_set_color(1, RGB_OFF);
                rgb_matrix_set_color(5, RGB_OFF);
            }
            break;
        case LT(_FN2, KC_SCLN): // turn LEDs back off when _FN2 layer is turned off
            if (!record->event.pressed) {
                rgb_matrix_set_color(1, RGB_OFF);
                rgb_matrix_set_color(5, RGB_OFF);
            }
            break;
        case LT(_FN2, KC_DOT): // turn LEDs back off when _FN2 layer is turned off
            if (!record->event.pressed) {
                rgb_matrix_set_color(1, RGB_OFF);
                rgb_matrix_set_color(5, RGB_OFF);
            }
            break;
        case LT(_FN2, KC_CAPS): // turn LEDs back off when caps lock is turned off
            if (!record->event.pressed) {
                rgb_matrix_set_color(1, RGB_OFF);
                rgb_matrix_set_color(2, RGB_OFF);
                rgb_matrix_set_color(3, RGB_OFF);
                rgb_matrix_set_color(4, RGB_OFF);
                rgb_matrix_set_color(5, RGB_OFF);
            }
            break;
        // customized macros
        case QM_TGED: // keep attacking
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_END)
                );
            }
            break;
        case QM_TGFW: // keep running
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
        case LT(_FN2, KC_SCLN):
            return 165;
        case LT(_FN2, KC_CAPS):
            return 155;
        case LT(_FN2, KC_DOT):
            return 155;
        case TD(MU_PL):
            return 200;
        case TD(VD_PR):
            return 275;
        case TD(VU_NX):
            return 275;
        case TD(SP_RA):
            return 165;
        case TD(N5_F5):
            return 165;
        case TD(BS_ES):
            return 175;
        case TD(PL_AS):
            return 175;
        case TD(MN_SL):
            return 175;
        case TD(K9_LB):
            return 165;
        case TD(K0_RB):
            return 165;
        case TD(EN_BS):
            return 175;
        default:
            return TAPPING_TERM;
    }
}
