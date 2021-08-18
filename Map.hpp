//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "Iterator.hpp"
#include "redblacktree.hpp"
#include <iostream>

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
			class map : public redblacktree<const Key, T, std::pair<const Key, T>, Compare, Alloc >
	{
	public:
		typedef redblacktree<const Key, T, std::pair<const Key, T>, Compare, Alloc>			Base;
		typedef Key																			key_type;
		typedef T																			mapped_type;
		typedef std::pair<const Key, T>															value_type;
		typedef size_t																		size_type;
		typedef ptrdiff_t																	difference_type;
		typedef Compare																		key_compare;
		typedef Alloc																		allocator_type;

		typedef value_type&																	reference;
		typedef const value_type&															const_reference;
		typedef typename allocator_type::pointer											pointer;
		typedef typename allocator_type::const_pointer										const_pointer;
		typedef mapIterator<value_type>														iterator;
		typedef mapIterator<const value_type>												const_iterator;
		typedef reverse_iterator<iterator> 													reverse_iterator;
		typedef revers_iterator<const_iterator>												const_reverse_iterator;
//		typedef redblacktree																base_type;

		class value_compare
		{
		protected:
			friend class map;
			Compare				compare;
			value_compare (Compare c) : compare(c) {}
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const { return compare(x.first, y.first); }
		};

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) {}

		map (const map& x) {}

		~map() {}

		map& operator= (const map& x) {}

		iterator begin() {}

		const_iterator begin() const {}

		iterator end() {}

		const_iterator end() const {}

		reverse_iterator rbegin() {}

		const_reverse_iterator rbegin() const {}

		reverse_iterator rend() {}

		const_reverse_iterator rend() const {}

		bool empty() const {}

		size_type size() const {}

		size_type max_size() const {}

		mapped_type& operator[] (const key_type& k) {}

		pair<iterator,bool> insert (const value_type& val) {}

		iterator insert(iterator position, const value_type& val) {}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {}

		void erase (iterator position);

		size_type erase (const key_type& k) {}

		void erase (iterator first, iterator last) {}

		void swap (map& x) {}

		void clear() {}

		key_compare key_comp() const {}

		value_compare value_comp() const {}

		iterator find (const key_type& k) {}

		const_iterator find (const key_type& k) const {}

		size_type count (const key_type& k) const {}

		iterator lower_bound (const key_type& k) {}

		const_iterator lower_bound (const key_type& k) const {}

		iterator upper_bound (const key_type& k) {}

		const_iterator upper_bound (const key_type& k) const {}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {}

		pair<iterator,iterator>             equal_range (const key_type& k) {}

		allocator_type get_allocator() const {}

	private:
		void _void;

	};

}

#endif //MAP_HPP
