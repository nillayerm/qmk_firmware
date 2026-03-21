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
    QM_CLST,              // focus on current window with a left click then close tab
};

// Tap Dance keycodes
enum td_keycodes {
    MUT_PLY, // 'mute' and 'play'
    VLD_PRV, // 'volume down' and 'previous track'
    VLU_NXT, // 'volume up' and 'next track'
    BKS_NLK, // 'backspace' and 'numlock'
    PLS_AST, // 'plus' and 'asterisk'
    MNS_SLS, // 'minus' and 'slash'
    KCM_CMM, // 'm' and 'comma'
    ENT_ESC, // 'enter' and 'escape'
    KC9_LBK, // '9' and 'left bracket'
    KC0_RBK, // '0' and 'right bracket'
    PRT_EQL, // 'Print Screen' and 'Equal'
    SLS_BSL, // 'Slash' and 'Backslash'
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


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &backspace_key_override,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer (Default Layer) */
    [_BASE] = LAYOUT_ortho_5x15(
        QK_GESC, KC_1,        KC_2,    KC_3,              KC_4,    KC_5,     TD(BKS_NLK), TD(PLS_AST), TD(MNS_SLS), KC_6,    KC_7,    KC_8,        TD(KC9_LBK), TD(KC0_RBK), TD(PRT_EQL),
        KC_TAB,  KC_Q,        KC_W,    KC_E,              KC_R,    KC_T,     KC_P7,       KC_P8,       KC_P9,       KC_Y,    KC_U,    KC_I,        KC_O,        KC_P,        KC_BSPC,
        KC_LSFT, KC_A,        KC_S,    KC_D,              KC_F,    KC_G,     KC_P4,       KC_P5,       KC_P6,       KC_H,    KC_J,    KC_K,        KC_L,        KC_RSFT,     XXXXXXX,
        XXXXXXX, TD(SLS_BSL), KC_Z,    KC_X,              KC_C,    KC_V,     KC_P1,       KC_P2,       KC_P3,       KC_B,    KC_N,    TD(KCM_CMM), KC_DOT,      KC_UP,       KC_ENT,
        KC_LCTL, KC_LGUI,     KC_LALT, LT(_FN2, KC_SCLN), KC_SPC,  MO(_FN1), TD(ENT_ESC), KC_P0,       KC_PDOT,     KC_QUOT, KC_SPC,  KC_RALT,     KC_LEFT,     KC_DOWN,     KC_RGHT
    ),

    /* FN1 Layer */
    [_FN1] = LAYOUT_ortho_5x15(
        KC_F12,    KC_F1,      KC_F2,     KC_F3,    KC_F4,    KC_F5,      _______,     _______,     _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,   KC_F11,
        _______,   C(KC_Q),    QM_CLST,   C(KC_E),  C(KC_R),  C(KC_T),    _______,     _______,     _______,  _______,  _______,  _______,  _______,    _______,  RM_TOGG,
        KC_CAPS,   C(KC_A),    C(KC_S),   C(KC_D),  C(KC_F),  MO(_SYST),  _______,     _______,     _______,  _______,  _______,  _______,  TG(_LOCK),  _______,  XXXXXXX,
        XXXXXXX,   C(S(KC_T)), C(KC_Z),   C(KC_X),  C(KC_C),  C(KC_V),    TD(VLU_NXT), _______,     _______,  _______,  _______,  _______,  _______,    RM_VALU,  _______,
        _______,   _______,    _______,   _______,  _______,  KC_TRNS,    TD(VLD_PRV), TD(MUT_PLY), _______,  _______,  _______,  KC_RCTL,  RM_PREV,    RM_VALD,  RM_NEXT
    ),

    /* FN2 Layer */
    [_FN2] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______,     _______,
        _______, _______, QM_TGFW, QM_TGED, _______, _______, _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______,     _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______,     XXXXXXX,
        XXXXXXX, _______, _______, QK_LOCK, MS_BTN1, _______, TD(VLU_NXT), _______,     _______,  _______,  _______,  _______,  _______,  TD(VLU_NXT), _______,
        _______, _______, KC_HOME, KC_TRNS, KC_END,  _______, TD(VLD_PRV), TD(MUT_PLY), _______,  _______,  _______,  _______,  _______,  TD(VLD_PRV), TD(MUT_PLY)
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

// --- LED index groups ---
static const uint8_t caps_leds[] = {2, 3, 4};
static const uint8_t lock_leds[] = {0, 1, 5, 6};
static const uint8_t num_led     = 68;

// --- Helper to set a group of LEDs ---
static void set_led_group(const uint8_t *leds, uint8_t count, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < count; i++) {
        rgb_matrix_set_color(leds[i], r, g, b);
    }
}

