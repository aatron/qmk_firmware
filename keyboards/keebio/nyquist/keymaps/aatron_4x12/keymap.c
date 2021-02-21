#include QMK_KEYBOARD_H

// TODO: Space Cadet Shift - KC_LSPO, KC_RSPC

enum layer_names {
    _DVORAK,
    _LOWER,
    _RAISE,
    _MOUSE,
    //_ADJUST,
    _NUMPAD,
    _SYMBOL
    //_LEFT_OS
    //_RSHIFT
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  NUMPAD,
  SYMBOL
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

// Defines the combo keys
enum combos {
  //DoubleAlt_OS,
  DoubleShift_Caps
  //Toggle_RGB
};

//const uint16_t PROGMEM os_combo[] = {KC_LALT, KC_RALT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};
//const uint16_t PROGMEM toggle_rgb_combo[] = {KC_ESC, KC_BSPC, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  // Left Alt + Right Alt = OS Key
  //[DoubleAlt_OS] = COMBO(os_combo, KC_LGUI),
  [DoubleShift_Caps] = COMBO(caps_combo, KC_CAPS)
  //[Toggle_RGB] = COMBO(toggle_rgb_combo, RGB_TOG)
};

//// Define RGB lights
//// Light LEDs 6              to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
//const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {1, 3, HSV_RED},       // Light 3 LEDs, starting with LED 1
//    {7, 3, HSV_RED}       // Light 3 LEDs, starting with LED 6
//);
//// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
//const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {4, 1, HSV_CYAN},
//    {10, 1, HSV_CYAN}
//);
//// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
//const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {5, 1, HSV_PURPLE},
//    {11, 1, HSV_PURPLE}
//);
//// Light LEDs 13 & 14 in green when keyboard layer 3 is active
//const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {6, 1, HSV_GREEN},
//    {12, 1, HSV_GREEN}
//);
//
//
//const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//    my_capslock_layer,
//    my_layer1_layer,    // Overrides caps lock layer
//    my_layer2_layer,    // Overrides other layers
//    my_layer3_layer     // Overrides other layers
//);

//void keyboard_post_init_user(void) {
//    // Enable the LED layers
//    rgblight_layers = my_rgb_layers;
//}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  OS  |Lower |NumPad|Symbol|Space |Space |Raise | Mouse| Alt  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,     KC_L,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_O,    KC_E,  KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,     KC_S,    KC_ENT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,  KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,     KC_Z,    KC_RSFT, \
  KC_LCTL, KC_LALT, KC_LGUI, LOWER, NUMPAD, SYMBOL, KC_SPC,  KC_SPC,   RAISE,  MO(_MOUSE), KC_RALT, KC_RCTL \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |  Del | Bksp |
 * +------+------+------+------+------|------+------+------+------+------+------+------|
 * |      |      | PgUp |  UP  |      |      |      | Left | Down |Right | PgUp |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      | PgDn | DOWN |      |      |      | Home |      | End  | PgDn | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |      |      |NUMPAD|SYMBOL|      |      |Raise |Mouse | Alt  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP,    XXXXXXX,  KC_DEL, KC_BSPC,
  XXXXXXX, XXXXXXX, KC_PGUP,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_RIGHT, KC_PGUP,  KC_ENT,
  KC_LSFT, XXXXXXX, KC_PGDN, KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,     KC_END, KC_PGDN, KC_RSFT,
  KC_LCTL, KC_LALT, XXXXXXX, _______,  NUMPAD, SYMBOL,  XXXXXXX, XXXXXXX,   RAISE, MO(_MOUSE), KC_RALT, KC_RCTL \
),

