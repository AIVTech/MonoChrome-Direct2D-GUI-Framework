#include "StateChangedEventHandler.h"


StateChangedEventHandler::StateChangedEventHandler(UIElement* sender, callback_function func)
{
	this->sender = sender;
	this->CheckboxCallbackEventFunc = func;
	this->oldState = static_cast<UICheckbox*>(sender)->GetChecked();
	std::thread t(&StateChangedEventHandler::StartListener, this);
	t.detach();
}

StateChangedEventHandler::~StateChangedEventHandler()
{

}

void StateChangedEventHandler::StartListener()
{
	while (true)
	{
		Sleep(2);
		if (sender->GetVisible() && sender->GetEnabled())
		{
			bool newState = static_cast<UICheckbox*>(sender)->GetChecked();
			if (newState != oldState)
			{
				oldState = newState;
				CheckboxCallbackEventFunc(sender);
			}
		}
	}
}
