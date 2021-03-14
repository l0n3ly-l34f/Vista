#pragma once

namespace Vista
{
	template<typename T>
	class Vector2D;
	class Mouse final
	{
	public:
		enum class Button
		{
			Left = 0,
			Right = 1,
			Middle = 2
		};
	public:
		Mouse() = delete;
		virtual ~Mouse() = delete;
		static bool IsButtonPressed(Vista::Mouse::Button button);
		static bool IsButtonReleased(Vista::Mouse::Button button);
		static bool IsButtonDown(Vista::Mouse::Button button);
		static bool IsButtonUp(Vista::Mouse::Button button);
		static Vista::Vector2D<float> GetPosition();
		static float GetWheelMove();
	};
}