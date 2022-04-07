//------------------------------------------------------------------------------
// file:	CP_Text.c
// author:	Daniel Hamilton, Justin Chambers
// brief:	Text functions for loading fonts and drawing text
//
// Copyright © 2019 DigiPen, All rights reserved.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "cprocessing.h"
#include "Internal_Text.h"
#include "Internal_System.h"
#include "vect.h"
#include "Internal_Resources.h"

//------------------------------------------------------------------------------
// Defines:
//------------------------------------------------------------------------------

#define FONT_LOAD_ERROR -1
#define CP_INITIAL_FONT_COUNT 16

VECT_GENERATE_TYPE(CP_Font)

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

static CP_Font  _default_font = NULL;

static vect_CP_Font* font_vector;

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

static CP_Font CP_Font_LoadInternal(const char* filepath, bool fromMemory, unsigned char* data, int ndata, int freeData);

static CP_Font CP_CheckIfFontIsLoaded(const char* filepath)
{
	for (int i = 0; i < font_vector->size; ++i)
	{
		CP_Font font = vect_at_CP_Font(font_vector, i);
		if (font && !strcmp(filepath, font->filepath))
		{
			return font;
		}
	}

	return NULL;
}

static void CP_AddFontHandle(CP_Font font)
{
	vect_push_CP_Font(font_vector, font);
}

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void CP_TextInit(void)
{
	// initialize our vector
	font_vector = vect_init_CP_Font(CP_INITIAL_FONT_COUNT);

	// load the default font from internal binary resource data
	_default_font = CP_Font_LoadInternal("./Assets/Exo2-Regular.ttf", true, Exo2_Regular_ttf, Exo2_Regular_ttf_size, 0);
}

void CP_TextShutdown(void)
{
	CP_CorePtr CORE = GetCPCore();
	if (!CORE || !CORE->nvg) return;

	for (int i = 0; i < font_vector->size; ++i)
	{
		CP_Font font = vect_at_CP_Font(font_vector, i);
		if (font)
			free(font);
	}

	vect_free_CP_Font(font_vector);
}

//------------------------------------------------------------------------------
// EXPORT Functions:
//------------------------------------------------------------------------------

CP_API CP_Font CP_Font_GetDefault(void)
{
	return _default_font;
}

CP_API CP_Font CP_Font_Load(const char* filepath)
{
	return CP_Font_LoadInternal(filepath, false, NULL, 0, 0);
}

static CP_Font CP_Font_LoadInternal(const char* filepath, bool fromMemory, unsigned char* data, int ndata, int freeData)
{
	CP_Font new_font = NULL;
	CP_CorePtr CORE = GetCPCore();

	// Check if the font is already loaded
	new_font = CP_CheckIfFontIsLoaded(filepath);
	if (new_font)
	{
		return new_font;
	}

	// Allocate the struct
	new_font = (CP_Font)malloc(sizeof(CP_Font_Struct));
	if (!new_font) {
		return NULL;
	}

	new_font->load_error = FALSE;
	new_font->handle = -1;
	strcpy_s(new_font->filepath, MAX_PATH, filepath);

	if (!CORE || !CORE->nvg)
	{
		new_font->load_error = TRUE;
		free(new_font);
		return NULL;
	}

	if (fromMemory)
	{
		new_font->handle = nvgCreateFontMem(CORE->nvg, filepath, data, ndata, freeData);
	}
	else
	{
		new_font->handle = nvgCreateFont(CORE->nvg, filepath, filepath);
	}
	
	if (new_font->handle == FONT_LOAD_ERROR) {
		new_font->load_error = TRUE;
		free(new_font);
		return NULL;
	}

	new_font->load_error = FALSE;

	// Store a pointer to the font
	CP_AddFontHandle(new_font);

	return new_font;
}

CP_API void CP_Font_DrawText(const char* text, float x, float y)
{
#if GERALD
	CP_Font_DrawTextCommand* commandData = CP_Commands_PushStruct(CP_Font_DrawTextCommand, CP_Commands_GetCurrentFrame(), COMMAND_FONT_DRAW_TEXT);
	commandData->text = text;
	commandData->x = x;
	commandData->y = y;
#endif 
	CP_CorePtr CORE = GetCPCore();
	if (!CORE || !CORE->nvg)
		return;

	nvgText(CORE->nvg, x, y, text, NULL);
}

CP_API void CP_Font_DrawTextBox(const char* text, float x, float y, float rowWidth)
{
#if GERALD
	CP_Font_DrawTextCommand* commandData = CP_Commands_PushStruct(CP_Font_DrawTextCommand, CP_Commands_GetCurrentFrame(), COMMAND_FONT_DRAW_TEXT);
	commandData->text = text;
	commandData->x = x;
	commandData->y = y;
#endif

	CP_CorePtr CORE = GetCPCore();

	if (!CORE || !CORE->nvg)
		return;

	nvgTextBox(CORE->nvg, x, y, rowWidth, text, NULL);
}

CP_API void CP_Font_Set(CP_Font font)
{
	CP_CorePtr CORE = GetCPCore();
	if (font == NULL || !CORE || !CORE->nvg) return;
	nvgFontFaceId(CORE->nvg, font->handle);
}

CP_API void CP_Settings_TextSize(float size)
{
	CP_CorePtr CORE = GetCPCore();
	if (!CORE || !CORE->nvg) return;
	nvgFontSize(CORE->nvg, size);
}

CP_API void CP_Settings_TextAlignment(CP_TEXT_ALIGN_HORIZONTAL h, CP_TEXT_ALIGN_VERTICAL v)
{
	int flags = h | v;
	CP_CorePtr CORE = GetCPCore();
	if (!CORE || !CORE->nvg) return;
	nvgTextAlign(CORE->nvg, flags);
}
