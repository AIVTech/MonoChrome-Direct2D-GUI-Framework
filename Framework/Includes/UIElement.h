#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "Graphics.h"

class UIElement 
{
public:

	virtual void Draw() = 0;
	virtual Graphics* GetGraphics() = 0;
	
	virtual float GetPosX() = 0;
	virtual float GetPosY() = 0;
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
	virtual bool GetVisible() = 0;
	virtual void SetVisible(bool state) = 0;
	virtual bool GetEnabled() = 0;

private:
};

#endif // !UIELEMENT_H