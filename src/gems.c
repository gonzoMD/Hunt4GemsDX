#include "globals.h"
#include "gems.h"

static struct Gem g[4];

void setupgems()
{
	int i;
	for (i = GEM_1; i <= GEM_4; ++i)
	{
		g[i-4].pointvar = 10;
		g[i-4].timevar = 0;
		g[i - 4].posx = rand() % 255;
		g[i - 4].posy = 0;
		g[i-4].speed = rand() % 4;

		*((unsigned char*)(VIC_SPRITEPTRADR + i)) = 8;
		VIC.spr_color[i] = COLOR_GREEN;
		VIC.spr_pos[i].x = g[i-4].posx;
		VIC.spr_ena |= 0xFF;
	}
}

void movegems()
{
	int i;
	for (i = GEM_1; i <= GEM_4; ++i)
	{
		g[i-4].posy += g[i-4].speed;
		VIC.spr_pos[i].y = g[i-4].posy;
	}
}

