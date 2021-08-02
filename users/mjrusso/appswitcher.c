#include "appswitcher.h"

void update_app_switcher(
    bool *active,
    uint16_t primary_trigger,
    uint16_t secondary_trigger,
    uint16_t keycode,
    keyrecord_t *record
) {

    uint16_t hold_key = KC_LGUI;

    // These keys have a special meaning when the app switcher is active.
    // Return early, to prevent hold_key from becoming unregistered.
    if (keycode == KC_ESC  || keycode == KC_DOT ||
        keycode == KC_PGUP || keycode == KC_PGDN ||
        keycode == KC_TAB  || keycode == KC_GRAVE
    ) {
      return;
    }

    if (keycode == primary_trigger || keycode == secondary_trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(hold_key);
            }
            if (keycode == primary_trigger) {
                tap_code(KC_TAB);
            } else {
                tap_code(KC_GRAVE);
            }
        } else {
            // Don't unregister hold_key until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code(hold_key);
        *active = false;
    }
}
