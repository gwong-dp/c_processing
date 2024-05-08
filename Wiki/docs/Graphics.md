This section contains all of the Graphics functions.

# Table Of Contents
* [CP_Graphics_ClearBackground](#cp_graphics_clearbackground)
* [CP_Graphics_DrawPoint](#cp_graphics_drawpoint)
* [CP_Graphics_DrawLine](#cp_graphics_drawline)
* [CP_Graphics_DrawLineAdvanced](#cp_graphics_drawlineadvanced)
* [CP_Graphics_DrawRect](#cp_graphics_drawrect)
* [CP_Graphics_DrawRectAdvanced](#cp_graphics_drawrectadvanced)
* [CP_Graphics_DrawCircle](#cp_graphics_drawcircle)
* [CP_Graphics_DrawEllipse](#cp_graphics_drawellipse)
* [CP_Graphics_DrawEllipseAdvanced](#cp_graphics_drawellipseadvanced)
* [CP_Graphics_DrawTriangle](#cp_graphics_drawtriangle)
* [CP_Graphics_DrawTriangleAdvanced](#cp_graphics_drawtriangleadvanced)
* [CP_Graphics_DrawQuad](#cp_graphics_drawquad)
* [CP_Graphics_DrawQuadAdvanced](#cp_graphics_drawquadadvanced)
* [CP_Graphics_BeginShape](#cp_graphics_beginshape)
* [CP_Graphics_AddVertex](#cp_graphics_addvertex)
* [CP_Graphics_EndShape](#cp_graphics_endshape)

# CP_Graphics_ClearBackground
This function clears anything previously drawn to the screen and sets the entire screen to the provided color. Typically, you will use this at the beginning of any update loop to set a background color.

## Function
```C
void CP_Graphics_ClearBackground(CP_Color color);
```

### Parameters
* color ([CP_Color](Types.md#cp_color)) - The color that will be used to clear the screen.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // Create the color green
    CP_Color myColor = CP_Color_Create(0, 255, 0, 255);

    // Set the background color to green and erase anything that was previously crawn
    CP_Graphics_ClearBackground(myColor);
}
```

## Related
* [CP_Color_Create](Color.md#cp_color_create)

# CP_Graphics_DrawPoint
This function draws a point at a given position. The color of the point is specified with the function [CP_Settings_Fill](Settings.md#cp_settings_fill). There is no stroke option for a point.

## Function
```C
void CP_Graphics_DrawPoint(float x, float y);
```

### Parameters
* x (float) - The horizontal position of the point.
* y (float) - The vertical position of the point.

### Return
This function does not return anything.

## Example
```C
void init()
{
    // fill the background black to see the white points
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
}

void update()
{
    // Hide the cursor on this window
    CP_System_ShowCursor(false);

    // fill the pixel white
    CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));

    // draw a single pixel at the mouse position
    CP_Graphics_DrawPoint(CP_Input_GetMouseX(), CP_Input_GetMouseY());
}
```

## Related
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_System_ShowCursor](System.md#cp_system_showcursor)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Graphics_DrawLine
This function draws a line using two points. For most shapes you can set the color using [CP_Settings_Fill](Settings.md#cp_settings_fill), but a line is only a stroke, so you must use [CP_Settings_Stroke](Settings.md#cp_settings_stroke) to set the color.

## Function
```C
void CP_Graphics_DrawLine(float x1, float y1, float x2, float y2);
```

### Parameters
* x1 (float) - The first point's x position.
* y1 (float) - The first point's y position.
* x2 (float) - The second point's x position.
* y2 (float) - The second point's y position.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // set the stroke color to orange
    CP_Settings_Stroke(CP_Color_Create(255, 160, 20, 255));

    // draw a line from (100, 100) to (100, 200)
    //                      x1      y1      x2      y2
    CP_Graphics_DrawLine(100.0f, 100.0f, 500.0f, 100.0f);

    // set the stroke color to light blue
    CP_Settings_Stroke(CP_Color_Create(0, 160, 255, 255));

    // draw a line from the origin to the mouse position
    CP_Graphics_DrawLine(0.0f, 0.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY());
}
```

## Related
* [CP_Settings_Stroke](Settings.md#cp_settings_stroke)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Graphics_DrawLineAdvanced
A specialized version of the [CP_Graphics_DrawLine](Graphics.md#cp_graphics_drawline) function which allows the user to specify a rotation (in degrees). The line is always rotated around the center.

## Function
```C
void CP_Graphics_DrawLineAdvanced(float x1, float y1, float x2, float y2, float degrees);
```

### Parameters
* x1 (float) - The horizontal position of the start of the line.
* y1 (float) - The vertical position of the start of the line.
* x2 (float) - The horizontal position of the end of the line.
* y1 (float) - The vertical position of the end of the line.
* degrees (float) - The rotation in degrees.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // a line from (100, 100) to (200, 100) rotated 45 degrees about the center
    CP_Graphics_DrawLineAdvanced(100.0f, 100.0f, 200.0f, 100.0f, 45.0f);
}
```

## Related
* [CP_Graphics_DrawLine](Graphics.md#cp_graphics_drawline)

# CP_Graphics_DrawRect
This is a function that draws a rectangle on the screen at a specified point with a specified width and height.

Note: You can use [CP_Settings_RectMode](Settings.md#cp_settings_rectmode) to control whether the specified point refers to the center of the rectangle or to its top left corner.

## Function
```C
void CP_Graphics_DrawRect(float x, float y, float w, float h);
```

### Parameters
* x (float) - The horizontal position of the rectangle.
* y (float) - The vertical position of the rectangle.
* w (float) - The width of the rectangle.
* h (float) - The height of the rectangle.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // Clear the background to a blue color
    CP_Graphics_ClearBackground(CP_Color_Create(20, 200, 255, 255));

    // Draw a rectangle at the point (100, 100)
    CP_Graphics_DrawRect(100.0f, 100.0f, 50.0f, 50.0f);

    // Draw a rectangle at the mouse position
    CP_Graphics_DrawRect(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 25.0f, 25.0f);
}
```

## Related
* [CP_Settings_RectMode](Settings.md#cp_settings_rectmode)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Graphics_DrawRectAdvanced
This is a specialized version of the [CP_Graphics_DrawRect](#cp_graphics_drawrect) function which additionally allows you to specify a rotation (in degrees). This rotates the rectangle around the reference point at which you draw the rectangle, so the CP_POSITION_CENTER [CP_Settings_RectMode](Settings.md#cp_settings_rectmode) will rotate around the center of the rectangle, while the CP_POSITION_CORNER [CP_Settings_RectMode](Settings.md#cp_settings_rectmode) will rotate around the top-left corner.

## Function
```C
void CP_Graphics_DrawRectAdvanced(float x, float y, float w, float h, float degrees, float cornerRadius);
```

### Parameters
* x (float) - The horizontal position of the rectangle.
* y (float) - The vertical position of the rectangle.
* w (float) - The width of the rectangle.
* h (float) - The height of the rectangle.
* degrees (float) - The rotation in degrees.
* cornerRadius (float) - The radius of the rounded corners of the rectangle (0 for no rounded corners).

### Return
This function does not return anything.

## Example
```C
void update()
{
    // draw a 100x50 rectangle rotated by 45 degrees
    CP_Graphics_DrawRectAdvanced(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 100.0f, 50.0f, 45.0f);
}
```

## Related
* [CP_Graphics_DrawRect](Graphics.md#cp_graphics_drawrect)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Graphics_DrawCircle
This is a simplified version of [CP_Graphics_DrawEllipse](#cp_graphics_drawellipse). A circle can be drawn on the screen using this function. The mode for drawing a circle and ellipse can be changed with [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode).

## Function
```C
void CP_Graphics_DrawCircle(float x, float y, float d);
```

### Parameters
* x (float) - The horizontal position of the circle.
* y (float) - The vertical position of the circle.
* d (float) - The diameter of the circle.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // set the background color
    CP_Graphics_ClearBackground(CP_Color_Create(255, 40, 200, 255));

    //draw a circle at (100, 100)
    CP_Graphics_DrawCircle(100, 100, 50.0f);

    // draw a circle at the mouse position
    CP_Graphics_DrawCircle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 20.0f);
}
```

## Related
* [CP_Graphics_DrawEllipse](#cp_graphics_drawellipse)
* [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Graphics_DrawEllipse
This function allows you to draw an ellipse with differing width and height. To draw an ellipse, provide the x and y values of a point and the width and height (diameters) of your ellipse. You can set the fill color of the drawn shape with [CP_Settings_Fill](Settings.md#cp_settings_fill) and the stroke color with [CP_Settings_Stroke](Settings.md#cp_settings_stroke). The method for drawing ellipses can be changed to different modes using [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode).

## Function
```C
void CP_Graphics_DrawEllipse(float x, float y, float w, float h);
```

### Parameters
* x (float) - The horizontal coordinate of the ellipse.
* y (float) - The vertical coordinate of the ellipse.
* w (float) - The width of the ellipse as a diameter.
* h (float) - The height of the ellipse as a diameter.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // Set the background color to red
    CP_Graphics_ClearBackground(CP_Color_Create(255, 100, 100, 255));

    // Draw an ellipse at the point (100, 100)
    CP_Graphics_DrawEllipse(100.0f, 100.0f, 50.0f, 80.0f);

    // Draw an ellipse at the mouse position
    CP_Graphics_DrawEllipse(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 20.0f, 60.0f);
}
```

## Related
* [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode)
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Settings_Stroke](Settings.md#cp_settings_stroke)
* [CP_Graphics_ClearBackground](Graphics.md#cp_graphics_clearbackground)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)

# CP_Graphics_DrawEllipseAdvanced
A specialized version of the [CP_Graphics_DrawEllipse](#cp_graphics_drawellipse) function which allows you to specify a rotation (in degrees). The shape will rotate about the reference point specified by the [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode).

## Function
```C
void CP_Graphics_DrawEllipseAdvanced(float x, float y, float w, float h, float degrees);
```

### Parameters
* x (float) - The horizontal position of the ellipse.
* y (float) - The vertical position of the ellipse.
* w (float) - The width (horizontal diameter) of the ellipse.
* h (float) - The height (vertical diameter) of the ellipse.
* degrees (float) - The rotation in degrees.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // draw a 100x50 ellipse rotated by 45 degrees at the mouse position
    CP_Graphics_DrawEllipseAdvanced(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 100.0f, 50.0f, 45.0f);
}
```

## Related
* [CP_Graphics_DrawEllipse](#cp_graphics_drawellipse)
* [CP_Settings_EllipseMode](Settings.md#cp_settings_ellipsemode)

# CP_Graphics_DrawTriangle
This function draws a triangle to the screen given three points. The filled color of the triangle can be set with [CP_Settings_Fill](Settings.md#cp_settings_fill) and the stroke outline can be changed with [CP_Settings_Stroke](Settings.md#cp_settings_stroke).

## Function
```C
void CP_Graphics_DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
```

### Parameters
* x1 (float) - The first point's horizontal position.
* y1 (float) - The first point's vertical position.
* x2 (float) - The second point's horizontal position.
* y2 (float) - The second point's vertical position.
* x3 (float) - The third point's horizontal position.
* y3 (float) - The third point's vertical position.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // set the fill color to red
    CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));

    // draw a triangle with three points
    CP_Graphics_DrawTriangle(100.0f, 100.0f,    // point 1
        200.0f, 100.0f,                         // point 2
        200.0f, 200.0f);                        // point 3

    // set the fill color to dark blue
    CP_Settings_Fill(CP_Color_Create(0, 0, 160, 255));

    // draw a triangle with three points
    CP_Graphics_DrawTriangle(0.0f, 0.0f,                             // point 1
        CP_Input_GetMouseX(), CP_Input_GetMouseY(),                  // point 2
        CP_Input_GetMousePreviousX(), CP_Input_GetMousePreviousY()); // point 3
}
```

## Related
* [CP_Settings_Fill](Settings.md#cp_settings_fill)
* [CP_Settings_Stroke](Settings.md#cp_settings_stroke)
* [CP_Color_Create](Color.md#cp_color_create)
* [CP_Input_GetMouseX](Input.md#cp_input_getmousex)
* [CP_Input_GetMouseY](Input.md#cp_input_getmousey)
* [CP_Input_GetMousePreviousX](Input.md#cp_input_getmousepreviousx)
* [CP_Input_GetMousePreviousY](Input.md#cp_input_getmousepreviousy)

# CP_Graphics_DrawTriangleAdvanced
A specialized version of the [CP_Graphics_DrawTriangle](#cp_graphics_drawtriangle) function which allows the user to specify a rotation (in degrees). The rotation is always about the center of the triangle.

## Function
```C
void CP_Graphics_DrawTriangleAdvanced(float x1, float y1, float x2, float y2, float x3, float y3, float degrees);
```

### Parameters
* x1 (float) - The first point's horizontal position.
* y1 (float) - The first point's vertical position.
* x2 (float) - The second point's horizontal position.
* y2 (float) - The second point's vertical position.
* x3 (float) - The third point's horizontal position.
* y3 (float) - The third point's vertical position.
* degrees (float) - The rotation in degrees.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // A triangle drawn based on the points (100, 100), (125, 150), (75, 150)
    // with a rotation of 15 degrees
    CP_Graphics_DrawTriangleAdvanced(100.0f, 100.0f, 125.0f, 150.0f, 75.0f, 150.0f, 15.0f);
}
```

## Related
* [CP_Graphics_DrawTriangle](#cp_graphics_drawtriangle)

# CP_Graphics_DrawQuad
This function will draw a quadrangle given four points. They will need to be in clockwise or counter-clockwise order, but it doesn't matter which.

## Function
```C
void CP_Graphics_DrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
```

### Parameters
* x1 (float) - The first point's horizontal position.
* y1 (float) - The first point's vertical position.
* x2 (float) - The second point's horizontal position.
* y2 (float) - The second point's vertical position.
* x3 (float) - The third point's horizontal position.
* y3 (float) - The third point's vertical position.
* x4 (float) - The fourth point's horizontal position.
* y4 (float) - The fourth point's vertical position.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // draw a quadrangle given four points
    //                     x       y
    CP_Graphics_DrawQuad(0.0f,   0.0f,    // corner 1
                         100.0f, 0.0f,    // corner 2
                         100.0f, 50.0f,   // corner 3
                         0.0f,   50.0f);  // corner 4
}
```

## Related
* [CP_Graphics_DrawQuadAdvanced](#cp_graphics_drawquadadvanced)

# CP_Graphics_DrawQuadAdvanced
A specialized version of the [CP_Graphics_DrawQuad](#cp_graphics_drawquad) function which allows the user to specify a rotation in degrees. The quadrangle is always rotated about the center.

## Function
```C
void CP_Graphics_DrawQuadAdvanced(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float degrees);
```

### Parameters
* x1 (float) - The first point's horizontal position.
* y1 (float) - The first point's vertical position.
* x2 (float) - The second point's horizontal position.
* y2 (float) - The second point's vertical position.
* x3 (float) - The third point's horizontal position.
* y3 (float) - The third point's vertical position.
* x4 (float) - The fourth point's horizontal position.
* y4 (float) - The fourth point's vertical position.
* degrees (float) - The rotation in degrees.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // draw a quad rotated by 45 degrees
    CP_Graphics_DrawQuadAdvanced(100.0f, 100.0f,  // corner 1
                                 200.0f, 100.0f,  // corner 2
                                 200.0f, 150.0f,  // corner 3
                                 100.0f, 150.0f,  // corner 4
                                 45.0f);          // degrees rotation
}

```

## Related
* [CP_Graphics_DrawQuad](#cp_graphics_drawquad)

# CP_Graphics_BeginShape
Using **CP_Graphics_BeginShape()**, [CP_Graphics_AddVertex](#cp_graphics_addvertex), and [CP_Graphics_EndShape](#cp_graphics_endshape), a shape can be defined with any number of vertices. After **CP_Graphics_BeginShape()** is called, use [CP_Graphics_AddVertex](#cp_graphics_addvertex) to specify the vertices of the shape. A shape will not be drawn until [CP_Graphics_EndShape](#cp_graphics_endshape) is called.

## Function
```C
void CP_Graphics_BeginShape(void);
```

### Parameters
This function has no parameters.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // Start drawing a shape
    CP_Graphics_BeginShape();

    // Specify three vertices
    CP_Graphics_AddVertex(100.0f, 100.0f);
    CP_Graphics_AddVertex(200.0f, 100.0f);
    CP_Graphics_AddVertex(200.0f, 200.0f);

   // signal the end of the shape and draw the shape
    CP_Graphics_EndShape();
}
```

## Related
* [CP_Graphics_AddVertex](#cp_graphics_addvertex)
* [CP_Graphics_EndShape](#cp_graphics_endshape)

# CP_Graphics_AddVertex
Using [CP_Graphics_BeginShape](#cp_graphics_beginshape), **CP_Graphics_AddVertex**, and [CP_Graphics_EndShape](#cp_graphics_endshape), a shape can be defined with any number of vertices. After [CP_Graphics_BeginShape](#cp_graphics_beginshape) is called, use **CP_Graphics_AddVertex** to specify the vertices of the shape. A shape will not be drawn until [CP_Graphics_EndShape](#cp_graphics_endshape) is called.

## Function
```C
void CP_Graphics_AddVertex(float x, float y);
```

### Parameters
* x (float) - The horizontal position of the vertex.
* y (float) - The vertical position of the vertex.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // Start drawing a shape
    CP_Graphics_BeginShape();

    // Specify three vertices
    CP_Graphics_AddVertex(100.0f, 100.0f);
    CP_Graphics_AddVertex(200.0f, 100.0f);
    CP_Graphics_AddVertex(200.0f, 200.0f);

   // signal the end of the shape and draw the shape
    CP_Graphics_EndShape();
}
```

## Related
* [CP_Graphics_BeginShape](#cp_graphics_beginshape)
* [CP_Graphics_EndShape](#cp_graphics_endshape)

# CP_Graphics_EndShape
Using [CP_Graphics_BeginShape](#cp_graphics_beginshape), [CP_Graphics_AddVertex](#cp_graphics_addvertex), and **CP_Graphics_EndShape**, a shape can be defined with any number of vertices. After [CP_Graphics_BeginShape](#cp_graphics_beginshape) is called, use [CP_Graphics_AddVertex](#cp_graphics_addvertex) to specify the vertices of the shape. A shape will not be drawn until **CP_Graphics_EndShape** is called.

## Function
```C
void CP_Graphics_EndShape(void);
```

### Parameters
This function has no parameters.

### Return
This function does not return anything.

## Example
```C
void update()
{
    // Start drawing a shape
    CP_Graphics_BeginShape();

    // Specify three vertices
    CP_Graphics_AddVertex(100.0f, 100.0f);
    CP_Graphics_AddVertex(200.0f, 100.0f);
    CP_Graphics_AddVertex(200.0f, 200.0f);

   // signal the end of the shape and draw the shape
    CP_Graphics_EndShape();
}
```

## Related
* [CP_Graphics_BeginShape](#cp_graphics_beginshape)
* [CP_Graphics_AddVertex](#cp_graphics_addvertex)
