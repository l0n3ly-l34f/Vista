#include "Vista/Resource/Font.hpp"

#include "raylib.h"

struct Vista::Font::Implementation final
{
	::Font font = {};
};

Vista::Font::Font()
	: implementation(std::make_unique< Vista::Font::Implementation>())
{

}

Vista::Font::~Font()
{

}

bool Vista::Font::OnLoad(const std::string& filepath)
{
	this->implementation->font = ::LoadFont(filepath.c_str());
	return (bool)(this->implementation->font.texture.id);
}

void Vista::Font::OnUnload()
{
	if (this->implementation->font.texture.id)
	{
		::UnloadFont(this->implementation->font);
		this->implementation->font = {};
	}
}

void* Vista::Font::OnGetData()
{
	return (void*)(&(this->implementation->font));
}