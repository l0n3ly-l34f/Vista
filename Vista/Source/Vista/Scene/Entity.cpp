#include "Vista/Scene/Entity.hpp"

#include "Vista/Scene/Component.hpp"

#include <unordered_map>

struct Vista::Entity::Implementation final
{
	std::unordered_map<Vista::Type::ID, std::unique_ptr<Vista::Component>> unordered_map_of_ids_and_components;
	bool waiting_to_be_destroyed = false;
};

Vista::Entity::Entity()
	: implementation(std::make_unique<Vista::Entity::Implementation>())
{

}

Vista::Entity::~Entity()
{

}

Vista::Component* Vista::Entity::GetComponent(Vista::Type::ID id)
{
	return this->implementation->unordered_map_of_ids_and_components[id].get();
}

Vista::Component* Vista::Entity::AddComponent(Vista::Type::ID id, std::unique_ptr<Vista::Component> unique_component_pointer)
{
	std::unique_ptr<Vista::Component>& unique_component_pointer_reference = this->implementation->unordered_map_of_ids_and_components[id] = std::move(unique_component_pointer);
	return unique_component_pointer_reference.get();
}

void Vista::Entity::RemoveComponent(Vista::Type::ID id)
{
	this->implementation->unordered_map_of_ids_and_components.erase(id);
}

void Vista::Entity::Destroy()
{
	this->implementation->waiting_to_be_destroyed = true;
}

bool Vista::Entity::IsWaitingToBeDestroyed()
{
	return this->implementation->waiting_to_be_destroyed;
}