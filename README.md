// Include Libraries:
// d2d1.lib, dwrite.lib, MonochromeFramework.lib
//
// Include <Framework.h> to use the library
//

To create a window loop, use win32 api GetMessage(&msg) and DispatchMessage(&msg) calls along with window.update() 
after creating the UIWindow, doing window.mcCreateWindow(), and doing window.Show();

// Example:

```
UIWindow* window = new UIWindow();
window->mcCreateWindow(800, 500, L"Demo Window");
window->Show();

MSG msg;
while (GetMessage(&msg, 0, 0, 0))
{
	DispatchMessage(&msg);
	window->Update();
}
```
