#include "UICursor.h"

LPWSTR UICursor::CurrentCursorStyle = IDC_ARROW;

float UICursor::GetMousePosX(UIWindow* clientWindow)
{
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(clientWindow->GetHWND(), &pos);
	return (float)pos.x;
}

float UICursor::GetMousePosY(UIWindow* clientWindow)
{
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(clientWindow->GetHWND(), &pos);
	return (float)pos.y;
}

void UICursor::SetNewCursor(LPWSTR style)
{
	UICursor::CurrentCursorStyle = style;
}

//********* CURSOR STYLES ************//

LPWSTR UICursor::Help = IDC_HELP;
LPWSTR UICursor::Default = IDC_ARROW;
LPWSTR UICursor::Hand = IDC_HAND;
LPWSTR UICursor::Waiting = IDC_WAIT;
