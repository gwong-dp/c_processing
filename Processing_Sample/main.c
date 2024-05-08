//
// This file showcases how to do a 2D 'light source' effect in CProcessing
// 
// This file assumes that:
// - You have Visual Studio 2022 set up correctly for
//   CProcessing as per the "Visual Studios Setup Guide" 
//

#include <stdio.h>
#include <crtdbg.h>

#include "cprocessing.h"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900
#define PLAYER_SPEED 400


void game_init(void) {
}

void game_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(50, 50, 50, 0));

	CP_Engine_Terminate();
}

void game_exit(void) {
}

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CP_System_SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run(1);
	
	return 0;
} 