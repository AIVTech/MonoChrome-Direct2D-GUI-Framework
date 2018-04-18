#include "SelectedIndexChangedEventHandler.h"


SelectedIndexChangedEventHandler::SelectedIndexChangedEventHandler(UIElement* sender, callback_function func)
{
	this->sender = sender;
	this->CallbackFunc = func;
	std::thread running_thread(&SelectedIndexChangedEventHandler::StartListener, this);
	running_thread.detach();
}


void SelectedIndexChangedEventHandler::StartListener()
{
	UICombobox* combo = static_cast<UICombobox*>(sender);
	int oldIndex = combo->GetSelectedIndex();
	while (true)
	{
		Sleep(4);
		int newIndex = combo->GetSelectedIndex();
		if (newIndex != oldIndex && newIndex != 0)
		{
			oldIndex = newIndex;
			CallbackFunc(sender);
		}
	}
}


SelectedIndexChangedEventHandler::~SelectedIndexChangedEventHandler()
{
}
