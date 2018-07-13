#ifndef UITEXTBOX_H
#define UITEXTBOX_H

#include "UIElement.h"
#include <vector>

class EventHandler;

class UITextbox : public UIElement
{
public:
	UITextbox(UIWindow* srcWindow);
	UITextbox(UIWindow* srcWindow, std::wstring text);
	UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName);
	UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize);
	UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY);
	UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY, float Width, float Height);
	UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY,
		float Width, float Height, Color* color);
	UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY,
		float Width, float Height, Color* color, float stroke);

	void Draw();

	// Getters
	UIWindow* GetSourceWindow() { return this->srcWindow; }
	std::wstring GetText() { return this->Text; }
	std::wstring GetFontName() { return this->FontName; }
	float GetFontSize() { return this->FontSize; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetWidth() { return this->Width; }
	float GetHeight() { return this->Height; }
	float GetStroke() { return this->Stroke; }
	float GetBorderStroke() { return this->BorderStroke; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return this->Enabled; }
	bool GetFocused() { return this->Focused; }
	int GetVisibleTextLimit() { return this->textLimit; }
	int GetTextStartIndex() { return this->displayStartIndex; }
	Color* GetColor() { return this->color; }
	Color* GetTextColor() { return this->textColor; }
	Color* GetBorderColor() { return this->borderColor; }

	// Setters
	void SetText(std::wstring text) { this->previousText.push_back(Text); this->Text = text; }
	void AddText(std::wstring text) { this->previousText.push_back(Text); this->Text += text; }
	void RemoveCharacter(int index);
	void SetFontName(std::wstring fontName) { this->Text = fontName; }
	void SetFontSize(int size) { this->FontSize = (float)size; if (size > 40) this->FontSize = 40.0f; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetColor(Color* color) { this->color = color; this->normalAlpha = color->a; }
	void SetTextColor(Color* color) { this->textColor = color; }
	void SetBorderColor(Color* color) { this->borderColor = color; }
	void SetStroke(float stroke) { this->Stroke = stroke; }
	void SetBorderStroke(float stroke) { this->BorderStroke = stroke; }
	void SetVisible(bool state) { this->Visible = state; }
	void SetEnabled(bool state) 
	{
		this->Enabled = state;
		if (state)
		{
			color->a = normalAlpha;
			textColor->a = normalAlpha;
			borderColor->a = normalAlpha;
		}
		else
		{
			color->a = 36;
			textColor->a = 36;
			borderColor->a = 36;
		}
	}
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetFocused(bool state) 
	{ 
		this->Focused = state;
		if (state)
		{
			borderColor->r = 0;
			borderColor->g = 0;
			borderColor->b = 255;
		}
		else
		{
			borderColor->r = 0;
			borderColor->g = 0;
			borderColor->b = 0;
		}
	}
	void UndoTextAction();
	void IncrementDisplayStartIndex() { if (displayStartIndex < Text.size()-1) this->displayStartIndex++; }
	void DecrementDisplayStartIndex() { if (displayStartIndex > 0) this->displayStartIndex--; }
	void SetVisibleTextLimit(int limit) { this->textLimit = limit; }
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

	~UITextbox();
private:
	UIWindow* srcWindow;

	std::wstring Text = std::wstring(L"");
	std::vector<std::wstring> previousText = { Text };
	int TextAllignment = TEXT_ALLIGNMENT_CENTER;
	int displayStartIndex = 0;
	int textLimit = 14;
	std::wstring FontName = std::wstring(L"Arial");
	float FontSize = 10;
	float xPos = 0.0f, yPos = 0.0f, Width = 0.0f, Height = 0.0f;
	Color* color = Color::White;
	Color* textColor = Color::Black;
	Color* borderColor = Color::Black;
	uint8_t normalAlpha = 255;
	float Stroke = 1.0f;
	float BorderStroke = 1.0f;
	bool Enabled = true;
	bool Filled = true;
	bool Visible = true;
	bool Focused = false;

	// Event Handling
	typedef void(*callback_function)(UIElement* sender);
	EventHandler* textboxStateHandler;
	void SetTextboxStateHandler();
};

#endif