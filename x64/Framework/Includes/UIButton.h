#ifndef __UIBUTTON_H
#define __UIBUTTON_H

#include <d2d1.h>
#include <string>
#include "Graphics.h"
#include "UIElement.h"

class EventHandler;

class UIButton : public UIElement
{
public:
	UIButton(UIWindow* srcWindow);
	UIButton(UIWindow* srcWindow, std::wstring text);
	UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName);
	UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize);
	UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float Width, float Height);
	UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, Color* color);

	UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke);

	UIButton(UIWindow* srcWindow, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, Color* color, float stroke, float margins);

	void Draw();

	// Getters
	UIWindow* GetSourceWindow() { return this->srcWindow; }
	std::wstring GetText() { return this->Text; }
	std::wstring GetFontName() { return this->FontName; }
	int GetFontSize() { return this->FontSize; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetWidth() { return this->Width; }
	float GetHeight() { return this->Height; }
	float GetStroke() { return this->Stroke; }
	float GetMargins() { return this->Margins; }
	Color* GetColor() { return this->color; }
	Color* GetTextColor() { return this->textColor; }
	bool GetFilled() { return this->Filled; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return this->Enabled; }
	bool GetRoundedCorners() { return this->RoundedCorners; }
	float GetRoundCornersRadiusX() { return this->roundCornerRadiusX; }
	float GetRoundCornersRadiusY() { return this->roundCornerRadiusY; }

	// Setters
	void SetText(std::wstring text) { this->Text = text; }
	void SetFontName(std::wstring fontName) { this->Text = fontName; }
	void SetTextAllignment(int alligment) { this->TextAllignment = alligment; }
	void SetFontSize(int size) { this->FontSize = size; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetColor(Color* color) { this->color = color; this->normalAlpha = color->a; }
	void SetTextColor(Color* color) { this->textColor = color; }
	void SetStroke(float stroke) { this->Stroke = stroke; }
	void SetMargins(float size) { this->Margins = size; }
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetFilled(bool state) { this->Filled = state; }
	void SetVisible(bool state) { this->Visible = state; }
	void SetEnabled(bool state) 
	{ 
		this->Enabled = state;
		if (state)
		{
			color->a = normalAlpha;
			borderColor->a = normalAlpha;
		}
		else
		{
			color->a = 36;
			borderColor->a = 36;
		}
	}
	void SetRoundedCorners(bool state) { this->RoundedCorners = state; }
	void SetRoundedCornersRadii(float radX, float radY) { this->roundCornerRadiusX = radX; this->roundCornerRadiusY = radY; }
	void FadeOut(int animationDelay, int decrementValue)
	{
		std::thread t([this, animationDelay, decrementValue] {
			for (int i = color->a; i >= 1; i -= decrementValue)
			{
				Sleep(animationDelay);
				uint8_t val = (uint8_t)i;
				color->a = val;
				this->normalAlpha = color->a;
				this->textColor->a = color->a;
				this->borderColor->a = color->a;
			}
			this->Visible = false;
			return;
		});
		t.detach();
	}
	void FadeIn(int animationDelay, int incrementValue, int finalAlpha)
	{
		if (finalAlpha >= 255)
			finalAlpha = 254;
		std::thread t([this, animationDelay, incrementValue, finalAlpha] {
			this->Visible = true;
			for (int i = color->a; i <= finalAlpha; i += incrementValue)
			{
				Sleep(animationDelay);
				uint8_t val = (uint8_t)i;
				color->a = val;
				this->normalAlpha = color->a;
				this->textColor->a = color->a;
				this->borderColor->a = color->a;
			}
		});
		t.detach();
	}

	// Setters for Event Handlers
	typedef void(*callback_function)(UIElement* sender);

	virtual ~UIButton();

private:
	UIWindow* srcWindow;
	std::wstring Text = std::wstring(L"");
	std::wstring FontName = std::wstring(L"Arial");
	int TextAllignment = TEXT_ALLIGNMENT_CENTER;
	int FontSize = 10;
	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	Color* color = new Color(140, 140, 140, 255);
	uint8_t normalAlpha = color->a;
	Color* textColor = Color::Black;
	Color* borderColor = new Color(40, 40, 40, 255);
	float borderStroke = 2.0f;
	float Stroke = 1.0f;
	float Margins = 0.1f;
	bool Filled = true;
	bool Visible = true;
	bool Enabled = true;
	bool RoundedCorners = false;
	float roundCornerRadiusX = 4, roundCornerRadiusY = 4;

	// Entire Label Border
	D2D1_RECT_F LabelBorder;

	// Text Border
	D2D1_RECT_F TextBorder;

	// Event Handlers
	EventHandler* MouseHoverHandler;
	void SetMouseHoverEventHandler(callback_function func, callback_function funcOff);
};


#endif // !UIBUTTON_H