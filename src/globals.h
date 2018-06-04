#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <c64.h>

enum
{
	GSTATE_title,
	GSTATE_ingame,
	GSTATE_showhighscore,
	GSTATE_newhighscore
};

extern int iGameState;
extern int gametime;
extern int level;
extern int score;

#define VIC_BANK         3
#define VIC_SCREENBLOCK  1
#define VIC_CHARBLOCK    1

#define VIC_BASEADR      (VIC_BANK * 0x4000)
#define VIC_SCREENADR    ((VIC_SCREENBLOCK * 0x0400) + VIC_BASEADR)
#define VIC_CHARSETADR   ((VIC_CHARBLOCK * 0x0800) + VIC_BASEADR)
#define VIC_SPRITEPTRADR (VIC_SCREENADR + 0x03F8)

#endif
