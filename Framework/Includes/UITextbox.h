#ifndef UITEXTBOX_H
#define UITEXTBOX_H

#include "UIElement.h"
#include <vector>

class EventHandler;

class UITextbox : public UIElement
{
public:
	UITextbox(Graphics* graphics);
	UITextbox(Graphics* graphics, std::wstring text);
	UITextbox(Graphics* graphics, std::wstring text, std::wstring fontName);
	UITextbox(Graphics* graphics, std::wstring text, std::wstring fontName, float fontSize);
	UITextbox(Graphics* graphics, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY);
	UITextbox(Graphics* graphics, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY, float Width, float Height);
	UITextbox(Graphics* graphics, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY, 
		float Width, float Height, float r, float g, float b, float a);
	UITextbox(Graphics* graphics, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY,
		float Width, float Height, float r, float g, float b, float a, float stroke);

	void Draw();

	// Getters
	Graphics* GetGraphics() { return this->graphics; }
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
	float GetAlphaComponent() { return this->a; }

	// Setters
	void SetText(std::wstring text) { this->previousText.push_back(Text); this->Text = text; }
	void AddText(std::wstring text) { this->previousText.push_back(Text); this->Text += text; }
	void RemoveCharacter(int index);
	void SetFontName(std::wstring fontName) { this->Text = fontName; }
	void SetFontSize(int size) { this->FontSize = (float)size; if (size > 40) this->FontSize = 40.0f; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetRGBAColor(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	void SetTextRGBAColor(float r, float g, float b, float a) { this->rText = r; this->gText = g; this->bText = b; this->aText = a; }
	void SetStroke(float stroke) { this->Stroke = stroke; }
	void SetBorderStroke(float stroke) { this->BorderStroke = stroke; }
	void SetVisible(bool state) { this->Visible = state; }
	void SetEnabled(bool state) 
	{
		this->Enabled = state;
		if (state)
		{
			a = normalAlpha;
			aText = normalAlpha;
			borderA = normalAlpha;
		}
		else
		{
			a = 0.14f;
			aText = 0.14f;
			borderA = 0.14f;
		}
	}
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetFocused(bool state) 
	{ 
		this->Focused = state;
		if (state)
		{
			borderR = 0.0f;
			borderG = 0.0f;
			borderB = 1.0f;
			borderA = 1.0f;
		}
		else
		{
			borderR = 0.0f;
			borderG = 0.0f;
			borderB = 0.0f;
			borderA = normalAlpha;
		}
	}
	void UndoTextAction();
	void IncrementDisplayStartIndex() { if (displayStartIndex < Text.size()-1) this->displayStartIndex++; }
	void DecrementDisplayStartIndex() { if (displayStartIndex > 0) this->displayStartIndex--; }
	void SetVisibleTextLimit(int limit) { this->textLimit = limit; }
	void FadeOut(int animationDelay)
	{
		std::thread t([this, animationDelay] {
			for (float i = a * 100; i >= 0; i--)
			{
				Sleep(animationDelay);
				a = i / 100;
				this->normalAlpha = a;
				this->aText = a;
				this->borderA = a;
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
				this->borderA = a;
			}
		});
		t.detach();
	}

	~UITextbox();
private:
	Graphics* graphics;

	std::wstring Text = std::wstring(L"");
	std::vector<std::wstring> previousText = { Text };
	int displayStartIndex = 0;
	int textLimit = 14;
	std::wstring FontName = std::wstring(L"Arial");
	float FontSize = 10;
	float xPos = 0.0f, yPos = 0.0f, Width = 0.0f, Height = 0.0f;
	float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f, normalAlpha = a;
	float rText = 0.0f, gText = 0.0f, bText = 0.0f, aText = 1.0f;
	float borderR = 0.0f, borderG = 0.0f, borderB = 0.0f, borderA = 1.0f;
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