//
// Created by Streetmentioner Copycat on 7/21/21.
//

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

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

	template <class T>
	class mapIterator
	{

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
}

#endif //ITERATOR_HPP
