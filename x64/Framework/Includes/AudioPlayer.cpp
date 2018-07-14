#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
{
}

AudioPlayer::~AudioPlayer()
{
}

void AudioPlayer::LoadMP3File(wchar_t* filepath)
{
	std::wstring cmd = L"open \"" + std::wstring(filepath) + std::wstring(L"\" type mpegvideo alias mp3");
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"mp3";
}

void AudioPlayer::LoadMP3File(const wchar_t* filepath)
{
	std::wstring cmd = L"open \"" + std::wstring(filepath) + std::wstring(L"\" type mpegvideo alias mp3");
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"mp3";
}

void AudioPlayer::LoadMP3File(char* filepath)
{
	std::string cmdString = "open \"" + std::string(filepath) + std::string("\" type mpegvideo alias mp3");
	std::wstring cmd(cmdString.begin(), cmdString.end());
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"mp3";
}

void AudioPlayer::LoadMP3File(const char* filepath)
{
	std::string cmdString = "open \"" + std::string(filepath) + std::string("\" type mpegvideo alias mp3");
	std::wstring cmd(cmdString.begin(), cmdString.end());
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"mp3";
}

void AudioPlayer::LoadWAVFile(wchar_t* filepath)
{
	std::wstring cmd = L"open \"" + std::wstring(filepath) + std::wstring(L"\" type waveaudio alias wav");
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"wav";
}

void AudioPlayer::LoadWAVFile(const wchar_t* filepath)
{
	std::wstring cmd = L"open \"" + std::wstring(filepath) + std::wstring(L"\" type waveaudio alias wav");
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"wav";
}

void AudioPlayer::LoadWAVFile(char* filepath)
{
	std::string cmdString = "open \"" + std::string(filepath) + std::string("\" type waveaudio alias wav");
	std::wstring cmd(cmdString.begin(), cmdString.end());
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"wav";
}

void AudioPlayer::LoadWAVFile(const char* filepath)
{
	std::string cmdString = "open \"" + std::string(filepath) + std::string("\" type waveaudio alias wav");
	std::wstring cmd(cmdString.begin(), cmdString.end());
	mciSendString(cmd.c_str(), NULL, 0, NULL);
	mode = L"wav";
}

void AudioPlayer::Play()
{
	std::wstring cmd = L"play " + mode;
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void AudioPlayer::Replay()
{
	std::wstring cmd = L"play " + mode + L" from 0";
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void AudioPlayer::PlayAndWaitUntilFinished()
{
	std::wstring cmd = L"play " + mode + L" from 0 wait";
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void AudioPlayer::PlayerOnRepeat()
{
	std::wstring cmd = L"play " + mode + L" repeat";
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void AudioPlayer::Pause()
{
	std::wstring cmd = L"pause " + mode;
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void AudioPlayer::Resume()
{
	std::wstring cmd = L"resume " + mode;
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void AudioPlayer::Stop()
{
	std::wstring cmd = L"stop " + mode;
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}

void AudioPlayer::Close()
{
	std::wstring cmd = L"close " + mode;
	mciSendString(cmd.c_str(), NULL, 0, NULL);
}
