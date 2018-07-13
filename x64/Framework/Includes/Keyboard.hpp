#pragma once
#include <Windows.h>
#include <string>

#define MC_BACKSPACE VK_BACK
#define MC_SPACE VK_SPACE
#define MC_BACKTICK VkKeyScan('`')
#define MC_ENTER VK_RETURN
#define MC_RETURN VK_RETURN
#define MC_LSHIFT VK_LSHIFT
#define MC_RSHIFT VK_RSHIFT
#define MC_LCONTROL VK_LCONTROL
#define MC_RCONTROL VK_RCONTROL
#define MC_ALT VK_MENU
#define MC_OPTION VK_MENU
#define MC_UP VK_UP
#define MC_DOWN VK_DOWN
#define MC_RIGHT VK_RIGHT
#define MC_LEFT VK_LEFT
#define MC_F1 VK_F1
#define MC_F2 VK_F2
#define MC_F3 VK_F3
#define MC_F4 VK_F4
#define MC_F5 VK_F5
#define MC_F6 VK_F6
#define MC_F7 VK_F7
#define MC_F8 VK_F8
#define MC_F9 VK_F9
#define MC_F10 VK_F10
#define MC_F11 VK_F11
#define MC_F12 VK_F12

#define MC_KEY1 0x31
#define MC_KEY2 0x32
#define MC_KEY3 0x33
#define MC_KEY4 0x34
#define MC_KEY5 0x35
#define MC_KEY6 0x36
#define MC_KEY7 0x37
#define MC_KEY8 0x38
#define MC_KEY9 0x39
#define MC_KEY0 0x30

#define MC_MINUS VkKeyScan('-')
#define MC_EQUALS VkKeyScan('=')
#define MC_COMMA VkKeyScan(',')
#define MC_PERIOD VkKeyScan('.')
#define MC_SEMICOLON VkKeyScan(';')
#define MC_TICK VK_OEM_7

#define MC_KEY_A 0x41
#define MC_KEY_B 0x42
#define MC_KEY_C 0x43
#define MC_KEY_D 0x44
#define MC_KEY_E 0x45
#define MC_KEY_F 0x46
#define MC_KEY_G 0x47
#define MC_KEY_H 0x48
#define MC_KEY_I 0x49
#define MC_KEY_J 0x4A
#define MC_KEY_K 0x4B
#define MC_KEY_L 0x4C
#define MC_KEY_M 0x4D
#define MC_KEY_N 0x4E
#define MC_KEY_O 0x4F
#define MC_KEY_P 0x50
#define MC_KEY_Q 0x51
#define MC_KEY_R 0x52
#define MC_KEY_S 0x53
#define MC_KEY_T 0x54
#define MC_KEY_U 0x55
#define MC_KEY_V 0x56
#define MC_KEY_W 0x57
#define MC_KEY_X 0x58
#define MC_KEY_Y 0x59
#define MC_KEY_Z 0x5A

class Keyboard
{
public:
	static int GetKeyCode(char key);
	static bool IsKeyDown(int key);
	static bool IsKeyPressed(int key);

	static void SimulateKeypress(int key);
	static void SimulateKeypressSequence(std::string msg);
	static void SimulateKeypressSequence(std::wstring msg);
	static void SimulateKeypressSequence(char* msg);

	static void SimulateKeypressWithShift(int key);
	static void SimulateKeypressSequenceWithShift(std::string msg);
	static void SimulateKeypressSequenceWithShift(std::wstring msg);
	static void SimulateKeypressSequenceWithShift(char* msg);
};

