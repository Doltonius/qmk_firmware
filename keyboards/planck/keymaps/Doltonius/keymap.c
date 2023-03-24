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
#include "muse.h"

enum planck_layers { //
    _QWERTY,         //
    _LOWER,          //
    _RAISE,          //
    _VIM,            //
    _VIM_SHIFT,      //
    _FN,             //
    _ADJUST2,        //
    _QWERTY2,        //
    _CONFIG,         //
};

enum planck_keycodes {   //
    QWERTY = SAFE_RANGE, //
    BACKLIT,             //
    EXT_PLV,             //
    NEW_LINE,            //
    CUT_LINE,            //
    JOIN_LINE,           //
    DELETE_TO_END,       //
    CHANGE_LINE,         //
    GO_TO_END,           //
    FIND,                //
    DELETE_WORD,         //
    SELECT_LINE,         //
};

enum {
    TD_YY,
    TD_PP,
    TD_DD,
};

void dance_yy(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_TAP(X_C) SS_TAP(X_LEFT) SS_UP(X_LGUI));
    } else {
        SEND_STRING(SS_LGUI("c"));
    }
}

void dance_pp(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_ENT) SS_LGUI("v"));
    } else {
        SEND_STRING(SS_LGUI("v"));
    }
}

void dance_dd(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_TAP(X_X) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_TAP(X_BSPC) SS_TAP(X_DOWN) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
    } else {
        SEND_STRING(SS_LGUI("x"));
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_YY] = ACTION_TAP_DANCE_FN(dance_yy),
    [TD_PP] = ACTION_TAP_DANCE_FN(dance_pp),
    [TD_DD] = ACTION_TAP_DANCE_FN(dance_dd),
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_grid(                                                                          //
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,                         //
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSLS,                     //
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_SFTENT,       //
        MO(_FN), KC_LALT, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_HYPR, KC_RALT, KC_RCTL, MO(_FN) //
        ),                                                                                                   //

    [_LOWER] = LAYOUT_planck_grid(                                                                                      //
        KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_BSPC,         //
        KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL,                  //
        _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, _______,              //
        _______, _______, _______, _______, _______, G(KC_SPC), G(KC_SPC), TO(_VIM), KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT //
        ),

    [_RAISE] = LAYOUT_planck_grid(                                                                                //
        KC_DEL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,                              //
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_RBRC, KC_QUOT,           //
        _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL, _______,         //
        _______, _______, _______, _______, TO(_VIM), KC_SPC, KC_SPC, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT //
        ),

    [_VIM] = LAYOUT_planck_grid(                                                                                                       //
        _______, KC_ESC, A(KC_RIGHT), A(KC_RIGHT), LSG(KC_Z), _______, TD(TD_YY), G(KC_Z), TO(_QWERTY), NEW_LINE, TD(TD_PP), KC_BSPC,  //
        LMCTL, GO_TO_END, _______, TD(TD_DD), FIND, G(KC_UP), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, G(KC_G), _______,                     //
        MO(_VIM_SHIFT), _______, DELETE_WORD, CHANGE_LINE, SELECT_LINE, A(KC_LEFT), G(KC_G), _______, G(KC_Z), G(KC_Y), FIND, LTVSENT, //
        MO(_FN), LMALT, LMALT, LMGUI, KC_PGUP, KC_SPC, KC_SPC, KC_PGDN, LMGUI, LMALT, LMCTL, MO(_FN)                                   //
        ),

    [_VIM_SHIFT] = LAYOUT_planck_grid(                                                                                            //
        _______, KC_ESC, A(KC_RIGHT), A(KC_RIGHT), LSG(KC_Z), _______, G(KC_C), G(KC_Z), TO(_QWERTY), NEW_LINE, G(KC_V), KC_BSPC, //
        LMCTL, GO_TO_END, _______, C(KC_K), FIND, G(KC_DOWN), KC_LEFT, JOIN_LINE, KC_UP, KC_RIGHT, G(KC_G), _______,              //
        KC_TRNS, _______, DELETE_WORD, DELETE_TO_END, SELECT_LINE, A(KC_LEFT), G(KC_G), _______, G(KC_Z), G(KC_Y), FIND, KC_ENT,  //
        MO(_FN), LMALT, LMALT, LMGUI, KC_PGUP, KC_SPC, KC_SPC, KC_PGDN, LMGUI, LMALT, LMCTL, MO(_FN)                              //
        ),

    [_FN] = LAYOUT_planck_grid(                                                                                       //
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PMNS,                                  //
        KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_4, KC_5, KC_6, KC_PCMM, KC_PPLS,                        //
        KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_1, KC_2, KC_3, KC_PEQL, KC_ENT,                        //
        KC_TRNS, MO(_CONFIG), MO(_QWERTY2), KC_NO, KC_NO, KC_SPC, KC_SPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PDOT, KC_TRNS //
        ),

    [_ADJUST2] = LAYOUT_planck_grid(                                                                               //
        _______, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,     //
        _______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, _______, _______, _______, _______,     //
        _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______,        //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ //
        ),

    [_QWERTY2] = LAYOUT_planck_grid(                                                                             //
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,                             //
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSLS,                         //
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLASH), KC_SFTENT,   //
        _______, _______, _______, _______, _______, KC_SPC, KC_SPC, _______, _______, _______, _______, _______ //
        ),

    [_CONFIG] = LAYOUT_planck_grid(                                                                                //
        _______, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,     //
        _______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, _______, _______, _______, _______,     //
        _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______,        //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ //
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
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
        case NEW_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_ENT));
            } else {
                layer_move(_QWERTY);
            }
            break;
        case CUT_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_TAP(X_BSPC) SS_UP(X_LGUI) SS_TAP(X_BSPC) SS_TAP(X_DOWN) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
            }
            break;
        case CHANGE_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_DOWN(X_LGUI) SS_TAP(X_BSPC) SS_UP(X_LGUI));
            } else {
                SEND_STRING(SS_TAP(X_BSPC));
                layer_move(_QWERTY);
            }
        case JOIN_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_SPC) SS_TAP(X_DEL));
            }
            break;
        case DELETE_TO_END:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_TAP(X_BSPC) SS_UP(X_LSFT) SS_UP(X_LGUI));
            } else {
                layer_move(_QWERTY);
            }
            break;
        case GO_TO_END:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI));
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
        case DELETE_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_TAP(X_BSPC) SS_UP(X_LALT));
            }
            break;
        case SELECT_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_UP(X_LGUI));
            }
            break;
    }
    return true;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

