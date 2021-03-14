#pragma once

#ifdef _MSC_VER
#define __VISTA_FUNCTION_SIGNATURE__ __FUNCSIG__
#endif

template<size_t N, size_t I = 0>
struct hash_calc {
	static constexpr size_t apply(const char(&s)[N]) {
		return  (hash_calc<N, I + 1>::apply(s) ^ s[I]) * 16777619u;
	};
};

template<size_t N>
struct hash_calc<N, N> {
	static constexpr size_t apply(const char(&s)[N]) {
		return  2166136261u;
	};
};

template<size_t N>
constexpr size_t hash(const char(&s)[N]) {
	return hash_calc<N>::apply(s);
}

namespace Vista
{
	class Type final
	{
	public:
		using ID = unsigned int;
		static Vista::Type::ID InvalidID;
	public:
		Type() = delete;
		virtual ~Type() = delete;
		template<typename T>
		Vista::Type::ID GetID()
		{
			return (Vista::Type::ID)(hash(__VISTA_FUNCTION_SIGNATURE__));
		}
	};
}