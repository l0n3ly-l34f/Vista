#include "Vista/Resource/ResourceManager.hpp"

#include "Vista/Resource/Texture.hpp"
#include "Vista/Resource/Font.hpp"
#include "Vista/Resource/Sound.hpp"
#include "Vista/Resource/Music.hpp"

#include "Vista/Utility/Path.hpp"

#include <unordered_map>

struct Vista::ResourceManager::Implementation final
{
	std::unordered_map<std::string, std::weak_ptr<Vista::Texture>> unordered_map_of_ids_and_weak_texture_pointers;
	std::unordered_map<std::string, std::weak_ptr<Vista::Font>> unordered_map_of_ids_and_weak_font_pointers;
	std::unordered_map<std::string, std::weak_ptr<Vista::Sound>> unordered_map_of_ids_and_weak_sound_pointers;
	std::unordered_map<std::string, std::weak_ptr<Vista::Music>> unordered_map_of_ids_and_weak_music_pointers;
	std::string application_directory = Vista::Path::GetApplicationFolderPath();
	std::string data_folder = "Data/";
	std::string asset_folder = "Assets/";
	std::string texture_folder = "Texture/";
	std::string font_folder = "Fonts/";
	std::string sound_folder = "Sound/";
	std::string music_folder = "Music/";
	std::string texture_directory = this->application_directory + this->data_folder + this->asset_folder + this->texture_folder;
	std::string font_directory = this->application_directory + this->data_folder + this->asset_folder + this->font_folder;
	std::string sound_directory = this->application_directory + this->data_folder + this->asset_folder + this->sound_folder;
	std::string music_directory = this->application_directory + this->data_folder + this->asset_folder + this->music_folder;
};

Vista::ResourceManager::Implementation Vista::ResourceManager::implementation;

template<>
std::shared_ptr<Vista::Texture> Vista::ResourceManager::Load<Vista::Texture>(const std::string& id, const std::string& filepath)
{
	std::weak_ptr<Vista::Texture>& weak_texture_pointer_reference = Vista::ResourceManager::implementation.unordered_map_of_ids_and_weak_texture_pointers[id];
	if (weak_texture_pointer_reference.expired())
	{
		std::shared_ptr<Vista::Texture> shared_texture_pointer = std::make_shared<Vista::Texture>();
		shared_texture_pointer->Load(Vista::ResourceManager::implementation.texture_directory + filepath);
		weak_texture_pointer_reference = shared_texture_pointer;
		return shared_texture_pointer;
	}
	else
	{
		return weak_texture_pointer_reference.lock();
	}
}

template<>
std::shared_ptr<Vista::Font> Vista::ResourceManager::Load<Vista::Font>(const std::string& id, const std::string& filepath)
{
	std::weak_ptr<Vista::Font>& weak_font_pointer_reference = Vista::ResourceManager::implementation.unordered_map_of_ids_and_weak_font_pointers[id];
	if (weak_font_pointer_reference.expired())
	{
		std::shared_ptr<Vista::Font> shared_font_pointer = std::make_shared<Vista::Font>();
		shared_font_pointer->Load(Vista::ResourceManager::implementation.font_directory + filepath);
		weak_font_pointer_reference = shared_font_pointer;
		return shared_font_pointer;
	}
	else
	{
		return weak_font_pointer_reference.lock();
	}
}

template<>
std::shared_ptr<Vista::Sound> Vista::ResourceManager::Load<Vista::Sound>(const std::string& id, const std::string& filepath)
{
	std::weak_ptr<Vista::Sound>& weak_sound_pointer_reference = Vista::ResourceManager::implementation.unordered_map_of_ids_and_weak_sound_pointers[id];
	if (weak_sound_pointer_reference.expired())
	{
		std::shared_ptr<Vista::Sound> shared_sound_pointer = std::make_shared<Vista::Sound>();
		shared_sound_pointer->Load(Vista::ResourceManager::implementation.sound_directory + filepath);
		weak_sound_pointer_reference = shared_sound_pointer;
		return shared_sound_pointer;
	}
	else
	{
		return weak_sound_pointer_reference.lock();
	}
}

template<>
std::shared_ptr<Vista::Music> Vista::ResourceManager::Load<Vista::Music>(const std::string& id, const std::string& filepath)
{
	std::weak_ptr<Vista::Music>& weak_music_pointer_reference = Vista::ResourceManager::implementation.unordered_map_of_ids_and_weak_music_pointers[id];
	if (weak_music_pointer_reference.expired())
	{
		std::shared_ptr<Vista::Music> shared_music_pointer = std::make_shared<Vista::Music>();
		shared_music_pointer->Load(Vista::ResourceManager::implementation.texture_directory + filepath);
		weak_music_pointer_reference = shared_music_pointer;
		return shared_music_pointer;
	}
	else
	{
		return weak_music_pointer_reference.lock();
	}
}