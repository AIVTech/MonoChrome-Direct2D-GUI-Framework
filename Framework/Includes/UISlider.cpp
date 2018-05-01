#include "UISlider.h"
#include "MouseMovedWhileDownEventHandler.h"
#include "ValueChangedEventHandler.h"

void somefunc(UIElement* sender)
{

}

// Default constructor
UISlider::UISlider(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
	SetPressedMouseMovedHandler(somefunc);
}

UISlider::UISlider(UIWindow* srcWindow, float x, float y)
{
	this->srcWindow = srcWindow;
	this->xPos = x;
	this->yPos = y;
	this->knobPosX = xPos + currentValue;
	SetPressedMouseMovedHandler(somefunc);
}

UISlider::UISlider(UIWindow* srcWindow, float x, float y, float width)
{
	this->srcWindow = srcWindow;
	this->xPos = x;
	this->yPos = y;
	this->knobPosX = xPos + currentValue;
	this->Width = width;
	SetPressedMouseMovedHandler(somefunc);
}

UISlider::~UISlider()
{

}


void UISlider::Draw()
{
	// draw a bar
	this->srcWindow->GetGraphics()->DrawRectangle(xPos, yPos, Width, Height, color->r, color->g, color->b, color->a, 2, true);
	
	// draw a slider-knob / handle
	this->srcWindow->GetGraphics()->DrawCircle(knobPosX, yPos, Radius, knobColor->r, knobColor->g, knobColor->b, knobColor->a, 1, true);
}

void UISlider::SetPressedMouseMovedHandler(callback_function func)
{
	PressedMouseMovedHandler = new MouseMovedWhileDownEventHandler(this, func);
}

void UISlider::SetValueChangedEventHandler(callback_function func)
{
	this->ValueChangedHandler = new ValueChangedEventHandler(this, func);
}

