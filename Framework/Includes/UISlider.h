#ifndef UISLIDER_H
#define UISLIDER_H

#include "Graphics.h"
#include "UIElement.h"

class EventHandler;

class UISlider : public UIElement
{
public:
	typedef void(*callback_function)(UIElement* sender);
	UISlider(Graphics* graphcis);
	UISlider(Graphics* graphcis, float x, float y);
	UISlider(Graphics* graphcis, float x, float y, float width);


	void Draw();

	// Getters
	Graphics* GetGraphics() { return graphics; }
	float GetPosX() { return xPos; }
	float GetPosY() { return yPos; }
	float GetWidth() { return Width; }
	float GetHeight() { return Height; }
	float GetKnobRadius() { return Radius; }
	float GetMinValue() { return MinValue; }
	float GetMaxValue() { return MaxValue; }
	float GetValue() { return currentValue; }
	float GetIntervals() { return Intervals; }
	float GetKnobPosX() { return knobPosX; }
	bool GetVisible() { return Visible; }
	bool GetEnabled() { return Enabled; }


	// Setters
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; this->knobPosX = xPos + currentValue; }
	void SetWidth(float width) { this->Width = width; }
	void SetKnobRadius(float radius) { this->Radius = radius; }
	void SetHeight(float height) { this->Height = height; }
	void SetRGBColor(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->normalAlpha = 1.0f; }
	void SetMinValue(float val) { this->MinValue = val; }
	void SetMaxValue(float val) { this->MaxValue = val; }
	void SetValue(float val) { this->currentValue = val; }
	void SetIntervals(float val) { this->Intervals = val; }
	void SetKnobPosX(float val) { this->knobPosX = val; }
	void SetVisible(bool state) { this->Visible = state; }
	void SetEnabled(bool state)
	{
		this->Enabled = state;
		if (state)
		{
			a = normalAlpha;
			knobColorA = normalAlpha;
		}
		else
		{
			a = 0.14f;
			knobColorA = 0.14f;
		}
	}

	// Event Handlers
	void SetValueChangedEventHandler(callback_function func);

	~UISlider();

private:
	Graphics * graphics;
	float xPos = 0, yPos = 0, Width = 120;
	float r = 0.2f, g = 0.2f, b = 0.2f, a = 1.0f, normalAlpha = a;
	float Height = 4;
	float MinValue = 0, MaxValue = 100, Intervals = 10;
	float currentValue = MinValue;
	bool Visible = true;
	bool Enabled = true;

	// some slider-knob attributes
	float knobPosX = xPos + currentValue;
	float knobColorR = 1.0f, knobColorG = 1.0f, knobColorB = 1.0f, knobColorA = 1.0f;
	float Radius = Height * 2;

	// Event Handler
	EventHandler* ValueChangedHandler;
	EventHandler* PressedMouseMovedHandler;
	void SetPressedMouseMovedHandler(callback_function func);
};


#endif