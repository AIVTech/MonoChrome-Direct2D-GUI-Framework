#ifndef COMBOBOXITEMEVENTHANDLER_H
#define COMBOBOXITEMEVENTHANDLER_H

#include "EventHandler.h"
#include "UICombobox.h"
#include <thread>

class ComboboxItemEventHandler : public EventHandler
{
public:
	ComboboxItemEventHandler(UIElement* sender);

	void StartListener();

	~ComboboxItemEventHandler();

private:
	UIElement* sender;
};

#endif