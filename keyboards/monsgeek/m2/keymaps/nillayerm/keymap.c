/* Copyright (C) 2023 jonylee@hfd
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

// clang-format off
enum __layers {
    BASE,
    FACT,
    FUNC,
    SYST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer Keymap - 98Keys
   *    - Indicator: A15(F) --> Factory Layer,  C10(C) --> Caps Lock,  C11(W) --> Windows Key Lock
   *    - Num Lock led(A15) replaced by Factory Layer indicator
   *    
   * ┌───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┐ ┌───┬───┬───┬───┐
   * │Esc│ │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│ │Ins│RCt│Hom│PgU│
   * └───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┘ └───┴───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌─┐ ┌───┬───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backsp │ │F│ │Del│ ↑ │End│PgD│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├─┤ ├───┼───┼───┼───┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │C│ │ ← │ ↓ │ → │ R │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─┈┈┈┈┤ ├─┤ ├───┼───┼───┤ S │
   * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │ │W│ │ 7 │ 8 │ 9 │ h │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┐─┘ └─┘ ├───┼───┼───┤───┤
   * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ RShift │ ┌───┐ │ 4 │ 5 │ 6 │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┴─┬─┴────┬───┘ │ - │ └───┼───┼───┤ + │
   * │LCtl│LGUI│LAlt│                        │ RAlt │ Func │ ┌───┼───┼───┐ │ 2 │ 3 │   │
   * └────┴────┴────┴────────────────────────┴──────┴──────┘ │ * │ 0 │ 1 │ └───┴───┴───┘
   *                                                         └───┴───┴───┘
   */

    [BASE] = LAYOUT( /* Default Layer */
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,           KC_INS,  KC_RCTL, KC_HOME, KC_PGUP,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,           KC_DEL,  KC_UP,   KC_END,  KC_PGDN,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,           KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,            KC_7,    KC_8,    KC_9,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_PPLS,
		KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT,      MO(FUNC),             KC_PAST,  KC_0,    KC_1,    KC_2,    KC_3
    ),

    [FACT] = LAYOUT( /* Factory stock layer */
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,            KC_HOME, KC_END,  KC_PGUP, KC_PGDN,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           KC_P4,   KC_P5,   KC_P6,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,  KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		_______, _______, _______,                   _______,                            _______,      KC_TRNS,              KC_LEFT,  KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT
    ),

    [FUNC] = LAYOUT( /* Function Layer */
		_______, KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______,            KC_NUM,  _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______,            KC_MPRV, KC_VOLU, KC_MNXT, _______,
		_______, _______, TG(FACT),_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, RGB_MOD,            KC_MPLY, KC_VOLD, KC_MUTE, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, KC_MPLY,          RGB_HUI,            _______, _______, _______,
		_______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, QK_LOCK,                   _______,  _______,  _______, RGB_VAI, _______, _______,
		_______, GUI_TOG, _______,                   _______,                            _______,      KC_TRNS,              MO(SYST), _______,  RGB_SAD, RGB_VAD, RGB_SAI
    ),

    [SYST] = LAYOUT( /* System Layer */
	    EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		QK_BOOT, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                            XXXXXXX,      KC_TRNS,              KC_TRNS, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
    )

};


// Make use of num lock led as a Factory Layer indicator
void layer_indicator_led(void) {
    if(layer_state_is(FACT)){
        writePinLow(LED_FACT_PIN);
    }
    else{
        writePinHigh(LED_FACT_PIN);
    }
}

// When toggle key for Factory Layer is pressed, checks for which layer is on, and turns mr led on if it's FACT
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG(FACT):
            if (!record->event.pressed) {  // When release after keypress
                layer_indicator_led(); // Toggle layer indicator
            }
            break;
        case GUI_TOG:
            if (record->event.pressed) {
                // Toggle LED on key press
                togglePin(LED_WIN_LOCK_PIN);
            }
            break;
        default:
            return true;           
    } 
    return true;
}