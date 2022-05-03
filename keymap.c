#include QMK_KEYBOARD_H

enum layers {
    _ISRT = 0, // default layer
    _PUNCTUATION,
    _MEDIA,
    _MOUSE,
    _QMK,
    _QWERTY,
    _FUNCTION,
};

// tap dance
enum {
    // SFT_CAPS,
    COMM_COLON,
    SLSH_DASH,
    DOT_UNDS,
    CURLY,
    PAREN,
    BRAC,
    ANGLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ISRT] = LAYOUT(
            /* Left side                                                                                Right side */
            KC_Y,   KC_C,   KC_L,        KC_M,          KC_K,           KC_Z,   KC_F,   KC_U,   LCTL(KC_BSPC),   TD(COMM_COLON),
            KC_I,   KC_S,   KC_R,        LGUI_T(KC_T),    KC_G,           KC_P,   LGUI_T(KC_N),  KC_E,   KC_A,   KC_O,
            KC_Q,   KC_V,   KC_W,        KC_D,          KC_J,           KC_B,   KC_H,   TD(SLSH_DASH), TD(DOT_UNDS), KC_X,

                        LALT_T(KC_SPC),   LSFT_T(OSM(MOD_LSFT)),          LCTL_T(KC_ESC), TO(_PUNCTUATION)
            ),

    [_PUNCTUATION] = LAYOUT(
            /* Left side                                                                                Right side */
            KC_MINS,    KC_QUOT,    KC_DQUO,    KC_TAB,  KC_EXLM,        KC_PERC,   KC_7,   KC_8,   KC_9,   KC_AT,
            TD(ANGLE),  TD(BRAC),   TD(PAREN),   TD(CURLY), KC_ASTR,     KC_EQL,   KC_4,    KC_5,   KC_6,   KC_0,
            KC_PLUS,    KC_HASH,    KC_DLR,     KC_SCLN, KC_QUES,        KC_AMPR,   KC_1,   KC_2,    KC_3,  KC_SLASH,

                                            TO(_ISRT),   KC_ENT,        KC_BSPC, TO(_MEDIA)
            ),

    [_MEDIA] = LAYOUT(
            /* Left side                                                                                Right side */
            KC_BRMU,    KC_VOLD,   KC_MUTE,    KC_VOLU, XXXXXXX,        XXXXXXX,   KC_TILD,      KC_GRV,  XXXXXXX,   XXXXXXX,
            KC_BRMD,    KC_MRWD,   KC_MSTP,    KC_MFFD, XXXXXXX,        XXXXXXX,    KC_PIPE,     KC_BSLS, KC_UNDS,   KC_CIRC,
            XXXXXXX,    KC_MPRV,   KC_MPLY,    KC_MNXT, XXXXXXX,        XXXXXXX,    TO(_MOUSE),  XXXXXXX, XXXXXXX,   XXXXXXX,

                                            TO(_ISRT),   KC_SPC,        KC_BSPC, TO(_FUNCTION)
            ),

    [_MOUSE] = LAYOUT(
            /* Left side                                                                                Right side */
            TO(_QMK),   KC_DEL,    KC_UP,      KC_BTN3, XXXXXXX,        KC_WH_L,  KC_WH_D,  KC_WH_U,    KC_WH_R,  XXXXXXX,
            KC_INS,     KC_LEFT,   KC_DOWN,    KC_RIGHT, KC_LCTL,       KC_MS_LEFT,    KC_MS_DOWN,  KC_MS_UP,   KC_MS_RIGHT,  XXXXXXX,
            TO(_QWERTY),KC_ACL0,   KC_ACL1,    KC_ACL2, KC_SYSREQ,       XXXXXXX,      KC_PGDN,      KC_PGUP,       KC_HOME,   KC_END,

                                            TO(_ISRT),   KC_BTN1,        KC_BTN2, KC_LSFT
            ),

    [_QMK] = LAYOUT(
            /* Left side                                                                                Right side */
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_CLEAR_EEPROM,       QK_BOOTLOADER, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,

                                            TO(_ISRT),   XXXXXXX,        XXXXXXX, XXXXXXX
            ),

    [_QWERTY] = LAYOUT(
            /* Left side                                                                                Right side */
            KC_ESC,     KC_Q,    KC_W,      KC_E, KC_R,        KC_T,  KC_Y,  KC_U,    KC_I,   KC_O,
            KC_LSFT,    KC_A,   KC_S,    KC_D, KC_F,       KC_G,    KC_H,  KC_J,   KC_K,    KC_L,
            KC_LCTL,    KC_Z,   KC_X,    KC_C, KC_V,       KC_B,      KC_N,      KC_M,       KC_COMM,   KC_DOT,

                                            TO(_ISRT),   KC_SPC,        KC_P, KC_BSPC
            ),

    [_FUNCTION] = LAYOUT(
            /* Left side                                                                                Right side */
            KC_F1,    KC_F2,   KC_F3,    KC_F4,  KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
            KC_F11,    KC_F12,   KC_F13,    KC_F14, KC_F15,          KC_F16,   KC_F17,    KC_F18,   KC_F19,   KC_F20,
            KC_F21,    KC_F22,     KC_F23,     KC_F24, XXXXXXX,        XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,

                                            TO(_ISRT),   XXXXXXX,        XXXXXXX, XXXXXXX
            ),
};

// tap dance stuff
qk_tap_dance_action_t tap_dance_actions[] = {
    // [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(set_oneshot_mods(MOD_BIT()), KC_SFT)
    //                               (tapped-key, held-key)
    [CURLY] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [BRAC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [ANGLE] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
    [COMM_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_COLON),
    [SLSH_DASH] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_MINUS),
    [DOT_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_UNDS),
};