bool rgb_matrix_indicators_user(void) {
    static bool prev_caps = false;
    static bool prev_lock = false;

    bool caps = host_keyboard_led_state().caps_lock;
    bool num  = host_keyboard_led_state().num_lock;
    bool lock = layer_state_is(_LOCK);

    // --- Caps Lock ---
    // ON → always enforce solid color
    // OFF → only update when state changes, release back to effect
    if (caps) {
        set_led_group(caps_leds, 3, 6, 255, 65);   // solid greenish ON
    } else if (caps != prev_caps) {
        set_led_group(caps_leds, 3, 0, 0, 0);      // release OFF
    }
    prev_caps = caps;

    // --- Num Lock ---
    // Always enforce binary state every cycle
    if (num) {
        rgb_matrix_set_color(num_led, 255, 128, 0); // solid orange ON
    } else {
        rgb_matrix_set_color(num_led, 0, 0, 0);     // forced black OFF
    }

    // --- _LOCK layer ---
    // ON → always enforce solid color
    // OFF → only update when state changes, release back to effect
    if (lock) {
        set_led_group(lock_leds, 4, 255, 30, 0);   // solid red ON
    } else if (lock != prev_lock) {
        set_led_group(lock_leds, 4, 0, 0, 0);      // release OFF
    }
    prev_lock = lock;

    return false; // allow other effects for non-indicator LEDs
}



// Key assignment for Tap Dance keycodes
tap_dance_action_t tap_dance_actions[] = {
    [MUT_PLY] = ACTION_TAP_DANCE_TAP_HOLD(KC_MUTE, KC_MPLY),
    [VLD_PRV] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLD, KC_MPRV),
    [VLU_NXT] = ACTION_TAP_DANCE_TAP_HOLD(KC_VOLU, KC_MNXT),
    [BKS_NLK] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, KC_NUM),
    [PLS_AST] = ACTION_TAP_DANCE_TAP_HOLD(KC_PPLS, KC_PAST),
    [MNS_SLS] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_SLSH),
    [KCM_CMM] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_COMM),
    [ENT_ESC] = ACTION_TAP_DANCE_TAP_HOLD(KC_ENT, KC_ESC),
    [KC9_LBK] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_LBRC),
    [KC0_RBK] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_RBRC),
    [PRT_EQL] = ACTION_TAP_DANCE_TAP_HOLD(KC_PSCR, KC_EQL),
    [SLS_BSL] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, KC_BSLS),
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
        case TD(MUT_PLY): case TD(VLD_PRV): case TD(VLU_NXT): case TD(BKS_NLK):
        case TD(PLS_AST): case TD(MNS_SLS): case TD(KCM_CMM): case TD(ENT_ESC):
        case TD(KC9_LBK): case TD(KC0_RBK): case TD(PRT_EQL):
        case TD(SLS_BSL):
            handle_tap_dance(keycode, record);
            break;

        // customized macros
        case QM_TGED:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_END)          // hold down 'end'
                );
            }
            break;
        case QM_TGFW:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_W)            // hold down 'w'
                );
            }
            break;
        case QM_CLST:
            if (record->event.pressed) {
                tap_code(MS_BTN1);          // Left click
                wait_ms(10);                // Delay 10 ms
                SEND_STRING(SS_LCTL("w"));  // Send Ctrl+W
            }
            break;
    }
    return true;
}

// tapping term adjustment here
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(MUT_PLY):
            return 190;
        case TD(VLD_PRV):
            return 225;
        case TD(VLU_NXT):
            return 225;
        case TD(PRT_EQL):
            return 190;
        case TD(KC0_RBK):
            return 195;
        case TD(KC9_LBK):
            return 195;
        case TD(KCM_CMM):
            return 185;
        default:
            return TAPPING_TERM;
    }
}
