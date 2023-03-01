//---------------------------------------------------------
// file:	main.c
// author:	Justin Chambers
// brief:	Main entry point for the sample usage project
//			of the CProcessing library
//
// Copyright © 2019 DigiPen, All rights reserved.
//---------------------------------------------------------

#include <windows.h>
#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>

CP_Sound sound;

void sandbox_init(void) {
	sound = CP_Sound_Load("Assets/Snare.wav");

}

void sandbox_update(void) {
	CP_Sound_Play(sound);
}

void sandbox_exit(void) {

}


int main(void)
{

	CP_Engine_SetNextGameState(sandbox_init, sandbox_update, sandbox_exit);
	CP_Engine_Run();
	return 0;
}

