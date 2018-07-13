#include "UICombobox.h"
#include "MouseClickEventHandler.h"
#include "ComboboxItemEventHandler.h"
#include "SelectedIndexChangedEventHandler.h"

void Mouse_OnClick(UIElement* sender)
{
	UICombobox* combo = static_cast<UICombobox*>(sender);
	combo->SetDrawItems(!combo->GetDrawItems());
}

UICombobox::UICombobox(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
	SetMouseClickedHandler(Mouse_OnClick);
	SetItemSelectionHandler();
}

UICombobox::UICombobox(UIWindow* srcWindow, float xPos, float yPos, float Width, float Height)
{
	this->srcWindow = srcWindow;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	SetMouseClickedHandler(Mouse_OnClick);
	SetItemSelectionHandler();
}

UICombobox::UICombobox(UIWindow* srcWindow, float xPos, float yPos, float Width, float Height, Color* color)
{
	this->srcWindow = srcWindow;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->normalAlpha = color->a;
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
		this->srcWindow->GetGraphics()->DrawRectangle(xPos, yPos, Width, Height, color->r, color->g, color->b, color->a, 0, true); // Actual combobox
		this->srcWindow->GetGraphics()->DrawRectangle(xPos - 0.1f, yPos - 0.1f,
			Width + 0.1f, Height + 0.1f, 128, 128, 128, 255, 1.0f, false); // Border box
	}
	else
	{
		this->srcWindow->GetGraphics()->DrawRoundedRectangle(xPos, yPos, Width, Height,
			roundCornerRadiusX, roundCornerRadiusY, color->r, color->g, color->b, color->a, 0, true); // Actual combobox

		this->srcWindow->GetGraphics()->DrawRoundedRectangle(xPos - 0.1f, yPos - 0.1f, Width + 0.1f, Height + 0.1f,
			roundCornerRadiusX, roundCornerRadiusY, 128, 128, 128, 255, 1.0f, false); // Border Box
	}

	this->srcWindow->GetGraphics()->drawText(L"▼", L"Arial", 16, xPos + Width - 14.0f, yPos, 4.0f, Height - 0.6f, 
		0, 0, 0, 255, DWRITE_TEXT_ALIGNMENT_CENTER, DWRITE_PARAGRAPH_ALIGNMENT_CENTER); // Arrow Key Down

	this->srcWindow->GetGraphics()->drawText(Items.at(SelectedIndex), L"Arial", Height - 10, xPos + 2.0f, yPos, Width - 14.0f, Height, 
		0, 0, 0, 255, DWRITE_TEXT_ALIGNMENT_CENTER, DWRITE_PARAGRAPH_ALIGNMENT_CENTER); // Actual Text

	if (this->drawItems)
	{
		// Drawing All the Items
		if (this->Items.size() > 1)
		{
			for (int i = 1; i < Items.size(); i++)
			{
				uint8_t red = color->r, green = color->g, blue = color->b, textRed = 0, textGreen = 0, textBlue = 0;
				if (i == hoverIndex)
				{
					red = 0;
					green = 0;
					blue = 230;

					textRed = 255;
					textGreen = 255;
					textBlue = 255;
				}

				float y = yPos + Height*i;
				float w = Width - 14.0f;
				this->srcWindow->GetGraphics()->DrawRectangle(xPos, y, w, Height, red, green, blue, color->a, 0, true); // Actual combobox
				this->srcWindow->GetGraphics()->DrawRectangle(xPos - 0.1f, y,
					w + 0.1f, Height + 0.1f, 128, 128, 128, 255, 1.0f, false); // Border box

				DWRITE_TEXT_ALIGNMENT textAllignment;
				DWRITE_PARAGRAPH_ALIGNMENT paragraphAllignment;
				MakeTextAllignment(this->TextAllignment, textAllignment, paragraphAllignment);

				this->srcWindow->GetGraphics()->drawText(Items.at(i), L"Arial", Height - 10, xPos + 2.0f, y, w, Height, 
					textRed, textGreen, textBlue, 255, textAllignment, paragraphAllignment);
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

void UICombobox::SetSelectedIndexChangedEventHandler(callback_function func)
{
	this->SelectedIndexChangedHandler = new SelectedIndexChangedEventHandler(this, func);
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
