#include "Renderer.h"

Renderer::Renderer(Graphics* graphics)
{
	this->graphics = graphics;
	r = 0.75f;
	g = 0.75f;
	b = 0.75f;
}

Renderer::~Renderer()
{
}

void Renderer::Render(std::vector<UIElement*>& elements)
{
	graphics->BeginDraw();
	//graphics->ClearScreen(0.079f, 0.091f, 0.10f);
	graphics->ClearScreen(r, g, b);

	// UI Elements
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements.at(i)->GetVisible())
		{
			elements.at(i)->Draw();
		}
	}

	graphics->EndDraw();
}