#pragma once

#include "Vista/Resource/Resource.hpp"

#include <memory>

namespace Vista
{
	template<typename T>
	class Vector2D;
	class Texture final : public Vista::Resource
	{
	private:
		struct Implementation;
	private:
		std::unique_ptr<Vista::Texture::Implementation> implementation;
	public:
		Texture();
		virtual ~Texture();
		Vista::Vector2D<unsigned int> GetDimensions();
	private:
		bool OnLoad(const std::string& filepath) override final;
		void OnUnload() override final;
		void* OnGetData() override final;
	};
}