#include "Vista/Input/Keyboard.hpp"

#include "raylib.h"

bool Vista::Keyboard::IsKeyPressed(Vista::Keyboard::Key key)
{
	return ::IsKeyPressed((int)(key));
}

bool Vista::Keyboard::IsKeyReleased(Vista::Keyboard::Key key)
{
	return ::IsKeyReleased((int)(key));
}

bool Vista::Keyboard::IsKeyDown(Vista::Keyboard::Key key)
{
	return ::IsKeyDown((int)(key));
}

bool Vista::Keyboard::IsKeyUp(Vista::Keyboard::Key key)
{
	return ::IsKeyUp((int)(key));
}

Vista::Keyboard::Key Vista::Keyboard::GetKeyPressed()
{
	return (Vista::Keyboard::Key)(::GetKeyPressed());
}

int Vista::Keyboard::GetCharPressed()
{
	return ::GetCharPressed();
}