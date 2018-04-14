#include "Graphics.h"


Graphics::Graphics()
{
	// Constructor
	Factory = NULL;
	RenderTarget = NULL;
}


Graphics::~Graphics()
{
	if (Factory) Factory->Release();
	if (RenderTarget) RenderTarget->Release();
}


bool Graphics::Init(HWND hWnd)
{
	this->hWnd = hWnd;
	HRESULT result = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &Factory);
	if (result != S_OK) return false;

	RECT rect;
	GetClientRect(hWnd, &rect);

	result = Factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(rect.right, rect.bottom)), &RenderTarget);

	if (result != S_OK) return false;

	return true;
}

void Graphics::ClearScreen(float r, float g, float b)
{
	RenderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a, float stroke, bool filled)
{
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	if (filled)
	{
		RenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush);
	}
	else
	{
		RenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, stroke);
	}
}

void Graphics::DrawRectangle(float x, float y, float width, float height, float r, float g, float b, float a, float stroke, bool filled)
{
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	D2D1_RECT_F rectangle = D2D1::RectF(x, y, x + width, y + height);

	if (!filled)
	{
		RenderTarget->DrawRectangle(&rectangle, brush, stroke);
	}
	else
	{
		RenderTarget->FillRectangle(&rectangle, brush);
	}
}

void Graphics::drawText(const std::wstring& text, std::wstring font, WCHAR fontSize,
	float xPos, float yPos, float width, float height, float r, float g, float b, float a)
{
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	IDWriteFactory* WriteFactory;
	HRESULT h = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), (IUnknown**)&WriteFactory);

	IDWriteTextFormat* format;
	h = WriteFactory->CreateTextFormat(font.c_str(), NULL, DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"", &format);

	// Center the text horizontally and vertically.
	format->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	format->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	RenderTarget->DrawTextW(text.c_str(), text.size(), format, D2D1::RectF(xPos, yPos, xPos + width, yPos + height), brush);
}