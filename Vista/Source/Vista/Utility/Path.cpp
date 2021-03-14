#include "Vista/Utility/Path.hpp"

#include <Windows.h>

std::string Vista::Path::GetApplicationPath()
{
	char application_path[256u] = { 0 };
	GetModuleFileNameA(nullptr, application_path, sizeof(application_path));
	for (unsigned int i = 0u; i < 256u; i++)
	{
		if (application_path[i] == '\\')
		{
			application_path[i] = '/';
		}
	}
	return std::string(application_path);
}

std::string Vista::Path::GetApplicationFolderPath()
{
	char application_path[256u] = { 0 };
	GetModuleFileNameA(nullptr, application_path, sizeof(application_path));
	for (unsigned int i = 0u; i < 256u; i++)
	{
		if (application_path[i] == '\\')
		{
			application_path[i] = '/';
		}
	}
	std::string path = application_path;
	path.erase(path.find_last_of('/') + 1, path.length() - path.find_last_of('/'));
	return path;
}