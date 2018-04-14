#include "UILabel.h"

// Default Constructor
UILabel::UILabel(Graphics* g)
{
	this->graphics = g;
}

UILabel::UILabel(Graphics* g, std::wstring text)
{
	this->graphics = g;
	this->Text = text;
}

UILabel::UILabel(Graphics* g, std::wstring text, std::wstring fontName)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
}

UILabel::UILabel(Graphics* g, std::wstring text, std::wstring fontName, int FontSize)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
}

UILabel::UILabel(Graphics* g, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float Width, float Height)
{
	this->graphics = g;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
}

UILabel::UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a) {

	this->graphics = graphics;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

UILabel::UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a, float stroke) {

	this->graphics = graphics;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	this->Stroke = stroke;
}

UILabel::UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a, float stroke, float margins) {

	this->graphics = graphics;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	this->Stroke = stroke;
	this->Margins = margins;
}


UILabel::~UILabel()
{
}

void UILabel::Draw()
{
	this->graphics->DrawRectangle(xPos, yPos, Width, Height, r, g, b, a, Stroke, Filled);
	this->graphics->drawText(std::wstring(Text), FontName, FontSize,
		xPos + Margins, yPos + Margins, Width - Margins, Height - Margins, rText, gText, bText, aText);
}