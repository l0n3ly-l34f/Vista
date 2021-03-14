#include "Vista/Scene/Scene.hpp"

#include "Vista/Scene/Entity.hpp"

#include <list>

struct Vista::Scene::Implementation final
{
	std::list<std::unique_ptr<Vista::Entity>> list_of_unique_entity_pointers;
};

Vista::Scene::Scene()
	: implementation(std::make_unique<Vista::Scene::Implementation>())
{

}

Vista::Scene::~Scene()
{

}

void Vista::Scene::Update(float delta_time)
{
	for (std::list<std::unique_ptr<Vista::Entity>>::iterator iterator = this->implementation->list_of_unique_entity_pointers.begin(); iterator != this->implementation->list_of_unique_entity_pointers.end(); iterator)
	{
		(*iterator)->Update();
		if ((*iterator)->IsWaitingToBeDestroyed())
		{
			iterator = this->implementation->list_of_unique_entity_pointers.erase(iterator);
		}
		else
		{
			iterator++;
		}
	}
}

void Vista::Scene::Input()
{
	for (auto& i : this->implementation->list_of_unique_entity_pointers)
	{
		i->Input();
	}
}

void Vista::Scene::Draw()
{
	for (auto& i : this->implementation->list_of_unique_entity_pointers)
	{
		i->Draw();
	}
}