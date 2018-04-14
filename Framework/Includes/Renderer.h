#ifndef RENDERER_H
#define RENDERER_H

#include <Windows.h>
#include <d2d1.h>
#include <string>
#include <vector>

// Local Includes
#include "Graphics.h"
#include "UIElement.h"

class Renderer
{
public:
	Renderer() {}
	Renderer(Graphics* graphics);

	void Render(std::vector<UIElement*>& elements);

	float r, g, b;

	~Renderer();

private:
	Graphics * graphics;
};


#endif // !GRAPHICS_H
