#include "Vista/Input/Mouse.hpp"

#include "Vista/Math/Vector2D.hpp"

#include "Vista/Graphics/Camera.hpp"
#include "Vista/Graphics/Renderer.hpp"

#include "raylib.h"

bool Vista::Mouse::IsButtonPressed(Vista::Mouse::Button button)
{
	return ::IsMouseButtonPressed((int)(button));
}

bool Vista::Mouse::IsButtonReleased(Vista::Mouse::Button button)
{
	return ::IsMouseButtonReleased((int)(button));
}

bool Vista::Mouse::IsButtonDown(Vista::Mouse::Button button)
{
	return ::IsMouseButtonDown((int)(button));
}

bool Vista::Mouse::IsButtonUp(Vista::Mouse::Button button)
{
	return ::IsMouseButtonUp((int)(button));
}

Vista::Vector2D<float> Vista::Mouse::GetPosition()
{
	return Vista::Vector2D<float>(Vista::Renderer::GetWorldPosition(Vista::Vector2D<float>((float)(::GetMouseX()), (float)(::GetMouseY()))));
}

float Vista::Mouse::GetWheelMove()
{
	return ::GetMouseWheelMove();
}