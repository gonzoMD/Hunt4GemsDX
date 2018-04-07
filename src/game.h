#ifndef GAME_H
#define GAME_H

void preparegame();
void ingame();

struct gems
{
	int color;
	int x,y;
	int value;
	int speed;
};

#endif
