#ifndef MOUSEHOVEREVENTHANDLER_H
#define MOUSEHOVEREVENTHANDLER_H

#include <thread>
#include "EventHandler.h"
#include "UIElement.h"

class MouseHoverEventHandler : public EventHandler
{
public:
	MouseHoverEventHandler(UIElement* sender, callback_function CallbackFuncOn, callback_function CallbackFuncOff);

	void StartListener();

	~MouseHoverEventHandler();

private:
	UIElement * sender;
	callback_function CallbackFuncOn;
	callback_function CallbackFuncOff;
};

#endif // !MOUSEHOVEREVENTHANDLER_H