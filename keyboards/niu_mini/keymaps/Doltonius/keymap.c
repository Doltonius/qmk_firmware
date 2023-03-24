/* Copyright 2015-2021 Jack Humbert
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

#define LMGUI LM(_QWERTY2, MOD_LGUI)
#define LMALT LM(_QWERTY2, MOD_LALT)
#define LMCTL LM(_QWERTY2, MOD_LCTL)
#define LTVSENT LT(_VIM_SHIFT, KC_ENT)

#include QMK_KEYBOARD_H

enum planck_layers {  //
    _QWERTY,          //
    _LOWER,           //
    _RAISE,           //
    _VIM,             //
    _VIM_SHIFT,       //
    _FN,              //
    _QWERTY2,         //
    _CONFIG,          //
};

enum planck_keycodes {    //
    QWERTY = SAFE_RANGE,  //
    BACKLIT,              //
    EXT_PLV,              //
    GO_TO_END,            //
    FIND,                 //
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_mit( //
        KC_TAB       , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  , KC_Y  , KC_U , KC_I   , KC_O   , KC_P    , KC_BSPC  , //
        KC_LCTL      , KC_A   , KC_S   , KC_D   , KC_F , KC_G  , KC_H  , KC_J , KC_K   , KC_L   , KC_SCLN , KC_BSLS  , //
        OSM(MOD_LSFT), KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_N  , KC_M , KC_COMM, KC_DOT , KC_SLASH, KC_SFTENT, //
        MO(_FN)      , KC_LALT, KC_LALT, KC_LGUI, LOWER, KC_SPC,  RAISE, KC_HYPR, KC_RALT, KC_RCTL , MO(_FN)    //
    ), //

    [_LOWER] = LAYOUT_planck_mit( //
        KC_ESC , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC  , KC_CIRC  , KC_AMPR , KC_ASTR, KC_LCBR, KC_RCBR, KC_BSPC, //
        KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5    , KC_F6    , KC_LPRN , KC_RPRN, KC_UNDS, KC_PLUS,  KC_DEL , //
        _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11   , KC_F12   , KC_LBRC , KC_RBRC, KC_UNDS, KC_PLUS, _______, //
        _______, _______, _______, _______, _______, G(KC_SPC),  TO(_VIM), KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT  //
    ),

    [_RAISE] = LAYOUT_planck_mit( //
        KC_DEL , KC_1   , KC_2   , KC_3   , KC_4    , KC_5  , KC_6   , KC_7   , KC_8   , KC_9    , KC_0   , KC_BSPC, //
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5 , KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_RBRC, KC_QUOT, //
        _______, KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11, KC_F12 , KC_LCBR, KC_RCBR, KC_MINS , KC_EQL , _______, //
        _______, _______, _______, _______, TO(_VIM), KC_SPC,  _______, KC_MPLY, KC_VOLD , KC_VOLU, KC_MNXT  //
    ),

    [_VIM] = LAYOUT_planck_mit( //
        _______       , KC_ESC   , A(KC_RIGHT), A(KC_RIGHT), LSG(KC_Z)  , _______   , G(KC_C), G(KC_Z), TO(_QWERTY), _______, G(KC_V), KC_BSPC, //
        LMCTL         , GO_TO_END, _______    , G(KC_X)  , FIND       , G(KC_UP)  , KC_LEFT  , KC_DOWN, KC_UP      , KC_RIGHT, G(KC_G)  , _______, //
        MO(_VIM_SHIFT), _______  , A(KC_BSPC), G(KC_BSPC), G(KC_V), A(KC_LEFT), G(KC_G)  , _______, G(KC_Z)    , G(KC_Y) , FIND     , LTVSENT, //
        MO(_FN)       , LMALT    , LMALT      , LMGUI      , KC_PGUP    ,  KC_SPC   , KC_PGDN, LMGUI      , LMALT   , LMCTL    , MO(_FN)  //
    ),

    [_VIM_SHIFT] = LAYOUT_planck_mit( //
        _______, KC_ESC   , A(KC_RIGHT), A(KC_RIGHT)  , LSG(KC_Z)  , _______   , G(KC_C), G(KC_Z)  , TO(_QWERTY), _______, G(KC_V), KC_BSPC, //
        LMCTL  , GO_TO_END, _______    , C(KC_K)      , FIND       , G(KC_DOWN), KC_LEFT, _______, KC_UP      , KC_RIGHT, G(KC_G), _______, //
        KC_TRNS, _______  , A(KC_BSPC), G(KC_BSPC), G(KC_V), A(KC_LEFT), G(KC_G), _______  , G(KC_Z)    , G(KC_Y) , FIND   , KC_ENT , //
        MO(_FN), LMALT    , LMALT      , LMGUI        , KC_PGUP    ,  KC_SPC , KC_PGDN  , LMGUI      , LMALT   , LMCTL  , MO(_FN)  //
    ),

    [_FN] = LAYOUT_planck_mit( //
        KC_ESC , KC_1       , KC_2        , KC_3 , KC_4  , KC_5  , KC_6  , KC_7   , KC_8   , KC_9   , KC_0   , KC_PMNS, //
        KC_CAPS, KC_F1      , KC_F2       , KC_F3, KC_F4 , KC_F5 , KC_F6 , KC_4   , KC_5   , KC_6   , KC_PCMM, KC_PPLS, //
        KC_NO  , KC_F7      , KC_F8       , KC_F9, KC_F10, KC_F11, KC_F12, KC_1   , KC_2   , KC_3   , KC_PEQL, KC_ENT , //
        KC_TRNS, MO(_CONFIG), MO(_QWERTY2), KC_NO, KC_NO ,  KC_SPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PDOT, KC_TRNS  //
    ),

    [_QWERTY2] = LAYOUT_planck_mit( //
        KC_TAB       , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T  , KC_Y  , KC_U   , KC_I   , KC_O   , KC_P            , KC_BSPC  , //
        KC_LCTL      , KC_A   , KC_S   , KC_D   , KC_F   , KC_G  , KC_H  , KC_J   , KC_K   , KC_L   , KC_SCLN         , KC_BSLS  , //
        OSM(MOD_LSFT), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B  , KC_N  , KC_M   , KC_COMM, KC_DOT , RSFT_T(KC_SLASH), KC_SFTENT, //
        _______      , _______, _______, _______, _______,  KC_SPC, _______, _______, _______, _______         , _______    //
    ),

    [_CONFIG] = LAYOUT_planck_mit( //
        _______, RESET  , DEBUG  , RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD , RGB_VAI, RGB_VAD, KC_DEL , //
        _______, _______, MU_MOD , AU_ON  , AU_OFF , AG_NORM, AG_SWAP, QWERTY , _______ , _______, _______, _______, //
        _______, MUV_DE , MUV_IN , MU_ON  , MU_OFF , MI_ON  , MI_OFF , TERM_ON, TERM_OFF, _______, _______, _______, //
        _______, _______, _______, _______,  _______, _______, _______, _______ , _______, _______, _______  //
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _VIM:
            rgblight_setrgb(0x00, 0xff, 0x44);
            break;
        case _VIM_SHIFT:
            rgblight_setrgb(0x00, 0xff, 0x44);
            break;
        case _CONFIG:
            rgblight_setrgb(0xFF, 0x44, 0x00);
            break;
        default:
            rgblight_setrgb(0xAA, 0x77, 0x44);
            break;
    }
    return state;
    /* return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST2); */
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GO_TO_END:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_LGUI)
                    SS_TAP(X_RIGHT)
                    SS_UP(X_LGUI)
                );
            } else {
                layer_move(_QWERTY);
            }
            break;
        case FIND:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("f"));
            } else {
                layer_move(_QWERTY);
            }
            break;
    }
    return true;
}

