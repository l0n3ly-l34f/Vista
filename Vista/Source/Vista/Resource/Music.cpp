#include "Vista/Resource/Music.hpp"

#include "raylib.h"

struct Vista::Music::Implementation final
{
	::Music music = {};
};

Vista::Music::Music()
	: implementation(std::make_unique<Vista::Music::Implementation>())
{

}

Vista::Music::~Music()
{

}

bool Vista::Music::OnLoad(const std::string& filepath)
{
	this->implementation->music = ::LoadMusicStream(filepath.c_str());
	return (bool)(this->implementation->music.stream.buffer);
}

void Vista::Music::OnUnload()
{
	if (this->implementation->music.stream.buffer)
	{
		::UnloadMusicStream(this->implementation->music);
		this->implementation->music = {};
	}
}

void* Vista::Music::OnGetData()
{
	return (void*)(&(this->implementation->music));
}