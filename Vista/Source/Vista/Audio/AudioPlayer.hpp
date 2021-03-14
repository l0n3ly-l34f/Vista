#pragma once

namespace Vista
{
	class Sound;
	class Music;
	class AudioPlayer final
	{
	private:
		struct Implementation;
	private:
		static Vista::AudioPlayer::Implementation implementation;
	public:
		AudioPlayer() = delete;
		virtual ~AudioPlayer() = delete;
		static void Update();
		static void Play(Vista::Sound& sound);
		static void Stop(Vista::Sound& sound);
		static void Pause(Vista::Sound& sound);
		static void Resume(Vista::Sound& sound);
		static void Play(Vista::Music& music);
		static void Stop(Vista::Music& music);
		static void Pause(Vista::Music& music);
		static void Resume(Vista::Music& music);
	};
}