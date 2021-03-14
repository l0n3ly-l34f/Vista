#include "Vista/Scene/SceneManager.hpp"

#include "Vista/Scene/Scene.hpp"

#include <stack>

struct Vista::SceneManager::Implementation final
{
	std::stack<std::unique_ptr<Vista::Scene>> stack_of_unique_scene_pointers;
};

Vista::SceneManager::Implementation Vista::SceneManager::implementation;

Vista::Scene* Vista::SceneManager::Load(std::unique_ptr<Vista::Scene> unique_scene_pointer)
{
	return Vista::SceneManager::implementation.stack_of_unique_scene_pointers.emplace(std::move(unique_scene_pointer)).get();
}

void Vista::SceneManager::Unload()
{
	Vista::SceneManager::implementation.stack_of_unique_scene_pointers.pop();
}

bool Vista::SceneManager::IsEmpty()
{
	return Vista::SceneManager::implementation.stack_of_unique_scene_pointers.empty();
}

Vista::Scene* Vista::SceneManager::GetActiveScenePointer()
{
	return Vista::SceneManager::implementation.stack_of_unique_scene_pointers.top().get();
}