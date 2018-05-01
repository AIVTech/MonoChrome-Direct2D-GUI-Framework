#include "UICircularProgressBar.h"

UICircularProgressBar::UICircularProgressBar(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
}

UICircularProgressBar::UICircularProgressBar(UIWindow* srcWindow, float xPos, float yPos)
{
	this->srcWindow = srcWindow;
	this->xPos = xPos;
	this->yPos = yPos;
	this->arcEndPointX = xPos;
	this->arcEndPointY = yPos - Radius;
}

UICircularProgressBar::UICircularProgressBar(UIWindow* srcWindow, float xPos, float yPos, float radius)
{
	this->srcWindow = srcWindow;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Radius = radius;
	this->arcEndPointX = xPos;
	this->arcEndPointY = yPos - Radius;
}

UICircularProgressBar::UICircularProgressBar(UIWindow* srcWindow, float xPos, float yPos, float radius, float stroke)
{
	this->srcWindow = srcWindow;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Radius = radius;
	this->Stroke = stroke;
	this->arcEndPointX = xPos;
	this->arcEndPointY = yPos - Radius;
}


UICircularProgressBar::~UICircularProgressBar()
{
}


void UICircularProgressBar::Draw()
{
	srcWindow->GetGraphics()->DrawCircle(xPos, yPos, Radius, color->r, color->g, color->b, color->a, Stroke, false);
	if (Value > MinValue)
	{
		srcWindow->GetGraphics()->DrawArc(xPos, yPos - Radius, arcEndPointX, arcEndPointY, Radius,
			D2D1_SWEEP_DIRECTION_CLOCKWISE, arcSize, progressColor->r, progressColor->g, progressColor->b, progressColor->a, Stroke);
	}
}

void UICircularProgressBar::UpdateArcEndPoint()
{
	if (this->Value	> this->MaxValue)
	{
		this->Value = this->MaxValue;
		return;
	}
	else if (this->Value < this->MinValue)
	{
		this->Value = this->MinValue;
		return;
	}

	float valueRange = MaxValue - MinValue;
	float currentPercent = (Value - MinValue) / valueRange;
	if (currentPercent < 0.5f)
	{
		arcSize = D2D1_ARC_SIZE_SMALL;
	}
	else
	{
		arcSize = D2D1_ARC_SIZE_LARGE;
	}

	float angle = 2 * 3.14 * currentPercent;

	float xCoord = xPos + sinf(angle) * Radius;
	float yCoord = yPos - cosf(angle) * Radius;

	SetArcEndPoint(xCoord, yCoord);
}

