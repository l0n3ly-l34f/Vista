#pragma once

#include <memory>

namespace Vista
{
	class Application;
	class Entity;
	class Scene
	{
	public:
		friend Vista::Application;
	private:
		struct Implementation;
	private:
		std::unique_ptr<Vista::Scene::Implementation> implementation;
	public:
		Scene();
		virtual ~Scene();
	private:
		void Update(float delta_time);
		void Input();
		void Draw();
	};
}