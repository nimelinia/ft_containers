//
// Created by Streetmentioner Copycat on 7/21/21.
//

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "redblacktree.hpp"
#include "enable_if.hpp"
#include <iostream>

namespace ft {
	class InputIteratorTag {};

	class OutputIteratorTag {};

	class ForwardIteratorTag: public InputIteratorTag {};

	class BidirectionalIteratorTag: public ForwardIteratorTag {};

	class RandomAccessIteratorTag: public BidirectionalIteratorTag {};

	template<class Iter>
	struct iterator_traits
	{
	public:
		typedef typename Iter::difference_type				difference_type;
		typedef typename Iter::value_type 					value_type;
		typedef typename Iter::pointer 						pointer;
		typedef typename Iter::reference					reference;
		typedef typename Iter::iterator_category			iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t								difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef RandomAccessIteratorTag						iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t								difference_type;
		typedef T											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef RandomAccessIteratorTag						iterator_category;
	};

	template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
	class Iterator
	{
	public:
		typedef T											value_type;
		typedef Distance 									difference_type;
		typedef Pointer										pointer;
		typedef Reference 									reference;
		typedef Category 									iterator_category;
	};

	template <class Iterator>
	class reverseIterator
	{
	public:
		typedef Iterator 								iterator_type;
		typedef iterator_traits<Iterator> 				traits;
		typedef typename traits::value_type				value_type;
		typedef typename traits::difference_type		difference_type;
		typedef typename traits::pointer				pointer;
		typedef typename traits::reference				reference;
		typedef typename traits::iterator_category		iterator_category;
	private:
		iterator_type m_it;

	public:
		reverseIterator() {};

		explicit reverseIterator (iterator_type it): m_it(it) {};

		reverseIterator (const reverseIterator<Iterator>& rev_it): m_it(rev_it.m_it) {};

		iterator_type base() const
		{
			return m_it;
		};

		reference operator*() const
		{
			iterator_type tmp = m_it;
			tmp--;
			return (*tmp);
		};

		reverseIterator operator+ (difference_type n) const
		{
			reverseIterator<iterator_type> tmp(m_it - n);
			return (tmp);
		};

		reverseIterator& operator++()
		{
			m_it--;
			return (*this);
		};

		reverseIterator  operator++(int)
		{
			reverseIterator tmp = *this;
			--(*this);
			return (tmp);
		};

		reverseIterator& operator+=(difference_type n)
		{
			m_it -= n;
			return (*this);
		};

		reverseIterator operator-(difference_type n) const
		{
			reverseIterator<iterator_type> tmp(m_it + n);
			return (tmp);
		};

		reverseIterator& operator--()
		{
			m_it++;
			return (*this);
		};

		reverseIterator  operator--(int)
		{
			reverseIterator temp = *this;
			++(*this);
			return (temp);
		};

		reverseIterator& operator-= (difference_type n)
		{
			m_it += n;
			return (*this);
		};

		pointer operator->() const
		{
			return (&(operator*()));
		}

		reference operator[] (difference_type n) const
		{
			return (m_it[- n - 1]);
		};

