#ifndef UILABEL_H
#define UILABEL_H

#include "Graphics.h"
#include "UIElement.h"
#include <string>
#include <d2d1.h>

class UILabel : public UIElement
{
public:
	UILabel(Graphics* g);
	UILabel(Graphics* g, std::wstring text);
	UILabel(Graphics* g, std::wstring text, std::wstring fontName);
	UILabel(Graphics* g, std::wstring text, std::wstring fontName, int FontSize);
	UILabel(Graphics* g, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float Width, float Height);
	UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a);

	UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a, float stroke);

	UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a, float stroke, float margins);

	void Draw();

	// Getters
	Graphics* GetGraphics() { return this->graphics; }
	std::wstring GetText() { return this->Text; }
	std::wstring GetFontName() { return this->FontName; }
	int GetFontSize() { return this->FontSize; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetWidth() { return this->Width; }
	float GetHeight() { return this->Height; }
	float GetStroke() { return this->Stroke; }
	float GetMargins() { return this->Margins; }
	bool GetFilled() { return this->Filled; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return true; }


	// Setters
	void SetText(std::wstring text) { this->Text = text; }
	void SetFontName(std::wstring fontName) { this->Text = fontName; }
	void SetFontSize(int size) { this->FontSize = size; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetRGBAColor(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	void SetTextRGBAColor(float r, float g, float b, float a) { this->rText = r; this->gText = g; this->bText = b; this->aText = a; }
	void SetStroke(float stroke) { this->Stroke = stroke; }
	void SetMargins(float size) { this->Margins = size; }
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetFilled(bool state) { this->Filled = state; }
	void SetVisible(bool state) { this->Visible = state; }


	virtual ~UILabel();

private:
	Graphics * graphics;
	std::wstring Text = std::wstring(L"");
	std::wstring FontName = std::wstring(L"Arial");
	int FontSize = 10;
	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	float r = 0.0f, g = 0.0f, b = 0.0f, a = 0.0f;
	float rText = 0.0f, gText = 0.0f, bText = 0.0f, aText = 1.0f;
	float Stroke = 1.0f;
	float Margins = 0.1f;
	bool Filled = true;
	bool Visible = true;

	// Entire Label Border
	D2D1_RECT_F LabelBorder;

	// Text Border
	D2D1_RECT_F TextBorder;
};
#endif