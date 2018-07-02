#ifndef UITEXTBOXSTATEHANDLER_H
#define UITEXTBOXSTATEHANDLER_H

#include "EventHandler.h"
#include "UIElement.h"
#include "UITextbox.h"
#include <thread>

class UITextboxStateHandler : public EventHandler
{
public:
	UITextboxStateHandler(UIElement* sender);

	void StartListener();

	~UITextboxStateHandler();
private:
	UITextbox* srcTextBox;

	void PasteFromClipboard()
	{
		OpenClipboard(NULL);
		HANDLE h = GetClipboardData(CF_TEXT);
		char* clipboardData = (char*)h;
		std::string s(clipboardData);
		std::wstring w(&s[0], &s[s.size()]);
		srcTextBox->AddText(w);
	}
	float CalculateVisibleTextLimit(int fontSize);

	/*																	
	
						LISTEN PLEASE 

		I REALLY HAVE NO IDEA WHY I HARD CODED ALL THIS STUFF
		I DIDN'T WANT TO, BUT I WAS FORCED TO BECAUSE I COULDN'T
		FIND A BETTER WAY, BUT THIS SHIT WORKS SOMEHOW.

		I ABSOLUTELY HAVE NO FREAKING IDEA ABOUT HOW I GOT 
		TO THIS POINT BUT APPARENTLY IT WORKS SOMEHOW, SO PLEASE 
		JUST LET IT BE.

		IF YOU HAVE A SOLUTION TO HOW TO CALCULATE THE GODDAM
		VISIBLE CHARACTER LIMIT SO THAT THERE IS ONLY
		ONE LINE IN THE TEXTBOX, PLEASE SEND ME AN EMAIL
		OR CONTACT ME BECAUSE I WOULD LOVE TO FIND AN EASIER
		WAY TO CALCULATE THIS SHIT.

	*/
};

#endif // !UITEXTBOXSTATEHANDLER_H