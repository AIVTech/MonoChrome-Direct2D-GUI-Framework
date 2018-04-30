#include "UIButton.h"
#include "MouseClickEventHandler.h"
#include "MouseHoverEventHandler.h"

Color* originalColor;

void Mouse_HoverOn(UIElement* sender)
{
	UIButton* btn = static_cast<UIButton*>(sender);
	originalColor = btn->GetColor();
	btn->SetColor(new Color(0.5f, 0.5f, 0.5f, btn->GetColor()->a));
}

void Mouse_HoverOff(UIElement* sender)
{
	UIButton* btn = static_cast<UIButton*>(sender);
	btn->SetColor(originalColor);
}

// Default Constructor
UIButton::UIButton(Graphics* graphics)
{
	this->graphics = graphics;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(Graphics* g, std::wstring text)
{
	this->graphics = g;
	this->Text = text;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(Graphics* g, std::wstring text, std::wstring fontName)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(Graphics* g, std::wstring text, std::wstring fontName, int FontSize)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(Graphics* g, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float Width, float Height)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color* color) {

	this->graphics = graphics;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->normalAlpha = color->a;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke) {

	this->graphics = graphics;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->normalAlpha = color->a;
	this->Stroke = stroke;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke, float margins) {

	this->graphics = graphics;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->normalAlpha = color->a;
	this->Stroke = stroke;
	this->Margins = margins;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}


UIButton::~UIButton()
{

}

void UIButton::Draw()
{
	if (!this->RoundedCorners)
	{
		this->graphics->DrawRectangle(xPos, yPos, Width, Height, color->r, color->g, color->b, color->a, Stroke, Filled); // button itself

		this->graphics->DrawRectangle(xPos - 0.2f, yPos - 0.2f, Width + 0.2f, Height + 0.2f,
			borderColor->r, borderColor->g, borderColor->b, borderColor->a, borderStroke, false); // border rectangle to indicate that its a button
	}
	else
	{
		this->graphics->DrawRoundedRectangle(xPos, yPos, Width, Height, roundCornerRadiusX, roundCornerRadiusY, 
			color->r, color->g, color->b, color->a, Stroke, Filled); // button itself

		this->graphics->DrawRoundedRectangle(xPos - 0.2f, yPos - 0.2f, Width + 0.2f, Height + 0.2f, roundCornerRadiusX, roundCornerRadiusY,
			borderColor->r, borderColor->g, borderColor->b, borderColor->a, borderStroke, false); // border rectangle to indicate that its a button
	}

	this->graphics->drawText(std::wstring(Text), FontName, FontSize,
		xPos + Margins, yPos + Margins, Width - Margins, Height - Margins, textColor->r, textColor->g, textColor->b, textColor->a); // text inside a button
}

void UIButton::SetMouseClickEventHandler(callback_function func)
{
	MouseClickHandler = new MouseClickEventHandler(this, func);
}

void UIButton::SetMouseHoverEventHandler(callback_function funcOn, callback_function funcOff)
{
	this->MouseHoverHandler = new MouseHoverEventHandler(this, funcOn, funcOff);
}

