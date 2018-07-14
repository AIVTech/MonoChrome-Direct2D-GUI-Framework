#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
#include <string>

class AudioPlayer
{
public:
	AudioPlayer();

	void LoadMP3File(wchar_t* filepath);
	void LoadMP3File(const wchar_t* filepath);
	void LoadMP3File(char* filepath);
	void LoadMP3File(const char* filepath);

	void LoadWAVFile(wchar_t* filepath);
	void LoadWAVFile(const wchar_t* filepath);
	void LoadWAVFile(char* filepath);
	void LoadWAVFile(const char* filepath);

	void Play();
	void Replay();
	void PlayAndWaitUntilFinished();
	void PlayerOnRepeat();

	void Pause();
	void Resume();
	void Stop();
	void Close();

	~AudioPlayer();
private:
	std::wstring mode = L"mp3";
};

