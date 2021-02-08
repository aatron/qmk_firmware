#include QMK_KEYBOARD_H

enum layer_names {
    _DVORAK,
    _LOWER,
    _RAISE,
    _MOUSE,
    _ADJUST,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// /* Qwerty
//  * ,-----------------------------------------------------------------------------------.
//  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
//  * |------+------+------+------+------+------|------+------+------+------+------+------|
//  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Ctrl |  `   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_QWERTY] = LAYOUT_ortho_4x12(
//   KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
//   MO(_MOUSE), KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
//   OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
//   KC_LCTL,       KC_GRV, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Lower |Space |Space |Space |Space |Raise | Mouse| Alt  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  KC_LCTL,  KC_LALT, KC_LGUI, LOWER, KC_SPC,   KC_SPC,  KC_SPC,  KC_SPC,  RAISE,  MO(_MOUSE), KC_RALT,   KC_RCTL \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  Up  |      |      |  Del | Bksp |
 * +------+------+------+------+------|------+------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Left | Down |Right |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      | Home |      | End  |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  OS  |Lower | PgUp | PgUp | PgDn | PgDn |Raise |Mouse | Alt  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_F1,    KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   XXXXXXX,  KC_UP,   XXXXXXX,  XXXXXXX,  KC_DEL, KC_BSPC,
  KC_F7,    KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_LEFT,  KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, KC_ENT,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,  XXXXXXX, KC_END,   XXXXXXX, XXXXXXX, KC_RSFT,
  KC_LCTL,  KC_LALT, KC_LGUI, LOWER,  KC_PGUP, KC_PGUP, KC_PGDN,  KC_PGDN, RAISE, MO(_MOUSE),   KC_RALT, KC_RCTL \
),

/* Raise
 * ,-------------------------------------------------------------------------------------.
 * |  ~   |  !    |   @   |   #  |   $  |   %  |      |      |      |      | Del  | Bksp |
 * |------+-------+-------+------+------+-------------+------+------+------+------+------|
 * |      |   ^   |   &   |   *  |   (  |   )  |      |      |      |      |      |Enter |
 * |------+-------+-------+------+------+------|------+------+------+------+------+------|
 * |Shift |   |   |   -   |   /  |   [  |   ]  |      |      |      |      |      | Shift|
 * |------+-------+-------+------+------+------+------+------+------+------+------+------|
 * |      |       |       |      |Space |Space |Space |Space |      |      |      |      |
 * `-------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DOLLAR, KC_PERCENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC,
  XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,   KC_RPRN,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
  KC_LSFT, KC_PIPE, KC_MINS, KC_SLSH, KC_LBRC,   KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,    KC_SPC,     KC_SPC,  KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

///* Adjust (Lower + Raise)
// * ,-----------------------------------------------------------------------------------.
// * |Taskmg|      |      |      |      |      |      |      |      |      |      |caltde|
// * |------+------+------+------+------+-------------+------+------+------+------+------|
// * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
// * |------+------+------+------+------+------|------+------+------+------+------+------|
// * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * |      |      |      |      |      |      |      |      |      |      |      | RESET|
// * `-----------------------------------------------------------------------------------'
// */
//[_NUMSYM] = LAYOUT_ortho_4x12(
//  TSKMGR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CALTDEL,
//  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
//  _______,  MUV_DE, MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
//),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      | MsUp |      |      |      |      | MsUp |      |      |  CAD |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | MsLe | MsDn | MsRi |      |      | MsLe | MsDn | MsRi |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      | Caps |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LtCk | LtCk | RtCk | RtCk |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, CALTDEL,
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

//    case KC_LSHIFT:
//      if (record->event.pressed) {
//        layer_on(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
  }
  return true;
}
