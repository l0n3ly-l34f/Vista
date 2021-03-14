#include "Vista/Audio/AudioPlayer.hpp"

#include "Vista/Resource/Sound.hpp"
#include "Vista/Resource/Music.hpp"

#include "raylib.h"

struct Vista::AudioPlayer::Implementation final
{
	::Music music;
};

Vista::AudioPlayer::Implementation Vista::AudioPlayer::implementation;

void Vista::AudioPlayer::Update()
{
	::UpdateMusicStream(Vista::AudioPlayer::implementation.music);
}

void Vista::AudioPlayer::Play(Vista::Sound& sound)
{
	::PlaySound(*((::Sound*)(sound.GetData())));
}

void Vista::AudioPlayer::Stop(Vista::Sound& sound)
{
	::StopSound(*((::Sound*)(sound.GetData())));
}

void Vista::AudioPlayer::Pause(Vista::Sound& sound)
{
	::PauseSound(*((::Sound*)(sound.GetData())));
}

void Vista::AudioPlayer::Resume(Vista::Sound& sound)
{
	::ResumeSound(*((::Sound*)(sound.GetData())));
}

void Vista::AudioPlayer::Play(Vista::Music& music)
{
	Vista::AudioPlayer::implementation.music = *((::Music*)(music.GetData()));
	::PlayMusicStream(Vista::AudioPlayer::implementation.music);
}

void Vista::AudioPlayer::Stop(Vista::Music& music)
{
	Vista::AudioPlayer::implementation.music = *((::Music*)(music.GetData()));
	::StopMusicStream(Vista::AudioPlayer::implementation.music);
}

void Vista::AudioPlayer::Pause(Vista::Music& music)
{
	Vista::AudioPlayer::implementation.music = *((::Music*)(music.GetData()));
	::PauseMusicStream(Vista::AudioPlayer::implementation.music);
}

void Vista::AudioPlayer::Resume(Vista::Music& music)
{
	Vista::AudioPlayer::implementation.music = *((::Music*)(music.GetData()));
	::ResumeMusicStream(Vista::AudioPlayer::implementation.music);
}