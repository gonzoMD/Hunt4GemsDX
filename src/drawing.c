#include "globals.h"

void DRAW_Screen(const char *data, const char border_col, const char screen_col)
{
    bordercolor(border_col);
    bgcolor(screen_col);
    memcpy(VIC_SCREENADR, data, 1000);
    memcpy(COLOR_RAM, data + 1000, 1000);
}
