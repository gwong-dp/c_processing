//
// This file showcases how to load and render font in CProcessing
// 
// This file assumes that:
// - You have Visual Studio 2022 set up correctly for
//   CProcessing as per the "Visual Studios Setup Guide" 
// - You have the file "Exo2-Regular.ttf" in your "Assets" folder, 
//   which should be a file in the TTF font format.
//

#include "cprocessing.h"

CP_Font my_awesome_font;

void game_init(void) {
	// Loads "Assets/Exo2-Regular.ttf" into memory and gives back
	// a representation of the font to us (aka a 'handle' to the font).
	// 
	// We assign the 'handle' to my_awesome_font. 
	// You can then think of my_awesome_font as holding information
	// information and data about Exo2-Regular.ttf.
	//
	my_awesome_font = CP_Font_Load("Assets/Exo2-Regular.ttf");

	// Tells CProcessing to use my_awesome_font for it's future
	// text drawing operations.
	CP_Font_Set(my_awesome_font);

	// Tells CProcessing that when drawing text in the future (via CP_Font_DrawText),
	// the position given to it is the center of the text horizontally and vertically.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	// Tells CProcessing that when drawing text in the future (via CP_Font_DrawText),
	// We use size 72 font height.
	CP_Settings_TextSize(72.f);
}

void game_update(void) {
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

	// Tells CProcessing to use the white color for anything we are drawing on the screen
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));

	// Draw the text "[Top Left]" with the position set to the top left of the screen,
	// with horizontal alignment set to the left and vertical alignment set to the top.
	// Thus it should appear at the top left hand side of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_TOP);
	CP_Font_DrawText("[Top Left]", 0, 0);

	// Draw the text "[Top Center]" with the position set to the top center of the screen,
	// with horizontal alignment set to the center and vertical alignment set to the top.
	// Thus it should appear at the top center hand side of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_TOP);
	CP_Font_DrawText("[Top Center]", (float)CP_System_GetWindowWidth() / 2, 0);

	// Draw the text "[Top Right]" with the position set to the top right of the screen,
	// with horizontal alignment set to the right and vertical alignment set to the top.
	// Thus it should appear at the top right hand side of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_RIGHT, CP_TEXT_ALIGN_V_TOP);
	CP_Font_DrawText("[Top Right]", (float)CP_System_GetWindowWidth(), 0);

	// Draw the text "[Left Center]"  with the position set to the left center of the screen,
	// with horizontal alignment set to the left and vertical alignment set to the middle.
	// Thus it should perfectly appear in the left center of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Font_DrawText("[Left Center]", 0, (float)CP_System_GetWindowHeight() / 2);

	// Draw the text "[Center]"  with the position set to the middle of the screen,
	// with horizontal alignment set to the center and vertical alignment set to the middle.
	// Thus it should perfectly appear in the middle of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Font_DrawText("[Center]", (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight() / 2);

	// Draw the text "[Right Center]"  with the position set to the right center of the screen,
	// with horizontal alignment set to the right and vertical alignment set to the middle.
	// Thus it should perfectly appear in the right center of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_RIGHT, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Font_DrawText("[Right Center]", (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight() / 2);


	// Draw the text "[Bottom Left]" with the position set to the bottom left of the screen,
	// with horizontal alignment set to the left and vertical alignment set to the bottom.
	// Thus it should appear at the bottom left of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_BOTTOM);
	CP_Font_DrawText("[Bottom Left]", 0, (float)CP_System_GetWindowHeight());


	// Draw the text "[Bottom Center]" with the position set to the bottom center of the screen,
	// with horizontal alignment set to the center and vertical alignment set to the bottom.
	// Thus it should appear at the bottom center of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_BOTTOM);
	CP_Font_DrawText("[Bottom Center]", (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight());


	// Draw the text "[Bottom Left]" with the position set to the bottom right of the screen,
	// with horizontal alignment set to the right and vertical alignment set to the bottom.
	// Thus it should appear at the bottom right of the screen.
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_RIGHT, CP_TEXT_ALIGN_V_BOTTOM);
	CP_Font_DrawText("[Bottom Left]", (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight());
}

void game_exit(void) {
	// Don't need to free font!
}

int main(void)
{
	CP_System_SetWindowSize(1600, 900);
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run(0);
	return 0;
}