#include "MouseMovedWhileDownEventHandler.h"

MouseMovedWhileDownEventHandler::MouseMovedWhileDownEventHandler(UIElement* sender, callback_function func)
{
	this->sender = sender;
	this->CallbackFunc = func;
	std::thread running_thread(&MouseMovedWhileDownEventHandler::StartListener, this);
	running_thread.detach();
}

MouseMovedWhileDownEventHandler::~MouseMovedWhileDownEventHandler()
{
}


void MouseMovedWhileDownEventHandler::StartListener()
{
	UISlider* slider = static_cast<UISlider*>(sender);
	bool on = false;
	while (true)
	{
		Sleep(2);
		if (slider->GetVisible() && slider->GetEnabled())
		{
			if (GetAsyncKeyState(VK_LBUTTON) == 0)
			{
				on = false;
			}

			// Get Mouse Position
			POINT pos;
			GetCursorPos(&pos);
			ScreenToClient(sender->GetGraphics()->GetHWND(), &pos);

			// If Mouse is Pressed
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{

				if (pos.x < slider->GetKnobPosX() + slider->GetKnobRadius() && pos.x > slider->GetKnobPosX() - slider->GetKnobRadius() &&
					pos.y < slider->GetPosY() + slider->GetKnobRadius() && pos.y > slider->GetPosY() - slider->GetKnobRadius())
				{
					on = true;
				}
			}

			// Make Changes to the slider's knob and set new values
			if (on)
			{
				// Maximum
				if (pos.x > slider->GetPosX() + slider->GetWidth())
				{
					slider->SetKnobPosX(slider->GetPosX() + slider->GetWidth());
					slider->SetValue(slider->GetMaxValue());
				}
				// Minimum
				else if (pos.x < slider->GetPosX())
				{
					slider->SetKnobPosX(slider->GetPosX());
					slider->SetValue(slider->GetMinValue());
				}
				// In the Middle
				else
				{
					float oldValue = slider->GetValue();
					slider->SetKnobPosX(pos.x);
					float distanceToKnob = slider->GetKnobPosX() - slider->GetPosX();
					float valueInPercent = distanceToKnob / slider->GetWidth();
					//float CurrentValue = valueInPercent * (slider->GetMaxValue() - slider->GetMinValue()) + slider->GetMinValue();

					int tickCount = (slider->GetMaxValue() - slider->GetMinValue()) / slider->GetIntervals();
					float distanceToEachTick = slider->GetWidth() / (float)tickCount;

					int ticksPast = (int)(distanceToKnob / distanceToEachTick);
					float value = (float)ticksPast * slider->GetIntervals();

					slider->SetValue(value);
				}
			}
		}
	}
}
