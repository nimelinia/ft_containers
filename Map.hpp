//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "Iterator.hpp"
#include "redblacktree.hpp"
#include <iostream>
#include <iomanip>

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map : public redblacktree<const Key, T, pair<const Key, T>, Compare, Alloc >
	{
	public:
		typedef redblacktree<const Key, T, pair<const Key, T>, Compare, Alloc>				Base;
		typedef Key																			key_type;
		typedef T																			mapped_type;
		typedef pair<const Key, T>															value_type;
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
//		typedef reverse_iterator<iterator> 													reverse_iterator;
//		typedef revers_iterator<const_iterator>												const_reverse_iterator;

		class value_compare
		{
		protected:
			friend class	map;
			Compare			compare;
			value_compare (Compare c) : compare(c) {}
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const { return compare(x.first, y.first); }
		};
	private:
//		Base 		m_data;
		Alloc		m_alloc;
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: Base()
		{}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type(),
			 typename enable_if<!is_integral<InputIterator>::value>::type * = 0) : Base()
		{
			this->insert(first, last);
		}

		map (const map& x)
		{
			this->insert(x.begin(), x.end());
		}

		~map()
		{
			this->clear();
		}

		map& operator= (const map& x)
		{
			if (*this != x)
			{
				this->clear();
				this->insert(x.begin(), x.end());
			}
			return (*this);
		}

		iterator begin()
		{
			return (iterator(Base::m_begin));
		}

		const_iterator begin() const
		{
			return (Base::m_begin);
		}

		iterator end()
		{
			return (Base::m_end);
		}

		const_iterator end() const
		{
			return (Base::m_data);
		}

//		reverse_iterator rbegin() {}
//
//		const_reverse_iterator rbegin() const {}
//
//		reverse_iterator rend() {}
//
//		const_reverse_iterator rend() const {}

		bool empty() const
		{
			return (Base::m_size == 0);
		}

		size_type size() const
		{
			return (Base::m_size);
		}

		size_type max_size() const
		{
			return (m_alloc.max_size());
		}

		mapped_type& operator[] (const key_type& k)
		{
			return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
		}

		pair<iterator,bool> insert (const value_type& val)
		{
			return (ft::make_pair(Base::insertNode(val), true));
		}

		iterator insert(iterator position, const value_type& val)
		{
			(void) position;
			return (insert(val).first);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last,
				typename enable_if<!is_integral<InputIterator>::value>::type * = 0)
		{
			for(; first != last; ++first)
				insert(*first);
		}

		void erase (iterator position)
		{
			Base::deleteNode(position);
		}

		size_type erase (const key_type& k)
		{
			Base::deleteNode(Base::findNode(*find(k)));
			return (1);
		}

		void erase (iterator first, iterator last)
		{
			for(; first != last; ++first)
				Base::deleteNode(Base::findNode(*first));
		}

		void swap (map& x)
		{
			std::swap(Base::m_root, x.m_root);
			std::swap(Base::m_begin, x.m_begin);
			std::swap(Base::m_end, x.m_begin);
			std::swap(Base::m_size, x.m_size);
			std::swap(Base::m_compare, x.m_compare);
			std::swap(Base::m_alloc, x.m_alloc);
			std::swap(m_alloc, x.m_alloc);
		}

		void clear()
		{
			erase(begin(), end());
		}

		key_compare key_comp() const {}

		value_compare value_comp() const {}

		iterator find (const key_type& k)
		{
			return (Base::findNodebyKey(k));
		}

		const_iterator find (const key_type& k) const {}

		size_type count (const key_type& k) const {}

		iterator lower_bound (const key_type& k) {}

		const_iterator lower_bound (const key_type& k) const {}

		iterator upper_bound (const key_type& k) {}

		const_iterator upper_bound (const key_type& k) const {}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {}

		pair<iterator,iterator>             equal_range (const key_type& k) {}

		allocator_type get_allocator() const {}

	public:
		void print_map()
		{
			Base::_print(Base::m_root, 0);
			std::cout << "\033[1;31m" << "--------------- end of tree ---------------" << "\033[0m" << "\n ";
		}
	};

}


#endif //MAP_HPP
