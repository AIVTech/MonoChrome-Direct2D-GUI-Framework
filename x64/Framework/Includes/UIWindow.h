#ifndef UIWINDOW_H
#define UIWINDOW_H

#include "Graphics.h"
#include <Windows.h>
#include <vector>
#include <string>

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

	uint8_t r = 120, g = 120, b = 120;

	HWND GetHWND() { return this->hWnd; }
	Graphics* GetGraphics() { return this->graphics; }
	std::vector<UIElement*> elements;

	~UIWindow();
private:
	HWND hWnd;
	Graphics* graphics;
};

#endif // !UIWINDOW_H