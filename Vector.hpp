//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Iterator.hpp"

namespace ft {

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T																	value_type;								// тип элементов, которые хранятся в этом контейнере
		typedef vector<T, Alloc>													container_type;
		typedef Alloc																allocator_type;
		typedef T*																	pointer;
		typedef const T*															const_pointer;
		typedef T&																	reference;
		typedef const T&															const_reference;
		typedef Iterator<T>															iterator;
		typedef ReverseIterator<Iterator<T>, T>										reverse_iterator;

	private:
		pointer																		m_begin;
		pointer																		m_end;
		size_t																		m_size;
		Alloc																		m_alloc;

	public:
/*
 * конструкторы
 */
		vector() : m_begin(NULL), m_end(NULL), m_size(0) {}
		explicit vector(size_t n, const value_type& val, const allocator_type& alloc) : m_size(n), m_alloc(alloc)			// конструктор от количества элементов и элемента по умолчанию
		{
			m_begin = m_alloc.allocate(n);
			m_end = m_begin + n;
		}
		template<class InputIterator>
		explicit vector(InputIterator first, InputIterator last, const allocator_type& alloc);								// конструктор от двух итераторов
/*
 * конструктор копирования
 */
		vector(const vector<T, Alloc> &other)
		{
//			*this = other;
		}
/*
 * деструктор
 */
		~vector();
/*
 * оператор присвоения
 */
		vector<T, Alloc> &operator=(const vector<T, Alloc> &other)
		{
//			this->c = other.c;
//			return (*this);
		}
/*
 * итераторы
 */
		iterator				begin()
		{
//				return ();
		};

		iterator				end()
		{
//			return ();
		}

		reverse_iterator		rbegin()
		{
//			return ();
		}

		reverse_iterator		rend()
		{
//			return ();
		}

		unsigned				size() const;
		unsigned				max_size() const;
		void					resize(size_t n, const value_type& val);													// позволяет увеличивать или уменьшать количество значений в контейнере
		unsigned				capacity() const;																			// позволяет получить размер внутреннего буфера контейнера (включая не проинициализированные значения)
		bool					empty() const;
		void					reserve(size_t n);																			// позволяет увеличить размер capacity


		reference				operator[] (size_t n);																		// оператор доступа к элементу контейнера по индексу (нет проверок)
		const_reference			operator[] (size_t n) const;

		bool operator==(const vector &rhs) const
		{
			return m_begin == rhs.m_begin &&
				   m_end == rhs.m_end &&
				   m_size == rhs.m_size &&
				   m_alloc == rhs.m_alloc;
		}
		bool operator!=(const vector &rhs) const
		{
			return !(rhs == *this);
		}
		bool operator<(const vector &rhs) const
		{
			if (m_begin < rhs.m_begin)
				return true;
			if (rhs.m_begin < m_begin)
				return false;
			if (m_end < rhs.m_end)
				return true;
			if (rhs.m_end < m_end)
				return false;
			if (m_size < rhs.m_size)
				return true;
			if (rhs.m_size < m_size)
				return false;
			return m_alloc < rhs.m_alloc;
		}
		bool operator>(const vector &rhs) const
		{
			return rhs < *this;
		}
		bool operator<=(const vector &rhs) const
		{
			return !(rhs < *this);
		}
		bool operator>=(const vector &rhs) const
		{
			return !(*this < rhs);
		}
		reference				at(size_t n);																				// оператор доступа к элементу контейнера по индексу (есть проверки)
		const_reference			at(size_t n) const;
		reference				front();																					// метод доступа к началу
		const_reference			front() const;
		reference				back();																						// метод доступа к концу
		const_reference			back() const;
		pointer					data();																						// возвращает указатель на начало контейнера

		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);											// метод присвоения значений диапазону
		void					assign (size_t n, const value_type& val);
		void 					push_back(const value_type& val);															// добавляет элемент (уже существующий) в конец контейнера
		void 					pop_back();																					// удаляет элементы из конца контейнера

		iterator				insert(iterator position, const value_type& val);											// добавляет элементы (уже существующие) в середину контейнера
		void					insert(iterator position, size_t n, const value_type& val);
		template <class InputIterator>
		void					insert (iterator position, InputIterator first, InputIterator last);

		iterator				erase(iterator position);																	// позволяет удалить один элемент из контейнера
		iterator				erase(iterator first, iterator last);														// позволяет удалить последовательности элементов из контейнера
		void					swap(vector& other);
		void					clear();

	};

}

#endif //VECTOR_HPP
