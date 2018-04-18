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
	UIButton(Graphics* g);
	UIButton(Graphics* g, std::wstring text);
	UIButton(Graphics* g, std::wstring text, std::wstring fontName);
	UIButton(Graphics* g, std::wstring text, std::wstring fontName, int FontSize);
	UIButton(Graphics* g, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float Width, float Height);
	UIButton(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a);

	UIButton(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a, float stroke);

	UIButton(Graphics* graphics, std::wstring text, std::wstring fontName,
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
	bool GetEnabled() { return this->Enabled; }
	bool GetRoundedCorners() { return this->RoundedCorners; }
	float GetRoundCornersRadiusX() { return this->roundCornerRadiusX; }
	float GetRoundCornersRadiusY() { return this->roundCornerRadiusY; }

	// Setters
	void SetText(std::wstring text) { this->Text = text; }
	void SetFontName(std::wstring fontName) { this->Text = fontName; }
	void SetFontSize(int size) { this->FontSize = size; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetRGBAColor(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; this->normalAlpha = a; }
	void SetTextRGBAColor(float r, float g, float b, float a) { this->rText = r; this->gText = g; this->bText = b; this->aText = a; }
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
			a = normalAlpha;
			borderA = normalAlpha;
		}
		else
		{
			a = 0.14f;
			borderA = 0.14f;
		}
	}
	void SetRoundedCorners(bool state) { this->RoundedCorners = state; }
	void SetRoundedCornersRadii(float radX, float radY) { this->roundCornerRadiusX = radX; this->roundCornerRadiusY = radY; }
	

	// Setters for Event Handlers
	typedef void(*callback_function)(UIElement* sender);
	void SetMouseClickEventHandler(callback_function func);

	virtual ~UIButton();

private:
	Graphics* graphics;
	std::wstring Text = std::wstring(L"");
	std::wstring FontName = std::wstring(L"Arial");
	int FontSize = 10;
	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	float r = 0.7f, g = 0.7f, b = 0.7f, a = 1.0f, normalAlpha = a;
	float rText = 0.0f, gText = 0.0f, bText = 0.0f, aText = 1.0f;
	float borderR = 0.2f, borderG = 0.2f, borderB = 0.2f, borderA = 1.0f, borderStroke = 2.0f;
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
	EventHandler* MouseClickHandler;

	EventHandler* MouseHoverHandler;
	void SetMouseHoverEventHandler(callback_function func, callback_function funcOff);
};


#endif // !UIBUTTON_H