#include "MouseHoverEventHandler.h"


MouseHoverEventHandler::MouseHoverEventHandler(UIElement* sender, callback_function CallbackFuncOn, callback_function CallbackFuncOff)
{
	this->sender = sender;
	this->CallbackFuncOn = CallbackFuncOn;
	this->CallbackFuncOff = CallbackFuncOff;
	std::thread running_thread(&MouseHoverEventHandler::StartListener, this);
	running_thread.detach();
}

void MouseHoverEventHandler::StartListener()
{
	bool on = false;
	while (true)
	{
		Sleep(2);
		if (sender->GetVisible() && sender->GetEnabled())
		{
			POINT pos;
			GetCursorPos(&pos);
			ScreenToClient(sender->GetGraphics()->GetHWND(), &pos);

			if (pos.x < sender->GetPosX() + sender->GetWidth() && pos.x > sender->GetPosX() &&
				pos.y < sender->GetPosY() + sender->GetHeight() && pos.y > sender->GetPosY())
			{
				if (!on)
				{
					CallbackFuncOn(sender);
					on = true;
				}
			}
			else
			{
				if (on)
				{
					CallbackFuncOff(sender);
					on = false;
				}
			}
		}
	}
}

MouseHoverEventHandler::~MouseHoverEventHandler()
{

}
