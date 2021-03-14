#pragma once

#include <string>

namespace Vista
{
	class Path
	{
	public:
		Path() = delete;
		virtual ~Path() = delete;
		static std::string GetApplicationPath();
		static std::string GetApplicationFolderPath();
	};
}