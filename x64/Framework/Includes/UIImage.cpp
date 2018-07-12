#include "UIImage.h"

UIImage::UIImage(UIWindow* srcWindow, const wchar_t* imgFilepath)
{
	this->srcWindow = srcWindow;
	this->bitmapImage = srcWindow->GetGraphics()->mcLoadImage(imgFilepath);
	this->Width = GetImageWidth();
	this->Height = GetImageHeight();
}

UIImage::UIImage(UIWindow* srcWindow, const wchar_t* imgFilepath, float xPos, float yPos)
{
	this->srcWindow = srcWindow;
	this->bitmapImage = srcWindow->GetGraphics()->mcLoadImage(imgFilepath);
	this->Width = GetImageWidth();
	this->Height = GetImageHeight();
	this->xPos = xPos;
	this->yPos = yPos;
}

UIImage::UIImage(UIWindow* srcWindow, const wchar_t* imgFilepath, float xPos, float yPos, float width, float height)
{
	this->srcWindow = srcWindow;
	this->bitmapImage = srcWindow->GetGraphics()->mcLoadImage(imgFilepath);
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = width;
	this->Height = height;
}

UIImage::~UIImage()
{
}

void UIImage::Draw()
{
	this->srcWindow->GetGraphics()->DrawBitmap(bitmapImage, xPos, yPos, Width, Height, imageOpacity);
}
