This section contains all functions relating to CP_Color.

# Table Of Contents
* [CP_Color_Create](#cp_color_create)
* [CP_Color_CreateHex](#cp_color_createhex)
* [CP_Color_Lerp](#cp_color_lerp)
* [CP_Color_FromColorHSL](#cp_color_fromcolorhsl)
* [CP_ColorHSL_Create](#cp_colorhsl_create)
* [CP_ColorHSL_Lerp](#cp_colorhsl_lerp)
* [CP_ColorHSL_FromColor](#cp_colorhsl_fromcolor)

# CP_Color_Create
Create a [CP_Color](Types.md#cp_color) from given red, green, blue, and alpha values. The input values must be in the range of 0 to 255. **CP_Color_Create()** can be used to create a variable or used to pass a [CP_Color](Types.md#cp_color) directly as a function parameter.

## Function
```C
CP_Color CP_Color_Create(int r, int g, int b, int a);
```

### Parameters
* r (int) - The red value of the color.
* g (int) - The green value of the color.
* b (int) - The blue value of the color.
* a (int) - The alpha value of the color.

### Return
* [CP_Color](Types.md#cp_color) - The new CP_Color variable with the given color values.

## Example
```C
void init()
{
    // Use the CP_Color_Create function to create a variable
    CP_Color color1 = CP_Color_Create(255, 40, 100, 255);

    // Set the background with color1 (berry red)
    CP_Graphics_ClearBackground(color1);

    // Create a color and pass it directly as a function parameter
    CP_Settings_Fill(CP_Color_Create(0, 200, 255, 255));

    // Draw a rectangle at the top left of the screen (blue)
    float rectWidth = CP_System_GetDisplayWidth() * 0.5f;
    float rectHeight = CP_System_GetDisplayHeight() * 0.5f;
    CP_Graphics_DrawRect(0, 0, rectWidth, rectHeight);
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_System_GetDisplayWidth](System.md#cp_system_getdisplaywidth)
* [CP_System_GetDisplayHeight](System.md#cp_system_getdisplayheight)


# CP_Color_CreateHex
Create a [CP_Color](Types.md#cp_color) from a hex value. The hex value will be interpreted in this format: 0xRRGGBBAA, where the bytes marked R become the red value, those marked G become the green value, those marked B become the blue value, and those marked A become the alpha value.  **CP_Color_CreateHex()** can be used to create a variable or used to pass a [CP_Color](Types.md#cp_color) directly as a function parameter.

## Function
```C
CP_Color CP_Color_CreateHex(int hexCode);
```

### Parameters
* hexCode (int) - The hex code to be interpreted.

### Return
* [CP_Color](Types.md#cp_color) - The new CP_Color variable with the given color values.

## Example
```C
CP_Color red = CP_Color_CreateHex(0xFF0000FF);
CP_Color green = CP_Color_CreateHex(0x00FF00FF);
CP_Color blue = CP_Color_CreateHex(0x0000FFFF);
CP_Color white = CP_Color_CreateHex(0xFFFFFFFF);
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)

# CP_Color_Lerp
Linearly interpolate (lerp) between two given [CP_Color](Types.md#cp_color) inputs using an interpolation factor from 0.0 to 1.0. Returns the newly computed color.

The calculation applied to each component of the color:

```C
new_color = (1.0f - lerp_factor) * a + lerp_factor * b;
```

## Function
```C
CP_Color CP_Color_Lerp(CP_Color a, CP_Color b, float t);
```

### Parameters
* a ([CP_Color](Types.md#cp_color)) - The base color to lerp from. The return value is `a` when `lerp_factor` = 0.0.
* b ([CP_Color](Types.md#cp_color)) - The end color to lerp to. The return values is `b` when `lerp_factor` = 1.0.
* lerp_factor (float) - The value between 0.0 and 1.0 used to linearly interpolate from `a` to `b`.

### Return
* [CP_Color](Types.md#cp_color) - The new CP_Color variable with the interpolated colors.

## Example
```C
void update()
{
    // Create colors for the four corners of the screen
    CP_Color red = CP_Color_Create(255, 0, 0, 255);
    CP_Color green = CP_Color_Create(0, 255, 0, 255);
    CP_Color blue = CP_Color_Create(0, 0, 255, 255);
    CP_Color white = CP_Color_Create(255, 255, 255, 255);

    // Get the mouse position relative to the canvas
    float mx = (float)CP_Input_GetMouseWorldX() / (float)CP_System_GetDisplayWidth();
    float my = (float)CP_Input_GetMouseWorldY() / (float)CP_System_GetDisplayHeight();

    // Clamp the values
    mx = CP_Math_ClampFloat(mx, 0.0f, 1.0f);
    my = CP_Math_ClampFloat(my, 0.0f, 1.0f);

    // Lerp the colors based on position along the x-axis
    CP_Color lerpx1 = CP_Color_Lerp(red, blue, mx);
    CP_Color lerpx2 = CP_Color_Lerp(green, white, mx);

    // Lerp the two previous colors based on y-axis position
    CP_Color lerp = CP_Color_Lerp(lerpx1, lerpx2, my);

    // Set the background based on the lerp
    CP_Graphics_ClearBackground(lerp);
}
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Input_GetMouseWorldX](Input.md#cp_input_getmouseworldx)
* [CP_Input_GetMouseWorldY](Input.md#cp_input_getmouseworldy)
* [CP_System_GetDisplayWidth](System.md#cp_system_getdisplaywidth)
* [CP_System_GetDisplayHeight](System.md#cp_system_getdisplayheight)
* [CP_Math_ClampFloat](Math.md#cp_math_clampfloat)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)

# CP_Color_FromColorHSL
Converts a [CP_ColorHSL](Types.md#cp_colorhsl) to a [CP_Color](Types.md#cp_color).

NOTE: All graphics and settings functions within CProcessing expect colors in RGB format ([CP_Color](Types.md#cp_color)) so you will be required to convert using this function if you are using HSL ([CP_ColorHSL](Types.md#cp_colorhsl)) formats for various effects.

## Function
```C
CP_Color CP_Color_FromColorHSL(CP_ColorHSL hsl);
```

### Parameters
* hsl ([CP_ColorHSL](Types.md#cp_colorhsl)) - The HSL value to be converted to RGB.

### Return
* [CP_Color](Types.md#cp_color) - The new CP_Color variable.

## Example
```C
void update()
{
    // Get the current framecount and set the background to black
    int frameCount = CP_System_GetFrameCount();
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Use framecount to slowly change the HSL color through all colors of the rainbow
    CP_ColorHSL hsl = CP_ColorHSL_Create(360 - (frameCount * 3), 100, 50, 255);

    // Convert from HSL to RGB to be used as the fill color and draw a rectangle
    CP_Settings_Fill(CP_Color_FromColorHSL(hsl));
    CP_Graphics_DrawRectAdvanced(10, 10, 380, 380, 0, 20);
}
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_ColorHSL_Create](Color.md#cp_colorhsl_create)
* [CP_System_GetFrameCount](System.md#cp_system_getframecount)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Graphics_DrawRectAdvanced](Graphics.md#cp_graphics_drawrectadvanced)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)

# CP_ColorHSL_Create
Create a [CP_ColorHSL](Types.md#cp_colorhsl) from given hue, saturation, value, and alpha values.

## Function
```C
CP_ColorHSL CP_ColorHSL_Create(int h, int s, int l, int a);
```

### Parameters
* h (int) - The hue of the color. Range of 0-360
* s (int) - The saturation of the color. Range of 0-100.
* v (int) - The value of the color. Range of 0-100.
* a (int) - The alpha of the color. Range of 0-255.

### Return
* [CP_ColorHSL](Types.md#cp_colorhsl) - The new CP_ColorHSL variable.

## Example
```C
void update()
{
    // Get the current framecount and set the background to black
    int frameCount = CP_System_GetFrameCount();
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Use framecount to slowly change the HSL color through all colors of the rainbow
    CP_ColorHSL hsl = CP_ColorHSL_Create((frameCount * 3) % 360, 100, 50, 255);
    CP_Settings_Fill(CP_Color_FromColorHSL(hsl));
    CP_Graphics_DrawRectAdvanced(10, 10, 380, 380, 0, 20);
}
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Color_FromColorHSL](Color.md#cp_color_fromcolorhsl)
* [CP_System_GetFrameCount](System.md#cp_system_getframecount)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Graphics_DrawRectAdvanced](Graphics.md#cp_graphics_drawrectadvanced)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)

# CP_ColorHSL_Lerp
Linearly interpolate (lerp) between two given [CP_ColorHSL](Types.md#cp_colorhsl) inputs using an interpolation factor from 0.0 to 1.0. Returns the newly computed color.

The calculation applied to each component of the color:

```C
new_color = (1.0f - lerp_factor) * a + lerp_factor * b;
```

## Function
```C
CP_ColorHSL CP_ColorHSL_Lerp(CP_ColorHSL a, CP_ColorHSL b, float t);
```

### Parameters
* a ([CP_ColorHSL](Types.md#cp_colorhsl)) - The base color to lerp from. The return value is `a` when `lerp_factor` = 0.0.
* b ([CP_ColorHSL](Types.md#cp_colorhsl)) - The end color to lerp to. The return values is `b` when `lerp_factor` = 1.0.
* lerp_factor (float) - The value between 0.0 and 1.0 used to linearly interpolate from `a` to `b`.

### Return
* [CP_ColorHSL](Types.md#cp_colorhsl) - The new CP_ColorHSL variable.

## Example
```C
void update()
{
    // Create colors for the left and right side of the screen
    CP_ColorHSL start = CP_ColorHSL_Create(0, 100, 50, 255);
    CP_ColorHSL end = CP_ColorHSL_Create(359, 100, 50, 255);

    // Get the mouse position relative to the canvas
    float mx = (float)CP_Input_GetMouseWorldX() / (float)CP_System_GetDisplayWidth();

    // Clamp the values
    mx = CP_Math_ClampFloat(mx, 0.0f, 1.0f);

    // Lerp the colors based on mouse position along the x-axis
    CP_ColorHSL lerp = CP_ColorHSL_Lerp(start, end, mx);

    // Set the background based on the lerp
    CP_Graphics_ClearBackground(CP_Color_FromColorHSL(lerp));
}
```

## Related
* [CP_ColorHSL_Create](Color.md#cp_colorhsl_create)
* [CP_Color_FromColorHSL](Color.md#cp_color_fromcolorhsl)
* [CP_Input_GetMouseWorldX](Input.md#cp_input_getmouseworldx)
* [CP_System_GetDisplayWidth](System.md#cp_system_getdisplaywidth)
* [CP_Math_ClampFloat](Math.md#cp_math_clampfloat)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)

# CP_ColorHSL_FromColor
Converts a [CP_Color](Types.md#cp_color) to a [CP_ColorHSL](Types.md#cp_colorhsl).

NOTE: All graphics and settings functions within CProcessing expect colors in RGB format ([CP_Color](Types.md#cp_color)) so you will be required to convert if you are using HSL ([CP_ColorHSL](Types.md#cp_colorhsl)) formats for various effects.

## Function
```C
CP_ColorHSL CP_ColorHSL_FromColor(CP_Color rgb);
```

### Parameters
* rgb ([CP_Color](Types.md#cp_color)) - The RGB value to be converted to HSL.

### Return
* [CP_ColorHSL](Types.md#cp_colorhsl) - The new C_ColorHSL variable.

## Example
```C
void update()
{
    // Get the current framecount and set the background to black
    int frameCount = CP_System_GetFrameCount();
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Use framecount to slowly change the HSL color through all colors of the rainbow
    CP_ColorHSL hsl = CP_ColorHSL_Create(360 - (frameCount * 3), 100, 50, 255);

    // Convert from HSL to RGB to be used as the fill color and draw a rectangle
    CP_Settings_Fill(CP_Color_FromColorHSL(hsl));
    CP_Graphics_DrawRectAdvanced(10, 10, 380, 380, 0, 20);
}
```

## Related
* [CP_ColorHSL_Create](Color.md#cp_colorhsl_create)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetFrameCount](System.md#cp_system_getframecount)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Graphics_DrawRectAdvanced](Graphics.md#cp_graphics_drawrectadvanced)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
