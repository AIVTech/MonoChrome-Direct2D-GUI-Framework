#include "Mouse.h"

LPWSTR Mouse::CurrentCursorStyle = IDC_ARROW;

float Mouse::GetMousePosX(UIWindow* clientWindow)
{
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(clientWindow->GetHWND(), &pos);
	return (float)pos.x;
}

float Mouse::GetMousePosY(UIWindow* clientWindow)
{
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(clientWindow->GetHWND(), &pos);
	return (float)pos.y;
}

void Mouse::SetNewCursor(LPWSTR style)
{
	Mouse::CurrentCursorStyle = style;
}

//********* CURSOR STYLES ************//

LPWSTR Mouse::Help = IDC_HELP;
LPWSTR Mouse::Default = IDC_ARROW;
LPWSTR Mouse::Hand = IDC_HAND;
LPWSTR Mouse::Waiting = IDC_WAIT;
LPWSTR Mouse::Text = IDC_IBEAM;
