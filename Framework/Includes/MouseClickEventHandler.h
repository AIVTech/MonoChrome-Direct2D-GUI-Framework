#ifndef __MOUSECLICKEVENTHANDLER_H
#define __MOUSECLICKEVENTHANDLER_H

#include "EventHandler.h"
#include "UIButton.h"
#include "UICheckbox.h"
#include "UIElement.h"
#include <thread>

class MouseClickEventHandler : public EventHandler
{
public:
	MouseClickEventHandler(UIElement* sender, uiElement_global_callback_function func);

	void StartListener();

	virtual ~MouseClickEventHandler();

private:
	UIElement* sender;
	uiElement_global_callback_function CallbackFunc;
};

#endif