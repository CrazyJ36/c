/*
Not working on toshiba x86 need real libcaca package
works in termux android.
# Requires:
sudo apt-get install pkg-config libcaca-dev libcaca0 libpng-dev libslang2-dev zlib1g-dev

# To Compile program using libcaca (pkg-config statement must be after specifying file):
gcc prog.c `pkg-config --libs --cflags caca`
*/

#include <caca.h>

int main(void)
{
    caca_canvas_t *cv; caca_display_t *dp; caca_event_t ev;
    dp = caca_create_display(NULL);
    if(!dp) return 1;
    cv = caca_get_canvas(dp);
    caca_set_display_title(dp, "Hello!");
    caca_set_color_ansi(cv, CACA_BLACK, CACA_WHITE);
    caca_put_str(cv, 0, 0, "This is a message. Using libcaca Version:");

    const char *version = caca_get_version();
    caca_put_str(cv, 0, 1, &version[0]);

    caca_refresh_display(dp);
    caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, -1);
    caca_free_display(dp);
    return 0;
}
