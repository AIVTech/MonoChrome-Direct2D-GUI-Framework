#include "UIView.h"


UIView::UIView(Graphics* graphics)
{
	this->graphics = graphics;
	this->r = 0.35;
	this->g = 0.35;
	this->b = 0.35;
	LoadComponents();
}

UIView::~UIView()
{

}

bool UIView::LoadComponents()
{
	return true;
}
