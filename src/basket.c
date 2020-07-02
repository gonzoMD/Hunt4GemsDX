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

    VIC.spr_ena |= 0b10000111;
    VIC.spr_hi_x = 0b00000000;
    VIC.spr_exp_y |= 0b10000000;
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
        VIC.spr_hi_x |=0b00000100;
        if(x_pos>231)
        {
            VIC.spr_hi_x |=0b10000010;
            if(x_pos>255)
            {
                VIC.spr_hi_x |=0b00000001;
            }
            else
            {
                VIC.spr_hi_x &=0b11111110;
            }
        }
        else
        {
            VIC.spr_hi_x &=0b01111101;
        }
    }
    else
    {
        VIC.spr_hi_x &=0b11111011;
    }

    for(i=BASKET_LEFT;i<=BASKET_RIGHT;i++)
    {
        VIC.spr_pos[i].x = x_pos + i * 24;
    }
    VIC.spr_pos[BASKET_GUY].x = x_pos + 24;
}
