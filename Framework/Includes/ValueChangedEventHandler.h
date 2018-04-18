#ifndef VALUECHANGEDEVENTHANDLER_H
#define VALUECHANGEDEVENTHANDLER_H

#include "EventHandler.h"
#include "UIElement.h"
#include "UISlider.h"
#include <thread>

class ValueChangedEventHandler : public EventHandler
{
public:
	ValueChangedEventHandler(UIElement* sender, callback_function func);

	void StartListener();

	~ValueChangedEventHandler();

private:
	UIElement* sender;
	callback_function CallbackFunc;
};

#endif