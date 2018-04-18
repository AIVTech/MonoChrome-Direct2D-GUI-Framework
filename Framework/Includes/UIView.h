#ifndef UIVIEW_H
#define UIVIEW_H

#include <d2d1.h>
#include "Graphics.h"
#include "UIElement.h"
#include "UILabel.h"
#include "UIButton.h"
#include "UICheckbox.h"
#include "UISlider.h"

#include <vector>

class UIView
{
public:
	UIView() {}
	UIView(Graphics* graphics);
	virtual ~UIView();

	bool LoadComponents();

	std::vector<UIElement*> UIElements;

	float r = 0.6, g = 0.6, b = 0.6;

private:
	Graphics* graphics;
	UICheckbox* checkboxx;
	UICheckbox* testCbx;
};

#endif // !UIVIEW_H