#pragma once

#include "Vista/API.hpp"

namespace Vista
{
	class Application final
	{
	public:
		Application();
		virtual ~Application();
		void Run(int argc, char* argv[]);
	};
}