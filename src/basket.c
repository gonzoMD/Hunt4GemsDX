#include "globals.h"
#include "joystick.h"
#include "basket.h"

int x_pos;
int i;

void setupbasket()
{
    for(i=BASKET_LEFT; i<=BASKET_RIGHT; i++)
    {
        *((unsigned char*)(VIC_SPRITEPTRADR + i)) = 4 + i;
        VIC.spr_color[i] = COLOR_BROWN;
        VIC.spr_pos[i].y = 205;
    }
    *((unsigned char*)(VIC_SPRITEPTRADR + BASKET_GUY)) = 7;
    VIC.spr_color[BASKET_GUY] = COLOR_LIGHTRED;
    VIC.spr_pos[BASKET_GUY].y = 191;

    VIC.spr_ena |= 135;     // 10000111
    VIC.spr_hi_x = 0;
    VIC.spr_exp_y |= 128;   // 10000000
    x_pos = 150;
}

void movebasket()
{
    switch (getstate(PORT_B))
    {
        case JOY_LEFT:
            if (x_pos>24)
            {
                x_pos-=3;
            }
        break;
        case JOY_RIGHT:
            if (x_pos<273)
            {
                x_pos+=3;
            }
        break;
    }

    if(x_pos>207)
    {
        VIC.spr_hi_x |= 4;              // 00000100
        if(x_pos>231)
        {
            VIC.spr_hi_x |= 134;        // 10000110
            if(x_pos>255)
            {
                VIC.spr_hi_x |= 135;    // 10000111    
            }
            else
            {
                VIC.spr_hi_x &= 254;    // 11111110
            }
        }
        else
        {
            VIC.spr_hi_x &= 124;        // 01111100
        }
    }
    else
    {
        VIC.spr_hi_x &= 248;            // 11111000
    }

    for(i=BASKET_LEFT;i<=BASKET_RIGHT;i++)
    {
        VIC.spr_pos[i].x = x_pos + i * 24;
    }
    VIC.spr_pos[BASKET_GUY].x = x_pos + 24;
}
