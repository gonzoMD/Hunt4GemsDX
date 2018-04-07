#include <c64.h>
#include "joystick.h"

int getstate(int port)
{
	
	int state = 0;
	
	switch (port)
	{
	case PORT_A:
		if (!(CIA1.pra & JOY_UP)) state += JOY_UP;
		if (!(CIA1.pra & JOY_DOWN)) state += JOY_DOWN;
		if (!(CIA1.pra & JOY_LEFT)) state += JOY_LEFT;
		if (!(CIA1.pra & JOY_RIGHT)) state += JOY_RIGHT;
		if (!(CIA1.pra & JOY_FIRE)) state += JOY_FIRE;
		return state;
		break;
	case PORT_B:
		if (!(CIA1.prb & JOY_UP)) state += JOY_UP;
		if (!(CIA1.prb & JOY_DOWN)) state += JOY_DOWN;
		if (!(CIA1.prb & JOY_LEFT)) state += JOY_LEFT;
		if (!(CIA1.prb & JOY_RIGHT)) state += JOY_RIGHT;
		if (!(CIA1.prb & JOY_FIRE)) state += JOY_FIRE;
	default:
		return state;
		break;
	};
}