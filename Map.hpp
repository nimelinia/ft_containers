//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "Iterator.hpp"
#include <iostream>

namespace ft {

	template <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> >
	class map
	{
	public:
		typedef Key																	key_type;								// тип элементов, которые хранятся в этом контейнере
		typedef T																	mapped_type;
		typedef ft::pair<const Key, T>												value_type;
		typedef size_t																size_type;
		typedef ptrdiff_t															difference_type;
		typedef Compare																key_compare;
		typedef Alloc																allocator_type;

		typedef value_type&															reference;
		typedef const value_type&													const_reference;
		typedef typename allocator_type::pointer									pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		typedef mapIterator<value_type>												iterator;
		typedef mapIterator<const value_type>										const_iterator;
		typedef reverse_iterator<iterator> 											reverse_iterator;
		typedef revers_iterator<const_iterator>										const_reverse_iterator;
		
	private:

		
	};

}

#endif //MAP_HPP
