#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>
#include <string>

class Graphics
{
public:
	Graphics();

	bool Init(HWND hWnd);
	void BeginDraw() { RenderTarget->BeginDraw(); }
	void EndDraw() { RenderTarget->EndDraw(); }

	HWND GetHWND() { return hWnd; }

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a, float stroke, bool filled);
	void DrawRectangle(float x, float y, float width, float height, float r, float g, float b, float a, float stroke, bool filled);

	void DrawRoundedRectangle(float x, float y, float width, float height, 
		float radiusX, float radiusY, float r, float g, float b, float a, float stroke, bool filled);

	void drawText(const std::wstring& text, std::wstring font, WCHAR fontSize,
		float xPos, float yPos, float width, float height, float r, float g, float b, float a);

	void DrawArc(float startX, float startY, float endX, float endY, float size, 
		D2D1_SWEEP_DIRECTION direction, D2D1_ARC_SIZE arcSize, float r, float g, float b, float a, float stroke);

	~Graphics();

private:
	ID2D1Factory* Factory;
	ID2D1HwndRenderTarget* RenderTarget;
	HWND hWnd;

};


#endif // !GRAPHICS_H