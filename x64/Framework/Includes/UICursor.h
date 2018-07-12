#pragma once

#include "UIWindow.h"

class UICursor
{
public:
	static float GetMousePosX(UIWindow* clientWindow); // client screen coordinates
	static float GetMousePosY(UIWindow* clientWindow); // client screen coordinates

	static LPWSTR CurrentCursorStyle;
	static void SetNewCursor(LPWSTR style);

	// Cursor Styles
	static LPWSTR Help;
	static LPWSTR Default;
	static LPWSTR Hand;
	static LPWSTR Waiting;
};
