#ifndef UISLIDER_H
#define UISLIDER_H

#include "Graphics.h"
#include "UIElement.h"

class EventHandler;

class UISlider : public UIElement
{
public:
	typedef void(*callback_function)(UIElement* sender);
	UISlider(UIWindow* srcWindow);
	UISlider(UIWindow* srcWindow, float x, float y);
	UISlider(UIWindow* srcWindow, float x, float y, float width);


	void Draw();

	// Getters
	UIWindow* GetSourceWindow() { return srcWindow; }
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
	Color* GetColor() { return this->color; }
	Color* GetKnobColor() { return this->knobColor; }
	

	// Setters
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; this->knobPosX = xPos + currentValue; }
	void SetWidth(float width) { this->Width = width; }
	void SetKnobRadius(float radius) { this->Radius = radius; }
	void SetHeight(float height) { this->Height = height; }
	void SetColor(Color* color) { this->color = color; this->normalAlpha = color->a; }
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
			color->a = normalAlpha;
			knobColor->a = normalAlpha;
		}
		else
		{
			color->a = 36;
			knobColor->a = 36;
		}
	}
	void FadeOut(int animationDelay, int decrementValue)
	{
		std::thread t([this, animationDelay, decrementValue] {
			for (int i = color->a; i >= 1; i -= decrementValue)
			{
				Sleep(animationDelay);
				uint8_t val = (uint8_t)i;
				color->a = val;
				this->normalAlpha = color->a;
				this->knobColor->a = color->a;
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
				this->knobColor->a = color->a;
			}
		});
		t.detach();
	}

	// Event Handlers
	void SetValueChangedEventHandler(callback_function func);

	~UISlider();

private:
	UIWindow* srcWindow;
	float xPos = 0, yPos = 0, Width = 120;
	uint8_t normalAlpha = 255;
	Color* color = new Color(80, 80, 80, 255);
	float Height = 4;
	float MinValue = 0, MaxValue = 100, Intervals = 10;
	float currentValue = MinValue;
	bool Visible = true;
	bool Enabled = true;

	// some slider-knob attributes
	float knobPosX = xPos + currentValue;
	Color* knobColor = new Color_White();
	float Radius = Height*2;

	// Event Handler
	EventHandler* ValueChangedHandler;
	EventHandler* PressedMouseMovedHandler;
	void SetPressedMouseMovedHandler(callback_function func);
};


#endif