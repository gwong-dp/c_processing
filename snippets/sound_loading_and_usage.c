//
// This file showcases how to load and play sound in CProcessing
// 
// This file assumes that:
// - You have Visual Studio 2022 set up correctly for
//   CProcessing as per the "Visual Studios Setup Guide" 
// - You have an sound named "sound.wav" in your "Assets" folder,
//   which should be in the WAV sound format.
//

#include "cprocessing.h"

CP_Sound my_awesome_sound;

void game_init(void) {
	// Loads "Assets/sound.wav" into memory and gives back
	// a representation of the sound to us (aka a 'handle' to the sound).
	// 
	// We assign the 'handle' to my_awesome_sound. 
	// You can then think of my_awesome_sound as holding information
	// information and data about sound.wav.
	//
	my_awesome_sound = CP_Sound_Load("Assets/sound.wav");

	// Play the sound once!
	CP_Sound_Play(my_awesome_sound);
}

void game_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	// We don't do anything here, unless you want to play the sound repeatedly.
}

void game_exit(void) {
	// Tell CProcessing to release the resources used for my_awesome_sound
	CP_Sound_Free(&my_awesome_sound);
}

int main(void)
{
	CP_System_SetWindowSize(1600, 900);
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run(0);
	return 0;
}