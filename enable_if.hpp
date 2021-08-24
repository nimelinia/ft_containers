//
// Created by Streetmentioner Copycat on 8/14/21.
//

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include <type_traits>

namespace ft {

	template <bool B, class T = void >
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<class T>
	struct is_integral_check
	{
		const static bool value = false;
	};

	template<>
	struct is_integral_check<bool>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<char>
			{
		const static bool value = true;
			};

	template<>
	struct is_integral_check<char16_t>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<char32_t>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<wchar_t>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<signed char>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<short int>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<int>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<long int>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<long long int>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<unsigned char>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<unsigned short int>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<unsigned int>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<unsigned long int>
	{
		const static bool value = true;
	};

	template<>
	struct is_integral_check<unsigned long long int>
	{
		const static bool value = true;
	};

	template<class T>
	struct is_integral
	{
		const static bool value = is_integral_check<T>::value;
	};


}


#endif //ENABLE_IF_HPP
