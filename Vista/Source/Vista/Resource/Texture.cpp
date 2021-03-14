#include "Vista/Resource/Texture.hpp"

#include "Vista/Math/Vector2D.hpp"

#include "raylib.h"

struct Vista::Texture::Implementation final
{
	::Texture2D texture_2d = {};
};

Vista::Texture::Texture()
	: implementation(std::make_unique<Vista::Texture::Implementation>())
{

}

Vista::Texture::~Texture()
{

}

Vista::Vector2D<unsigned int> Vista::Texture::GetDimensions()
{
	return { (unsigned int)(this->implementation->texture_2d.width), (unsigned int)(this->implementation->texture_2d.height) };
}

bool Vista::Texture::OnLoad(const std::string& filepath)
{
	this->implementation->texture_2d = ::LoadTexture(filepath.c_str());
	return (bool)(this->implementation->texture_2d.id);
}

void Vista::Texture::OnUnload()
{
	if (this->implementation->texture_2d.id)
	{
		::UnloadTexture(this->implementation->texture_2d);
		this->implementation->texture_2d = {};
	}
}

void* Vista::Texture::OnGetData()
{
	return (void*)(&(this->implementation->texture_2d));
}