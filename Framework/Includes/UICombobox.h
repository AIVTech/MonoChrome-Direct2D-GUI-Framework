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

	UICombobox(Graphics* graphics);
	UICombobox(Graphics* graphics, float xPos, float yPos, float Width, float Height);
	UICombobox(Graphics* graphics, float xPos, float yPos, float Width, float Height, float r, float g, float b, float a);

	void Draw();

	// Getters
	Graphics* GetGraphics() { return this->graphics; }
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
			a = normalAlpha;
		}
		else
		{
			a = 0.14f;
		}
	}
	void SetRGBAColor(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	void SetItems(std::vector<std::wstring> items) { this->Items = items; }
	void SetDrawItems(bool state) { this->drawItems = state; }
	void SetSelectedIndex(int index) { this->SelectedIndex = index; }
	void SetHoverIndex(int index) { this->hoverIndex = index; }
	void SetRoundedCorners(bool state) { this->RoundedCorners = state; }
	void SetRoundedCornersRadii(float radX, float radY) { this->roundCornerRadiusX = radX; this->roundCornerRadiusY = radY; }

	void AddItem(std::wstring item) { this->Items.push_back(item); }
	void RemoveItem(int index);
	void RemoveItem(std::wstring item);
	int IndexOf(std::wstring item);

	typedef void(*callback_function)(UIElement* sender);
	// Event Handler
	void SetSelectedIndexChangedEventHandler(callback_function func);

	~UICombobox();

private:
	Graphics* graphics;
	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f, normalAlpha = a;
	bool Visible = true;
	bool Enabled = true;
	std::vector<std::wstring> Items = { L" " };
	int SelectedIndex = 0;
	bool drawItems = false;
	int hoverIndex = -1;
	bool RoundedCorners = false;
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