/*
Copyright 2012,2013 gezhaoyou <gezhaoyou@126.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum layers { _BASE, _FN1, _FN2};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_numpad_5x4(
        TG(_FN2), KC_PSLS, KC_PAST,   LT(_FN1, KC_PMNS),
        KC_7,     KC_8,    KC_9,
        KC_4,     KC_5,    KC_6,      KC_PPLS,
        KC_1,     KC_2,    KC_3,
        KC_0,              KC_DOT,    KC_PENT),

  [_FN1] = LAYOUT_numpad_5x4(
        KC_TRNS,  KC_CALC, KC_BSPC,   KC_TRNS,
        RGB_MOD,  RGB_VAI, RGB_HUI,
        RGB_SPD,  RGB_TOG, RGB_SPI,   QK_BOOT,
        RGB_RMOD, RGB_VAD, RGB_HUD,
        _______,           _______,   EE_CLR),

  [_FN2] = LAYOUT_numpad_5x4(
        KC_TRNS,  KC_7,    KC_8,      KC_9,
        KC_HOME,  KC_UP,   KC_PGUP,
        KC_LEFT,  KC_DOWN, KC_RGHT,   KC_RSFT,
        KC_END,   KC_J,    KC_PGDN,
        KC_INS,            KC_DEL,    _______)
};


/* MR LED is non-standard. Need to override led init */
void led_init_ports(void) {
#ifdef LED_MR_LOCK_PIN
    gpio_set_pin_output(LED_MR_LOCK_PIN);
#endif
}

// num lock led as layer indicator
void layer_indicator_led(void) {
    if(layer_state_is(_FN2)){
        writePinHigh(LED_MR_LOCK_PIN);
    }
    else{
        writePinLow(LED_MR_LOCK_PIN);
    }
}

// When toggle key for mr layer (_FN2) is pressed, checks for which layer is on, and turns mr led on if it's (_FN2)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG(_FN2):
            if (!record->event.pressed) {  // When release after keypress
                layer_indicator_led(); // Toggle MR layer indicator
            }
            break;
        default:
            return true;           
    } 
    return true;
}