/* Raise
 * ,-------------------------------------------------------------------------------------.
 * |  F1  |   F2  |   F3  |  F4  |   F5 |  F6  |      |      |      |      | Del  | Bksp |
 * |------+-------+-------+------+------+-------------+------+------+------+------+------|
 * |  F7  |   F8  |   F9  |  F10 |   F11|  F12 |      |      |      |      |      |Enter |
 * |------+-------+-------+------+------+------|------+------+------+------+------+------|
 * |Shift |       |       |      |      |      |      |      |      |      |      | Shift|
 * |------+-------+-------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt   |       |      |      |      |      |      |      |Mouse | Alt  | Ctrl |
 * `-------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_DEL,  KC_BSPC,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_ENT,
  KC_LSFT, KC_PIPE, KC_MINS, KC_SLSH, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_RSFT,
  KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_MOUSE), KC_RALT, KC_RCTL
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * | RGB  |      |      | MsUp |      |      |      |      | MsUp |      |      |  CAD |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | MsLe | MsDn | MsRi |      |      | MsLe | MsDn | MsRi |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Caps |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LtCk | LtCk | RtCk | RtCk |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12(
  RGB_TOG, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, CALTDEL,
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Number Pad (NumPad)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   7  |   8  |   9  |  +=  |Delete| Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   4  |   5  |   6  |  --  |      |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |   1  |   2  |   3  |  /   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Cntrl|      |      |      |      |      |   0  |   0  |   .  |  *   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,   KC_EQL,  KC_DEL,  KC_BSPC,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,   KC_MINS, KC_EQL,  KC_ENT,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,   KC_SLSH, XXXXXXX, XXXXXXX,
  KC_LCTL, XXXXXXX, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT, KC_PAST, XXXXXXX, XXXXXXX
),

/* Symbol
 * ,-------------------------------------------------------------------------------------.
 * |      |       |       |      |      |      |      |   ~  |  (   |  )   | Del  | Bksp |
 * |------+-------+-------+------+------+-------------+------+------+------+------+------|
 * |      |       |       |      |      |      |      |      |  [   |  ]   |  |   |Enter |
 * |------+-------+-------+------+------+------|------+------+------+------+------+------|
 * |Shift |       |       |      |      |      |      |      |      |      |      | Shift|
 * |------+-------+-------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt   |       |      |      |      |Space |Space |      |Mouse | Alt  | Ctrl |
 * `-------------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_GRV, KC_LPRN, KC_RPRN,    KC_DEL,  KC_BSPC,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,    KC_BSLS, KC_ENT,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_RSFT,
  KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,  KC_SPC, XXXXXXX, MO(_MOUSE), KC_RALT, KC_RCTL
),

///* Left OS
// * ,-----------------------------------------------------------------------------------.
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * |------+------+------+------+------+-------------+------+------+------+------+------|
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * |------+------+------+------+------+------|------+------+------+------+------+------|
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * `-----------------------------------------------------------------------------------'
// */
//[_LEFT_OS] = LAYOUT_ortho_4x12(
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//  _______, _______, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______
//),

///* Right Shift
// * ,-----------------------------------------------------------------------------------.
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * |------+------+------+------+------+-------------+------+------+------+------+------|
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * |------+------+------+------+------+------|------+------+------+------+------+------|
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * |      |      |      |      |      |      |      |      |      |      |      |      |
// * `-----------------------------------------------------------------------------------'
// */
//[_RSHIFT] = LAYOUT_ortho_4x12(
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//),

};

// IF KC_LGUI pressed and _NUMPAD activated then return false from KC_LGUI

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  //rgblight_enable();
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        //update_tri_layer(_LOWER, _LEFT_OS, _NUMPAD);
      } else {
        layer_off(_LOWER);
        //rgblight_enable();
        //update_tri_layer(_LOWER, _LEFT_OS, _NUMPAD);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        //update_tri_layer(_LOWER, _LEFT_OS, _NUMPAD);
      } else {
        layer_off(_NUMPAD);
        //update_tri_layer(_LOWER, _LEFT_OS, _NUMPAD);
      }
      return false;
      break;
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
      } else {
        layer_off(_SYMBOL);
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
  }
  return true;
}
