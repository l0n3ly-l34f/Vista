#pragma once

#include <string>

namespace Vista
{
	template<typename T>
	class Vector2D;
	template<typename T>
	class Rect2D;
	class Color;
	class Texture;
	class Font;
	class Renderer final
	{
	public:
		enum class Horizontal
		{
			Left = 0,
			Center = 1,
			Right = 2
		};
		enum class Vertical
		{
			Top = 0,
			Center = 1,
			Down = 2
		};
	public:
		Renderer() = delete;
		virtual ~Renderer() = delete;
		static void StartDrawing();
		static void EndDrawing();
		static void StartCamera();
		static void EndCamera();
		static void StartClipping(const Vista::Rect2D<float>& rect_2d);
		static void EndClipping();
		static void Clear(const Vista::Color& color);
		static void DrawFPS(const Vista::Vector2D<float>& vector_2d);
		static Vista::Vector2D<float> GetScreenPosition(const Vista::Vector2D<float>& vector_2d);
		static Vista::Vector2D<float> GetWorldPosition(const Vista::Vector2D<float>& vector_2d);
		static Vista::Rect2D<float> GetScreenRect(const Vista::Rect2D<float>& rect_2d);
		static Vista::Rect2D<float> GetWorldRect(const Vista::Rect2D<float>& rect_2d);
		static void DrawTexture(Vista::Texture& texture, const Vista::Rect2D<unsigned int>& source_rect, const Vista::Rect2D<float> destination_rect, float rotation, const Vista::Color& tint);
		static void DrawNineSliceTexture(Vista::Texture& texture, const Vista::Rect2D<unsigned int>& source_rect, unsigned int source_left_width, unsigned int source_right_width, unsigned int source_top_height, unsigned int source_bottom_height, const Vista::Rect2D<float>& destination_rect, float destination_left_width, float destination_right_width, float destination_top_height, float destination_bottom_height, const Vista::Color& tint);
		static void DrawText(Vista::Font& font, const char* string, const Vista::Rect2D<float>& rect, float size, float spacing, bool warp, const Vista::Color& color);
		static void DrawText(Vista::Font& font, const char* string, const Vista::Rect2D<float>& rect, float size, float spacing, Vista::Renderer::Horizontal horizontal, Vista::Renderer::Vertical vertical, const Vista::Color& color);
	};
}