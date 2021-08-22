//
// Created by Streetmentioner Copycat on 7/21/21.
//

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "redblacktree.hpp"
#include "enable_if.hpp"
#include <iostream>

namespace ft {
	template <class T>
	class Iterator
	{
		typedef ptrdiff_t 							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;


		void advance (Iterator& it, difference_type n)
		{
			it += n;
		};
//		size_t distance (Iterator first, Iterator last);


	};

	template<typename Iterator>
	class ReverseIterator
	{
		struct IteratorTraits																									// позволяет определить тип итератора (с расширенным функционалом, двунаправленный или однонаправленный)
		{
			typedef typename Iterator::difference_type   difference_type;														//тип. который возвращает разницу двух итераторов (если оператор не random access, то вернет void)
			typedef typename Iterator::value_type        value_type;															// тип элемента, на который ссылается данный итератор
			typedef typename Iterator::pointer           pointer;																// тип указателя на такой элемент
			typedef typename Iterator::reference         reference;																// тип ссылки на такой элемент
			typedef typename Iterator::iterator_category iterator_category;														// категория итератора
		};
//		template <class T>
//		struct IteratorTraits<T* >																								// позволяет определить тип итератора (с расширенным функционалом, двунаправленный или однонаправленный)
//		{
//			typedef ptrdiff_t 							difference_type;
//			typedef T									value_type;
//			typedef T*									pointer;
//			typedef T&									reference;
//			typedef std::random_access_iterator_tag		iterator_category;
//		};
		typedef ptrdiff_t 									difference_type;
		typedef typename IteratorTraits::value_type 		value_type;
		typedef typename IteratorTraits::pointer 			pointer;
		typedef typename IteratorTraits::reference 			reference;
		typedef typename IteratorTraits::iterator_category	iterator_category;
	};



	template<class  Iterator, class T>
	class OperationIterators
	{
		typedef ptrdiff_t 							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;

	private:
		Iterator		m_iterator;

	public:
		OperationIterators() : m_iterator() {}

		pointer operator++()
		{
			++m_iterator;
			return *this;
		}

		pointer operator--()
		{
			--m_iterator;
			return *this;
		}


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
