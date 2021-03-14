#include "Vista/Graphics/Renderer.hpp"

#include "Vista/Math/Vector2D.hpp"
#include "Vista/Math/Rect2D.hpp"

#include "Vista/Graphics/Color.hpp"
#include "Vista/Graphics/Camera.hpp"

#include "Vista/Resource/Texture.hpp"
#include "Vista/Resource/Font.hpp"

#include "raylib.h"

void Vista::Renderer::StartDrawing()
{
	::BeginDrawing();
}

void Vista::Renderer::EndDrawing()
{
	::EndDrawing();
}

void Vista::Renderer::StartCamera()
{
	::BeginMode2D({ { 0.0f, 0.0f }, { Vista::Camera::position.x, Vista::Camera::position.y }, Vista::Camera::rotation, Vista::Camera::zoom });
}

void Vista::Renderer::EndCamera()
{
	::EndMode2D();
}

void Vista::Renderer::StartClipping(const Vista::Rect2D<float>& rect_2d)
{
	Vista::Rect2D<float> rectangle = Vista::Renderer::GetScreenRect(rect_2d);
	::BeginScissorMode((int)(rectangle.x), (int)(rectangle.y), (int)(rectangle.width), (int)(rectangle.height));
}

void Vista::Renderer::EndClipping()
{
	::EndScissorMode();
}

void Vista::Renderer::Clear(const Vista::Color& color)
{
	::ClearBackground({ color.r, color.g, color.b, color.a });
}

void Vista::Renderer::DrawFPS(const Vista::Vector2D<float>& vector_2d)
{
	::DrawFPS((int)(vector_2d.x), (int)(vector_2d.y));
}

Vista::Vector2D<float> Vista::Renderer::GetScreenPosition(const Vista::Vector2D<float>& vector_2d)
{
	::Vector2 position = ::GetWorldToScreen2D({ vector_2d.x, vector_2d.y }, { { 0.0f, 0.0f }, { Vista::Camera::position.x, Vista::Camera::position.y }, Vista::Camera::rotation, Vista::Camera::zoom });
	return Vista::Vector2D<float>(position.x, position.y);
}

Vista::Vector2D<float> Vista::Renderer::GetWorldPosition(const Vista::Vector2D<float>& vector_2d)
{
	::Vector2 position = ::GetScreenToWorld2D({ vector_2d.x, vector_2d.y }, { { 0.0f, 0.0f }, { Vista::Camera::position.x, Vista::Camera::position.y }, Vista::Camera::rotation, Vista::Camera::zoom });
	return Vista::Vector2D<float>(position.x, position.y);
}

Vista::Rect2D<float> Vista::Renderer::GetScreenRect(const Vista::Rect2D<float>& rect_2d)
{
	::Vector2 position_0 = ::GetWorldToScreen2D({ rect_2d.x, rect_2d.y }, { { 0.0f, 0.0f }, { Vista::Camera::position.x, Vista::Camera::position.y }, Vista::Camera::rotation, Vista::Camera::zoom });
	::Vector2 position_1 = ::GetWorldToScreen2D({ rect_2d.x + rect_2d.width, rect_2d.y + rect_2d.height }, { { 0.0f, 0.0f }, { Vista::Camera::position.x, Vista::Camera::position.y }, Vista::Camera::rotation, Vista::Camera::zoom });
	return Vista::Rect2D<float>(position_0.x, position_0.y, position_1.x - position_0.x, position_1.y - position_0.y);
}

Vista::Rect2D<float> Vista::Renderer::GetWorldRect(const Vista::Rect2D<float>& rect_2d)
{
	::Vector2 position_0 = ::GetScreenToWorld2D({ rect_2d.x, rect_2d.y }, { { 0.0f, 0.0f }, { Vista::Camera::position.x, Vista::Camera::position.y }, Vista::Camera::rotation, Vista::Camera::zoom });
	::Vector2 position_1 = ::GetScreenToWorld2D({ rect_2d.x + rect_2d.width, rect_2d.y + rect_2d.height }, { { 0.0f, 0.0f }, { Vista::Camera::position.x, Vista::Camera::position.y }, Vista::Camera::rotation, Vista::Camera::zoom });
	return Vista::Rect2D<float>(position_0.x, position_0.y, position_1.x - position_0.x, position_1.y - position_0.y);
}

void Vista::Renderer::DrawTexture(Vista::Texture& texture, const Vista::Rect2D<unsigned int>& source_rect, const Vista::Rect2D<float> destination_rect, float rotation, const Vista::Color& tint)
{
	::DrawTexturePro(*((Texture2D*)(texture.GetData())), { (float)(source_rect.x), (float)(source_rect.y), (float)(source_rect.width), (float)(source_rect.height) }, { destination_rect.x, destination_rect.y, destination_rect.width, destination_rect.height }, {}, rotation, { tint.r, tint.g, tint.b, tint.a });
}

