#ifndef GRAPHICS_H
#define GRAPHICS_H

#define CLAMP(value, min, max) (((value) > (max)) ? (max) : (((value) < (min)) ? (min) : (value)))

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

	void ClearScreen(uint8_t r, uint8_t g, uint8_t b);
	void DrawCircle(float x, float y, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke, bool filled);
	void DrawRectangle(float x, float y, float width, float height, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke, bool filled);

	void DrawRoundedRectangle(float x, float y, float width, float height, 
		float radiusX, float radiusY, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke, bool filled);

	void drawText(const std::wstring& text, std::wstring font, WCHAR fontSize,
		float xPos, float yPos, float width, float height, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void DrawArc(float startX, float startY, float endX, float endY, float size, 
		D2D1_SWEEP_DIRECTION direction, D2D1_ARC_SIZE arcSize, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke);

	~Graphics();

private:
	ID2D1Factory* Factory;
	ID2D1HwndRenderTarget* RenderTarget;
	HWND hWnd;

	float ConvertUI8ToFloat(uint8_t value)
	{
		float f;
		f = CLAMP(((float)((value&0x0000ff))) / 255.0f, 0.0f, 1.0f);
		return f;
	}

};


#endif // !GRAPHICS_H