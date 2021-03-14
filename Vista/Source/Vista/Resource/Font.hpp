#pragma once

#include "Vista/Resource/Resource.hpp"

#include <memory>

namespace Vista
{
	class Font final : public Vista::Resource
	{
	private:
		struct Implementation;
	private:
		std::unique_ptr<Vista::Font::Implementation> implementation;
	public:
		Font();
		virtual ~Font();
	private:
		bool OnLoad(const std::string& filepath) override final;
		void OnUnload() override final;
		void* OnGetData() override final;
	};
}