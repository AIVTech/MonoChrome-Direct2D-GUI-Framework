#include "UITextboxStateHandler.h"

UITextboxStateHandler::UITextboxStateHandler(UIElement* sender)
{
	this->srcTextBox = static_cast<UITextbox*>(sender);
	std::thread running_thread(&UITextboxStateHandler::StartListener, this);
	running_thread.detach();
}

UITextboxStateHandler::~UITextboxStateHandler()
{

}

void UITextboxStateHandler::StartListener()
{
	//*****************************************//
	//
	// Keyboard Events have to be controlled 
	// manually due to checking for upper/lower 
	// case and shift or caps lock state
	//
	/******************************************/
	bool mousePressed = false;
	bool ctrlPressed = false;
	std::wstring oldText = srcTextBox->GetText();
	while (true)
	{
		float lim = CalculateVisibleTextLimit((int)srcTextBox->GetFontSize());
		srcTextBox->SetVisibleTextLimit((int)lim);
		Sleep(4);
		if (srcTextBox->GetVisible() && srcTextBox->GetEnabled())
		{

			bool textChanged = false;
			// Text Handling
			std::wstring currentText = srcTextBox->GetText();
			if (!currentText._Equal(oldText))
			{
				textChanged = true;
				oldText = currentText;
			}
			if (srcTextBox->GetText().size() > srcTextBox->GetVisibleTextLimit())
			{
				if (GetAsyncKeyState(VK_RIGHT) & 1)
				{
					srcTextBox->IncrementDisplayStartIndex();
				}
				else if (GetAsyncKeyState(VK_LEFT) & 1)
				{
					srcTextBox->DecrementDisplayStartIndex();
				}
				else
				{
					if (textChanged)
					{
						srcTextBox->IncrementDisplayStartIndex();
					}
				}
			}

			


			// Mouse Input
			if (GetAsyncKeyState(VK_LBUTTON) == 0)
				mousePressed = false;

			if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousePressed)
			{
				mousePressed = true;

				// Left Click Action
				POINT pos;
				GetCursorPos(&pos);
				ScreenToClient(srcTextBox->GetSourceWindow()->GetHWND(), &pos);

				if (pos.x < srcTextBox->GetPosX() + srcTextBox->GetWidth() && pos.x > srcTextBox->GetPosX() &&
					pos.y < srcTextBox->GetPosY() + srcTextBox->GetHeight() && pos.y > srcTextBox->GetPosY())
				{
					srcTextBox->SetFocused(true);
				}
				else
				{
					srcTextBox->SetFocused(false);
				}
			}

			// Keyboard Input
			if (srcTextBox->GetFocused())
			{
				// Delete / Backspace
				if (GetAsyncKeyState(VK_BACK) & 1)
				{
					srcTextBox->RemoveCharacter(srcTextBox->GetText().size()-1);
				}
				// Space
				if (GetAsyncKeyState(VK_SPACE) & 1)
				{
					srcTextBox->AddText(L" ");
				}

				// Key: 1
				if (GetAsyncKeyState(0x31) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"!");
					}
					else
					{
						srcTextBox->AddText(L"1");
					}
				}
				// Key: 2
				if (GetAsyncKeyState(0x32) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"@");
					}
					else
					{
						srcTextBox->AddText(L"2");
					}
				}
				// Key: 3
				if (GetAsyncKeyState(0x33) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"#");
					}
					else
					{
						srcTextBox->AddText(L"3");
					}
				}
				// Key: 4
				if (GetAsyncKeyState(0x34) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"$");
					}
					else
					{
						srcTextBox->AddText(L"4");
					}
				}
				// Key: 5
				if (GetAsyncKeyState(0x35) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"%");
					}
					else
					{
						srcTextBox->AddText(L"5");
					}
				}
				// Key: 6
				if (GetAsyncKeyState(0x36) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"^");
					}
					else
					{
						srcTextBox->AddText(L"6");
					}
				}
				// Key: 7
				if (GetAsyncKeyState(0x37) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"&");
					}
					else
					{
						srcTextBox->AddText(L"7");
					}
				}
				// Key: 8
				if (GetAsyncKeyState(0x38) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"*");
					}
					else
					{
						srcTextBox->AddText(L"8");
					}
				}
				// Key: 9
				if (GetAsyncKeyState(0x39) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"(");
					}
					else
					{
						srcTextBox->AddText(L"9");
					}
				}
				// Key: 0
				if (GetAsyncKeyState(0x30) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L")");
					}
					else
					{
						srcTextBox->AddText(L"0");
					}
				}

				// Letter A
				if (GetAsyncKeyState(0x41) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"A");
					}
					else
					{
						srcTextBox->AddText(L"a");
					}
				}
				// Letter B
				if (GetAsyncKeyState(0x42) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"B");
					}
					else
					{
						srcTextBox->AddText(L"b");
					}
				}
				// Letter C
				if (GetAsyncKeyState(0x43) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"C");
					}
					else
					{
						srcTextBox->AddText(L"c");
					}
				}
				// Letter D
				if (GetAsyncKeyState(0x44) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"D");
					}
					else
					{
						srcTextBox->AddText(L"d");
					}
				}
				// Letter E
				if (GetAsyncKeyState(0x45) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"E");
					}
					else
					{
						srcTextBox->AddText(L"e");
					}
				}
				// Letter F
				if (GetAsyncKeyState(0x46) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"F");
					}
					else
					{
						srcTextBox->AddText(L"f");
					}
				}
				// Letter G
				if (GetAsyncKeyState(0x47) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"G");
					}
					else
					{
						srcTextBox->AddText(L"g");
					}
				}
				// Letter H
				if (GetAsyncKeyState(0x48) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"H");
					}
					else
					{
						srcTextBox->AddText(L"h");
					}
				}
				// Letter I
				if (GetAsyncKeyState(0x49) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"I");
					}
					else
					{
						srcTextBox->AddText(L"i");
					}
				}
				// Letter J
				if (GetAsyncKeyState(0x4A) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"J");
					}
					else
					{
						srcTextBox->AddText(L"j");
					}
				}
				// Letter K
				if (GetAsyncKeyState(0x4B) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"K");
					}
					else
					{
						srcTextBox->AddText(L"k");
					}
				}
				// Letter L
				if (GetAsyncKeyState(0x4C) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"L");
					}
					else
					{
						srcTextBox->AddText(L"l");
					}
				}
				// Letter M
				if (GetAsyncKeyState(0x4D) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"M");
					}
					else
					{
						srcTextBox->AddText(L"m");
					}
				}
				// Letter N
				if (GetAsyncKeyState(0x4E) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"N");
					}
					else
					{
						srcTextBox->AddText(L"n");
					}
				}
				// Letter O
				if (GetAsyncKeyState(0x4F) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"O");
					}
					else
					{
						srcTextBox->AddText(L"o");
					}
				}
				// Letter P
				if (GetAsyncKeyState(0x50) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"P");
					}
					else
					{
						srcTextBox->AddText(L"p");
					}
				}
				// Letter Q
				if (GetAsyncKeyState(0x51) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"Q");
					}
					else
					{
						srcTextBox->AddText(L"q");
					}
				}
				// Letter R
				if (GetAsyncKeyState(0x52) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"R");
					}
					else
					{
						srcTextBox->AddText(L"r");
					}
				}
				// Letter S
				if (GetAsyncKeyState(0x53) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"S");
					}
					else
					{
						srcTextBox->AddText(L"s");
					}
				}
				// Letter T
				if (GetAsyncKeyState(0x54) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"T");
					}
					else
					{
						srcTextBox->AddText(L"t");
					}
				}
				// Letter U
				if (GetAsyncKeyState(0x55) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"U");
					}
					else
					{
						srcTextBox->AddText(L"u");
					}
				}
				// Letter V
				if (GetAsyncKeyState(0x56) & 1)
				{
					if (ctrlPressed) // Paste from Clipboard
					{
						PasteFromClipboard();
						continue;
					}
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"V");
					}
					else
					{
						srcTextBox->AddText(L"v");
					}
				}
				// Letter W
				if (GetAsyncKeyState(0x57) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"W");
					}
					else
					{
						srcTextBox->AddText(L"w");
					}
				}
				// Letter X
				if (GetAsyncKeyState(0x58) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"X");
					}
					else
					{
						srcTextBox->AddText(L"x");
					}
				}
				// Letter Y
				if (GetAsyncKeyState(0x59) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"Y");
					}
					else
					{
						srcTextBox->AddText(L"y");
					}
				}
				// Letter Z
				if (GetAsyncKeyState(0x5A) & 1)
				{
					if (ctrlPressed) // Undo action
					{
						srcTextBox->UndoTextAction();
						continue;
					}
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || (GetKeyState(0x14)) != 0)
					{
						srcTextBox->AddText(L"Z");
					}
					else
					{
						srcTextBox->AddText(L"z");
					}
				}

				// Key: ` (~)
				if (GetAsyncKeyState(VkKeyScan('`')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"~");
					}
					else
					{
						srcTextBox->AddText(L"`");
					}
				}
				// Key: , (<)
				if (GetAsyncKeyState(VK_OEM_COMMA) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"<");
					}
					else
					{
						srcTextBox->AddText(L",");
					}
				}
				// Key: . (>)
				if (GetAsyncKeyState(VK_OEM_PERIOD) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L">");
					}
					else
					{
						srcTextBox->AddText(L".");
					}
				}
				// Key: / (?)
				if (GetAsyncKeyState(VkKeyScan('/')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"?");
					}
					else
					{
						srcTextBox->AddText(L"/");
					}
				}
				// Key: ; (:)
				if (GetAsyncKeyState(VkKeyScan(';')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L":");
					}
					else
					{
						srcTextBox->AddText(L";");
					}
				}
				// Key: ' (")
				if (GetAsyncKeyState(VK_OEM_7) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"\"");
					}
					else
					{
						srcTextBox->AddText(L"'");
					}
				}
				// Key: [ ({)
				if (GetAsyncKeyState(VkKeyScan('[')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"{");
					}
					else
					{
						srcTextBox->AddText(L"[");
					}
				}
				// Key: ] (})
				if (GetAsyncKeyState(VkKeyScan(']')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"}");
					}
					else
					{
						srcTextBox->AddText(L"]");
					}
				}
				// Key: \ (|)
				if (GetAsyncKeyState(VkKeyScan('\\')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"|");
					}
					else
					{
						srcTextBox->AddText(L"\\");
					}
				}
				// Key: - (_)
				if (GetAsyncKeyState(VkKeyScan('-')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"_");
					}
					else
					{
						srcTextBox->AddText(L"-");
					}
				}
				// Key: = (+)
				if (GetAsyncKeyState(VkKeyScan('=')) & 1)
				{
					// Check for upper/lower case
					if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
					{
						srcTextBox->AddText(L"+");
					}
					else
					{
						srcTextBox->AddText(L"=");
					}
				}
				// Key: TAB
				if (GetAsyncKeyState(VK_TAB) & 1)
				{
					// Check for upper/lower case
					srcTextBox->AddText(L"    ");
				}

				// Combination of CONTROL + KEY				
				if (GetAsyncKeyState(VK_CONTROL) & 1)
					ctrlPressed = true;

				if (GetAsyncKeyState(VK_CONTROL) == 0)
					ctrlPressed = false;
				
			}
		}
	}
}

