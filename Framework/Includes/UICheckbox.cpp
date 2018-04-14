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
UICheckbox::UICheckbox(Graphics* graphics)
{
	this->graphics = graphics;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(Graphics* g, std::wstring text)
{
	this->graphics = g;
	this->Text = text;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(Graphics* g, std::wstring text, std::wstring fontName)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(Graphics* g, std::wstring text, std::wstring fontName, int FontSize)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(Graphics* g, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float size)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Size = size;
	SetMouseClickHandler(ChangeState_OnMouseClick);
}

UICheckbox::UICheckbox(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float size, float TextWidth, float TextHeight) {

	this->graphics = graphics;
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

UICheckbox::UICheckbox(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float size, float TextWidth, float TextHeight, float margins) {

	this->graphics = graphics;
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
	graphics->DrawRectangle(xPos, yPos, Size, Size, r, g, b, a, 0, true);
	graphics->drawText(Text, FontName, FontSize, xPos + Size, yPos - Size / 2, TextWidth, TextHeight, rText, gText, bText, aText);

	if (Checked)
	{
		// Indicate that the checkbox is checked.
		graphics->drawText(L"✔", L"Verdana", Size - 10, xPos + 0.2f, yPos + 0.2f, Size - 0.2f, Size - 0.2f, 0.0f, 0.0f, 0.0f, 1.0f);
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
