#include "UIElement.h"
#include "GlobalWhileMouseDownEventHandler.h"
#include "MouseClickEventHandler.h"

void UIElement::AddWhileMouseDownEventHandler(uiElement_global_callback_function callbackFunc)
{
	new GlobalWhileMouseDownEventHandler(this, callbackFunc);
}

void UIElement::AddMouseClickEventHandler(uiElement_global_callback_function callbackFunc)
{
	new MouseClickEventHandler(this, callbackFunc);
}