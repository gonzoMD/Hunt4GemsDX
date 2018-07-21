#include "globals.h"
#include "joystick.h"

int x_pos;
int i;

void setupbasket()
{
    for(i=0; i<3; i++)
    {
        *((unsigned char*)(VIC_SPRITEPTRADR + i)) = 4 + i;
        VIC.spr_color[i] = COLOR_BROWN;
        VIC.spr_pos[i].y = 223;
    }

    VIC.spr_ena |= 0x7;
    VIC.spr_hi_x &=248;
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

    for(i=0;i<3;i++)
    {
        VIC.spr_pos[i].x = x_pos + i * 24;
    }
}
