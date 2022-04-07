//------------------------------------------------------------------------------
// file:	Internal_Input.h
// author:	Daniel Hamilton
// brief:	Handle input and querying
//
// INTERNAL USE ONLY, DO NOT DISTRIBUTE
//
// Copyright © 2019 DigiPen, All rights reserved.
//------------------------------------------------------------------------------

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// GLFW includes needed for input
struct GLFWwindow;
typedef struct GLFWwindow GLFWwindow;

typedef struct CP_GAMEPAD_ANALOG_STATE
{
	CP_Vector left_stick;
	CP_Vector right_stick;
	float left_trigger;
	float right_trigger;
} CP_GAMEPAD_ANALOG_STATE;

////////////////////////////////////////////////////////////////////////////////
// INTERNAL USE
void CP_InputCallback(GLFWwindow* win, int key, int scancode, int action, int mods);
void CP_MouseCallback(GLFWwindow* window, int button, int action, int mods);
void CP_MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void CP_InputInit(void);
void CP_InputUpdate(void);
void CP_KeyboardUpdate(void);
void CP_MouseUpdate(void);
void CP_GamepadUpdate(void);
void CP_UpdateWorldMouse(void);
void CP_SetWorldMouseDirty(void);
int  CP_IsValidKey(CP_KEY key);
int  CP_IsValidMouse(CP_MOUSE button);
int  CP_IsValidGamepad(CP_GAMEPAD button);
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
