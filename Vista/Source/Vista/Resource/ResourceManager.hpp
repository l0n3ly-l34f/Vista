#pragma once

#include <memory>
#include <string>

namespace Vista
{
	class Texture;
	class Font;
	class Sound;
	class Music;
	class ResourceManager final
	{
	private:
		struct Implementation;
	private:
		static Vista::ResourceManager::Implementation implementation;
	public:
		ResourceManager() = delete;
		virtual ~ResourceManager() = delete;
		template<typename T>
		std::shared_ptr<T> Load(const std::string& id, const std::string& filepath)
		{
			return {};
		}
		template<>
		std::shared_ptr<Vista::Texture> Load<Vista::Texture>(const std::string& id, const std::string& filepath);
		template<>
		std::shared_ptr<Vista::Font> Load<Vista::Font>(const std::string& id, const std::string& filepath);
		template<>
		std::shared_ptr<Vista::Sound> Load<Vista::Sound>(const std::string& id, const std::string& filepath);
		template<>
		std::shared_ptr<Vista::Music> Load<Vista::Music>(const std::string& id, const std::string& filepath);
	};
}