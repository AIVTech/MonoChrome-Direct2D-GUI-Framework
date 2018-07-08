#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "UIElement.h"

class EventHandler
{
public:
	typedef void(*callback_function)(UIElement*);
	typedef void(*uiElement_global_callback_function)(UIElement*);

	virtual void StartListener() = 0;

protected:

private:
	
};

#endif // !EVENTHANDLER_H