#ifndef STATECHANGEDEVENTHANDLER_H
#define STATECHANGEDEVENTHANDLER_H

#include "EventHandler.h"
#include "UIElement.h"
#include "UIButton.h"
#include "UICheckbox.h"
#include <thread>

class StateChangedEventHandler : public EventHandler
{
public:
	typedef void(*callback_function)(UIElement* sender);

	StateChangedEventHandler(UIElement* sender, callback_function func);

	void StartListener();

	~StateChangedEventHandler();

private:
	UIElement * sender;
	callback_function CheckboxCallbackEventFunc;
	bool oldState;
};


#endif // !STATECHANGEREVENTHANDLER_H