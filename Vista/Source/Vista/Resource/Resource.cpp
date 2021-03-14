#include "Vista/Resource/Resource.hpp"

Vista::Resource::Resource()
{

}

Vista::Resource::~Resource()
{
	this->Unload();
}

bool Vista::Resource::Load(const std::string& filepath)
{
	this->Unload();
	this->filepath = filepath;
	return this->OnLoad(filepath);
}

void Vista::Resource::Unload()
{
	this->filepath.clear();
	this->OnUnload();
}

void* Vista::Resource::GetData()
{
	return this->OnGetData();
}