#include "Vista/VisualNovel.hpp"

#include "Vista/Core/Application.hpp"

Vista::VisualNovel::VisualNovel()
{

}

Vista::VisualNovel::~VisualNovel()
{

}

void Vista::VisualNovel::Run(int argc, char* argv[])
{
	Vista::Application application;
	application.Run(argc, argv);
}