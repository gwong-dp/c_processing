//---------------------------------------------------------
// file:	main.c
// author:	Gerald Wong
// brief:	Main entry point for the sample usage project
//			of the CProcessing library
//
// Copyright 2023 DigiPen, All rights reserved.
//---------------------------------------------------------

#include <windows.h>
#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>

CP_Sound sound;
CP_Image img;
CP_Image img2;
CP_Font font; 

void sandbox_init(void) {
	//sound = CP_Sound_Load("Assets/Snare.wav");
	font = CP_Font_Load("Assets/Exo2-Regular.ttf");
	CP_Font_Set(font);
	img = CP_Image_Load("Assets/nanamo.jpg");
	img = CP_Image_Load("Assets/nanamo.jpg");
	img = CP_Image_Load("Assets/nanamo.jpg");
	img = CP_Image_Load("Assets/nanamo.jpg");
	img2 = CP_Image_Load("Assets/justin1.png");

	
}

void sandbox_update(void) {
	//CP_Sound_Play(sound);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	CP_Image_Draw(img, 200, 200, 200, 300, 255);
	CP_Font_DrawText("Hello World", 100.f, 100.f);

}

void sandbox_exit(void) {
	CP_Image_Free(&img);
	//CP_Sound_Free(&sound);
}


int main(void)
{
	CP_Engine_SetNextGameState(sandbox_init, sandbox_update, sandbox_exit);
	CP_Engine_Run();
	return 0;
}

