#pragma once

#include "EventHandler.h"

class GlobalWhileMouseDownEventHandler : public EventHandler
{
public:
	GlobalWhileMouseDownEventHandler(UIElement* sender, uiElement_global_callback_function func);

	void StartListener();

	~GlobalWhileMouseDownEventHandler();

private:
	UIElement* sender;
	uiElement_global_callback_function CallbackFunc;
};

