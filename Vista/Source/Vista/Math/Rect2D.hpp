#pragma once

#include "Vista/Math/Vector2D.hpp"

namespace Vista
{
	template<typename T>
	class Rect2D final
	{
	public:
		T x = (T)(0);
		T y = (T)(0);
		T width = (T)(0);
		T height = (T)(0);
	public:
		Rect2D<T>()
		{

		}
		Rect2D<T>(T x, T y, T width, T height)
			: x(x), y(y), width(width), height(height)
		{

		}
		Rect2D<T>(const Vista::Vector2D<T>& position, const Vista::Vector2D<T>& size)
			: x(position.x), y(position.y), width(size.x), height(size.y)
		{

		}
		Rect2D<T>(const Vista::Rect2D<T>& rect_2d)
			: x(rect_2d.x), y(rect_2d.y), width(rect_2d.width), height(rect_2d.height)
		{

		}
		virtual ~Rect2D<T>()
		{

		}
		Vista::Rect2D<T>& operator=(const Vista::Rect2D<T>& rect_2d)
		{
			this->x = rect_2d.x;
			this->y = rect_2d.y;
			this->width = rect_2d.width;
			this->height = rect_2d.height;
			return *this;
		}
		bool operator==(const Vista::Rect2D<T>& rect_2d)
		{
			return this->x == rect_2d.x && this->y == rect_2d.y && this->width == rect_2d.width && this->height == rect_2d.height;
		}
		bool operator!=(const Vista::Rect2D<T>& rect_2d)
		{
			return !(*this == rect_2d);
		}
		template<typename U>
		operator Vista::Rect2D<U>()
		{
			return Vista::Rect2D<U>((U)(this->x), (U)(this->y), (U)(this->width), (U)(this->height));
		}
	};
}