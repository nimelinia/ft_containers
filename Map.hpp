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
		typedef reverseIterator<iterator> 													reverse_iterator;
		typedef reverseIterator<const_iterator>												const_reverse_iterator;

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
		Alloc			m_alloc;
		value_compare	m_v_compare;
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: Base(), m_alloc(alloc), m_v_compare(comp)
		{}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type(),
			 typename enable_if<!is_integral<InputIterator>::value>::type * = 0) : Base(), m_v_compare(comp)
		{
			this->insert(first, last);
		}

		map (const map& x) : m_v_compare(x.m_v_compare)
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
			return (Base::m_end ? Base::m_end->m_right : Base::m_end);
		}

		const_iterator end() const
		{
//			return (Base::m_end->m_right);
			return (Base::nil);
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(Base::m_end));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(end()));
		}

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
			return (m_alloc.max_size() / 2);
		}

		mapped_type& operator[] (const key_type& k)
		{
			iterator it = find(k);
			if (it != end())
				return (it.GetNode()->ref_value().second);
			else
				return ((insert(ft::make_pair(k, mapped_type()))).first).GetNode()->value->second;
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
				insert(ft::make_pair(first->first, first->second));
		}

		void erase (iterator position)
		{
			if (position != end())
				Base::deleteNode(position.GetNode());
		}

		size_type erase (const key_type& k)
		{
			iterator it = find(k);
			if (it == end())
				return (0);
			Base::deleteNode(Base::findNode(*it));
			return (1);
		}

		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				iterator it = first;
				++first;
				Base::deleteNode(Base::findNode(*it));
			}
		}

		void swap (map& x)
		{
			std::swap(Base::m_root, x.m_root);
			std::swap(Base::m_begin, x.m_begin);
			std::swap(Base::m_end, x.m_end);
			std::swap(Base::m_size, x.m_size);
			std::swap(Base::m_compare, x.m_compare);
			std::swap(Base::m_alloc, x.m_alloc);
			std::swap(m_alloc, x.m_alloc);
		}

		void clear()
		{
			if (size())
				erase(begin(), end());
		}

		key_compare key_comp() const
		{
			return (Base::m_compare);
		}

		value_compare value_comp() const
		{
			return (m_v_compare);
		}

		iterator find(const key_type& k)
		{
			return (Base::findNodebyKey(k));
		}

		const_iterator find(const key_type& k) const
		{
			return (Base::findNodebyKey(k));
		}

		size_type count (const key_type& k) const
		{
			return !(find(k) == end());
		}

		iterator lower_bound (const key_type& k)
		{
			iterator it = find(k);
			if (it != end())
				return (it);
			else
				return (find_nearest(k, false));
		}

		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = find(k);
			if (it != end())
				return (it);
			else
				return (find_nearest(k, false));
		}

		iterator upper_bound(const key_type& k)
		{
			return (find_nearest(k, true));
		}

		const_iterator upper_bound (const key_type& k) const
		{
			return (find_nearest(k, true));
		}

		pair<const_iterator,const_iterator> equal_range(const key_type& k) const
		{
			const_iterator it1(lower_bound(k));
			const_iterator it2(upper_bound(k));
			pair<const_iterator, const_iterator> ret(it1, it2);
			return (ret);
		}

		pair<iterator,iterator>             equal_range(const key_type& k)
		{
			iterator it1(lower_bound(k));
			iterator it2(upper_bound(k));
			return (ft::make_pair(it1, it2));
		}

		allocator_type get_allocator() const
		{
			return (m_alloc);
		}

		bool operator==(const map &rhs) const
		{
			if (Base::m_size != rhs.size())
				return (false);
			return (ft::equal(begin(), end(), rhs.begin()));
		}

		bool operator!=(const map &rhs) const
		{
			return !(rhs == *this);
		}

		bool operator<(const map &rhs) const
		{
			return (ft::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end()));
		}

		bool operator>(const map &rhs) const
		{
			return rhs < *this;
		}

		bool operator<=(const map &rhs) const
		{
			return !(rhs < *this);
		}

		bool operator>=(const map &rhs) const
		{
			return !(*this < rhs);
		}

	public:
		void print_map()
		{
			Base::_print(Base::m_root, 0);
			std::cout << "\033[1;31m" << "--------------- end of tree ---------------" << "\033[0m" << "\n";
		}

	private:
		iterator find_nearest(const key_type& k, bool biger)
		{
			iterator it(Base::m_root);

			if (Base::m_compare(k, Base::m_begin->value->first) && !biger)
			{
				iterator lit(Base::m_begin);
				return (lit);
			}
			while (it != NULL && (Base::m_compare(k, it.GetNode()->value->first) == biger))
			{
				if (biger)
					--it;
				else
					++it;
			}
			while (it != NULL && (Base::m_compare(k, it.GetNode()->value->first) != biger))
			{
				if (biger)
					++it;
				else
					--it;
				if (it != NULL && (Base::m_compare(k, it.GetNode()->value->first) == biger))
					return (biger ? it : ++it);
			}
			return (it);
		}
	};
}

#endif //MAP_HPP
