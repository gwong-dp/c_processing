This section contains all functions relating to CP_Image.

# Table Of Contents
* [CP_Image_Load](#cp_image_load)
* [CP_Image_Free](#cp_image_free)
* [CP_Image_GetWidth](#cp_image_getwidth)
* [CP_Image_GetHeight](#cp_image_getheight)
* [CP_Image_Draw](#cp_image_draw)
* [CP_Image_DrawAdvanced](#cp_image_drawadvanced)
* [CP_Image_DrawSubImage](#cp_image_drawsubimage)
* [CP_Image_CreateFromData](#cp_image_createfromdata)
* [CP_Image_Screenshot](#cp_image_screenshot)
* [CP_Image_GetPixelData](#cp_image_getpixeldata)
* [CP_Image_UpdatePixelData](#cp_image_updatepixeldata)

# CP_Image_Load
Load a [CP_Image](Types.md#cp_image) by inputting the file path of the image file as a string (const char*). When finished, the image should be released using [CP_Image_Free](#cp_image_free).

## Function
```C
CP_Image CP_Image_Load(const char* filepath);
```

### Parameters
* filepath (const char*) - The path to the image file that you want to load.

### Return
* [CP_Image](Types.md#cp_image) - The new image created from the specified file. Will be NULL if the image could not be created.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    justinFace = CP_Image_Load("./Assets/Justins_face.png");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int width = CP_System_GetWindowWidth();
    int height = CP_System_GetWindowHeight();

    CP_Image_Draw(justinFace, width / 2, height / 2, width / 2, width / 2, 255);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Image_Draw](Image.md#cp_image_draw)
* [CP_Image_Free](Image.md#cp_image_free)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_Free
Free a [CP_Image](Types.md#cp_image) by giving the image that you want to free.

## Function
```C
void CP_Image_Free(CP_Image* img);
```

### Parameters
* image ([CP_Image](Types.md#cp_image)) - The image that you want to free.

### Return
This function does not return anything.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    justinFace = CP_Image_Load("./Assets/Justins_face.png");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int width = CP_System_GetWindowWidth();
    int height = CP_System_GetWindowHeight();

    CP_Image_Draw(justinFace, width / 2, height / 2, width / 2, width / 2, 255);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Image_Draw](Image.md#cp_image_draw)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_GetWidth
Get the width in pixels of a given [CP_Image](Types.md#cp_image).

## Function
```C
int CP_Image_GetWidth(CP_Image img);
```

### Parameters
* image ([CP_Image](Types.md#cp_image)) - The image that you want to know the width of.

### Return
* int - The width of the image in pixels.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    justinFace = CP_Image_Load("./Assets/Justins_face.png");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int width = CP_Image_GetWidth(justinFace);

    int windowWidth = CP_System_GetWindowWidth();
    int windowHeight = CP_System_GetWindowHeight();

    CP_Image_Draw(justinFace, windowWidth / 2, windowHeight / 2, windowWidth / 2, windowHeight / 2, 255);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_Draw](Image.md#cp_image_draw)
* [CP_Image_Free](Image.md#cp_image_free)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_GetHeight
Get the height in pixels of a given [CP_Image](Types.md#cp_image).

## Function
```C
int CP_Image_GetHeight(CP_Image img);
```

### Parameters
* image ([CP_Image](Types.md#cp_image)) - The image that you want to know the height of.

### Return
* int - The height of the image in pixels.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    justinFace = CP_Image_Load("./Assets/Justins_face.png");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int height = CP_Image_GetHeight(justinFace);

    int windowWidth = CP_System_GetWindowWidth();
    int windowHeight = CP_System_GetWindowHeight();

    CP_Image_Draw(justinFace, windowWidth / 2, windowHeight / 2, windowWidth / 2, windowHeight / 2, 255);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_Draw](Image.md#cp_image_draw)
* [CP_Image_Free](Image.md#cp_image_free)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_Draw
Draws a given [CP_Image](Types.md#cp_image) to the screen using the given size and coordinates.

## Function
```C
void CP_Image_Draw(CP_Image img, float x, float y, float w, float h, int alpha);
```

### Parameters
* image ([CP_Image](Types.md#cp_image)) - The image that you want to draw to the screen.
* x (float) - The x coordinate of the image in screen coordinates.
* y (float) - The y coordinate of the image in screen coordinates.
* w (float) - The width to draw the image in pixels.
* h (float) - The height to draw the image in pixels.
* alpha (float) - The alpha value to draw the image with (0-255).

### Return
This function does not return anything.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    justinFace = CP_Image_Load("./Assets/Justins_face.png");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int width = CP_System_GetWindowWidth();
    int height = CP_System_GetWindowHeight();

    CP_Image_Draw(justinFace, width / 2, height / 2, width / 2, width / 2, 255);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}

```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_Free](Image.md#cp_image_free)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_DrawAdvanced
Draws a given [CP_Image](Types.md#cp_image) to the screen using the given position, size, alpha, and rotation.

## Function
```C
void CP_Image_DrawAdvanced(CP_Image img, float x, float y, float w, float h, int alpha, float degrees);
```

### Parameters
* image ([CP_Image](Types.md#cp_image)) - The image that you want to draw to the screen.
* x (float) - The x coordinate of the image in screen coordinates.
* y (float) - The y coordinate of the image in screen coordinates.
* w (float) - The width to draw the image in pixels.
* h (float) - The height to draw the image in pixels.
* alpha (float) - The alpha value to draw the image with (0-255).
* degrees (float) - The degrees to rotate the image.

### Return
This function does not return anything.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    justinFace = CP_Image_Load("./Assets/Justins_face.png");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int width = CP_System_GetWindowWidth();
    int height = CP_System_GetWindowHeight();

    CP_Image_DrawAdvanced(justinFace, width / 2, height / 2, width / 2, width / 2, 255, 180);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_Free](Image.md#cp_image_free)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_DrawSubImage
Draws a given [CP_Image](Types.md#cp_image) to the screen using the given position, size, texture coordinates, and alpha.

## Function
```C
void CP_Image_DrawSubImage(CP_Image img, float x, float y, float w, float h, float u0, float v0, float u1, float v1, int alpha);
```

### Parameters
* image ([CP_Image](Types.md#cp_image)) - The image that you want to draw to the screen.
* x (float) - The x coordinate of the image in screen coordinates.
* y (float) - The y coordinate of the image in screen coordinates.
* w (float) - The width to draw the image in pixels.
* h (float) - The height to draw the image in pixels.
* s0 (float) - The left most pixel of the sub-image(far left = 0).
* t0 (float) - The top most pixel of the sub-image (top = 0).
* s1 (float) - The right most pixel for the sub-image (far right = image width).
* t0 (float) - The bottom most pixel for the sub-image (bottom = image height).
* alpha (float) - The alpha value to draw the image with (0-255).

### Return
This function does not return anything.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    justinFace = CP_Image_Load("./Assets/Justins_face.png");
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int width = CP_System_GetWindowWidth();
    int height = CP_System_GetWindowHeight();

    int imageWidth = CP_Image_GetWidth(justinFace);
    int imageHeight = CP_Image_GetHeight(justinFace);

    // draws the top left quarter of the image
    CP_Image_DrawSubImage(justinFace, (width / 2), (height / 2), width, height, 0, 0, imageWidth / 2, imageHeight / 2, 255);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Image_GetWidth](Image.md#cp_image_getwidth)
* [CP_Image_GetHeight](Image.md#cp_image_getheight)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_Free](Image.md#cp_image_free)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_CreateFromData
Creates a [CP_Image](Types.md#cp_image) from the given data.

## Function
```C
CP_Image CP_Image_CreateFromData(int w, int h, unsigned char* pixelDataInput);
```

### Parameters
* w (int) - The width you want the created image to be (must correspond to the size of the data given).
* h (int) - The height you want the created image to be (must correspond to the size of the data given).
* pixelDataInput (unsigned char*) - The data to use to create the new image.

### Return
* [CP_Image](Types.md#cp_image) - A new [CP_Image](Types.md#cp_image) based on the provided data.

## Example
```C
CP_Image justinFace = NULL;

void init()
{
    unsigned char pixelData[] = {
        255, 0, 0, 255, 255, 0, 0, 255, // 2 red pixels
        0, 0, 255, 255, 0, 0, 255, 255    // 2 blue pixels
    };


    justinFace = CP_Image_CreateFromData(2, 2, pixelData);
}

void update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    int width = CP_System_GetWindowWidth();
    int height = CP_System_GetWindowHeight();

        // draws the top left quarter of the image
    CP_Image_Draw(justinFace, width / 2, height / 2, width, height, 255);
}

void shutdown()
{
    CP_Image_Free(&justinFace);
}
```

## Related
* [CP_Image_Draw](Image.md#cp_image_draw)
* [CP_Image_Free](Image.md#cp_image_free)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowheight)

# CP_Image_Screenshot
This function will capture an area of the screen and return it as a [CP_Image](Types.md#cp_image).

## Function
```C
CP_Image CP_Image_Screenshot(int x, int y, int w, int h);
```

### Parameters
* x (int) - The X coordinate of the top left corner of the screen area to be captured.
* y (int) - The Y coordinate of the top left corner of the screen area to be captured.
* w (int) - The width of the screen area to be captured.
* h (int) - The height of the screen area to be captured.

### Return
* [CP_Image](Types.md#cp_image) - A new [CP_Image](Types.md#cp_image) that matches the specified screen area.

## Example
```C
void update()
{
    if (CP_Input_KeyTriggered(KEY_S))
    {
        int windowWidth = CP_System_GetWindowWidth();
        int windowHeight = CP_System_GetWindowHeight();

        // Take a screenshot of the entire window
        CP_Image screenshot = CP_Image_Screenshot(0, 0, windowWidth, windowHeight);
    }
}
```

## Related
* [CP_Input_KeyTriggered](Input.md#cp_input_keytriggered)
* [CP_System_GetWindowWidth](System.md#cp_system_getwindowwidth)
* [CP_System_GetWindowHeight](System.md#cp_system_getwindowwidth)

# CP_Image_GetPixelData
This function allows you to get an array of [CP_Color](Types.md#cp_color) variables that correspond to the pixels in a [CP_Image](Types.md#cp_image). You must create and delete the array yourself, and its length must be the same as the number of pixels in the image (in other words, the image width times the image height).

## Function
```C
void CP_Image_GetPixelData(CP_Image img, CP_Color* pixelDataOutput);
```

### Parameters
* img ([CP_Image](Types.md#cp_image)) - The image to get the pixel data from.
* pixelDataOutput ([CP_Color](Types.md#cp_color)*) - This CP_Color array will be filled with the color data from the image.

### Return
This function does not return anything.

## Example
```C
CP_Image myImage;

void init()
{
    // Load an image
    myImage = CP_Image_Load("./Assets/Tree.png");

    // Get the size of the array using the image width and height
    int arraySize = CP_Image_GetWidth(myImage) * CP_Image_GetHeight(myImage);

    // Create the array using the image size and the size of a CP_Color
    CP_Color* colorArray = malloc(arraySize * sizeof(CP_Color));

    // Get the array of pixel colors from the image
    CP_Image_GetPixelData(myImage, colorArray);

    // If any pixel is not transparent, set it to red
    CP_Color red = CP_Color_Create(255, 0, 0, 255);
    for (int i = 0; i < arraySize; ++i)
    {
        if (colorArray[i].a > 0)
        {
            colorArray[i] = red;
        }
    }

    // Update the image with the altered pixels
    CP_Image_UpdatePixelData(myImage, colorArray);

    // Free the array memory
    free(colorArray);
}

void update()
{
    CP_Image_Draw(myImage, 50, 100, 100, 200, 255);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Color](Types.md#cp_color)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_GetWidth](Image.md#cp_image_getwidth)
* [CP_Image_GetHeight](Image.md#cp_image_getheight)
* [CP_Image_UpdatePixelData](Image.md#cp_image_updatepixeldata)
* [CP_Image_Draw](Image.md#cp_image_draw)

# CP_Image_UpdatePixelData
This function will replace the current pixel data in the image with the data in the array which is passed into the function. Make sure the array is at least as big as the number of pixels in the image!

## Function
```C
void CP_Image_UpdatePixelData(CP_Image img, CP_Color* pixelDataInput);
```

### Parameters
* img (CP_Image) - The image to copy the pixel data into.
* pixelDataInput (CP_Color*) - A CP_Color array that will be used to change the image pixels.

### Return
This function does not return anything.

## Example
```C
CP_Image myImage;

void init()
{
    // Load an image
    myImage = CP_Image_Load("./Assets/Tree.png");

    // Get the size of the array using the image width and height
    int arraySize = CP_Image_GetWidth(myImage) * CP_Image_GetHeight(myImage);

    // Create the array using the image size and the size of a CP_Color
    CP_Color* colorArray = malloc(arraySize * sizeof(CP_Color));

    // Get the array of pixel colors from the image
    CP_Image_GetPixelData(myImage, colorArray);

    // If any pixel is not transparent, set it to red
    CP_Color red = CP_Color_Create(255, 0, 0, 255);
    for (int i = 0; i < arraySize; ++i)
    {
        if (colorArray[i].a > 0)
        {
            colorArray[i] = red;
        }
    }

    // Update the image with the altered pixels
    CP_Image_UpdatePixelData(myImage, colorArray);

    // Free the array memory
    free(colorArray);
}

void update()
{
    CP_Image_Draw(myImage, 50, 100, 100, 200, 255);
}
```

## Related
* [CP_Image](Types.md#cp_image)
* [CP_Color](Types.md#cp_color)
* [CP_Image_Load](Image.md#cp_image_load)
* [CP_Image_GetWidth](Image.md#cp_image_getwidth)
* [CP_Image_GetHeight](Image.md#cp_image_getheight)
* [CP_Image_GetPixelData](Image.md#cp_image_getpixeldata)
