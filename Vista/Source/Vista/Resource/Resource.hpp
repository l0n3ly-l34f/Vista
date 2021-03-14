#pragma once

#include <string>

namespace Vista
{
	class Resource
	{
	private:
		std::string filepath;
	public:
		Resource();
		virtual ~Resource();
		bool Load(const std::string& filepath);
		void Unload();
		void* GetData();
	private:
		virtual bool OnLoad(const std::string& filepath) = 0;
		virtual void OnUnload() = 0;
		virtual void* OnGetData() = 0;
	};
}