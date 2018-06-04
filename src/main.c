#include "globals.h"
#include "data.h"
#include "title.h"
#include "game.h"

int iGameState = GSTATE_title;

void setup()
{
    CIA2.ddra |= 0x03;
    CIA2.pra &= 0xfc;

    VIC.addr = 0x12;
    *(unsigned char*)0x288 = 0xc4;

    VIC.spr_mcolor = 255;
    VIC.spr_mcolor0 = COLOR_GRAY1;
    VIC.spr_mcolor1 = COLOR_WHITE;

    loaddata();
	return;
}

int main(void)
{
	setup();

    while(1)
    {
		switch (iGameState)
		{
            case GSTATE_title:
                showtitle();
                iGameState = GSTATE_ingame;
                break;
    		case GSTATE_ingame:
                ingame();
    			break;
    		case GSTATE_showhighscore:
    			break;
    		case GSTATE_newhighscore:
    			break;
    		default:
                break;
		}
    }
}
