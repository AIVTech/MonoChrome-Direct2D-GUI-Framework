#include "Keyboard.hpp"

int Keyboard::GetKeyCode(char key)
{
	return VkKeyScan(key);
}

bool Keyboard::IsKeyDown(int key)
{
	return GetAsyncKeyState(key) & 0x8000;
}

bool Keyboard::IsKeyPressed(int key)
{
	return GetAsyncKeyState(key) & 1;
}

void Keyboard::SimulateKeypress(int key)
{
	INPUT input;

	// Set up a generic keyboard event.
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = 0; // hardware scan code for key
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	input.ki.wVk = key;
	input.ki.dwFlags = 0;

	// Send key PRESS
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;

	// Send key RELEASE
	SendInput(1, &input, sizeof(INPUT));
}

void Keyboard::SimulateKeypressSequence(std::string msg)
{
	for (char c : msg)
	{
		SimulateKeypress(Keyboard::GetKeyCode(c));
	}
}

void Keyboard::SimulateKeypressSequence(std::wstring msg)
{
	for (char c : msg)
	{
		SimulateKeypress(Keyboard::GetKeyCode(c));
	}
}

void Keyboard::SimulateKeypressSequence(char* msg)
{
	for (int i = 0; i < strlen(msg); i++)
	{
		SimulateKeypress(Keyboard::GetKeyCode(msg[i]));
	}
}

void Keyboard::SimulateKeypressWithShift(int key)
{
	INPUT keyInput;

	// Set up a generic keyboard event.
	keyInput.type = INPUT_KEYBOARD;
	keyInput.ki.wScan = 0; // hardware scan code for key
	keyInput.ki.time = 0;
	keyInput.ki.dwExtraInfo = 0;

	keyInput.ki.wVk = MC_LSHIFT;
	keyInput.ki.dwFlags = 0;

	SendInput(1, &keyInput, sizeof(INPUT));	// shift down
	keyInput.ki.wVk = key;
	SendInput(1, &keyInput, sizeof(INPUT));	// key down

	keyInput.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &keyInput, sizeof(INPUT));	// key up
	keyInput.ki.wVk = MC_LSHIFT;
	SendInput(1, &keyInput, sizeof(INPUT));	// shift up
}

void Keyboard::SimulateKeypressSequenceWithShift(std::string msg)
{
	for (char c : msg)
	{
		SimulateKeypressWithShift(Keyboard::GetKeyCode(c));
	}
}

void Keyboard::SimulateKeypressSequenceWithShift(std::wstring msg)
{
	for (char c : msg)
	{
		SimulateKeypressWithShift(Keyboard::GetKeyCode(c));
	}
}

void Keyboard::SimulateKeypressSequenceWithShift(char* msg)
{
	for (int i = 0; i < strlen(msg); i++)
	{
		SimulateKeypressWithShift(Keyboard::GetKeyCode(msg[i]));
	}
}
