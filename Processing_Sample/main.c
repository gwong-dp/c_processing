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

void sandbox_init(void) {
	CP_Vector vec_a = CP_Vector_Set(1, 0);
	CP_Vector vec_b = CP_Vector_Set(0, 1);
	float angleBetweenAB = CP_Vector_AngleCCW(vec_a, vec_b); // returns 270
	float angleBetweenBA = CP_Vector_AngleCCW(vec_b, vec_a); // returns 90

	(void)angleBetweenAB;
	(void)angleBetweenBA;
}

void sandbox_update(void) {

}

void sandbox_exit(void) {

}


int main(void)
{

	CP_Engine_SetNextGameState(sandbox_init, sandbox_update, sandbox_exit);
	CP_Engine_Run();
	return 0;
}

