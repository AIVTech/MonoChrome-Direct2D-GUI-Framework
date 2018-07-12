#ifndef UIWINDOW_H
#define UIWINDOW_H

#include "Graphics.h"
#include <Windows.h>
#include <vector>
#include <string>
#include "Color.h"

class UIElement;

class UIWindow
{
public:
	UIWindow();

	void mcCreateWindow(const int width, const int height, LPCWSTR windowName);
	void Show();
	void Hide();
	void Dispose();
	void Update();
	bool IsOpened();

	uint8_t r = 120, g = 120, b = 120;

	HWND GetHWND() { return this->hWnd; }
	Graphics* GetGraphics() { return this->graphics; }

	void Add(UIElement* element);
	void Remove(UIElement* element);

	int GetWidth() { return this->width; }
	int GetHeight() { return this->height; }

	void SetResizable(bool state) { this->resizable = state; }
	void SetBackgroundColor(Color* color) { this->r = color->r; this->g = color->g; this->b = color->b; }

	~UIWindow();
private:
	HWND hWnd;
	Graphics* graphics;
	bool resizable = true;
	int width = 0, height = 0;
	std::vector<UIElement*> elements;
	MSG msg;
};

#endif // !UIWINDOW_H