#include "UIButton.h"
#include "MouseClickEventHandler.h"
#include "MouseHoverEventHandler.h"

Color* originalColor;

void Mouse_HoverOn(UIElement* sender)
{
	UIButton* btn = static_cast<UIButton*>(sender);
	originalColor = btn->GetColor();
	btn->SetColor(new Color(70, 70, 70, btn->GetColor()->a));
}

void Mouse_HoverOff(UIElement* sender)
{
	UIButton* btn = static_cast<UIButton*>(sender);
	btn->SetColor(originalColor);
}

// Default Constructor
UIButton::UIButton(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(UIWindow* srcWindow, std::wstring text)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float Width, float Height)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	SetMouseHoverEventHandler(Mouse_HoverOn, Mouse_HoverOff);
}

UIButton::UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color* color) {

	this->srcWindow = srcWindow;
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

UIButton::UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke) {

	this->srcWindow = srcWindow;
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

UIButton::UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke, float margins) {

	this->srcWindow = srcWindow;
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
		this->srcWindow->GetGraphics()->DrawRectangle(xPos, yPos, Width, Height, color->r, color->g, color->b, color->a, Stroke, Filled); // button itself

		this->srcWindow->GetGraphics()->DrawRectangle(xPos - 0.2f, yPos - 0.2f, Width + 0.2f, Height + 0.2f,
			borderColor->r, borderColor->g, borderColor->b, borderColor->a, borderStroke, false); // border rectangle to indicate that its a button
	}
	else
	{
		this->srcWindow->GetGraphics()->DrawRoundedRectangle(xPos, yPos, Width, Height, roundCornerRadiusX, roundCornerRadiusY,
			color->r, color->g, color->b, color->a, Stroke, Filled); // button itself

		this->srcWindow->GetGraphics()->DrawRoundedRectangle(xPos - 0.2f, yPos - 0.2f, Width + 0.2f, Height + 0.2f, roundCornerRadiusX, roundCornerRadiusY,
			borderColor->r, borderColor->g, borderColor->b, borderColor->a, borderStroke, false); // border rectangle to indicate that its a button
	}

	DWRITE_TEXT_ALIGNMENT textAllignment;
	DWRITE_PARAGRAPH_ALIGNMENT paragraphAllignment;
	MakeTextAllignment(this->TextAllignment, textAllignment, paragraphAllignment);

	this->srcWindow->GetGraphics()->drawText(std::wstring(Text), FontName, FontSize,
		xPos + Margins, yPos + Margins, Width - Margins, Height - Margins, textColor->r, textColor->g, textColor->b, textColor->a,
		textAllignment, paragraphAllignment); // text inside a button
}

void UIButton::SetMouseHoverEventHandler(callback_function funcOn, callback_function funcOff)
{
	this->MouseHoverHandler = new MouseHoverEventHandler(this, funcOn, funcOff);
}

