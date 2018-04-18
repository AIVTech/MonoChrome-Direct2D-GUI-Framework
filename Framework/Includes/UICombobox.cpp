#include "UICombobox.h"
#include "MouseClickEventHandler.h"
#include "ComboboxItemEventHandler.h"

void Mouse_OnClick(UIElement* sender)
{
	UICombobox* combo = static_cast<UICombobox*>(sender);
	combo->SetDrawItems(!combo->GetDrawItems());
}

UICombobox::UICombobox(Graphics* graphics)
{
	this->graphics = graphics;
	SetMouseClickedHandler(Mouse_OnClick);
	SetItemSelectionHandler();
}

UICombobox::UICombobox(Graphics* graphics, float xPos, float yPos, float Width, float Height)
{
	this->graphics = graphics;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	SetMouseClickedHandler(Mouse_OnClick);
	SetItemSelectionHandler();
}

UICombobox::UICombobox(Graphics* graphics, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a)
{
	this->graphics = graphics;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	this->normalAlpha = a;
	SetMouseClickedHandler(Mouse_OnClick);
	SetItemSelectionHandler();
}


UICombobox::~UICombobox()
{
}

void UICombobox::Draw()
{
	if (!RoundedCorners)
	{
		this->graphics->DrawRectangle(xPos, yPos, Width, Height, r, g, b, a, 0, true); // Actual combobox
		this->graphics->DrawRectangle(xPos - 0.1f, yPos - 0.1f,
			Width + 0.1f, Height + 0.1f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, false); // Border box
	}
	else
	{
		this->graphics->DrawRoundedRectangle(xPos, yPos, Width, Height, roundCornerRadiusX, roundCornerRadiusY, r, g, b, a, 0, true); // Actual combobox
		this->graphics->DrawRoundedRectangle(xPos - 0.1f, yPos - 0.1f, Width + 0.1f, Height + 0.1f, 
			roundCornerRadiusX, roundCornerRadiusY, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, false); // Border Box
	}

	this->graphics->drawText(L"▼", L"Arial", 16, xPos + Width - 14.0f, yPos, 4.0f, Height - 0.6f, 0.0f, 0.0f, 0.0f, 1.0f); // Arrow Key Down

	this->graphics->drawText(Items.at(SelectedIndex), L"Arial", Height - 10, xPos + 2.0f, yPos, Width - 14.0f, Height, 0.0f, 0.0f, 0.0f, 1.0f); // Actual Text

	if (this->drawItems)
	{
		// Drawing All the Items
		if (this->Items.size() > 1)
		{
			for (int i = 1; i < Items.size(); i++)
			{
				float red = r, green = g, blue = b, textRed = 0.0f, textGreen = 0.0f, textBlue = 0.0f;
				if (i == hoverIndex)
				{
					red = 0.0f;
					green = 0.0f;
					blue = 0.9f;

					textRed = 1.0f;
					textGreen = 1.0f;
					textBlue = 1.0f;
				}

				float y = yPos + Height*i;
				float w = Width - 14.0f;
				this->graphics->DrawRectangle(xPos, y, w, Height, red, green, blue, a, 0, true); // Actual combobox
				this->graphics->DrawRectangle(xPos - 0.1f, y,
					w + 0.1f, Height + 0.1f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, false); // Border box

				this->graphics->drawText(Items.at(i), L"Arial", Height - 10, xPos + 2.0f, y, w, Height, textRed, textGreen, textBlue, 1.0f);
			}
		}
	}
	else
	{
		hoverIndex = -1;
	}
}


void UICombobox::SetMouseClickedHandler(callback_function func)
{
	this->MouseClickHandler = new MouseClickEventHandler(this, func);
}

void UICombobox::SetItemSelectionHandler()
{
	this->ItemSelectionHandler = new ComboboxItemEventHandler(this);
}

void UICombobox::RemoveItem(int index)
{
	if (index > 0 && index < this->Items.size())
	{
		this->Items.erase(this->Items.begin() + index);
	}
}

void UICombobox::RemoveItem(std::wstring item)
{
	if (std::find(this->Items.begin(), this->Items.end(), item) != this->Items.end())
	{
		this->Items.erase(std::remove(this->Items.begin(), this->Items.end(), item));
	}
}

int UICombobox::IndexOf(std::wstring item)
{
	for (int i = 0; i < this->Items.size(); i++)
	{
		if (item._Equal(this->Items.at(i)))
		{
			return i;
		}
	}
	return 0;
}
