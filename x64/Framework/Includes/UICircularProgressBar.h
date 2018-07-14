#ifndef CIRCULARPROGRESSBAR_H
#define CIRCULARPROGRESSBAR_H

#include "UIElement.h"

class UICircularProgressBar : public UIElement
{
public:
	UICircularProgressBar(UIWindow* srcWindow);
	UICircularProgressBar(UIWindow* srcWindow, float xPos, float yPos);
	UICircularProgressBar(UIWindow* srcWindow, float xPos, float yPos, float radius);
	UICircularProgressBar(UIWindow* srcWindow, float xPos, float yPos, float radius, float stroke);

	void Draw();

	// Getters
	UIWindow* GetSourceWindow() { return this->srcWindow; }
	float GetPosX() { return this->xPos; }
	float GetPosY() { return this->yPos; }
	float GetWidth() { return this->Width; }
	float GetHeight() { return this->Height; }
	bool GetVisible() { return this->Visible; }
	bool GetEnabled() { return this->Enabled; }
	float GetStroke() { return this->Stroke; }
	float GetRadius() { return this->Radius; }
	float GetValue() { return this->Value; }
	float GetMinValue() { return this->MinValue; }
	float GetMaxValue() { return this->MaxValue; }
	float GetInterval() { return this->Interval; }
	Color* GetColor() { return this->color; }
	Color* GetProgressColor() { return this->progressColor; }

	// Setters
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; UpdateArcEndPoint(); }
	void SetVisible(bool state) { this->Visible = state; }
	void SetStroke(float stroke) { this->Stroke = stroke; }
	void SetRadius(float size) { this->Radius = size; UpdateArcEndPoint(); }
	void SetColor(Color* color) { this->color = color; this->normalAlpha = color->a; }
	void SetProgressColor(Color* color) { this->progressColor = color; }
	void SetEnabled(bool state)
	{ 
		this->Enabled = state;
		if (state)
		{
			color->a = normalAlpha;
			progressColor->a = normalAlpha;
		}
		else
		{
			color->a = 36;
			progressColor->a = 36;
		}
	}
	void SetValue(float value) { this->Value = value; UpdateArcEndPoint();  }
	void SetMinValue(float value) { this->MinValue = value; }
	void SetMaxValue(float value) { this->MaxValue = value; }
	void SetInterval(float value) { this->Interval = value; }
	void FadeOut(int animationDelay, int decrementValue)
	{
		std::thread t([this, animationDelay, decrementValue] {
			for (int i = color->a; i >= 1; i -= decrementValue)
			{
				Sleep(animationDelay);
				uint8_t val = (uint8_t)i;
				color->a = val;
				this->normalAlpha = color->a;
				this->progressColor->a = color->a;
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
				this->progressColor->a = color->a;
			}
		});
		t.detach();
	}

	~UICircularProgressBar();
private:
	UIWindow* srcWindow;

	void SetArcEndPoint(float x, float y) { this->arcEndPointX = x; this->arcEndPointY = y; }
	void UpdateArcEndPoint();
	D2D1_ARC_SIZE arcSize = D2D1_ARC_SIZE_SMALL;

	float xPos = 50, yPos = 40, Width = 0, Height = 0;
	uint8_t normalAlpha = 255;
	Color* color = Color::Black;
	Color* progressColor = Color::Cyan;
	float arcEndPointX = xPos;
	float arcEndPointY = yPos - Radius;
	float Stroke = 4.0f;
	float Radius = 20.0f;
	float Value = 0.0f;
	float Interval = 1.0f;
	float MinValue = 0.0f, MaxValue = 100.0f;
	bool Visible = true;
	bool Enabled = true;
};

#endif // !CIRCULARPROGRESSBAR_H