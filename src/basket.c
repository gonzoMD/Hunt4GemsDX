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

    VIC.spr_ena |= 0xF;
    VIC.spr_hi_x &=240;
    VIC.spr_exp_y |=0x8;
    x_pos = 150;
}

void movebasket()
{
    switch (getstate(PORT_B))
    {
        case JOY_LEFT:
            if (x_pos>24)
            {
                x_pos--;
            }
        break;
        case JOY_RIGHT:
            if (x_pos<273)
            {
                x_pos++;
            }
        break;
    }

    if(x_pos>207)
    {
        VIC.spr_hi_x |=4;
        if(x_pos>231)
        {
            VIC.spr_hi_x |=14;
            if(x_pos>255)
            {
                VIC.spr_hi_x |=15;
            }
            else
            {
                VIC.spr_hi_x &=254;
            }
        }
        else
        {
            VIC.spr_hi_x &=245;
        }
    }
    else
    {
        VIC.spr_hi_x &=251;
    }

    for(i=BASKET_LEFT;i<=BASKET_RIGHT;i++)
    {
        VIC.spr_pos[i].x = x_pos + i * 24;
    }
    VIC.spr_pos[BASKET_GUY].x = x_pos + 24;
}
