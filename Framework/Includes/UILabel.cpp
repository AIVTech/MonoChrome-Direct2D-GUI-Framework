#include "UILabel.h"

// Default Constructor
UILabel::UILabel(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
}

UILabel::UILabel(UIWindow* srcWindow, std::wstring text)
{
	this->srcWindow = srcWindow;
	this->Text = text;
}

UILabel::UILabel(UIWindow* srcWindow, std::wstring text, std::wstring fontName)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
}

UILabel::UILabel(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
}

UILabel::UILabel(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float Width, float Height)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
}

UILabel::UILabel(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
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
}

UILabel::UILabel(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
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
	this->Stroke = stroke;
}

UILabel::UILabel(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
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
	this->Stroke = stroke;
	this->Margins = margins;
}


UILabel::~UILabel()
{
}

void UILabel::Draw()
{
	this->srcWindow->GetGraphics()->DrawRectangle(xPos, yPos, Width, Height, color->r, color->g, color->b, color->a, Stroke, Filled);
	this->srcWindow->GetGraphics()->drawText(std::wstring(Text), FontName, FontSize, 
		xPos+Margins, yPos+Margins, Width-Margins, Height-Margins, textColor->r, textColor->g, textColor->b, textColor->a);
}
