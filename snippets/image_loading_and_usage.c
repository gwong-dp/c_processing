//
// This file showcases how to load and render and image in CProcessing
// 
// This file assumes that:
// - You have Visual Studio 2022 set up correctly for
//   CProcessing as per the "Visual Studios Setup Guide" 
// - You have an image named "DigiPen_BLACK.png" in your "Assets" folder,
//   which should be in the PNG image format.
//

#include "cprocessing.h"

CP_Image my_awesome_image;

void game_init(void) {
	// Loads "Assets/DigiPen_BLACK.png" into memory and gives back
	// a representation of the image to us (aka a 'handle' to the image).
	// 
	// We assign the 'handle' to my_awesome_image. 
	// You can then think of my_awesome_image as holding information
	// information and data about DigiPen_BLACK.png.
	//
	my_awesome_image = CP_Image_Load("Assets/DigiPen_BLACK.png");

}

void game_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

	// Tells CProcessing to draw an image using my_awsome_image as reference.
	// It will draw starting from the middle of the window and 
	// stretch to fill up the whole window.
	// It will also be 100% opaque.
	float x = (float)CP_System_GetWindowWidth() / 2;    // middle of the window horizontally
	float y = (float)CP_System_GetWindowHeight() / 2;   // middle of the window vertically
	float w = (float)CP_System_GetWindowWidth();	  // width of the window 
	float h = (float)CP_System_GetWindowHeight();     // height of the window
	int alpha = 255; // This sets the image to 100% opaque
	CP_Image_Draw(my_awesome_image, x, y, w, h, alpha);
}

void game_exit(void) {
	// Tell CProcessing to release the resources used for my_awesome_image
	CP_Image_Free(&my_awesome_image);
}

int main(void)
{
	CP_System_SetWindowSize(1600, 900);
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run(0);
	return 0;
}


