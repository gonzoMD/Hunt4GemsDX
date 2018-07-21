#include "globals.h"
#include "joystick.h"

int x_pos;

void setupbasket()
{
    int i;
    VIC.spr0_color = VIC.spr1_color = VIC.spr2_color = COLOR_BROWN;
    for(i=0; i<3; i++)
    {
        *((unsigned char*)(VIC_SPRITEPTRADR + i)) = 4 + i;
    }

    VIC.spr0_y = VIC.spr1_y = VIC.spr2_y = 223;

    VIC.spr_ena = 0x7;
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
            VIC.spr_hi_x |=2;
            if(x_pos>255)
            {
                VIC.spr_hi_x |=1;
            }
            else
            {
                VIC.spr_hi_x &=254;
            }
        }
        else
        {
            VIC.spr_hi_x &=253;
        }
    }
    else
    {
        VIC.spr_hi_x &=251;
    }
    VIC.spr0_x = x_pos;
    VIC.spr1_x = x_pos + 24;
    VIC.spr2_x = x_pos + 48;
}
