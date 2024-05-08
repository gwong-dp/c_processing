This section contains all Math functions.

# Table Of Contents
* [CP_Math_ClampInt](#cp_math_clampint)
* [CP_Math_ClampFloat](#cp_math_clampfloat)
* [CP_Math_LerpInt](#cp_math_lerpint)
* [CP_Math_LerpFloat](#cp_math_lerpfloat)
* [CP_Math_Square](#cp_math_square)
* [CP_Math_Distance](#cp_math_distance)
* [CP_Math_Degrees](#cp_math_degrees)
* [CP_Math_Radians](#cp_math_radians)
* [CP_Math_ScreenToWorld](#cp_math_screentoworld)
* [CP_Math_WorldToScreen](#cp_math_worldtoscreen)

# CP_Math_ClampInt
Clamps an int to a range and returns the clamped value. If the provided int value is less than the provided min value the min value will be returned; if the provided int value is greater than the provided max value the max value will be returned; otherwise the provided int value will be returned.

## Function
```C
int CP_Math_ClampInt(int value, int min, int max);
```

### Parameters
* value (int) - The value to clamp to the input range.
* min (int) - The minimum value in the range.
* max (int) - The maximum value in the range.

### Return
* int - The clamped value within the provided range.

## Example
```C
void update()
{
    // Get the mouse position/canvas size ratio
    float mx = (float)CP_Input_GetMouseWorldX() / (float)CP_System_GetWindowWidth();
    float my = (float)CP_Input_GetMouseWorldY() / (float)CP_System_GetWindowHeight();

    // Convert to 0-255 values for color
    int r_color = (int)(mx * 255);
    int b_color = (int)(my * 255);

    // Clamp the values
    r_color = CP_Math_ClampInt(r_color, 0, 255);
    b_color = CP_Math_ClampInt(b_color, 0, 255);

    // Set the background as the color
    CP_Graphics_ClearBackground(CP_Color_Create(r_color, 0, b_color, 255));
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Input_GetMouseWorldX](Input.md#cp_input_getmouseworldx)
* [CP_Input_GetMouseWorldY](Input.md#cp_input_getmouseworldy)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Math_ClampFloat
Clamps a float to a range and returns the clamped value. If the provided float value is less than the provided min value the min value will be returned; if the provided float value is greater than the provided max value the max value will be returned; otherwise the provided float value will be returned.

## Function
```C
float CP_Math_ClampFloat(float value, float min, float max);
```

### Parameters
* value (float) - The value to clamp to the input range.
* min (float) - The minimum value in the range.
* max (float) - The maximum value in the range.

### Return
* float - The clamped value within the provided range.

## Example
```C
static CP_Color Red;
static CP_Color Green;
static CP_Color Blue;
static CP_Color White;

void init()
{
    // Create colors for the four corners of the screen
    Red = CP_Color_Create(255, 0, 0, 255);
    Green = CP_Color_Create(0, 255, 0, 255);
    Blue = CP_Color_Create(0, 0, 255, 255);
    White = CP_Color_Create(255, 255, 255, 255);
}

void update()
{
    // Get the mouse position
    float mx = (float)CP_Input_GetMouseWorldX() / (float)CP_System_GetWindowWidth();
    float my = (float)CP_Input_GetMouseWorldY() / (float)CP_System_GetWindowHeight();

    // Clamp the values
    mx = CP_Math_ClampFloat(mx, 0.0, 1.0);
    my = CP_Math_ClampFloat(my, 0.0, 1.0);

    // Lerp along both axis
    CP_Color lerpx = CP_Color_Lerp(Red, Blue, mx);
    CP_Color lerpy = CP_Color_Lerp(Green, White, my);

    // Lerp them together
    CP_Color lerp = CP_Color_Lerp(lerpx, lerpy, 0.5f);

    // Set the background based on the lerp
    CP_Graphics_ClearBackground(lerp);
}
```

## Related
* [CP_Color](Types.md#cp_color)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Color_Lerp](Color.md#cp_color_lerp)
* [CP_Input_GetMouseWorldX](Input.md#cp_input_getmouseworldx)
* [CP_Input_GetMouseWorldY](Input.md#cp_input_getmouseworldy)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Math_LerpInt
Linearly interpolates between two input integers with an input lerp factor. The lerp factor should be from 0.0 to 1.0.

## Function
```C
int CP_Math_LerpInt(int a, int b, float lerpFactor);
```

### Parameters
* a (int) - The value the function returns when lerp_factor is 0.0, the starting value.
* b (int) - The value the function returns when lerp_factor is 1.0, the ending value.
* lerp_factor (float) - The ratio used to determine what value to return between a and b.

### Return
* int - The interpolated value between `a` and `b` according to `lerp_factor`.

## Example
```C
void update()
{
    // Get the mouse position/canvas size ratio
    float mx = (float)CP_Input_GetMouseWorldX() / (float)CP_System_GetWindowWidth();
    float my = (float)CP_Input_GetMouseWorldY() / (float)CP_System_GetWindowHeight();

    // Convert to 0-255 values for color
    int r_color = CP_Math_LerpInt(0, 255, mx);
    int b_color = CP_Math_LerpInt(0, 255, my);

    // Clamp the values
    r_color = CP_Math_ClampInt(r_color, 0, 255);
    b_color = CP_Math_ClampInt(b_color, 0, 255);

    // Set the background as the color
    CP_Graphics_ClearBackground(CP_Color_Create(r_color, 0, b_color, 255));
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Math_ClampInt](Math.md#cp_math_clampint)
* [CP_Input_GetMouseWorldX](Input.md#cp_input_getmouseworldx)
* [CP_Input_GetMouseWorldY](Input.md#cp_input_getmouseworldy)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Math_LerpFloat
Linearly interpolates between two input floats with an input lerp factor. The lerp factor should be from 0.0 to 1.0.

## Function
```C
float CP_Math_LerpFloat(float a, float b, float lerpFactor);
```

### Parameters
* a (float) - The value the function returns when lerp_factor is 0.0, the starting value.
* b (float) - The value the function returns when lerp_factor is 1.0, the ending value.
* lerp_factor (float) - The ratio used to determine what value to return between a and b.

### Return
* float - The interpolated value between `a` and `b` according to `lerp_factor`.

## Example
```C
CP_Image justin_face;

void init()
{
    justin_face = CP_Image_Load(Assets.mdjustin1.png");
}

float rot_counter = 0;
void update()
{
    // Increment rotation lerp factor or reset
    if (rot_counter >= 1.0f)
        rot_counter -= 1.0f;
    else
        rot_counter += CP_System_GetDt();

    // Lerp rotation and draw image
    float rotation = CP_Math_LerpFloat(0.0f, 360.0f, rot_counter);
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
    CP_Image_DrawAdvanced(justin_face, CP_Input_GetMouseWorldX(), CP_Input_GetMouseWorldY(), 100, 150, 255, rotation);
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_DrawAdvanced](Image.md#cp_image_drawadvanced)
* [CP_Input_GetMouseWorldX](Input.md#cp_input_getmouseworldx)
* [CP_Input_GetMouseWorldY](Input.md#cp_input_getmouseworldy)
* [CP_System_GetDt](System.md#cp_system_getdt)

# CP_Math_Square
Takes in a float and returns its squared value.

## Function
```C
float CP_Math_Square(float number);
```

### Parameters
* number (float) - The number to square.

### Return
* float - The squared value.

## Example
```C
void square_init()
{
    CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
    CP_Settings_TextAlignment(CP_ALIGN_H_CENTER, CP_ALIGN_V_BOTTOM);
}

float random_value = 0.0f;
float time_elapsed = 1.5;
void square_update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    if (time_elapsed >= 1.5f)
    {
        random_value = CP_Random_RangeFloat(0.0f, 100.0f);
        time_elapsed = 0.0f;
    }
    else
        time_elapsed += dt();

    char num_string[128] = { 0 };
    sprintf_s(num_string, 128, "The square of %.2f is %.2f", random_value, CP_Math_Square(random_value));
    CP_Font_DrawTextBox(num_string, 0, canvasHeight / 2, canvasWidth);
}
```

## Related
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Random_RangeFloat](Random.md#cp_random_rangefloat)
* [CP_Font_DrawTextBox](Font.md#cp_font_drawtextbox)

# CP_Math_Distance
This function returns the distance between two provided points.

## Function
```C
float CP_Math_Distance(float x1, float y1, float x2, float y2);
```

### Parameters
* x1 (float) - The X coordinate of the first point.
* y1 (float) - The Y coordinate of the first point.
* x2 (float) - The X coordinate of the second point.
* y2 (float) - The Y coordinate of the second point.

### Return
* float - The distance between the two provided points.

## Example
```C
float startPointX = 20.0;
float startPointY = 350.0;
float endPointX = CP_Input_GetMouseX();
float endPointY = CP_Input_GetMouseY();

float distance = CP_Math_Distance(startPointX, startPointY, endPointX, endPointY);
```

## Related
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Math_Degrees
Takes an input number of radians as a float, then returns it converted to degrees as a float.

## Function
```C
float CP_Math_Degrees(float radians);
```

### Parameters
* radians (float) - The angle to convert to degrees from radians.

### Return
* float - The provided angle converted to degrees.

## Example
```C

float r_radians;
float counter = 2.0f;
void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    // Change degrees every few seconds
    if (counter >= 2.0f)
    {
        r_radians = CP_Random_RangeFloat(0.0f, PI);
        counter = 0.0f;
    }
    else
        counter += CP_System_GetDt();

    // Print out number of radians and convert to degrees
    char buffer[128] = { 0 };
    sprintf_s(buffer, 128, "Radians: %.3f\nis equal to\nDegrees: %.3f", r_radians, CP_Math_Degrees(r_radians));
    CP_Font_DrawTextBox(buffer, 100, 150, 200);
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Font_Set](Font.md#cp_font_set)
* [CP_Font_DrawTextBox](Font.md#cp_font_drawtextbox)
* [CP_System_GetDt](System.md#cp_system_getdt)
* [CP_Random_RangeFloat](Random.md#cp_random_rangefloat)

# CP_Math_Radians
Takes an input number of degrees as a float, then returns it converted to radians as a float.

## Function
```C
float CP_Math_Radians(float degrees);
```

### Parameters
* degrees (float) - The angle to convert to radians from degrees.

### Return
* float - The provided angle converted to radians.

## Example
```C

float r_degrees;
float counter = 2.0f;
void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    // Change degrees every few seconds
    if (counter >= 2.0f)
    {
        r_degrees = CP_Random_RangeFloat(0.0f, 360.0f);
        counter = 0.0f;
    }
    else
        counter += CP_System_GetDt();

    // Print out number of degrees and convert to radians
    char buffer[128] = { 0 };
    sprintf_s(buffer, 128, "Degrees: %.3f\nis equal to\nRadians: %.3f", r_degrees, CP_Math_Radians(r_degrees));
    CP_Font_DrawTextBox(buffer, 100, 150, 200);
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Font_Set](Font.md#cp_font_set)
* [CP_Font_DrawTextBox](Font.md#cp_font_drawtextbox)
* [CP_System_GetDt](System.md#cp_system_getdt)
* [CP_Random_RangeFloat](Random.md#cp_random_rangefloat)

# CP_Math_ScreenToWorld
Takes a given set of coordinates in screen space and transforms it to world coordinates. This means that the provided position will be translated by any transformation functions called ([CP_Settings_Translate](Settings.md#cp_settings_translate), [CP_Settings_Scale](Settings.md#cp_settings_scale), [CP_Settings_Rotate](Settings.md#cp_settings_rotate)).

## Function
```C
void CP_Math_ScreenToWorld(float xIn, float yIn, float* xOut, float* yOut);
```

### Parameters
* xIn (float) - The x coordinate to convert.
* yIn (float) - The y coordinate to convert.
* xOut (float*) - The variable to store the converted x coordinate.
* yOut (float*) - The variable to store the converted y coordinate.

### Return
This function does not return anything.

## Example
```C
void init()
{
    // Variables to pass into the conversion functions
    float x = PI;
    float y = PI;

    // Run back and forth 100 times
    for (int i = 0; i < 100; ++i)
    {
        CP_Math_ScreenToWorld(x, y, &x, &y);
        CP_Math_WorldToScreen(x, y, &x, &y);
    }

    // Should still be PI
    printf(" %9f\n(%9f,%9f)\n", PI, x, y);
}
```

## Related
* [CP_Math_WorldToScreen](Math.md#cp_math_worldtoscreen)


# CP_Math_WorldToScreen
Takes given set of coordinates in world space and transforms it to screen coordinates. This means that the provided position will be translated by any transformation functions called ([CP_Settings_Translate](Settings.md#cp_settings_translate), [CP_Settings_Scale](Settings.md#cp_settings_scale), [CP_Settings_Rotate](Settings.md#cp_settings_rotate)).

## Function
```C
void CP_Math_WorldToScreen)(float xIn, float yIn, float* xOut, float* yOut);
```

### Parameters
* xIn (float) - The x coordinate to convert.
* yIn (float) - The y coordinate to convert.
* xOut (float*) - The variable to store the converted x coordinate.
* yOut (float*) - The variable to store the converted y coordinate.

### Return
This function does not return anything.

## Example
```C
void init()
{
    // Variables to pass into the conversion functions
    float x = PI;
    float y = PI;

    // Run back and forth 100 times
    for (int i = 0; i < 100; ++i)
    {
        CP_Math_ScreenToWorld(x, y, &x, &y);
        CP_Math_WorldToScreen(x, y, &x, &y);
    }

    // Should still be PI
    printf(" %9f\n(%9f,%9f)\n", PI, x, y);
}
```

## Related
* [CP_Math_ScreenToWorld](Math.md#cp_math_screentoworld)
