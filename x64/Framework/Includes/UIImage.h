#pragma once

#include "UIElement.h"

class UIImage : public UIElement
{
public:
	UIImage(UIWindow* srcWindow, const wchar_t* imgFilepath);
	UIImage(UIWindow* srcWindow, const wchar_t* imgFilepath, float xPos, float yPos);
	UIImage(UIWindow* srcWindow, const wchar_t* imgFilepath, float xPos, float yPos, float width, float height);

	void Draw();

	// Getters
	UIWindow* GetSourceWindow() { return this->srcWindow; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetWidth() { return this->Width; }
	float GetHeight() { return this->Height; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return true; }
	Color* GetColor() { return nullptr; }
	float GetImageOpacity() { return this->imageOpacity; }

	// Setters
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; }
	void SetColor(Color* color) {}
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetVisible(bool state) { this->Visible = state; }
	void FadeOut(int animationDelay, int decrementValue) {}
	void FadeIn(int animationDelay, int incrementValue, int finalAlpha) {}

	float GetImageWidth() { return bitmapImage->GetSize().width; }
	float GetImageHeight() { return bitmapImage->GetSize().height; }
	void SetImageOpacity(float opacity) { this->imageOpacity = opacity; }

	~UIImage();
private:
	UIWindow* srcWindow;
	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	bool Visible = true;
	float imageOpacity = 1.0f;
	ID2D1Bitmap* bitmapImage;
};

