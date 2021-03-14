#pragma once

namespace Vista
{
	class Color final
	{
	public:
		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;
		unsigned char a = 0;
	public:
		Color();
		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		Color(const Vista::Color& color);
		virtual ~Color();
		Vista::Color& operator=(const Vista::Color& color);
		bool operator==(const Vista::Color& color);
		bool operator!=(const Vista::Color& color);
	};
}