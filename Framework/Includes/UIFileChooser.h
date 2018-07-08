#ifndef UIFILECHOOSER_H
#define UIFILECHOOSER_H

#include "UIElement.h"

class UIFileChooser
{
public:
	UIFileChooser();

	bool OpenFileDialogue();
	bool SaveFileDialogue();

	void SetFilter(const char* filter);

	std::string GetFullFilepath() { return this->filepath; }
	std::string GetFileName();
	std::string GetFileExtension();

	~UIFileChooser();

private:
	const char* filter = "All Files\0*.*\0";
	std::string filepath = "";
};

#endif // !UIFILECHOOSER_H