float UITextboxStateHandler::CalculateVisibleTextLimit(int fontSize)  // NEEDS WORK ASAP OR ELSE TEXTBOX IS GONNA BE BROKEN!!!a
{
	float width = srcTextBox->GetWidth();
	float cw = 1.0f; // Width of 1 character
	switch (fontSize)
	{
	case 8:
		cw = 11.0f;
		break;
	case 9:
		cw = 12.0f;
		break;
	case 10:
		cw = 13.0f;
		break;
	case 11:
		cw = 15.0f;
		break;
	case 12:
		cw = 16.0f;
		break;
	case 13:
		cw = 17.0f;
		break;
	case 14:
		cw = 19.0f;
		break;
	case 15:
		cw = 21.0f;
		break;
	case 16:
		cw = 22.0f;
		break;
	case 17:
		cw = 23.0f;
		break;
	case 18:
		cw = 24.0f;
		break;
	case 19:
		cw = 25.0f;
		break;
	case 20:
		cw = 26.0f;
		break;
	case 21:
		cw = 26.0f;
		break;
	case 22:
		cw = 29.0f;
		break;
	case 23:
		cw = 31.0f;
		break;
	case 24:
		cw = 32.0f;
		break;
	case 25:
		cw = 26.0f;
		break;
	case 26:
		cw = 36.0f;
		break;
	case 27:
		cw = 36.0f;
		break;
	case 28:
		cw = 37.0f;
		break;
	case 29:
		cw = 38.0f;
		break;
	case 30:
		cw = 40.0f;
		break;
	case 31:
		cw = 41.0f;
		break;
	case 32:
		cw = 42.0f;
		break;
	case 33:
		cw = 44.0f;
		break;
	case 34:
		cw = 45.0f;
		break;
	case 35:
		cw = 47.0f;
		break;
	case 36:
		cw = 48.0f;
		break;
	case 37:
		cw = 49.0f;
		break;
	case 38:
		cw = 50.0f;
		break;
	case 39:
		cw = 51.0f;
		break;
	case 40:
		cw = 52.0f;
		break;
	default:
		cw = 100.0f;
		break;
	}
	
	int result = (int)((width / cw) - 1);
	return (float)(result*3-2);
}
