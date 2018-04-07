#ifndef JOYSTICK_H
#define JOYSTICK_H

enum JOY_PORT
{
	PORT_A,
	PORT_B
};

enum JOY_STATE
{
	JOY_UP = 1,
    JOY_DOWN = 2,
	JOY_LEFT = 4,
	JOY_RIGHT = 8,
	JOY_FIRE = 16
};

int getstate(int);

#endif