extern rgblight_config_t rgblight_config;

void keyboard_post_init_user(void) {
    rgblight_setrgb(0xAA, 0x77, 0x44); //
}

enum combo_events {
    JK_ESC,        //
    QUOT,          //
    DQUOT,         //
    LRB,           //
    LB,
    RB,
    LRS,           //
    LS,
    RS,
    LRP,           //
    LP,
    RP,
    TOVIM,         //
    EXCLAMATION,
    COMBO_LENGTH,  //
};

uint16_t COMBO_LEN = COMBO_LENGTH;  // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM jk_esc[]      = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM quot[]        = {KC_SCLN, KC_BSLS, COMBO_END};
const uint16_t PROGMEM dquot[]       = {KC_L, KC_SCLN, KC_BSLS, COMBO_END};
const uint16_t PROGMEM lrb[]         = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM lb[]         = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM rb[]         = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM lrs[]         = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM ls[]         = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM rs[]         = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM lrp[]         = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM lp[]         = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM rp[]         = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM tovim[]       = {KC_PGUP, KC_PGDN, COMBO_END};
const uint16_t PROGMEM exclamation[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
    [JK_ESC]      = COMBO_ACTION(jk_esc),  //
    [QUOT]        = COMBO_ACTION(quot),    //
    [DQUOT]       = COMBO_ACTION(dquot),   //
    [LRB]         = COMBO_ACTION(lrb),     //
    [LB]          = COMBO_ACTION(lb),
    [RB]          = COMBO_ACTION(rb),
    [LRS]         = COMBO_ACTION(lrs),     //
    [LS]          = COMBO_ACTION(ls),
    [RS] = COMBO_ACTION(rs),
    [LRP]         = COMBO_ACTION(lrp),     //
    [LP] = COMBO_ACTION(lp),
    [RP] = COMBO_ACTION(rp),
    [TOVIM]       = COMBO_ACTION(tovim),   //
    [EXCLAMATION] = COMBO_ACTION(exclamation),
};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case JK_ESC:
            if (pressed) {
                SEND_STRING(SS_TAP(X_ESC));
            }
            break;
        case QUOT:
            if (pressed) {
                SEND_STRING("'");
            }
            break;
        case DQUOT:
            if (pressed) {
                SEND_STRING("\"");
            }
            break;
        case LRB:
            if (pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
            }
            break;
        case LB:
            if (pressed) {
              SEND_STRING("{");
            }
            break;
        case RB:
            if (pressed) {
              SEND_STRING("}");
            }
            break;
        case LRS:
            if (pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;
        case LS:
            if (pressed) {
              SEND_STRING("[");
            }
            break;
        case RS:
            if (pressed) {
              SEND_STRING("]");
            }
            break;
        case LRP:
            if (pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            break;
        case LP:
            if (pressed) {
              SEND_STRING("(");
            }
            break;
        case RP:
            if (pressed) {
              SEND_STRING(")");
            }
            break;
        case TOVIM:
            if (pressed) {
                layer_move(_QWERTY);
            }
            break;
        case EXCLAMATION:
            if (pressed) {
                SEND_STRING("!");
            }
            break;
    }
}