void Vista::Renderer::DrawNineSliceTexture(Vista::Texture& texture, const Vista::Rect2D<unsigned int>& source_rect, unsigned int source_left_width, unsigned int source_right_width, unsigned int source_top_height, unsigned int source_bottom_height, const Vista::Rect2D<float>& destination_rect, float destination_left_width, float destination_right_width, float destination_top_height, float destination_bottom_height, const Vista::Color& tint)
{
	Vista::Rect2D<unsigned int> source_rects[9];
	Vista::Rect2D<float> destination_rects[9];
	source_rects[0] = { source_rect.x, source_rect.y, source_left_width, source_top_height };
	source_rects[1] = { source_rect.x + source_left_width, source_rect.y, source_rect.width - source_left_width - source_right_width, source_top_height };
	source_rects[2] = { source_rect.x + source_rect.width - source_right_width, source_rect.y, source_right_width, source_top_height };
	source_rects[3] = { source_rect.x, source_rect.y + source_top_height, source_left_width, source_rect.height - source_top_height - source_bottom_height };
	source_rects[4] = { source_rect.x + source_left_width, source_rect.y + source_top_height, source_rect.width - source_left_width - source_right_width, source_rect.height - source_top_height - source_bottom_height };
	source_rects[5] = { source_rect.x + source_rect.width - source_right_width, source_rect.y + source_top_height, source_right_width, source_rect.height - source_top_height - source_bottom_height };
	source_rects[6] = { source_rect.x, source_rect.y + source_rect.height - source_bottom_height, source_left_width, source_top_height };
	source_rects[7] = { source_rect.x + source_left_width, source_rect.y + source_rect.height - source_bottom_height, source_rect.width - source_left_width - source_right_width, source_top_height };
	source_rects[8] = { source_rect.x + source_rect.width - source_right_width, source_rect.y + source_rect.height - source_bottom_height, source_right_width, source_top_height };
	destination_rects[0] = { destination_rect.x, destination_rect.y, destination_left_width, destination_top_height };
	destination_rects[1] = { destination_rect.x + destination_left_width, destination_rect.y, destination_rect.width - destination_left_width - destination_right_width, destination_top_height };
	destination_rects[2] = { destination_rect.x + destination_rect.width - destination_right_width, destination_rect.y, destination_right_width, destination_top_height };
	destination_rects[3] = { destination_rect.x, destination_rect.y + destination_top_height, destination_left_width, destination_rect.height - destination_top_height - destination_bottom_height };
	destination_rects[4] = { destination_rect.x + destination_left_width, destination_rect.y + destination_top_height, destination_rect.width - destination_left_width - destination_right_width, destination_rect.height - destination_top_height - destination_bottom_height };
	destination_rects[5] = { destination_rect.x + destination_rect.width - destination_right_width, destination_rect.y + destination_top_height, destination_right_width, destination_rect.height - destination_top_height - destination_bottom_height };
	destination_rects[6] = { destination_rect.x, destination_rect.y + destination_rect.height - destination_bottom_height, destination_left_width, destination_top_height };
	destination_rects[7] = { destination_rect.x + destination_left_width, destination_rect.y + destination_rect.height - destination_bottom_height, destination_rect.width - destination_left_width - destination_right_width, destination_top_height };
	destination_rects[8] = { destination_rect.x + destination_rect.width - destination_right_width, destination_rect.y + destination_rect.height - destination_bottom_height, destination_right_width, destination_top_height };
	Vista::Renderer::DrawTexture(texture, source_rects[0], destination_rects[0], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[1], destination_rects[1], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[2], destination_rects[2], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[3], destination_rects[3], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[4], destination_rects[4], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[5], destination_rects[5], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[6], destination_rects[6], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[7], destination_rects[7], 0.0f, tint);
	Vista::Renderer::DrawTexture(texture, source_rects[8], destination_rects[8], 0.0f, tint);
}

void Vista::Renderer::DrawText(Vista::Font& font, const char* string, const Vista::Rect2D<float>& rect, float size, float spacing, bool warp, const Vista::Color& color)
{
	Vista::Renderer::StartClipping(rect);
	::DrawTextRec(*((::Font*)(font.GetData())), string, { rect.x, rect.y, rect.width, rect.height }, size, spacing, warp, { color.r, color.g, color.b, color.a });
	Vista::Renderer::EndClipping();
}

void Vista::Renderer::DrawText(Vista::Font& font, const char* string, const Vista::Rect2D<float>& rect, float size, float spacing, Vista::Renderer::Horizontal horizontal, Vista::Renderer::Vertical vertical, const Vista::Color& color)
{
	Vista::Vector2D<float> text_position;
	switch (horizontal)
	{
	case Vista::Renderer::Horizontal::Left:
		text_position.x = rect.x;
		break;
	case Vista::Renderer::Horizontal::Center:
		text_position.x = rect.x + rect.width / 2.0f - ::MeasureTextEx(*((::Font*)(font.GetData())), string, size, spacing).x / 2.0f;
		break;
	case Vista::Renderer::Horizontal::Right:
		text_position.x = rect.x + rect.width - ::MeasureTextEx(*((::Font*)(font.GetData())), string, size, spacing).x;
		break;
	default:
		break;
	}
	switch (vertical)
	{
	case Vista::Renderer::Vertical::Top:
		text_position.y = rect.y;
		break;
	case Vista::Renderer::Vertical::Center:
		text_position.y = rect.y + rect.height / 2.0f - ::MeasureTextEx(*((::Font*)(font.GetData())), string, size, spacing).y / 2.0f;
		break;
	case Vista::Renderer::Vertical::Down:
		text_position.y = rect.y + rect.height - ::MeasureTextEx(*((::Font*)(font.GetData())), string, size, spacing).y;
		break;
	default:
		break;
	}
	Vista::Renderer::StartClipping(rect);
	::DrawTextEx(*((::Font*)(font.GetData())), string, { text_position.x, text_position.y }, size, spacing, { color.r, color.g, color.b, color.a });
	Vista::Renderer::EndClipping();
}