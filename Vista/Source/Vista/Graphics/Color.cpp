#include "Vista/Graphics/Color.hpp"

Vista::Color::Color()
{

}

Vista::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	: r(r), g(g), b(b), a(a)
{

}

Vista::Color::Color(const Vista::Color& color)
{
	*this = color;
}

Vista::Color::~Color()
{

}

Vista::Color& Vista::Color::operator=(const Vista::Color& color)
{
	this->r = color.r;
	this->g = color.g;
	this->b = color.b;
	this->a = color.a;
	return *this;
}

bool Vista::Color::operator==(const Vista::Color& color)
{
	return this->r == color.r && this->g == color.g && this->b == color.b && this->a == color.a;
}

bool Vista::Color::operator!=(const Vista::Color& color)
{
	return !(*this == color);
}