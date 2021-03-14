#pragma once

#include <memory>

namespace Vista
{
	class Application;
	class Scene;
	class SceneManager final
	{
	public:
		friend Vista::Application;
	private:
		struct Implementation;
	private:
		static Vista::SceneManager::Implementation implementation;
	public:
		SceneManager() = delete;
		virtual ~SceneManager() = delete;
		static Vista::Scene* Load(std::unique_ptr<Vista::Scene> unique_scene_pointer);
		static void Unload();
		template<typename T, typename... A>
		T* Load(A&&... arg)
		{
			return (T*)(this->Load(std::make_unique<T>(arg...)));
		}
	private:
		static bool IsEmpty();
		static Vista::Scene* GetActiveScenePointer();
	};
}