#include "ComboboxItemEventHandler.h"


ComboboxItemEventHandler::ComboboxItemEventHandler(UIElement* sender)
{
	this->sender = sender;
	std::thread running_thread(&ComboboxItemEventHandler::StartListener, this);
	running_thread.detach();
}

void ComboboxItemEventHandler::StartListener()
{
	UICombobox* combo = static_cast<UICombobox*>(sender);
	bool mousePressed = false;
	while (true)
	{
		Sleep(2);
		if (combo->GetEnabled() && combo->GetVisible() && combo->GetDrawItems())
		{
			if (mousePressed && GetAsyncKeyState(VK_LBUTTON) == 0)
			{
				mousePressed = false;
			}

			// Left Click Action
			POINT pos;
			GetCursorPos(&pos);
			ScreenToClient(sender->GetGraphics()->GetHWND(), &pos);

			for (int i = 1; i < combo->GetItems().size(); i++)
			{
				float y = combo->GetPosY() + combo->GetHeight() * i;
				float width = combo->GetWidth() - 14.0f;

				if (pos.x < combo->GetPosX() + width && pos.x > combo->GetPosX() &&
					pos.y < y + sender->GetHeight() && pos.y > y)
				{
					combo->SetHoverIndex(i);
					if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && !mousePressed)
					{
						mousePressed = true;
						combo->SetSelectedIndex(i);
						combo->SetDrawItems(false);
					}
				}
			}
		}
	}
}


ComboboxItemEventHandler::~ComboboxItemEventHandler()
{
}