		friend bool operator==(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
		{
			return (lhs.m_it == rhs.m_it);
		};

		friend bool operator!=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
		{
			return !(lhs == rhs);
		};

		friend bool operator<(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
		{
			return (lhs.m_it < rhs.m_it);
		};

		friend bool operator<=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
		{
			return (lhs < rhs || lhs == rhs);
		};

		friend bool operator>(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
		{
			return !(lhs <= rhs);
		};

		friend bool operator>=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
		{
			return !(lhs < rhs);
		};

		friend reverseIterator<Iterator> operator+ (typename reverseIterator<Iterator>::difference_type n,
				const reverseIterator<Iterator>& rev_it)
		{
			return (rev_it + n);
		};

		friend typename reverseIterator<Iterator>::difference_type operator- (const reverseIterator<Iterator>& lhs,
				const reverseIterator<Iterator>& rhs)
		{
			return lhs._it - rhs._it;
		};
	};


	template <class T>
	class vectIterator : public Iterator<RandomAccessIteratorTag, T>
	{
	public:
		typedef ptrdiff_t												difference_type;
		typedef vectIterator<T>											iterator;
		typedef iterator_traits<Iterator<RandomAccessIteratorTag, T> > 	traits;
		typedef typename traits::value_type 							value_type;
		typedef typename traits::pointer 								pointer;
		typedef typename traits::reference 								reference;
		typedef typename traits::iterator_category 						iterator_category;
	private:
		pointer m_it;
	public:
		vectIterator() : m_it() {}

		vectIterator(pointer ptr) : m_it(ptr) {}

		vectIterator(vectIterator const &it) : m_it(it.m_it) {}

		vectIterator &operator= (vectIterator const &it)
		{
			if (it.m_it != m_it)
				m_it = it.m_it;
			return (*this);
		}

		reference operator*() const
		{
			return (*m_it);
		}

		pointer operator->()
		{
			return (m_it);
		}

		reference operator[](difference_type n) const
		{
			return (m_it[n]);
		}

		iterator &operator++()
		{
			m_it++;
			return (*this);
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		iterator &operator--()
		{
			m_it--;
			return (*this);
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		iterator operator+(difference_type n) const
		{
			iterator tmp(*this);
			tmp.m_it += n;
			return (tmp);
		}

		iterator operator-(difference_type n) const
		{
			iterator tmp(*this);
			tmp.m_it -= n;
			return (tmp);
		}

		iterator &operator+=(difference_type n)
		{
			m_it += n;
			return (*this);
		}

		iterator &operator-=(difference_type n)
		{
			m_it -= n;
			return (*this);
		}

		friend bool operator==(const iterator& lhs, const iterator& rhs)
		{
			return  (lhs.m_it == rhs.m_it);
		};

		friend bool operator!=(const iterator& lhs, const iterator& rhs)
		{
			return !(lhs.m_it == rhs.m_it);
		};

		friend iterator operator+(difference_type n, const iterator& it)
		{
			return (it + n);
		};

		friend iterator operator-(difference_type n, const iterator& it)
		{
			return (it - n);
		};

		friend difference_type operator-(const iterator& lhs, const iterator& rhs)
		{
			return (lhs.m_it - rhs.m_it);
		};

		friend difference_type operator+(const iterator& lhs, const iterator& rhs)
		{
			return (lhs.m_it + rhs.m_it);
		};

		friend bool operator<(const iterator& lhs, const iterator& rhs)
		{
			return (lhs.m_it < rhs.m_it);
		};

		friend bool operator>(const iterator& lhs, const iterator& rhs)
		{
			return (rhs < lhs);
		};

		friend bool operator<=(const iterator& lhs, const iterator& rhs)
		{
			return (rhs < lhs || rhs == lhs);
		};

		friend bool operator>=(const iterator& lhs, const iterator& rhs)
		{
			return !(lhs < rhs);
		};
	};


	template<class T>
	class mapIterator
	{
	public:
		typedef std::bidirectional_iterator_tag               iterator_category;
		typedef T                                             value_type;
		typedef std::ptrdiff_t                                difference_type;
		typedef value_type                                    *pointer;
		typedef value_type                                    &reference;
		typedef mapIterator<T>                                 self_type;
		typedef rbtNode<typename std::remove_const<value_type>::type> node_type;
		mapIterator(node_type *node = NULL) : _node(node) {};
	private:
		node_type *_node;
	public:
		template<class Some>
		mapIterator(const mapIterator<Some> &it, typename enable_if<!std::is_const<Some>::value>::type* = 0)
		{
			_node = it.GetNode();
		}

		mapIterator(const self_type &it)
		{
			_node = it.GetNode();
		}

		node_type *GetNode() const
		{
			return _node;
		}

		bool operator==(const mapIterator &rhs) const
		{
			return _node == rhs._node;
		}

		bool operator!=(const mapIterator &rhs) const
		{
			return !(rhs == *this);
		}

		self_type &operator++()
		{
			_node = _increment(_node);
			return *this;
		}

		self_type operator++(int) {
			self_type tmp = *this;
//			this->_node = increment(this->_node);
			return tmp;
		}

		self_type &operator--() {
			_node = _decrement(_node);
			return *this;
		}

		self_type operator--(int)
		{
			self_type tmp = *this;
//			this->_node = decrement(this->_node);
			return tmp;
		}

		node_type* _increment(node_type* node)
		{
			node_type* it(node);

			if (!it)
				return (NULL);
			if (it->m_right)
			{
				it = it->m_right;
				while (it->m_left)
					it = it->m_left;
				return (it);
			}
			while (it->m_parent && it->m_parent->m_left != it)
				it = it->m_parent;
			if (it->m_parent && it->m_parent->m_left == it)
				return (it->m_parent);
			return (NULL);
		}

		node_type* _decrement(node_type* node)
		{
			node_type* it(node);

			if (!it)
				return (NULL);
			if (it->m_left)
			{
				it = it->m_left;
				while (it->m_right)
					it = it->m_right;
				return (it);
			}
			if (it->m_parent && it->m_parent->m_right == it)
				return (it->m_parent);
			while (it->m_parent && it->m_parent->m_right != it)
				it = it->m_parent;
			return (it->m_parent);
		}

		reference operator*() { return const_cast<reference>(*_node->value); }
		pointer operator->() { return &(_node->value); }

		reference operator*() const { return const_cast<reference>(*_node->value); }
		pointer operator->() const { return &(_node->value); }
		};
}

#endif //ITERATOR_HPP
