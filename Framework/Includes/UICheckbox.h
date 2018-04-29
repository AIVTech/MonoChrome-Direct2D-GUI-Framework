#ifndef UICHECKBOX_H
#define UICHECKBOX_H

#include <d2d1.h>
#include <string>
#include "Graphics.h"
#include "UIElement.h"

class EventHandler;

class UICheckbox : public UIElement
{
public:
	UICheckbox(Graphics* g);
	UICheckbox(Graphics* g, std::wstring text);
	UICheckbox(Graphics* g, std::wstring text, std::wstring fontName);
	UICheckbox(Graphics* g, std::wstring text, std::wstring fontName, int FontSize);
	UICheckbox(Graphics* g, std::wstring text, std::wstring fontName, int FontSize, float xPos, float yPos, float size);

	UICheckbox(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float size, float TextWidth, float TextHeight);

	UICheckbox(Graphics* graphics, std::wstring text, std::wstring fontName,
		int FontSize, float xPos, float yPos, float size, float TextWidth, float TextHeight, float margins);

	void Draw();

	// Getters
	Graphics* GetGraphics() { return this->graphics; }
	std::wstring GetText() { return this->Text; }
	std::wstring GetFontName() { return this->FontName; }
	int GetFontSize() { return this->FontSize; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetSize() { return this->Size; }
	float GetWidth() { return this->Size; }
	float GetHeight() { return this->Size; }
	float GetMargins() { return this->Margins; }
	float GetTextWidth() { return this->TextWidth; }
	float GetTextHeight() { return this->TextHeight; }
	bool GetChecked() { return this->Checked; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return this->Enabled; }
	bool GetRoundedCorners() { return this->RoundedCorners; }
	float GetRoundCornersRadiusX() { return this->roundCornerRadiusX; }
	float GetRoundCornersRadiusY() { return this->roundCornerRadiusY; }
	float GetAlphaComponent() { return this->a; }

	// Setters
	void SetText(std::wstring text) { this->Text = text; }
	void SetFontName(std::wstring fontName) { this->Text = fontName; }
	void SetFontSize(int size) { this->FontSize = size; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetTextRGBAColor(float r, float g, float b, float a) { this->rText = r; this->gText = g; this->bText = b; this->aText = a; this->normalAlpha = a; }
	void SetMargins(float size) { this->Margins = size; }
	void SetSize(float size) { this->Size = size; }
	void SetTextWidth(float w) { this->TextWidth = w; }
	void SetTextHeight(float h) { this->TextHeight = h; }
	void SetChecked(bool state) { this->Checked = state; }
	void SetVisible(bool state) { this->Visible = state; }
	void SetEnabled(bool state)
	{ 
		this->Enabled = state;
		if (state)
		{
			a = normalAlpha;
		}
		else
		{
			a = 0.14f;
		}
	}
	void SetRoundedCorners(bool state) { this->RoundedCorners = state; }
	void SetRoundedCornersRadii(float radX, float radY) { this->roundCornerRadiusX = radX; this->roundCornerRadiusY = radY; }
	void FadeOut(int animationDelay)
	{
		std::thread t([this, animationDelay] {
			for (float i = a * 100; i >= 0; i--)
			{
				Sleep(animationDelay);
				a = i / 100;
				this->normalAlpha = a;
				this->aText = a;
			}
			this->Visible = false;
		});
		t.detach();
	}
	void FadeIn(int animationDelay, float finalAlpha)
	{
		std::thread t([this, animationDelay, finalAlpha] {
			this->Visible = true;
			for (float i = a; i <= finalAlpha; i += 0.01f)
			{
				Sleep(animationDelay);
				a = i;
				this->normalAlpha = a;
				this->aText = a;
			}
		});
		t.detach();
	}

	// Setters for Event Handlers
	typedef void(*callback_function)(UIElement* sender);
	void SetStateChangedEventHandler(callback_function func);

	virtual ~UICheckbox();

private:
	Graphics* graphics;
	std::wstring Text = std::wstring(L"");
	std::wstring FontName = std::wstring(L"Arial");
	int FontSize = 10;
	float xPos = 0, yPos = 0, Size = 0, TextWidth = 0, TextHeight = 0;
	float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f, rText = 0.0f, gText = 0.0f, bText = 0.0f, aText = 1.0f, normalAlpha = 1.0f;
	float Margins = 1.0f;
	bool Visible = true;
	bool Enabled = true;
	bool RoundedCorners = false;
	float roundCornerRadiusX = 4, roundCornerRadiusY = 4;

	// Checked State
	bool Checked = false;

	// Entire Label Border
	D2D1_RECT_F LabelBorder;

	// Text Border
	D2D1_RECT_F TextBorder;

	// Event Handlers
	void SetMouseClickHandler(callback_function func);
	EventHandler* MouseClickHandler;
	EventHandler* StateEventHandler;

};


#endif // !UICHECKBOX_H