extern rgblight_config_t rgblight_config;

void keyboard_post_init_user(void) {
    rgblight_setrgb(0xAA, 0x77, 0x44); //
}

enum combo_events {
    JK_ESC, //
    QUOT,   //
    DQUOT,  //
    LRB,    //
    LB,
    RB,
    LRS, //
    LS,
    RS,
    LRP, //
    LP,
    RP,
    TOVIM, //
    EXCLAMATION,
    /* LPARENS, */
    /* RPARENS, */
    /* LANGLE, */
    /* RANGLE, */
    /* LSQUARE, */
    /* RSQUARE, */
    /* LCURLY, */
    /* RCURLY, */
    /* ATT, */
    /* HASH, */
    /* DOLLAR, */
    /* PERCENT, */
    /* CARET, */
    /* AMPER, */
    /* STAR, */
    /* EQUAL, */
    /* PLUS, */
    /* MINUS, */
    /* QUESTION, */
    /* PIPE, */
    /* SLASH, */
    COMBO_LENGTH, //
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM jk_esc[]      = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM quot[]        = {KC_SCLN, KC_BSLS, COMBO_END};
const uint16_t PROGMEM dquot[]       = {KC_L, KC_SCLN, KC_BSLS, COMBO_END};
const uint16_t PROGMEM lrb[]         = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM lb[]          = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM rb[]          = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM lrs[]         = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM ls[]          = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM rs[]          = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM lrp[]         = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM lp[]          = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM rp[]          = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM tovim[]       = {KC_PGUP, KC_PGDN, COMBO_END};
const uint16_t PROGMEM exclamation[] = {KC_Q, KC_W, COMBO_END};
/* const uint16_t PROGMEM lparens[]     = {KC_L, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM rparens[]     = {KC_R, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM langle[]      = {KC_L, KC_A, COMBO_END}; */
/* const uint16_t PROGMEM rangle[]      = {KC_R, KC_A, COMBO_END}; */
/* const uint16_t PROGMEM lsquare[]     = {KC_L, KC_S, COMBO_END}; */
/* const uint16_t PROGMEM rsquare[]     = {KC_R, KC_S, COMBO_END}; */
/* const uint16_t PROGMEM lcurly[]      = {KC_L, KC_C, COMBO_END}; */
/* const uint16_t PROGMEM rcurly[]      = {KC_R, KC_C, COMBO_END}; */
/* const uint16_t PROGMEM at[]          = {KC_A, KC_M, COMBO_END}; */
/* const uint16_t PROGMEM hash[]        = {KC_H, KC_S, COMBO_END}; */
/* const uint16_t PROGMEM dollar[]      = {KC_D, KC_L, COMBO_END}; */
/* const uint16_t PROGMEM percent[]     = {KC_P, KC_C, COMBO_END}; */
/* const uint16_t PROGMEM caret[]       = {KC_R, KC_T, COMBO_END}; */
/* const uint16_t PROGMEM amper[]       = {KC_A, KC_D, COMBO_END}; */
/* const uint16_t PROGMEM star[]        = {KC_S, KC_R, COMBO_END}; */
/* const uint16_t PROGMEM equal[]       = {KC_E, KC_Q, COMBO_END}; */
/* const uint16_t PROGMEM plus[]        = {KC_P, KC_S, COMBO_END}; */
/* const uint16_t PROGMEM minus[]       = {KC_M, KC_S, COMBO_END}; */
/* const uint16_t PROGMEM question[]    = {KC_Q, KC_N, COMBO_END}; */
/* const uint16_t PROGMEM pipe[]        = {KC_P, KC_E, COMBO_END}; */
/* const uint16_t PROGMEM slash[]       = {KC_S, KC_L, COMBO_END}; */

combo_t key_combos[] = {
    [JK_ESC]      = COMBO_ACTION(jk_esc), //
    [QUOT]        = COMBO_ACTION(quot),   //
    [DQUOT]       = COMBO_ACTION(dquot),  //
    [LRB]         = COMBO_ACTION(lrb),    //
    [LB]          = COMBO_ACTION(lb),
    [RB]          = COMBO_ACTION(rb),
    [LRS]         = COMBO_ACTION(lrs), //
    [LS]          = COMBO_ACTION(ls),
    [RS]          = COMBO_ACTION(rs),
    [LRP]         = COMBO_ACTION(lrp), //
    [LP]          = COMBO_ACTION(lp),
    [RP]          = COMBO_ACTION(rp),
    [TOVIM]       = COMBO_ACTION(tovim), //
    [EXCLAMATION] = COMBO_ACTION(exclamation),
    /* [LPARENS]     = COMBO_ACTION(lparens), */
    /* [RPARENS]     = COMBO_ACTION(rparens), */
    /* [LANGLE]      = COMBO_ACTION(langle), */
    /* [RANGLE]      = COMBO_ACTION(rangle), */
    /* [LSQUARE]     = COMBO_ACTION(lsquare), */
    /* [RSQUARE]     = COMBO_ACTION(rsquare), */
    /* [LCURLY]      = COMBO_ACTION(lcurly), */
    /* [RCURLY]      = COMBO_ACTION(rcurly), */
    /* [ATT]         = COMBO_ACTION(at), */
    /* [HASH]        = COMBO_ACTION(hash), */
    /* [DOLLAR]      = COMBO_ACTION(dollar), */
    /* [PERCENT]     = COMBO_ACTION(percent), */
    /* [CARET]       = COMBO_ACTION(caret), */
    /* [AMPER]       = COMBO_ACTION(amper), */
    /* [STAR]        = COMBO_ACTION(star), */
    /* [PLUS]        = COMBO_ACTION(plus), */
    /* [EQUAL]       = COMBO_ACTION(equal), */
    /* [MINUS]       = COMBO_ACTION(minus), */
    /* [QUESTION]    = COMBO_ACTION(question), */
    /* [PIPE]        = COMBO_ACTION(pipe), */
    /* [SLASH]       = COMBO_ACTION(slash), */
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
            /* case LPARENS: */
            /*     if (pressed) { */
            /*        SEND_STRING("("); */
            /*     } */
            /*     break; */
            /* case RPARENS: */
            /*     if (pressed) { */
            /*        SEND_STRING(")"); */
            /*     } */
            /*     break; */
            /* case LANGLE: */
            /*     if (pressed) { */
            /*        SEND_STRING("<"); */
            /*     } */
            /*     break; */
            /* case RANGLE: */
            /*     if (pressed) { */
            /*        SEND_STRING(">"); */
            /*     } */
            /*     break; */
            /* case LSQUARE: */
            /*     if (pressed) { */
            /*        SEND_STRING("["); */
            /*     } */
            /*     break; */
            /* case RSQUARE: */
            /*     if (pressed) { */
            /*        SEND_STRING("]"); */
            /*     } */
            /*     break; */
            /* case LCURLY: */
            /*     if (pressed) { */
            /*        SEND_STRING("{"); */
            /*     } */
            /*     break; */
            /* case RCURLY: */
            /*     if (pressed) { */
            /*        SEND_STRING("}"); */
            /*     } */
            /*     break; */
            /* case ATT: */
            /*     if (pressed) { */
            /*        SEND_STRING("@"); */
            /*     } */
            /*     break; */
            /* case HASH: */
            /*     if (pressed) { */
            /*        SEND_STRING("#"); */
            /*     } */
            /*     break; */
            /* case DOLLAR: */
            /*     if (pressed) { */
            /*        SEND_STRING("$"); */
            /*     } */
            /*     break; */
            /* case PERCENT: */
            /*     if (pressed) { */
            /*        SEND_STRING("%"); */
            /*     } */
            /*     break; */
            /* case CARET: */
            /*     if (pressed) { */
            /*        SEND_STRING("^"); */
            /*     } */
            /*     break; */
            /* case AMPER: */
            /*     if (pressed) { */
            /*        SEND_STRING("&"); */
            /*     } */
            /*     break; */
            /* case STAR: */
            /*     if (pressed) { */
            /*        SEND_STRING("*"); */
            /*     } */
            /*     break; */
            /* case PLUS: */
            /*     if (pressed) { */
            /*        SEND_STRING("+"); */
            /*     } */
            /*     break; */
            /* case EQUAL: */
            /*     if (pressed) { */
            /*        SEND_STRING("="); */
            /*     } */
            /*     break; */
            /* case MINUS: */
            /*     if (pressed) { */
            /*        SEND_STRING("-"); */
            /*     } */
            /*     break; */
            /* case QUESTION: */
            /*     if (pressed) { */
            /*        SEND_STRING("?"); */
            /*     } */
            /*     break; */
            /* case PIPE: */
            /*     if (pressed) { */
            /*        SEND_STRING("|"); */
            /*     } */
            /*     break; */
            /* case SLASH: */
            /*     if (pressed) { */
            /*        SEND_STRING("/"); */
            /*     } */
            /*     break; */
    }
}
