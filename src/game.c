#include "globals.h"
#include "drawing.h"
#include "data.h"

int gametime=75, level=1, score=0, x=150;

void preparegame()
{
    clock_t t1, t2;
    int i;

    VIC.spr0_x = 175;
    VIC.spr0_y = 165;
    VIC.spr0_color = COLOR_RED;
    VIC.spr_ena = 1;
    DRAW_Screen(SCREEN_prepare, COLOR_BLACK, COLOR_BLACK);
    gotoxy(23,6);
    cprintf("%2d", level);

    for(i=3; i>0; i--)
    {
        t2=clock()+CLOCKS_PER_SEC;
        *((unsigned char*)VIC_SPRITEPTRADR) = i;
        do
        {
            t1=clock();
        }while(t1<t2);
    }

    VIC.spr0_x = 160;
    VIC.spr0_y = 155;
    VIC.spr_exp_x = VIC.spr_exp_y=1;
    *((unsigned char*)VIC_SPRITEPTRADR)= 0;

    t2=clock()+(CLOCKS_PER_SEC*2);
    do
    {
        t1=clock();
    } while(t1<t2);
    VIC.spr_ena = 0;
    VIC.spr_exp_x = VIC.spr_exp_y=0;
}

void ingame()
{
    clock_t t1, t2;
    int i;


    for(level=1;level<=10;level++)
    {
        preparegame();
        VIC.spr0_color = VIC.spr1_color = VIC.spr2_color = COLOR_BROWN;
        for(i=0;i<3;i++)
            *((unsigned char*)(VIC_SPRITEPTRADR+i)) = 4+i;
        VIC.spr0_y = VIC.spr1_y = VIC.spr2_y = 223;

        VIC.spr0_x = x;
        VIC.spr1_x = x+24;
        VIC.spr2_x = x+48;
        
        VIC.spr_ena = 0x7;
        textcolor(COLOR_YELLOW);
        DRAW_Screen(SCREEN_ingame, COLOR_WHITE, COLOR_LIGHTBLUE);

        gametime=15;

        t2=clock()+CLOCKS_PER_SEC;
        while(gametime>=0)
        {
            gotoxy(22,0);
            cprintf("%2d",level);
            gotoxy(27,0);
            cprintf("%2d",gametime);
            gotoxy(33,0);
            cprintf("%6d",score);


            t1=clock();
            if(t1>=t2)
            {
                gametime--;
                t2=clock()+CLOCKS_PER_SEC;
            }
        }

    }
      iGameState = GSTATE_showhighscore;
}
