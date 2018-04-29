#ifndef CIRCULARPROGRESSBAR_H
#define CIRCULARPROGRESSBAR_H

#include "UIElement.h"

class UICircularProgressBar : public UIElement
{
public:
	UICircularProgressBar(Graphics* graphics);
	UICircularProgressBar(Graphics* graphics, float xPos, float yPos);
	UICircularProgressBar(Graphics* graphics, float xPos, float yPos, float radius);
	UICircularProgressBar(Graphics* graphics, float xPos, float yPos, float radius, float stroke);

	void Draw();

	// Getters
	Graphics* GetGraphics() { return this->graphics; }
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
	float GetAlphaComponent() { return this->a; }

	// Setters
	void SetWidth(float width) { this->Width = width; }
	void SetHeight(float height) { this->Height = height; }
	void SetPosition(float x, float y) { this->xPos = x; this->yPos = y; UpdateArcEndPoint(); }
	void SetVisible(bool state) { this->Visible = state; }
	void SetStroke(float stroke) { this->Stroke = stroke; }
	void SetRadius(float size) { this->Radius = size; UpdateArcEndPoint(); }
	void SetRGBAColor(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; this->normalAlpha = a; }
	void SetRGBAProgressColor(float r, float g, float b, float a) { this->progressR = r; this->progressG = g; this->progressB = b; this->progressA = a; }
	void SetEnabled(bool state)
	{ 
		this->Enabled = state;
		if (state)
		{
			a = normalAlpha;
			progressA = normalAlpha;
		}
		else
		{
			a = 0.14f;
			progressA = 0.14f;
		}
	}
	void SetValue(float value) { this->Value = value; UpdateArcEndPoint();  }
	void SetMinValue(float value) { this->MinValue = value; }
	void SetMaxValue(float value) { this->MaxValue = value; }
	void SetInterval(float value) { this->Interval = value; }
	void FadeOut(int animationDelay)
	{
		std::thread t([this, animationDelay] {
			for (float i = a * 100; i >= 0; i--)
			{
				Sleep(animationDelay);
				a = i / 100;
				this->normalAlpha = a;
				this->progressA = a;
			}
			this->Visible = false;
		});
		t.detach();
	}
	void FadeIn(int animationDelay, float finalAlpha)
	{
		std::thread t([this, animationDelay, finalAlpha] {
			this->Visible = true;
			for (float i = a; i <= finalAlpha; i += 0.01f)
			{
				Sleep(animationDelay);
				a = i;
				this->normalAlpha = a;
				this->progressA = a;
			}
		});
		t.detach();
	}

	~UICircularProgressBar();
private:
	Graphics * graphics;

	void SetArcEndPoint(float x, float y) { this->arcEndPointX = x; this->arcEndPointY = y; }
	void UpdateArcEndPoint();
	D2D1_ARC_SIZE arcSize = D2D1_ARC_SIZE_SMALL;

	float xPos = 0, yPos = 0, Width = 0, Height = 0;
	float r = 4.0f, g = 4.0f, b = 4.0f, a = 1.0f, normalAlpha = a;
	float progressR = 0.0f, progressG = 1.0f, progressB = 0.0f, progressA = 1.0f;
	float arcEndPointX = xPos;
	float arcEndPointY = yPos - Radius;
	float Stroke = 4.0f;
	float Radius = 30.0f;
	float Value = 0.0f;
	float Interval = 1.0f;
	float MinValue = 0.0f, MaxValue = 100.0f;
	bool Visible = true;
	bool Enabled = true;
};

#endif // !CIRCULARPROGRESSBAR_H