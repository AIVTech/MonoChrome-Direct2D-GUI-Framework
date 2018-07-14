#ifndef UICOMBOBOX_H
#define UICOMBOBOX_H

#include "Graphics.h"
#include "UIElement.h"
#include "EventHandler.h"
#include <vector>
#include <string>
#include <algorithm>

class EventHandler;

class UICombobox : public UIElement
{
public:

	UICombobox(UIWindow* srcWindow);
	UICombobox(UIWindow* srcWindow, float xPos, float yPos, float Width, float Height);
	UICombobox(UIWindow* srcWindow, float xPos, float yPos, float Width, float Height, Color* color);

	void Draw();

	// Getters
	UIWindow* GetSourceWindow() { return this->srcWindow; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetWidth() { return this->Width; }
	float GetHeight() { return this->Height; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return this->Enabled; }
	bool GetDrawItems() { return drawItems; }
	std::vector<std::wstring> GetItems() { return this->Items; }
	int GetSelectedIndex() { return this->SelectedIndex; }
	int GetHoverIndex() { return this->hoverIndex; }
	bool GetRoundedCorners() { return this->RoundedCorners; }
	float GetRoundCornersRadiusX() { return this->roundCornerRadiusX; }
	float GetRoundCornersRadiusY() { return this->roundCornerRadiusY; }
	Color* GetColor() { return this->color; }

	// Setters
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetVisible(bool state) { this->Visible = state; }
	void SetEnabled(bool state)
	{
		this->Enabled = state;
		if (state)
		{
			color->a = normalAlpha;
		}
		else
		{
			color->a = 36;
		}
	}
	void SetColor(Color* color) { this->color = color; }
	void SetItems(std::vector<std::wstring> items) { this->Items = items; }
	void SetDrawItems(bool state) { this->drawItems = state; }
	void SetSelectedIndex(int index) { this->SelectedIndex = index; }
	void SetHoverIndex(int index) { this->hoverIndex = index; }
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
			}
		});
		t.detach();
	}

	void AddItem(std::wstring item) { this->Items.push_back(item); }
	void RemoveItem(int index);
	void RemoveItem(std::wstring item);
	int IndexOf(std::wstring item);

	typedef void(*callback_function)(UIElement* sender);
	// Event Handler
	void SetSelectedIndexChangedEventHandler(callback_function func);

	~UICombobox();

private:
	UIWindow* srcWindow;
	float xPos = 30, yPos = 60, Width = 160, Height = 26;
	uint8_t normalAlpha = 255;
	Color* color = Color::White;
	bool Visible = true;
	bool Enabled = true;
	std::vector<std::wstring> Items = { L" " };
	int TextAllignment = TEXT_ALLIGNMENT_CENTER;
	int SelectedIndex = 0;
	bool drawItems = false;
	int hoverIndex = -1;
	bool RoundedCorners = true;
	float roundCornerRadiusX = 4, roundCornerRadiusY = 4;

	// Event Handlers
	typedef void(*callback_function)(UIElement* sender);

	EventHandler* MouseClickHandler;
	void SetMouseClickedHandler(callback_function func);

	EventHandler* ItemSelectionHandler;
	void SetItemSelectionHandler();

	EventHandler* SelectedIndexChangedHandler;
};

#endif // !UICOMBOBOX_H