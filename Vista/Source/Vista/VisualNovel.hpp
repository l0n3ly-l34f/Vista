#pragma once

#include "Vista/API.hpp"

namespace Vista
{
	class __VISTA_API__ VisualNovel final
	{
	public:
		VisualNovel();
		virtual ~VisualNovel();
		void Run(int argc, char* argv[]);
	};
}