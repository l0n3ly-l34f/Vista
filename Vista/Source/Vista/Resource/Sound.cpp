#include "Vista/Resource/Sound.hpp"

#include "raylib.h"

struct Vista::Sound::Implementation final
{
	::Sound sound = {};
};

Vista::Sound::Sound()
	: implementation(std::make_unique<Vista::Sound::Implementation>())
{

}

Vista::Sound::~Sound()
{

}

bool Vista::Sound::OnLoad(const std::string& filepath)
{
	this->implementation->sound = ::LoadSound(filepath.c_str());
	return (bool)(this->implementation->sound.stream.buffer);
}

void Vista::Sound::OnUnload()
{
	if (this->implementation->sound.stream.buffer)
	{
		::UnloadSound(this->implementation->sound);
		this->implementation->sound = {};
	}
}

void* Vista::Sound::OnGetData()
{
	return (void*)(&(this->implementation->sound));
}