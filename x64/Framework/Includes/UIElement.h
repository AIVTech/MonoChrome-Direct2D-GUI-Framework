#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "UIWindow.h"
#include "Graphics.h"
#include "Color.h"
#include <thread>

#define TEXT_ALLIGNMENT_CENTER 1
#define TEXT_ALLIGNMENT_LEFT 2 
#define TEXT_ALLIGNMENT_RIGHT 3 

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

	typedef void(*uiElement_global_callback_function)(UIElement*);
	virtual void AddWhileMouseDownEventHandler(uiElement_global_callback_function callbackFunc);
	virtual void AddMouseClickEventHandler(uiElement_global_callback_function callbackFunc);

	void MakeTextAllignment(int allignment, DWRITE_TEXT_ALIGNMENT& textAllignment, DWRITE_PARAGRAPH_ALIGNMENT& paragraphAllignment)
	{
		if (allignment == TEXT_ALLIGNMENT_CENTER)
		{
			textAllignment = DWRITE_TEXT_ALIGNMENT_CENTER;
			paragraphAllignment = DWRITE_PARAGRAPH_ALIGNMENT_CENTER;
		}
		else if (allignment == TEXT_ALLIGNMENT_LEFT)
		{
			textAllignment = DWRITE_TEXT_ALIGNMENT_LEADING;
			paragraphAllignment = DWRITE_PARAGRAPH_ALIGNMENT_NEAR;
		}
		else if (allignment == TEXT_ALLIGNMENT_RIGHT)
		{
			textAllignment = DWRITE_TEXT_ALIGNMENT_TRAILING;
			paragraphAllignment = DWRITE_PARAGRAPH_ALIGNMENT_FAR;
		}
		else
		{
			textAllignment = DWRITE_TEXT_ALIGNMENT_CENTER;
			paragraphAllignment = DWRITE_PARAGRAPH_ALIGNMENT_CENTER;
		}
	}

private:
};

#endif // !UIELEMENT_H