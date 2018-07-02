#include "ValueChangedEventHandler.h"


ValueChangedEventHandler::ValueChangedEventHandler(UIElement* sender, callback_function func)
{
	this->sender = sender;
	this->CallbackFunc = func;
	std::thread running_thread(&ValueChangedEventHandler::StartListener, this);
	running_thread.detach();
}


ValueChangedEventHandler::~ValueChangedEventHandler()
{
}


void ValueChangedEventHandler::StartListener()
{
	UISlider* slider = static_cast<UISlider*>(sender);
	float oldValue = slider->GetValue();
	while (true)
	{
		Sleep(2);
		if (slider->GetVisible() && slider->GetEnabled())
		{
			float currentValue = slider->GetValue();
			if (currentValue != oldValue)
			{
				CallbackFunc(sender);
			}
			oldValue = currentValue;
		}
	}
}
