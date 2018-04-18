#ifndef SELECTEDINDEXCHANGEDEVENTHANDLER_H
#define SELECTEDINDEXCHANGEDEVENTHANDLER_H

#include "EventHandler.h"
#include "UIElement.h"
#include "UICombobox.h"
#include <thread>

class SelectedIndexChangedEventHandler : public EventHandler
{
public:
	SelectedIndexChangedEventHandler(UIElement* sender, callback_function func);

	void StartListener();

	~SelectedIndexChangedEventHandler();

private:
	UIElement* sender;
	callback_function CallbackFunc;
};

#endif // !SELECTEDINDEXCHANGEDEVENTHANDLER_H