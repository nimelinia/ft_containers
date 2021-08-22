//
// Created by Streetmentioner Copycat on 8/16/21.
//

#ifndef PAIR_HPP
#define PAIR_HPP

#include <ostream>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1			first_type;
		typedef T2			second_type;

		first_type 			first;
		second_type			second;

		pair() : first(), second() {}

		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		pair (const first_type& a, const second_type& b) :  first(a), second(b) {}



		template<class U, class V>
		pair& operator= (const pair<U, V>& pr)
		{
			if (*this != pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		}

		pair& operator= (const pair& pr)
		{
			if (*this != pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		}

		friend std::ostream &operator<<(std::ostream &os, const pair &pair) {
			os << "[ " << pair.first << " # " << pair.second << " ]";
			return os;
		}
	};



	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return (true);
		return (false);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs.first < lhs.first && rhs.second < lhs.second);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs < rhs));
	}

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u )
	{
		pair<T1, T2> pair_(t, u);
		return (pair_);
	}


}

#endif //PAIR_HPP
