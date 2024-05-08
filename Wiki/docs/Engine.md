This section contains all of the Engine functions.

# Table of Contents
* [CP_Engine_Run](#cp_engine_run)
* [CP_Engine_Terminate](#cp_engine_terminate)
* [CP_Engine_SetNextGameState](#cp_engine_setnextgamestate)
* [CP_Engine_SetNextGameStateForced](#cp_engine_setnextgamestateforced)
* [CP_Engine_SetPreUpdateFunction](#cp_engine_setpreupdatefunction) NEW
* [CP_Engine_SetPostUpdateFunction](#cp_engine_setpostupdatefunction) NEW

# CP_Engine_Run()
This function is what starts the CProcessing engine. Before calling **CP_Engine_Run()**, [CP_Engine_SetNextGameState](#cp_engine_setnextgamestate) or [CP_Engine_SetNextGameStateForced](#cp_engine_setnextgamestateforced) must be called to set the initial state of the program. Failing to do so will cause the program to end immediately.

## Function
```C
void CP_Engine_Run();
```

### Parameters
This function has no parameters.

### Return
This function does not return anything.

## Example
```C
void init()
{
    /* Set the size of the window */
    CP_System_SetWindowSize(500, 500);
}

void update()
{
    /* Set the background color to black every frame */
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    /* Draw a rectangle at the mouse position */
    CP_Graphics_DrawRect(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 50, 50);
}

int main()
{
    // Set the initial game state
    CP_Engine_SetNextGameState(init, update, NULL);

    // Run the program
    CP_Engine_Run();
}

```
## Related

* [CP_System_SetWindowSize](System.md#cp_system_setwindowsize)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Engine_Terminate()
This will end the program after completing the current frame.

## Function
```C
void CP_Engine_Terminate();
```

### Parameters
This function has no parameters.

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
}

void update()
{
    // Set background to black
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Draw the square
    CP_Graphics_DrawRect(x_pos, (float)CP_System_GetWindowHeight()/ 2.0f, 100, 100);
    x_pos += 2;

    // If space pressed, reset the state
    if (CP_Input_KeyTriggered(KEY_SPACE))
    {
        CP_Engine_SetNextGameStateForced(init, update, NULL);
    }

    // If escape is pressed, end the program
    if (CP_Input_KeyTriggered(KEY_ESCAPE))
    {
        CP_Engine_Terminate();
    }
}

int main(void)
{
    // Set the initial game state
    CP_Engine_SetNextGameState(init, update, NULL);

    // Run the program
    CP_Engine_Run();
}
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Engine_SetNextGameState()
This sets the next state for the program to enter. This will call the shutdown function of the current state if own exists. Calling **CP_Engine_SetNextGameState()** on the same state you are currently in will have no effect, but calling [CP_Engine_SetNextGameStateForced](#cp_engine_setnextgamestateforced) will restart the current state.

## Function
```C
void CP_Engine_SetNextGameState(FunctionPtr init, FunctionPtr update, FunctionPtr shutdown);
```

### Parameters
* init (FunctionPtr) - The name of the function called once when the state first begins. This can be NULL if no initialization is needed for your state.
* update (FunctionPtr) - The name of the function called every frame to update the state.
* shutdown (FunctionPtr) - The name of the function called when you leave a state. This occurs when you call **CP_Engine_SetNextGameState** or [CP_Engine_SetNextGameStateForced](#cp_engine_setnextgamestateforced) to change states. This can be NULL if no cleanup is needed for your state.

### Return
This function does not return anything.

## Example
```C
void init()
{
    /* Set the size of the window */
    CP_System_SetWindowSize(500, 500);
}

void update()
{
    /* Set the background color to black every frame */
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    /* Draw a rectangle at the mouse position */
    CP_Graphics_DrawRect(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 50, 50);
}

int main()
{
    // Set the initial game state
    CP_Engine_SetNextGameState(init, update, NULL);

    // Run the program
    CP_Engine_Run();
}
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_System_SetWindowSize](System.md#cp_system_setwindowsize)

# CP_Engine_SetNextGameStateForced()
This sets the next state for the program to enter. This will call the shutdown function of the current state if it exists. Calling **CP_Engine_SetNextGameStateForced()** allows you to reset your current game state, while [CP_Engine_SetNextGameState](#cp_engine_setnextgamestate) with the current game state will not.

## Function
```C
void CP_Engine_SetNextGameStateForced(FunctionPtr init, FunctionPtr update, FunctionPtr shutdown);
```

### Parameters
* init (FunctionPtr) - The name of the function called once when the state first begins. This can be NULL if no initialization is needed for your state.
* update (FunctionPtr) - The name of the function called every frame to update the state.
* shutdown (FunctionPtr) - The name of the function called when you leave a state. This occurs when you call [CP_Engine_SetNextGameState](#cp_engine_setnextgamestate) or **CP_Engine_SetNextGameStateForced()** to change states. This can be NULL if no cleanup is needed for your state.

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
}

void update()
{
    // Set background to black
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Draw the square
    CP_Graphics_DrawRect(x_pos, (float)CP_System_GetWindowHeight() / 2.0f, 100, 100);
    x_pos += 2;

    // If space pressed, reset the state
    if (CP_Input_KeyTriggered(KEY_SPACE))
        CP_Engine_SetNextGameStateForced(init, update, NULL);
}

int main(void)
{
    // Set the initial game state
    CP_Engine_SetNextGameState(init, update, NULL);

    // Run the program
    CP_Engine_Run();
}
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Engine_SetPreUpdateFunction()
This sets a function which will be called immediately before the current state's update function. This function is independent of the game state: it will continue to be called even if the game state is changed.

## Function
```C
void CP_Engine_SetPreUpdateFunction(FunctionPtr function);
```

### Parameters
* function (FunctionPtr) - The name of the function to be called before the update.

### Return
This function does not return anything.

## Example
```C
void preUpdate()
{
    // Change the fill color
    CP_Settings_Fill(CP_Color_Create(187, 24, 211, 255));
}

void init()
{
    CP_Engine_SetPreUpdateFunction(preUpdate);
}
```

## Related
* [CP_Settings_Fill](Settings.md#cp_settings_fill)

# CP_Engine_SetPostUpdateFunction()
This sets a function which will be called immediately after the current state's update function. This function is independent of the game state: it will continue to be called even if the game state is changed.

## Function
```C
void CP_Engine_SetPostUpdateFunction(FunctionPtr function);
```

### Parameters
* function (FunctionPtr) - The name of the function to be called after the update.

### Return
This function does not return anything.

## Example
```C
void postUpdate()
{
    // Change the fill color
    CP_Settings_Fill(CP_Color_Create(187, 24, 211, 255));
}

void init()
{
    CP_Engine_SetPostUpdateFunction(postUpdate);
}
```

## Related
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
