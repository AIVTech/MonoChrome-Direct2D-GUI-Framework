#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "UIWindow.h"
#include "Graphics.h"
#include "Color.h"
#include <thread>

class UIElement 
{
public:

	virtual void Draw() = 0;
	virtual UIWindow* GetSourceWindow() = 0;
	
	virtual float GetPosX() = 0;
	virtual float GetPosY() = 0;
	virtual void SetPosition(float x, float y) = 0;
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
	virtual void SetWidth(float width) = 0;
	virtual void SetHeight(float height) = 0;
	virtual Color* GetColor() = 0;
	virtual bool GetVisible() = 0;
	virtual void SetVisible(bool state) = 0;
	virtual bool GetEnabled() = 0;
	virtual void FadeOut(int animationDelay, int decrementValue) = 0;
	virtual void FadeIn(int animationDelay, int incrementValue, int finalAlpha) = 0;

private:
};

#endif // !UIELEMENT_H