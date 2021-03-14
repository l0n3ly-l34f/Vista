#pragma once

#include "Vista/Resource/Resource.hpp"

#include <memory>

namespace Vista
{
	class Music final : public Vista::Resource
	{
	private:
		struct Implementation;
	private:
		std::unique_ptr<Vista::Music::Implementation> implementation;
	public:
		Music();
		virtual ~Music();
	private:
		bool OnLoad(const std::string& filepath) override final;
		void OnUnload() override final;
		void* OnGetData() override final;
	};
}