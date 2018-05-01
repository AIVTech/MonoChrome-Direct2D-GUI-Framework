#include "UICheckbox.h"
#include "MouseClickEventHandler.h"
#include "StateChangedEventHandler.h"

void ChangeState_OnMouseClick(UIElement* sender)
{
	UICheckbox* cbx = static_cast<UICheckbox*>(sender);
	if (!cbx->GetChecked())
	{
		cbx->SetChecked(true);
	}
	else
	{
		cbx->SetChecked(false);
	}
}

// Default Constructor
UICheckbox::UICheckbox(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(UIWindow* srcWindow, std::wstring text)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float size)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Size = size;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float size, float TextWidth, float TextHeight) {

	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Size = size;
	this->TextWidth = TextWidth;
	this->TextHeight = TextHeight;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float size, float TextWidth, float TextHeight, float margins) {

	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Size = size;
	this->TextWidth = TextWidth;
	this->TextHeight = TextHeight;
	this->Margins = margins;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}



UICheckbox::~UICheckbox()
{

}

void UICheckbox::Draw()
{
	if (!this->RoundedCorners)
	{
		srcWindow->GetGraphics()->DrawRectangle(xPos, yPos, Size, Size, color->r, color->g, color->b, color->a, 0, true);
	}
	else
	{
		srcWindow->GetGraphics()->DrawRoundedRectangle(xPos, yPos, Size, Size, roundCornerRadiusX, roundCornerRadiusY, 
			color->r, color->g, color->b, color->a, 0, true);
	}

	srcWindow->GetGraphics()->drawText(Text, FontName, FontSize, xPos+Size, yPos-Size/2, TextWidth, TextHeight, 
		textColor->r, textColor->g, textColor->b, textColor->a);

	if (Checked)
	{
		// Indicate that the checkbox is checked.
		srcWindow->GetGraphics()->drawText(L"✔", L"Verdana", Size-10, xPos+0.2f, yPos+0.2f, Size-0.2f, Size-0.2f, 0, 0, 0, 255);
	}
}

void UICheckbox::SetStateChangedEventHandler(callback_function func)
{
	StateEventHandler = new StateChangedEventHandler(this, func);
}

void UICheckbox::SetMouseClickHandler(callback_function func)
{
	MouseClickHandler = new MouseClickEventHandler(this, func);
}


