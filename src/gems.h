#ifndef GEMS_H
#define GEMS_H

enum
{
	GEM_1 = 3,
	GEM_2 = 4,
	GEM_3 = 5,
	GEM_4 = 6
};

struct Gem
{
	char pointvar;
	char timevar;
	char posx;
	char posy;
	char speed;
};

void setupgems(void);
void movegems(void);

#endif