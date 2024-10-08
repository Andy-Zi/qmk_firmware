#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Layer 1 Modifier

#define M_Z LSFT_T(KC_Z)
#define M_X LCTL_T(KC_X)
#define M_C LGUI_T(KC_C)
#define M_V LALT_T(KC_V)

#define M_M RALT_T(KC_M)
#define M_COMM RGUI_T(KC_COMM)
#define M_DOT RCTL_T(KC_DOT)
#define M_SLSH RSFT_T(KC_SLSH)

// Layer 2 Modifier
//
#define M_UNDS LCTL_T(KC_UNDS)
#define M_MINS LGUI_T(KC_MINS)
#define M_LBRC LALT_T(KC_LBRC)

#define M_RBRC RALT_T(KC_RBRC)
#define M_PLUS RGUI_T(KC_PLUS)
#define M_EQL RCTL_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    M_Z,      M_X,     M_C,     M_V,    KC_B,                         KC_N,     M_M,  M_COMM,   M_DOT,  M_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          SC_LCPO,   MO(1),KC_SPACE,   KC_ENTER,   MO(2), SC_RCPC
                                      //`--------------------------'  `--------------------------'

  ),
  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LSFT, KC_UNDS,  M_MINS,  M_LBRC, KC_LCBR,                      KC_RCBR,  M_RBRC, KC_PLUS,   M_EQL, KC_RSFT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_TRNS,KC_SPACE,   KC_ENTER,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______,  KC_DEL,                      KC_BSPC, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_BTN1, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(3),KC_SPACE,   KC_ENTER, KC_TRNS, _______
                                      //`--------------------------'  `--------------------------'

  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, KC_PSCR,                      KC_MPRV, KC_MPLY, KC_MUTE, KC_MNXT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, _______,                      _______, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_TRNS,KC_SPACE,   KC_ENTER, KC_TRNS, _______
                                      //`--------------------------'  `--------------------------'

  ),
};

// disable built-in led
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
