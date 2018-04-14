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
	void drawText(const std::wstring& text, std::wstring font, WCHAR fontSize,
		float xPos, float yPos, float width, float height, float r, float g, float b, float a);

	~Graphics();

private:
	ID2D1Factory * Factory;
	ID2D1HwndRenderTarget* RenderTarget;
	HWND hWnd;

};


#endif // !GRAPHICS_H