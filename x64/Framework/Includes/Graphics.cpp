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

	RenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
	RenderTarget->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE);

	return true;
}

void Graphics::ClearScreen(uint8_t r, uint8_t g, uint8_t b)
{
	float red = ConvertUI8ToFloat(r);
	float green = ConvertUI8ToFloat(g);
	float blue = ConvertUI8ToFloat(b);
	RenderTarget->Clear(D2D1::ColorF(red, green, blue));
}

void Graphics::DrawCircle(float x, float y, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke, bool filled)
{
	float red = ConvertUI8ToFloat(r);
	float green = ConvertUI8ToFloat(g);
	float blue = ConvertUI8ToFloat(b);
	float alpha = ConvertUI8ToFloat(a);
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(red, green, blue, alpha), &brush);

	if (filled)
	{
		RenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush);
	}
	else
	{
		RenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, stroke);
	}
}

void Graphics::DrawRectangle(float x, float y, float width, float height, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke, bool filled)
{
	float red = ConvertUI8ToFloat(r);
	float green = ConvertUI8ToFloat(g);
	float blue = ConvertUI8ToFloat(b);
	float alpha = ConvertUI8ToFloat(a);
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(red, green, blue, alpha), &brush);

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

void Graphics::DrawRoundedRectangle(float x, float y, float width, float height, 
	float radiusX, float radiusY, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke, bool filled)
{
	float red = ConvertUI8ToFloat(r);
	float green = ConvertUI8ToFloat(g);
	float blue = ConvertUI8ToFloat(b);
	float alpha = ConvertUI8ToFloat(a);
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(red, green, blue, alpha), &brush);

	D2D1_RECT_F rectangle = D2D1::RectF(x, y, x + width, y + height);
	D2D1_ROUNDED_RECT roundedRectangle = D2D1::RoundedRect(rectangle, radiusX, radiusY);

	if (!filled)
	{
		RenderTarget->DrawRoundedRectangle(&roundedRectangle, brush, stroke);
	}
	else
	{
		RenderTarget->FillRoundedRectangle(&roundedRectangle, brush);
	}
}

void Graphics::drawText(const std::wstring& text, std::wstring font, WCHAR fontSize, 
	float xPos, float yPos, float width, float height, uint8_t r, uint8_t g, uint8_t b, uint8_t a, 
	DWRITE_TEXT_ALIGNMENT textAllignment, DWRITE_PARAGRAPH_ALIGNMENT paragraphAllignment)
{
	float red = ConvertUI8ToFloat(r);
	float green = ConvertUI8ToFloat(g);
	float blue = ConvertUI8ToFloat(b);
	float alpha = ConvertUI8ToFloat(a);
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(red, green, blue, alpha), &brush);

	IDWriteFactory* WriteFactory;
	HRESULT h = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), (IUnknown**)&WriteFactory);

	IDWriteTextFormat* format;
	h = WriteFactory->CreateTextFormat(font.c_str(), NULL, DWRITE_FONT_WEIGHT_NORMAL, 
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"", &format);

	// Center the text horizontally and vertically.
	format->SetTextAlignment(textAllignment);
	format->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	RenderTarget->DrawTextW(text.c_str(), text.size(), format, D2D1::RectF(xPos, yPos, xPos+width, yPos+height), brush);
}


void Graphics::DrawArc(float startX, float startY, float endX, float endY, float size, 
	D2D1_SWEEP_DIRECTION direction, D2D1_ARC_SIZE arcSize, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float stroke)
{
	float red = ConvertUI8ToFloat(r);
	float green = ConvertUI8ToFloat(g);
	float blue = ConvertUI8ToFloat(b);
	float alpha = ConvertUI8ToFloat(a);
	ID2D1SolidColorBrush* brush;
	RenderTarget->CreateSolidColorBrush(D2D1::ColorF(red, green, blue, alpha), &brush);
	ID2D1PathGeometry* path;
	D2D1_POINT_2F begin;
	begin.x = startX;
	begin.y = startY;
	D2D1_POINT_2F end;
	end.x = endX;
	end.y = endY;

	D2D1_ARC_SEGMENT arc = {
		end,
		{ size, size },
		0.0f,
		direction,
		arcSize
	};

	Factory->CreatePathGeometry(&path);
	ID2D1GeometrySink* sink;
	path->Open(&sink);

	sink->BeginFigure(begin, D2D1_FIGURE_BEGIN_FILLED);
	sink->AddArc(arc);
	sink->EndFigure(D2D1_FIGURE_END_OPEN);
	sink->Close();

	RenderTarget->DrawGeometry(path, brush, stroke);
	
}

void Graphics::ResizeRenderTarget(int width, int height)
{
	this->RenderTarget->Resize(&D2D1::SizeU(width, height));
}

ID2D1Bitmap* Graphics::mcLoadImage(const wchar_t* filepath)
{
	HRESULT hr;
	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&wicFactory);
	if (hr != S_OK)
	{
		return NULL;
	}
	
	IWICBitmapDecoder* wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(filepath, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &wicDecoder);
	if (hr != S_OK)
	{
		return NULL;
	}

	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame); // taking first frame for a static image
	if (hr != S_OK)
	{
		return NULL;
	}

	// create converter
	IWICFormatConverter* wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);
	if (hr != S_OK)
	{
		return NULL;
	}

	// setup the converter
	hr = wicConverter->Initialize(
		wicFrame, 
		GUID_WICPixelFormat32bppPBGRA, 
		WICBitmapDitherTypeNone, 
		NULL, 
		0.0,	// alpha transparency percentage
		WICBitmapPaletteTypeCustom);
	if (hr != S_OK)
	{
		return NULL;
	}

	// creating D2D1 Bitmap
	ID2D1Bitmap* bmp;
	RenderTarget->CreateBitmapFromWicBitmap(wicConverter, NULL, &bmp);

	// releasing resources
	if (wicFactory) wicFactory->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicConverter) wicConverter->Release();
	if (wicFrame) wicFrame->Release();

	return bmp;
}

void Graphics::DrawBitmap(ID2D1Bitmap* bmp, float xPos, float yPos, float width, float height, float opacity)
{
	RenderTarget->DrawBitmap(
		bmp,	// bitmap
		//D2D1::RectF(xPos, yPos, bmp->GetSize().width, bmp->GetSize().height), // destination rectangle
		D2D1::RectF(xPos, yPos, xPos + width, yPos + height), // destination rectangle
		opacity,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		//D2D1::RectF(xPos, yPos, bmp->GetSize().width, bmp->GetSize().height) // source rectangle
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height) // source rectangle
	);
}
