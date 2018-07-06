#include "UIFileChooser.h"

UIFileChooser::UIFileChooser()
{
}

UIFileChooser::~UIFileChooser()
{
}

bool UIFileChooser::OpenFileDialogue()
{
	OPENFILENAMEA ofn;
	char file[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFilter = this->filter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFile = file;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

	std::string filepath = " ";
	if (GetOpenFileNameA(&ofn))
	{
		filepath = file;
		this->filepath = filepath;
	}
	
	if (filepath._Equal(" "))
		return false;

	return true;
}

bool UIFileChooser::SaveFileDialogue()
{
	OPENFILENAMEA ofn;
	char file[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFilter = this->filter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFile = file;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

	std::string filepath = " ";
	if (GetSaveFileNameA(&ofn))
	{
		filepath = file;
		this->filepath = filepath;
	}

	if (filepath._Equal(" "))
		return false;

	return true;
}

void UIFileChooser::SetFilter(const char* filter)
{
	this->filter = filter;
}

std::string UIFileChooser::GetFileName()
{
	std::string result = "";
	for (int i = (int)filepath.size() - 1; i >= 0; i--)
	{
		if (filepath.at(i) == '\\')
			return result;
		result = filepath.at(i) + result;
	}
	return result;
}

std::string UIFileChooser::GetFileExtension()
{
	std::string result = "";
	for (int i = (int)filepath.size() - 1; i >= 0; i--)
	{
		if (filepath.at(i) == '.')
			return result;
		result = filepath.at(i) + result;
	}
	return result;
}
