#include "UITextbox.h"
#include "UITextboxStateHandler.h"

UITextbox::UITextbox(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
	SetTextboxStateHandler();
}

UITextbox::UITextbox(UIWindow* srcWindow, std::wstring text)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	SetTextboxStateHandler();
}

UITextbox::UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	SetTextboxStateHandler();
}

UITextbox::UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = fontSize;
	SetTextboxStateHandler();
}

UITextbox::UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = fontSize;
	this->xPos = posX;
	this->yPos = posY;
	SetTextboxStateHandler();
}

UITextbox::UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY, float Width, float Height)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = fontSize;
	this->xPos = posX;
	this->yPos = posY;
	this->Width = Width;
	this->Height = Height;
	SetTextboxStateHandler();
}

UITextbox::UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY,
	float Width, float Height, Color* color)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = fontSize;
	this->xPos = posX;
	this->yPos = posY;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->normalAlpha = color->a;
	SetTextboxStateHandler();
}

UITextbox::UITextbox(UIWindow* srcWindow, std::wstring text, std::wstring fontName, float fontSize, float posX, float posY,
	float Width, float Height, Color* color, float stroke)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = fontSize;
	this->xPos = posX;
	this->yPos = posY;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->normalAlpha = color->a;
	this->Stroke = stroke;
	SetTextboxStateHandler();
}

UITextbox::~UITextbox()
{
}

void UITextbox::Draw()
{

	this->srcWindow->GetGraphics()->DrawRectangle(xPos, yPos, Width, Height, color->r, color->g, color->b, color->a, Stroke, Filled); // Actual Textbox.
	this->srcWindow->GetGraphics()->DrawRectangle(xPos - 0.2f, yPos - 0.2f, Width + 0.2f, Height + 0.2f,
		borderColor->r, borderColor->g, borderColor->b, borderColor->a, BorderStroke, false); // Bounding box.

	std::wstring txt = Text;
	if (txt.size() > textLimit)
	{
		txt.erase(txt.begin(), txt.begin()+displayStartIndex);
		if (txt.size() > textLimit)
		{
			txt.erase(txt.begin() + textLimit, txt.end());
		}
		else
		{
			txt = Text;
			int startIndex = txt.size() - textLimit;
			txt.erase(txt.begin(), txt.begin() + startIndex);
		}
	}

	DWRITE_TEXT_ALIGNMENT textAllignment;
	DWRITE_PARAGRAPH_ALIGNMENT paragraphAllignment;
	MakeTextAllignment(this->TextAllignment, textAllignment, paragraphAllignment);

	this->srcWindow->GetGraphics()->drawText(std::wstring(txt), FontName, FontSize,
		xPos + 0.2f, yPos + 0.2f, Width - 0.2f, Height - 0.2f, textColor->r, textColor->g, textColor->b, textColor->a,
		textAllignment, paragraphAllignment); // Text.
}

void UITextbox::SetTextboxStateHandler()
{
	textboxStateHandler = new UITextboxStateHandler(this);
}

void UITextbox::RemoveCharacter(int index)
{
	if (index > Text.size() - 1 || index < 0)
		return;

	this->previousText.push_back(Text);
	this->Text.erase(Text.begin() + index);
}

void UITextbox::UndoTextAction()
{
	if (previousText.size() > 1)
	{
		this->Text = previousText.at(previousText.size() - 1);
		this->previousText.erase(previousText.begin() + previousText.size() - 1);
	}
}
