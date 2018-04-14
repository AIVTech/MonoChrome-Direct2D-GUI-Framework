#ifndef MOUSEMOVEDWHILEDOWNEVENTHANDLER_H
#define MOUSEMOVEDWHILEDOWNEVENTHANDLER_H

#include "UIElement.h"
#include "UISlider.h"
#include "EventHandler.h"

#include <thread>

class MouseMovedWhileDownEventHandler : public EventHandler
{
public:
	MouseMovedWhileDownEventHandler(UIElement* sender, callback_function func);

	void StartListener();

	~MouseMovedWhileDownEventHandler();

private:
	UIElement * sender;
	callback_function CallbackFunc;
};

#endif // !MOUSEMOVEDWHILEDOWNEVENTHANDLER_H