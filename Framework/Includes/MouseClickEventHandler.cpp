#include "MouseClickEventHandler.h"

MouseClickEventHandler::MouseClickEventHandler(UIElement* sender, uiElement_global_callback_function func)
{
	this->CallbackFunc = func;
	this->sender = sender;
	std::thread running_thread(&MouseClickEventHandler::StartListener, this);
	running_thread.detach();
}

void MouseClickEventHandler::StartListener()
{
	bool pressed = false;
	while (true)
	{
		Sleep(2);
		if (sender->GetVisible() && sender->GetEnabled())
		{
			if (GetAsyncKeyState(VK_LBUTTON) == 0)
				pressed = false;

			Sleep(2);
			if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !pressed)
			{
				pressed = true;

				// Left Click Action
				POINT pos;
				GetCursorPos(&pos);
				ScreenToClient(sender->GetSourceWindow()->GetHWND(), &pos);

				if (pos.x < sender->GetPosX() + sender->GetWidth() && pos.x > sender->GetPosX() &&
					pos.y < sender->GetPosY() + sender->GetHeight() && pos.y > sender->GetPosY())
				{
					CallbackFunc(sender);
				}
			}
		}
	}
}

MouseClickEventHandler::~MouseClickEventHandler()
{

}

