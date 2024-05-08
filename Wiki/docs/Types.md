This section contains all C_Processing types declared in cprocessing_common.h

# Table Of Contents
* [CP_BOOL](#cp_bool)
* [CP_Image](#cp_image)
* [CP_Sound](#cp_sound)
* [CP_Font](#cp_font)
* [CP_Color](#cp_color)
* [CP_ColorHSL](#cp_colorhsl)
* [CP_LINE_CAP_MODE](#cp_line_cap_mode)
* [CP_LINE_JOINT_MODE](#cp_line_joint_mode)
* [CP_POSITION_MODE](#cp_position_mode)
* [CP_BLEND_MODE](#cp_blend_mode)
* [CP_IMAGE_FILTER_MODE](#cp_image_filter_mode)
* [CP_IMAGE_WRAP_MODE](#cp_image_wrap_mode)
* [CP_TEXT_ALIGN_HORIZONTAL](#cp_text_align_horizontal)
* [CP_TEXT_ALIGN_VERTICAL](#cp_text_align_vertical)
* [CP_SOUND_GROUP](#cp_sound_group)
* [CP_Vector](#cp_vector)
* [CP_Matrix](#cp_matrix)
* [CP_KEY](#cp_key)
* [CP_MOUSE](#cp_mouse)
* [CP_GAMEPAD](#cp_gamepad)
* [CP_MAX_GAMEPADS](#cp_max_gamepads)

# CP_BOOL
A TRUE (1) or FALSE (0) type.

# CP_Image
A type used to store loaded images.

## Related
* [All Image Functions](Image.md)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_Draw](Image.md#cp_image_draw)
* [CP_Image_Free](Image.md#cp_image_free)

# CP_Sound
A type used to store loaded sounds.

## Related
* [All Sound Functions](Sound.md)
* [CP_Sound_Load](Sound.md#cp_sound_load)
* [CP_Sound_Play](Sound.md#cp_sound_play)
* [CP_Sound_Free](Sound.md#cp_sound_free)

# CP_Font
A type used to store loaded fonts.

## Related
* [All Font Functions](Font.md)
* [CP_Font_Load](Font.md#cp_font_load)
* [CP_Font_Set](Font.md#cp_font_set)

# CP_Color
A type that stores red, green, blue, and alpha values of a color (RGBA). Each color is represented by a number between 0 and 255.

## Common Colors
* black - CP_Color_Create(0, 0, 0, 255)
* white - CP_Color_Create(255, 255, 255, 255)
* gray 50% - CP_Color_Create(128, 128, 128, 255)
* red - CP_Color_Create(255, 0, 0, 255)
* green - CP_Color_Create(0, 255, 0, 255)
* blue - CP_Color_Create(0, 0, 255, 255)

## Related
* [All Color Functions](Color.md)
* [CP_ColorHSL](#cp_colorhsl)
* [CP_Color_Create](Color.md#cp_color_create)

# CP_ColorHSL
A type that stores the hue, saturation, light, and alpha of a color (HSLA). Hue has a range of 0 - 360, Saturation and Light have a range of 0 - 100, and Alpha has a range of 0 - 255.

## Related
* [All HSL Color Functions](Color.md)
* [CP_ColorHSL_Create](Color.md#cp_colorhsl_create)

# CP_LINE_CAP_MODE
Indicates how the ends of lines should be drawn. The default is CP_LINE_CAP_BUTT.

## Valid Enums
* CP_LINE_CAP_BUTT
* CP_LINE_CAP_ROUND
* CP_LINE_CAP_SQUARE

## Related
* [CP_Settings_LineCapMode](Settings.md#cp_settings_linecapmode)

# CP_LINE_JOINT_MODE
Controls how sharp corners are when drawing. Default is CP_LINE_JOINT_BEVEL.

## Valid Enums
* CP_LINE_JOINT_ROUND
* CP_LINE_JOINT_BEVEL
* CP_LINE_JOINT_MITER

## Related
* [CP_Settings_LineJointMode](Settings.md#cp_settings_linejointmode)

# CP_POSITION_MODE
Controls the local origin for drawing functions. Center will draw objects from the center, corner will draw from the top left corner.

## Valid Enums
* CP_POSITION_CENTER
* CP_POSITION_CORNER

## Related
* [CP_Settings_RectMode](Settings.md#cp_settings_rectmode)
* [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode)
* [CP_Settings_ImageMode](Settings.md#cp_settings_imagemode)

# CP_BLEND_MODE
Controls the math that is done when two colors are drawn on top of each other. CP_BLEND_ALPHA is the default.

## Valid Enums
* CP_BLEND_ALPHA - Blends the two colors together naturally
* CP_BLEND_ADD - Adds the overlapping color values together
* CP_BLEND_SUBTRACT - Subtracts the first color from the second color
* CP_BLEND_MULTIPLY - Multiplies the color values together
* CP_BLEND_MIN - Takes the lower values in each color
* CP_BLEND_MAX - Takes the highest values in each color

## Related
* [CP_Settings_BlendMode](Settings.md#cp_settings_blendmode)

# CP_IMAGE_FILTER_MODE
Chooses what math to use when anti-aliasing images.

## Valid Enums
* CP_IMAGE_FILTER_NEAREST - Filters the nearest pixel of the image, good for pixel art, has sharp edges
* CP_IMAGE_FILTER_LINEAR - Attempts to blend all nearby pixels together to have smoother edges/lines

## Related
* [CP_Settings_ImageFilterMode](Settings.md#cp_settings_imagefiltermode)

# CP_IMAGE_WRAP_MODE
Controls the math for what happens at the edge of textures.

## Valid Enums
* CP_IMAGE_WRAP_CLAMP - Samples the edge of the border when drawing texels outside the image
* CP_IMAGE_WRAP_CLAMP_EDGE - Samples the pixel closest to the edge of the border when drawing texels outside the image
* CP_IMAGE_WRAP_REPEAT - Consistently repeats the image when drawing texels outside the image
* cp_IMAGE_WRAP_MIRROR - Consistently mirrors the image when drawing texels outside the image

## Related
* [CP_Settings_ImageWrapMode](Settings.md#cp_settings_imagewrapmode)

# CP_TEXT_ALIGN_HORIZONTAL
Controls the horizontal alignment of text when drawing.

## Valid Enums
* CP_TEXT_ALIGN_H_LEFT - Aligns it so the starting point is to the left of the text and grows towards the right.
* CP_TEXT_ALIGN_H_CENTER - Aligns it so the starting point is the center of the text and it grows outward.
* CP_TEXT_ALIGN_H_RIGHT - Aligns it so the starting point is to the right of the text and grows towards the left.

## Related
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)

# CP_TEXT_ALIGN_VERTICAL
Controls the vertical alignment of text when drawing.

## Valid Enums
* CP_TEXT_ALIGN_V_TOP - Aligns it so that the starting point is above the tallest letter in the text.
* CP_TEXT_ALIGN_V_MIDDLE - Aligns it so the starting point is in the center (vertically) of the text.
* CP_TEXT_ALIGN_V_BOTTOM - Aligns it so that the starting point is below the lowest letter in the text, including tails (such as lower-case g).
* CP_TEXT_ALIGN_V_BASELINE - Aligns it so that the starting point is below the letters in the text, excluding tails.

## Related
* [CP_Settings_TextAlignment](Settings.md#cp_settings_textalignment)

# CP_SOUND_GROUP
Allows for the organization of sounds within different groups.

## Valid Enums
* CP_SOUND_GROUP_0
* CP_SOUND_GROUP_1
* CP_SOUND_GROUP_2
* CP_SOUND_GROUP_3
* CP_SOUND_GROUP_4
* CP_SOUND_GROUP_5
* CP_SOUND_GROUP_6
* CP_SOUND_GROUP_7
* CP_SOUND_GROUP_8
* CP_SOUND_GROUP_9
* CP_SOUND_GROUP_MAX
* CP_SOUND_GROUP_SFX = CP_SOUND_GROUP_0
* CP_SOUND_GROUP_MUSIC = CP_SOUND_GROUP_1

## Related
* [All Sound Functions](Sound.md)
* [CP_Sound_ResumeGroup](Sound.md#cp_sound_resumegroup)
* [CP_Sound_PauseGroup](Sound.md#cp_sound_pausegroup)

# CP_Vector
A structure that holds two float values. Used for linear algebra, position values, or any purpose requiring two floats.

## Example
```C
void update()
{
    // create a position vec2
    CP_Vector position;

    // set the position
    position.x = 100;
    position.y = 200;

    // scale the position by 1.5
    position = CP_Vector_Scale(position, 1.5f);

    // draw a rectangle at the position
    CP_Graphics_DrawRect(position[0], position[1], 50, 50);
}
```
## Related
* [All Vector Functions](Vector.md)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)

# CP_Matrix
A structure that holds 9 floats, used for linear algebra, transformations, or any other purpose requiring 9 floats.

## Example
```C
void update()
{
    // create a transform and set it to initialized values
    CP_Matrix transform = CP_Matrix_Identity();

    // make the matrix a translation transform by (100, 100)
    transform = CP_Matrix_Translate((CP_Vector) { 100, 100 });

    // create a vec2 position
    CP_Vector position;
    position.x = 100;
    position.y = 100;

    // apply that matrix to the point and store it in the position
    position = CP_Matrix_MultiplyVector(transform, position);
}
```

## Related
* [All Matrix Functions](Matrix.md)
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)

# CP_KEY
An Enum used to check keyboard operations.

## Valid Enums
* KEY_SPACE
* KEY_APOSTROPHE
* KEY_COMMA
* KEY_MINUS
* KEY_PERIOD
* KEY_SLASH
* KEY_0
* KEY_1
* KEY_2
* KEY_3
* KEY_4
* KEY_5
* KEY_6
* KEY_7
* KEY_8
* KEY_9
* KEY_SEMICOLON
* KEY_EQUAL
* KEY_A
* KEY_B
* KEY_C
* KEY_D
* KEY_E
* KEY_F
* KEY_G
* KEY_H
* KEY_I
* KEY_J
* KEY_K
* KEY_L
* KEY_M
* KEY_N
* KEY_O
* KEY_P
* KEY_Q
* KEY_R
* KEY_S
* KEY_T
* KEY_U
* KEY_V
* KEY_W
* KEY_X
* KEY_Y
* KEY_Z
* KEY_LEFT_BRACKET
* KEY_BACKSLASH
* KEY_RIGHT_BRACKET
* KEY_GRAVE_ACCENT
* KEY_WORLD_1
* KEY_WORLD_2
* KEY_ESCAPE
* KEY_ENTER
* KEY_TAB
* KEY_BACKSPACE
* KEY_INSERT
* KEY_DELETE
* KEY_RIGHT
* KEY_LEFT
* KEY_DOWN
* KEY_UP
* KEY_PAGE_UP
* KEY_PAGE_DOWN
* KEY_HOME
* KEY_END
* KEY_CAPS_LOCK
* KEY_SCROLL_LOCK
* KEY_NUM_LOCK
* KEY_PRINT_SCREEN
* KEY_PAUSE
* KEY_F1
* KEY_F2
* KEY_F3
* KEY_F4
* KEY_F5
* KEY_F6
* KEY_F7
* KEY_F8
* KEY_F9
* KEY_F10
* KEY_F11
* KEY_F12
* KEY_F13
* KEY_F14
* KEY_F15
* KEY_F16
* KEY_F17
* KEY_F18
* KEY_F19
* KEY_F20
* KEY_F21
* KEY_F22
* KEY_F23
* KEY_F24
* KEY_F25
* KEY_KP_0
* KEY_KP_1
* KEY_KP_2
* KEY_KP_3
* KEY_KP_4
* KEY_KP_5
* KEY_KP_6
* KEY_KP_7
* KEY_KP_8
* KEY_KP_9
* KEY_KP_DECIMAL
* KEY_KP_DIVIDE
* KEY_KP_MULTIPLY
* KEY_KP_SUBTRACT
* KEY_KP_ADD
* KEY_KP_ENTER
* KEY_KP_EQUAL
* KEY_LEFT_SHIFT
* KEY_LEFT_CONTROL
* KEY_LEFT_ALT
* KEY_LEFT_SUPER
* KEY_RIGHT_SHIFT
* KEY_RIGHT_CONTROL
* KEY_RIGHT_ALT
* KEY_RIGHT_SUPER
* KEY_MENU

## Related
* [All Input Functions](Input.md)
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)
* [CP_Input_KeyReleased](Input.md#cp_input_keyreleased)

# CP_MOUSE
An Enum to check Mouse operations.

## Valid Enums
* MOUSE_BUTTON_1
* MOUSE_BUTTON_2
* MOUSE_BUTTON_3
* MOUSE_BUTTON_4
* MOUSE_BUTTON_5
* MOUSE_BUTTON_6
* MOUSE_BUTTON_7
* MOUSE_BUTTON_8
* MOUSE_BUTTON_LAST = MOUSE_BUTTON_8
* MOUSE_BUTTON_LEFT = MOUSE_BUTTON_1
* MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3
* MOUSE_BUTTON_RIGHT = MOUSE_BUTTON_2

## Related
* [All Input Functions](Input.md)
* [CP_Input_MouseClicked](Input.md#cp_input_mouseclicked)
* [CP_Input_MouseDown](Input.md#cp_input_mousedown)


# CP_GAMEPAD
An Enum to check gamepad operations.

## Valid Enums
* GAMEPAD_DPAD_UP
* GAMEPAD_DPAD_DOWN
* GAMEPAD_DPAD_LEFT
* GAMEPAD_DPAD_RIGHT
* GAMEPAD_START
* GAMEPAD_BACK
* GAMEPAD_LEFT_THUMB
* GAMEPAD_RIGHT_THUMB
* GAMEPAD_LEFT_SHOULDER
* GAMEPAD_RIGHT_SHOULDER
* GAMEPAD_A
* GAMEPAD_B
* GAMEPAD_X
* GAMEPAD_Y

## Related
* [All Input Functions](Input.md)
* [CP_Input_GamepadDown](Input.md#cp_input_gamepaddown)
* [CP_Input_GamepadReleased](Input.md#cp_input_gamepadreleased)

# CP_MAX_GAMEPADS
An int indicating the max number of gamepads, the current max is 4.
