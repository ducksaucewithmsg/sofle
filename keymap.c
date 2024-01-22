#include QMK_KEYBOARD_H
#include "oled.c"

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAP  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  -   |
 * |------+------+------+------+------+------|       |    |  GAME |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  '   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | lctl | Lgui | Lalt |enter | /lower  /       \Raise \  |space |  BS  |   [  |   ]  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,     KC_7,     KC_8,     KC_9,   KC_0,     KC_BSLS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,     KC_U,     KC_I,     KC_O,   KC_P,     KC_EQL,
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,     KC_J,     KC_K,     KC_L,   KC_SCLN,  KC_MINS,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_TRNS,      TG(3), KC_N,     KC_M,     KC_COMM,  KC_DOT, KC_SLSH,  KC_QUOT,
                    KC_LCTL, KC_LGUI, KC_LALT, KC_ENT, MO(1),        MO(2), KC_SPC,   KC_BSPC,  KC_LBRC,  KC_RBRC
),
/* fn1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  num |      |      |      |      |      |                    |      |      |      |      | print| F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | prev | next | pl&pa|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |  del |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
  KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                            KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,
  KC_NUM,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR, KC_F12,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PERC,                          KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_MPLY, KC_TRNS,
                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_DEL,   KC_TRNS,  KC_TRNS
),
/* fn2
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |on/off|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | hui+ | hui- |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | sat+ | sat- |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |brit+ | brit-|      |      |      |      |--------|   |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  RGB_TOG,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN,                           RGB_M_G,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  RGB_HUI,  RGB_HUD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  RGB_SAI,  RGB_SAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  RGB_VAI,  RGB_VAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAP  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  -   |
 * |------+------+------+------+------+------| mute  |    |  GAME |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  '   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | lctl | Lgui | Lalt | space| /lower  /       \Raise \  |enter |  BS  |   [  |   ]  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,     KC_9,   KC_0,     KC_BSLS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,     KC_EQL,
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,  KC_MINS,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,        KC_TRNS,  KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  KC_QUOT,
                    KC_LCTL, KC_TRNS, KC_LALT, KC_SPC,  MO(1),          MO(2),    KC_ENT,  KC_BSPC, KC_LBRC,  KC_RBRC
  )
};
