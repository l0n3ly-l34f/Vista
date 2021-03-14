#pragma once

namespace Vista
{
	template<typename T>
	class Vector2D;
	class Camera final
	{
	public:
		static Vista::Vector2D<float> position;
		static float zoom;
		static float rotation;
	public:
		Camera() = delete;
		virtual ~Camera() = delete;
	};
}