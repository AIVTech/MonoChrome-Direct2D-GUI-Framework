#include "UISlider.h"
#include "MouseMovedWhileDownEventHandler.h"
#include "ValueChangedEventHandler.h"

void somefunc(UIElement* sender)
{

}

// Default constructor
UISlider::UISlider(Graphics* graphics)
{
	this->graphics = graphics;
	SetPressedMouseMovedHandler(somefunc);
}

UISlider::UISlider(Graphics* graphics, float x, float y)
{
	this->graphics = graphics;
	this->xPos = x;
	this->yPos = y;
	this->knobPosX = xPos + currentValue;
	SetPressedMouseMovedHandler(somefunc);
}

UISlider::UISlider(Graphics* graphics, float x, float y, float width)
{
	this->graphics = graphics;
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
	this->graphics->DrawRectangle(xPos, yPos, Width, Height, r, g, b, a, 2, true);

	// draw a slider-knob / handle
	this->graphics->DrawCircle(knobPosX, yPos, Radius, knobColorR, knobColorG, knobColorB, knobColorA, 1, true);
}

void UISlider::SetPressedMouseMovedHandler(callback_function func)
{
	PressedMouseMovedHandler = new MouseMovedWhileDownEventHandler(this, func);
}

void UISlider::SetValueChangedEventHandler(callback_function func)
{
	this->ValueChangedHandler = new ValueChangedEventHandler(this, func);
}
