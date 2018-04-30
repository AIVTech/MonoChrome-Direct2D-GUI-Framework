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
			color->a = 0.14f;
			knobColor->a = 0.14f;
		}
	}
	void FadeOut(int animationDelay)
	{
		std::thread t([this, animationDelay] {
			for (float i = color->a * 100; i >= 0; i--)
			{
				Sleep(animationDelay);
				color->a = i / 100;
				this->normalAlpha = color->a;
				this->knobColor->a = color->a;
			}
			this->Visible = false;
		});
		t.detach();
	}
	void FadeIn(int animationDelay, float finalAlpha)
	{
		std::thread t([this, animationDelay, finalAlpha] {
			this->Visible = true;
			for (float i = color->a; i <= finalAlpha; i += 0.01f)
			{
				Sleep(animationDelay);
				color->a = i;
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
	Graphics* graphics;
	float xPos = 0, yPos = 0, Width = 120;
	float normalAlpha = 1.0f;
	Color* color = new Color(0.2f, 0.2f, 0.2f, 1.0f);
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