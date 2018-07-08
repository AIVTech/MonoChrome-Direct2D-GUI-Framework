#pragma once

#include "UIElement.h"

class UISlot
{
public:
	UIElement* uiElement = NULL;
	float width = 0, height = 0;
};

class UIScrollableSlotArea : public UIElement
{
public:
	UIScrollableSlotArea(UIWindow* srcWindow);
	UIScrollableSlotArea(UIWindow* srcWindow, float xPos, float yPos);
	UIScrollableSlotArea(UIWindow* srcWindow, float xPos, float yPos, float width, float height);

	void Draw();

	// Getters
	UIWindow* GetSourceWindow() { return this->srcWindow; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetWidth() { return this->Width; }
	float GetHeight() { return this->Height; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return this->Enabled; }
	Color* GetColor() { return this->color; }

	// Setters
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetVisible(bool state) { this->Visible = state; }
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetColor(Color* color) { this->color = color; }
	void SetEnabled(bool state) {}

	void FadeOut(int animationDelay, int decrementValue) {}
	void FadeIn(int animationDelay, int decrementValue, int finalAlpha) {}

	// Functions specific to UIScrollableSlotArea
	void AddElement(UIElement* elem);
	void AddEmptySlot();
	void RemoveElement(int index);
	void RemoveElement(UIElement* elem);

	float GetDistanceBetweenSlots() { return this->distanceBetweenSlots; }
	void SetDistanceBetweenSlots(float distance) { this->distanceBetweenSlots = distance; }

	float GetSlotWidth() { return this->slotWidth; }
	void SetSlotWidth(float width) { this->slotWidth = width; }

	float GetSlotHeight() { return this->slotHeight; }
	void SetSlotHeight(float height) { this->slotHeight = height; }

	float GetSlotMarginTop() { return this->slotMarginTop; }
	float GetSlotMarginLeft() { return this->slotMarginLeft; }
	void SetSlotMarginTop(float margin) { this->slotMarginTop = margin; }
	void SetSlotMarginLeft(float margin) { this->slotMarginLeft = margin; }

	~UIScrollableSlotArea();

private:
	UIWindow * srcWindow;
	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	bool Visible = true;
	bool Enabled = true;
	Color* color = new Color_LightGray();
	uint8_t normalAlpha = color->a;

	// Slots and their properties
	std::vector<UISlot*> slots;
	float slotWidth = 0, slotHeight = 0, distanceBetweenSlots = 0;
	float slotMarginTop = 0, slotMarginLeft = 0;

	// Scroll bars
	bool shouldDrawScrollBar = false;
	float scrollBarWidth = 0, scrollBarHeight = 0;
	float scrollBarPosX = 0, scrollBarPosY = 0;
	void attachScrollBarEventHandler();
	void startScrollBarListener();
	void startScrollWheelListener();
};
