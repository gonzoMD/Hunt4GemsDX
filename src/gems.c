#include "globals.h"
#include "gems.h"

static struct Gem g[4];

void setupgems()
{
	int i;
	for (i = GEM_1; i <= GEM_4; ++i)
	{
		g[i-3].pointvar = 10;
		g[i-3].timevar = 0;
		g[i - 3].posx = rand() % 255;
		g[i - 3].posy = 0;
		g[i-3].speed = rand() % 4;

		*((unsigned char*)(VIC_SPRITEPTRADR + i)) = 8;
		VIC.spr_color[i] = COLOR_GREEN;
		VIC.spr_pos[i].x = g[i-3].posx;
		VIC.spr_ena |= 120;  // 01111000
	}
}

void movegems()
{
	int i;
	for (i = GEM_1; i <= GEM_4; ++i)
	{
		g[i-3].posy += g[i-3].speed;
		VIC.spr_pos[i].y = g[i-3].posy;
	}
}

