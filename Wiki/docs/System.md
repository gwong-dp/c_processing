This section contains all System functions.

# Table Of Contents
* [CP_System_SetWindowSize     ](#cp_system_setwindowsize)
* [CP_System_SetWindowPosition ](#cp_system_setwindowposition) NEW
* [CP_System_Fullscreen        ](#cp_system_fullscreen)
* [CP_System_FullscreenAdvanced](#cp_system_fullscreenadvanced)
* [CP_System_GetWindowWidth    ](#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight   ](#cp_system_getwindowheight)
* [CP_System_GetDisplayWidth   ](#cp_system_getdisplaywidth) NEW
* [CP_System_GetDisplayHeight  ](#cp_system_getdisplayheight) NEW
* [CP_System_GetWindowHandle   ](#cp_system_getwindowhandle)
* [CP_System_SetWindowTitle    ](#cp_system_setwindowtitle)
* [CP_System_ShowCursor        ](#cp_system_showcursor)
* [CP_System_GetFrameCount     ](#cp_system_getframecount)
* [CP_System_GetFrameRate      ](#cp_system_getframerate)
* [CP_System_SetFrameRate      ](#cp_system_setframerate)
* [CP_System_GetDt             ](#cp_system_getdt)
* [CP_System_GetMillis         ](#cp_system_getmillis)
* [CP_System_GetSeconds        ](#cp_system_getseconds)

# CP_System_SetWindowSize
This function modifies the size of the window. Typically, the window size is set in the init function.

## Function
```C
void CP_System_SetWindowSize(int new_width, int new_height);
```

### Parameters
* new_width (int) - The width to set the window to.
* new_height (int) - The height to set the window to.

### Return
This function does not return anything.

## Example
```C
void init()
{
    // Set the window size to a small square
    CP_System_SetWindowSize(10, 10);

    // Set the background to white
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)

# CP_System_SetWindowPosition
This function sets the position of the application window within the user's monitor screen. The top-left corner of the window will be set to the position provided. Note: The position (0, 0) is at the top left of the monitor screen.

## Function
```C
void CP_System_SetWindowPosition(int x, int y);
```

### Parameters
* x (int) - The X coordinate of the window's top-left corner.
* y (int) - The Y coordinate of the window's top-left corner.

### Return
This function does not return anything.

## Example
```C
void init()
{
    // Set the window position to be 100 pixels from the top of the screen
    // and 200 pixels from the left edge of the screen
    CP_System_SetWindowPosition(200, 100);
}
```

## Related

# CP_System_Fullscreen
This function sets the window to fullscreen. It will automatically sets the window's pixel width and height to the monitor's width and height. Use [CP_System_FullscreenAdvanced](#cp_system_fullscreenadvanced) to specify a pixel width and height for the fullscreen window.

## Function
```C
void CP_System_Fullscreen(void);
```

### Parameters
This function has no parameters.

### Return
This function does not return anything.

## Example
```C
void init()
{
    // Set the window to fill the screen
    CP_System_Fullscreen();

    // Set the background to black
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)

# CP_System_FullscreenAdvanced
This function sets the window to fullscreen like [CP_System_Fullscreen](#cp_system_fullscreen) but lets you set the pixel aspect ratio of the screen as well. If you try to set the screen to an aspect ratio unsupported by the monitor, it will be set to the closest aspect ratio possible.

## Function
```C
void CP_System_FullscreenAdvanced(int targetWidth, int targetHeight);
```

### Parameters
* targetWidth (int) - The pixel width of the window.
* targetHeight (int) - The pixel height of the window.

### Return
This function does not return anything.

## Example
```C
// Horizontal position of the square
float x_pos;

void init()
{
    // Start the square at the left of the screen
    x_pos = 0;

    // Set the square to draw yellow
    CP_Settings_Fill(CP_Color_Create(255, 255, 0, 255));

    // Set the window to fullscreen 1280x720
    CP_System_FullscreenAdvanced(1280, 720);
}

void update()
{
    // Set background to black
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Draw the square
    CP_Graphics_DrawRect(x_pos, CP_System_GetWindowHeight() / 2.0f, 100, 100);
    x_pos += 2;

    // If space pressed, reset the state
    if (CP_Input_KeyTriggered(KEY_SPACE))
        CP_Engine_SetNextGameStateForced(init, update, NULL);
    else if (CP_Input_KeyTriggered(KEY_Q))
        CP_Engine_Terminate();
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Engine_SetNextGameStateForced](Engine.md#cp_engine_setnextgamestateforced)
* [CP_Engine_Terminate](Engine.md#cp_engine_terminate)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_System_GetWindowWidth
Gets the display width of the window excluding the window frame. This is the width of the canvas you are drawing to.

## Function
```C
int CP_System_GetWindowWidth(void);
```

### Parameters
This function has no parameters.

### Return
* int - The width of the game window.

## Example
```C
void update()
{
    // Clear the background to a blue color
    CP_Graphics_ClearBackground(CP_Color_Create(20, 200, 255, 255));

    // Draw a rectangle at the mouse position
    CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 25.0f, 25.0f);
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_System_GetWindowHeight
Gets the display height of the window excluding the window frame. This is the height of the canvas you are drawing to.

## Function
```C
int CP_System_GetWindowHeight(void);
```

### Parameters
This function has no parameters.

### Return
* int - The height of the game window.

## Example
```C
void update()
{
    // Clear the background to a blue color
    CP_Graphics_ClearBackground(CP_Color_Create(20, 200, 255, 255));

    // Draw a rectangle at the mouse position
    CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 25.0f, 25.0f);
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)

# CP_System_GetDisplayWidth
Gets the width of the user's monitor in pixels.

## Function
```C
int CP_System_GetDisplayWidth(void);
```

### Parameters
This function has no parameters.

### Return
* int - The width of the monitor.

## Example
```C
void init()
{
    // Set the window size to the same size as the screen
    CP_System_SetWindowSize(CP_System_GetDisplayWidth(), CP_System_GetDisplayHeight());
}
```

## Related
* [CP_System_SetWindowSize](System.md#cp_system_setwindowsize)
* [CP_System_GetDisplayHeight](System.md#cp_system_getdisplayheight)

# CP_System_GetDisplayHeight
Gets the height of the user's monitor in pixels.

## Function
```C
int CP_System_GetDisplayHeight(void);
```

### Parameters
This function has no parameters.

### Return
* int - The height of the monitor.

## Example
```C
void init()
{
    // Set the window size to the same size as the screen
    CP_System_SetWindowSize(CP_System_GetDisplayWidth(), CP_System_GetDisplayHeight());
}
```

## Related
* [CP_System_SetWindowSize](System.md#cp_system_setwindowsize)
* [CP_System_GetDisplayWidth](System.md#cp_system_getdisplaywidth)

# CP_System_GetWindowHandle
Returns the window handle (HWND) of the program running. See https://docs.microsoft.com/en-us/windows/win32/apiindex/windows-api-list for windows.h documentation and examples.

## Function
```C
HWND CP_System_GetWindowHandle(void);
```

### Parameters
This function has no parameters.

### Return
* HWND - Windows type that represents the handle to the window.

# CP_System_SetWindowTitle
Sets the title of the running program.

## Function
```C
void CP_System_SetWindowTitle(const char* title);
```

### Parameters
* title (const char*) - The string containing the title to change the title bar to.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // Set the window title to the number of frames that have passed.
    char buffer[256] = { 0 };
    sprintf_s(buffer, 256, "%d frames have passed", frameCount);
    CP_System_SetWindowTitle(buffer);
}
```

# CP_System_ShowCursor
This function sets whether the cursor is visible or not. Typically, it is used in the init function.

## Function
```C
void CP_System_ShowCursor(CP_BOOL show);
```

### Parameters
* show (CP_BOOL) - True/False for whether the cursor is visible.

### Return
This function does not return anything.

## Example
```C
CP_BOOL cursor = TRUE;

void init()
{
    // Set the window to fullscreen
    CP_System_Fullscreen();

    // Show the cursor
    CP_System_ShowCursor(cursor);
}

void update()
{
    // Check if the spacebar is triggered
    if (CP_Input_KeyTriggered(KEY_SPACE))
    {
        // Swap whether the cursor is shown
        cursor = !cursor;
        CP_System_ShowCursor(cursor);
    }
}
```

## Related
* [CP_System_Fullscreen](System.md#cp_system_fullscreen)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)

# CP_System_GetFrameCount
Returns the current frame count. The frame count starts at 0 when the program launches and increments every frame until the program ends.

Note: the frame count can't be set by the user and isn't reset when changing game states.

## Function
```C
int CP_System_GetFrameCount();
```

### Parameters
This function has no parameters.

### Return
* int - The current frame count.

## Example
```C
void update(void)
{
    // print the current frame count to the center of the window
    CP_Settings_TextSize(200);
    CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
    CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
    CP_Settings_Fill(CP_Color_Create(100, 20, 100, 255));

    int currentFrameCount = CP_System_GetFrameCount();

    char buffer[16] = { 0 };
    sprintf_s(buffer, 16, "%i", currentFrameCount);
    CP_Font_DrawText(buffer, 200, 200);
}
```

## Related
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Font_DrawText](Font.md#cp_font_drawtext)

# CP_System_GetFrameRate
Returns the current frames per second.

## Function
```C
float CP_System_GetFrameRate(void);
```

### Parameters
This function has no parameters.

### Return
* float - The current number of frames per second.

## Example
```C
void update(void)
{
    // print the current frame rate to the center of the window
    CP_Settings_TextSize(200);
    CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
    CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
    CP_Settings_Fill(CP_Color_Create(100, 20, 100, 255));

    float currentFrameRate = CP_System_GetFrameRate();

    char buffer[16] = { 0 };
    sprintf_s(buffer, 16, "%.1f", currentFrameRate );
    CP_Font_DrawText(buffer, 200, 200);
}
```

## Related
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Font_DrawText](Font.md#cp_font_drawtext)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)

# CP_System_SetFrameRate
Sets the target frame rate (fps) for the application.

The internal frame rate controller manages when each update call happens. If the processing required to complete one update finishes quickly then the frame rate controller will idle the CPU. Once the total desired frame time has passed it will then start the next frame. If the processing required to complete one update takes longer than one frame's worth of time then the next frame will start immediately.

## Function
```C
void CP_System_SetFrameRate(float fps)
```

### Parameters
* fps - the target application update speed in frames per second.

### Return
This function does not return anything.

## Example
```C
void init(void)
{
    // set framerate to 2 fps (slow)
    CP_System_SetFrameRate(2.0f);

    // initialize settings
    CP_Settings_TextSize(200);
    CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
    CP_Settings_Fill(CP_Color_Create(100, 20, 100, 255));
}

void update(void)
{
    // clear the screen
    CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));

    // print the current frame count to the center of the window
    int currentFrameCount = CP_System_GetFrameCount();

    char buffer[16] = { 0 };
    sprintf_s(buffer, 16, "%i", currentFrameCount);
    CP_Font_DrawText(buffer, 200, 200);
}
```

## Related
* [CP_System_GetFrameCount](System.md#cp_system_getframecount)
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Font_DrawText](Font.md#cp_font_drawtext)

# CP_System_GetDt
Returns the elapsed time (in seconds) from the last frame. This is very important when making frame independent calculations such as movement or physics.

## Function
```C
float CP_System_GetDt(void);
```

### Parameters
This function has no parameters.

### Return
* float - The fraction of a second that has passed since the last frame.

## Example
```C
void init(void)
{
    // initialize settings
    CP_Settings_TextSize(150);
    CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
    CP_Settings_Fill(CP_Color_Create(100, 20, 100, 255));
}

void update(void)
{
    // clear the background
    CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));

    // get dt and then print total elapsed time
    float currentElapsedTime = CP_System_GetDt();
    static float totalElapsedTime = 0;
    totalElapsedTime += currentElapsedTime;

    char buffer[16] = { 0 };
    sprintf_s(buffer, 16, "%.2f", totalElapsedTime);
    CP_Font_DrawText(buffer, 200, 200);
}
```

## Related
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Font_DrawText](Font.md#cp_font_drawtext)

# CP_System_GetMillis
Returns the total milliseconds from the start of the program.

NOTE: This number is always increasing and cannot be changed or reset by the user.

## Function
```C
float CP_System_GetMillis(void);
```

### Parameters
This function has no parameters.

### Return
* float - The milliseconds that have passed since the program started.

## Example
```C
void init(void)
{
    // initialize settings
    CP_Settings_TextSize(150);
    CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
    CP_Settings_Fill(CP_Color_Create(100, 20, 100, 255));
}

void update(void)
{
    // clear the background
    CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));

    // print milliseconds since program start
    float totalMillis = CP_System_GetMillis();

    char buffer[16] = { 0 };
    sprintf_s(buffer, 16, "%.1f", totalMillis);
    CP_Font_DrawText(buffer, 200, 200);
}
```

## Related
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Font_DrawText](Font.md#cp_font_drawtext)

# CP_System_GetSeconds
Returns the total number of seconds from the start of the program.

NOTE: This number is always increasing and cannot be changed or reset by the user.

## Function
```C
float CP_System_GetSeconds(void);
```

### Parameters
This function has no parameters.

### Return
* float - The number of seconds that have passed since the program started.

## Example
```C
void init(void)
{
    // initialize settings
    CP_Settings_TextSize(150);
    CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
    CP_Settings_Fill(CP_Color_Create(100, 20, 100, 255));
}

void update(void)
{
    // clear the background
    CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));

    // print seconds since program start
    float totalSeconds = CP_System_GetSeconds();

    char buffer[16] = { 0 };
    sprintf_s(buffer, 16, "%.2f", totalSeconds);
    CP_Font_DrawText(buffer, 200, 200);
}
```

## Related
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Font_DrawText](Font.md#cp_font_drawtext)
