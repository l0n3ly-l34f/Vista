#pragma once

#include "Vista/Utility/Type.hpp"

#include <memory>

namespace Vista
{
	class Scene;
	class Component;
	class Entity
	{
	public:
		friend Vista::Scene;
	private:
		struct Implementation;
	private:
		std::unique_ptr<Vista::Entity::Implementation> implementation;
	public:
		Entity();
		virtual ~Entity();
		Vista::Component* GetComponent(Vista::Type::ID id);
		Vista::Component* AddComponent(Vista::Type::ID id, std::unique_ptr<Vista::Component> unique_component_pointer);
		void RemoveComponent(Vista::Type::ID id);
		template<typename T>
		T* GetComponent()
		{
			return (T*)(this->GetComponent(Vista::Type::GetID<T>()));
		}
		template<typename T, typename... A>
		T* AddComponent(A&&... arg)
		{
			return (T*)(this->AddComponent(Vista::Type::GetID<T>(), std::make_unique<T>(arg...)));
		}
		template<typename T>
		void RemoveComponent()
		{
			this->RemoveComponent(Vista::Type::GetID<T>());
		}
		void Destroy();
	private:
		bool IsWaitingToBeDestroyed();
		virtual void Update() = 0;
		virtual void Input() = 0;
		virtual void Draw() = 0;
	};
}