#pragma once

#include "Vista/Resource/Resource.hpp"

#include <memory>

namespace Vista
{
	class Sound final : public Vista::Resource
	{
	private:
		struct Implementation;
	private:
		std::unique_ptr<Vista::Sound::Implementation> implementation;
	public:
		Sound();
		virtual ~Sound();
	private:
		bool OnLoad(const std::string& filepath) override final;
		void OnUnload() override final;
		void* OnGetData() override final;
	};
}