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
		int FontSize, float xPos, float yPos, float Width, float Height, Color* color);

	UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke);

	UILabel(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke, float margins);

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
	Color* GetColor() { return this->color; }
	Color* GetTextColor() { return this->textColor; }
	

	// Setters
	void SetText(std::wstring text) { this->Text = text; }
	void SetFontName(std::wstring fontName) { this->Text = fontName; }
	void SetFontSize(int size) { this->FontSize = size; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetColor(Color* color) { this->color = color; }
	void SetTextColor(Color* color) { this->textColor = color; }
	void SetStroke(float stroke) { this->Stroke = stroke; }
	void SetMargins(float size) { this->Margins = size; }
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetFilled(bool state) { this->Filled = state; }
	void SetVisible(bool state) { this->Visible = state; }
	void FadeOut(int animationDelay)
	{
		std::thread t([this, animationDelay] {
			for (float i = color->a * 100; i >= 0; i--)
			{
				Sleep(animationDelay);
				color->a = i / 100;
				this->textColor->a = color->a;
			}
			this->Visible = false;
		});
		t.detach();
	}
	void FadeIn(int animationDelay, float finalAlpha)
	{
		std::thread t([this, animationDelay, finalAlpha] {
			this->Visible = true;
			for (float i = color->a; i <= finalAlpha; i += 0.01f)
			{
				Sleep(animationDelay);
				color->a = i;
				this->textColor->a = color->a;
			}
		});
		t.detach();
	}

	virtual ~UILabel();

private:
	Graphics* graphics;
	std::wstring Text = std::wstring(L"");
	std::wstring FontName = std::wstring(L"Arial");
	int FontSize = 10;
	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	Color* color = new Color(0.8f, 0.8f, 0.8f, 1.0f);
	Color* textColor = new Color_White();
	float Stroke = 1.0f;
	float Margins = 0.1f;
	bool Filled = false;
	bool Visible = true;

	// Entire Label Border
	D2D1_RECT_F LabelBorder;

	// Text Border
	D2D1_RECT_F TextBorder;
};


#endif