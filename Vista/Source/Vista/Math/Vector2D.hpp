#pragma once

namespace Vista
{
	template<typename T>
	class Vector2D final
	{
	public:
		T x = (T)(0);
		T y = (T)(0);
	public:
		Vector2D<T>()
		{

		}
		Vector2D<T>(T x, T y)
			: x(x), y(y)
		{

		}
		Vector2D<T>(const Vista::Vector2D<T>& vector_2d)
			: x(vector_2d.x), y(vector_2d.y)
		{

		}
		virtual ~Vector2D<T>()
		{

		}
		Vista::Vector2D<T>& operator=(const Vista::Vector2D<T>& vector_2d)
		{
			this->x = vector_2d.x;
			this->y = vector_2d.y;
			return *this;
		}
		Vista::Vector2D<T> operator+(const Vista::Vector2D<T>& vector_2d)
		{
			return Vista::Vector2D<T>(this->x + vector_2d.x, this->y + vector_2d.y);
		}
		Vista::Vector2D<T> operator-(const Vista::Vector2D<T>& vector_2d)
		{
			return Vista::Vector2D<T>(this->x - vector_2d.x, this->y - vector_2d.y);
		}
		Vista::Vector2D<T> operator*(T value)
		{
			return Vista::Vector2D<T>(this->x * value, this->y * value);
		}
		Vista::Vector2D<T> operator/(T value)
		{
			return Vista::Vector2D<T>(this->x / value, this->y / value);
		}
		Vista::Vector2D<T>& operator+=(const Vista::Vector2D<T>& vector_2d)
		{
			this->x += vector_2d.x;
			this->y += vector_2d.y;
			return *this;
		}
		Vista::Vector2D<T>& operator-=(const Vista::Vector2D<T>& vector_2d)
		{
			this->x -= vector_2d.x;
			this->y -= vector_2d.y;
			return *this;
		}
		Vista::Vector2D<T>& operator*=(T value)
		{
			this->x *= value;
			this->y *= value;
			return *this;
		}
		Vista::Vector2D<T>& operator/=(T value)
		{
			this->x /= value;
			this->y /= value;
			return *this;
		}
		bool operator==(const Vista::Vector2D<T>& vector_2d)
		{
			return this->x == vector_2d.x && this->y == vector_2d.y;
		}
		bool operator!=(const Vista::Vector2D<T>& vector_2d)
		{
			return !(*this == vector_2d);
		}
		template<typename U>
		operator Vista::Vector2D<T>()
		{
			return Vista::Vector2D<T>((U)(this->x), (U)(this->y));
		}
	};
}