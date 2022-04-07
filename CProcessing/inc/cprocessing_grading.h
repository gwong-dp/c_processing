#pragma once


#ifdef GRADING
#include "cprocessing_common.h"
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct CP_CommandsEntryHeader {
    unsigned type; 
    unsigned offset_to_data;
} CP_CommandsEntryHeader;

typedef struct CP_Commands {
    unsigned char* memory;
    unsigned char* data_memory_at;
    unsigned char* entry_memory_start;
    unsigned char* entry_memory_at;
    unsigned memory_size;
    unsigned entry_count;
} CP_Commands;

typedef enum CP_COMMAND {
	COMMAND_GRAPHICS_DRAW_CIRCLE,
    COMMAND_GRAPHICS_DRAW_RECT,
    COMMAND_SETTINGS_SET_FILL,
	COMMAND_GRAPHICS_CLEAR_BACKGROUND,
    COMMAND_FONT_DRAW_TEXT
} CP_COMMAND;

typedef struct CP_Graphics_DrawCircleCommand {
	float x, y, d;
} CP_Graphics_DrawCircleCommand;

typedef struct CP_Graphics_DrawRectCommand {
    float x, y, w, h;
} CP_Graphics_DrawRectCommand;

typedef struct CP_Graphics_ClearBackgroundCommand {
	CP_Color color;
} CP_Graphics_ClearBackgroundCommand;

typedef struct CP_Settings_SetFillCommand {
    CP_Color color;
} CP_Settings_SetFillCommand;

typedef struct CP_Font_DrawTextCommand {
    float x, y;
    const char* text;

} CP_Font_DrawTextCommand;

//---------------------------------------------------------
// GRADING:
//		Extra functions for grading purposes
CP_API void					CP_Input_ForceMouseTriggered(CP_MOUSE button);
CP_API void					CP_Input_ForceMouseMove(float mouseX, float mouseY);
CP_API void					CP_InputForceKeyTriggered(CP_KEY keyCode);



CP_API CP_Commands* CP_Commands_GetCurrentFrame(void);
CP_API unsigned					CP_Commands_GetCount(CP_Commands* commands);
CP_API void						CP_Commands_Clear(CP_Commands* commands);
CP_API int						CP_Commands_Init(CP_Commands* commands, void* memory, unsigned int memory_size);
CP_API CP_CommandsEntryHeader* CP_Commands_GetEntry(CP_Commands* commands, unsigned int Index);
CP_API void* CP_Commands_GetEntryData(CP_Commands* commands, CP_CommandsEntryHeader* Entry);
CP_API void* CP_Commands_PushBlock(CP_Commands* commands, unsigned int Size, unsigned char Alignment, unsigned int Id);

#define alignof(type) ((size_t)&((struct { char c; type d; } *)0)->d)
#define CP_Commands_PushStruct(type, commands, Id) (type*)CP_Commands_PushBlock(commands, sizeof(type), alignof(type), Id)
#define CP_Commands_GetEntryDataAs(type, commands,entry) (type*)CP_Commands_GetEntryData(commands, entry)


#ifdef __cplusplus
}

#endif // ENABLE_COMMANDS

#endif

