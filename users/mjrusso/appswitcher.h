#pragma once

#include QMK_KEYBOARD_H

// Enables the use of the MacOS application switcher, without requiring the
// user to hold down the ⌘ key.
//
// On the first tap of `primary_trigger`, ⌘-Tab is issued, and the ⌘ modifier
// is held until a non-blessed key is pressed. Likewise, `secondary_trigger`
// behaves in a similar fashion, but sends ⌘-`, which cycles through apps in
// the reverse direction. (Alternatively, if the application switcher is not
// active, and the user taps `secondary_trigger`, this will instead cycle
// through the windows of the currently-active application.)
//
// Some keys have special meaning when the application switcher is active. For
// example, both ⌘-Escape and ⌘-. dismiss the application switcher (without
// changing the active app), and ⌘-PgUp/ ⌘-PgDn move focus to the first/last
// app in the list. The implementation ensures that these keyboard shortcuts
// will work as expected.
//
// Note that this has been adapted from `update_swapper` in Callum's userspace:
// https://github.com/callum-oakley/qmk_firmware/blob/master/users/callum/swapper.c

void update_app_switcher(
    bool *active,
    uint16_t primary_trigger,
    uint16_t secondary_trigger,
    uint16_t keycode,
    keyrecord_t *record
);
