#include "globals.h"
#include "joystick.h"
#include "data.h"
#include "drawing.h"

void showtitle()
{
	DRAW_Screen(SCREEN_title, COLOR_BLACK, COLOR_BLACK);
	CIA1.ddra = 224;
	while ((getstate(PORT_A)) != JOY_FIRE) {  }
	CIA1.ddra = 255;
}
