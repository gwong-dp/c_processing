This section contains all functions relating to CP_Font.

**NOTE:** There is no `CP_Font_Free()` function, so you don't have to free any font loaded.

# Table Of Contents
* [CP_Font_Load](#cp_font_load)
* [CP_Font_Set](#cp_font_set)
* [CP_Font_DrawText](#cp_font_drawtext)
* [CP_Font_DrawTextBox](#cp_font_drawtextbox)

# CP_Font_Load
Loads a [CP_Font](Types.md#cp_font) from the given filepath.

## Function
```C
CP_Font CP_Font_Load(const char* filepath);
```

### Parameters
* filepath (const char*) - The filepath to the font that you want to load.

### Return
* [CP_Font](Types.md#cp_font) - The font loaded from the given filepath, will be NULL if no font could be loaded.

## Example
```C
CP_Font myFont;

void init()
{
    myFont = CP_Font_Load("Assets/Justins_Font.ttf");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    CP_Font_Set(myFont);
    CP_Font_DrawText("Hi Justin!", 100, 100);
}

void shutdown()
{
    // note that you don't need to free fonts unlike images!
}

```

## Related
* [CP_Font](Types.md#cp_font)
* [CP_Font_Set](#cp_font_set)
* [CP_Font_DrawText](#cp_font_drawtext)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)

# CP_Font_Set
Sets a given [CP_Font](Types.md#cp_font) as the font to use when drawing text.

## Function
```C
void CP_Font_Set(CP_Font font);
```

### Parameters
* font ([CP_Font](Types.md#cp_font)) - The font that you want to use when drawing text.

### Return
This function does not return anything.

## Example
```C
CP_Font myFont;

void init()
{
    myFont = CP_Font_Load("Assets/Justins_Font.ttf");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    CP_Font_Set(myFont);
    CP_Font_DrawText("Hi Justin!", 100, 100);
}

void shutdown()
{
    // note that you don't need to free fonts unlike images!
}
```

## Related
* [CP_Font](Types.md#cp_font)
* [CP_Font_Load](#cp_font_load)
* [CP_Font_DrawText](#cp_font_drawtext)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)

# CP_Font_DrawText
Draws the given text to the screen using the current [CP_Font](Types.md#cp_font).

## Function
```C
void CP_Font_DrawText(const char* text, float x, float y);
```

### Parameters
* text (const char*) - The text you want to display on the screen.
* x (float) - The x position of the text.
* y (float) - The y position of the text.

### Return
This function does not return anything

## Example
```C
#include <stdio.h>
#include <stdlib.h>

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
    CP_Settings_TextSize(20.0f);

    char buffer[50] = { 0 };
    sprintf_s(buffer, 50, "Frame count: %i", CP_System_GetFrameCount());
    CP_Font_DrawText(buffer, 30, 30);

    CP_Font_DrawText("Hi Justin!", 100, 200);
}
```

## Related
* [CP_Font](Types.md#cp_font)
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)

# CP_Font_DrawTextBox
Draws the given text onto the screen within a text box using the current [CP_Font](Types.md#cp_font).

## Function
```C
void CP_Font_DrawTextBox(const char* text, float x, float y, float rowWidth);
```

### Parameters
* text (const char*) - The text you want to display on the screen.
* x (float) - The x position of the text.
* y (float) - The y position of the text.
* rowWidth (float) - The width of each row.

### Return
This function does not return anything

## Example
```C
void update()
{
  CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

  CP_Font_DrawTextBox("Hi Justin!", 100, 100, 20);
}
```

## Related
* [CP_Font](Types.md#cp_font)
* [CP_Settings_TextSize](Settings.md#cp_settings_textsize)
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
