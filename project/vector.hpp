//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Iterator.hpp"
#include <stdexcept>

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
		size_t																		m_capacity;

	public:
/*
 * конструкторы
 */
		vector() : m_begin(NULL), m_end(NULL), m_size(0), m_capacity(0) {}													// конструктор по умолчанию
		explicit vector(size_t n, const value_type& val, const allocator_type& alloc) : m_size(n), m_alloc(alloc)			// конструктор от количества элементов и элемента по умолчанию
		{
			m_begin = m_alloc.allocate(n);
			m_end = m_begin + n;
			for (size_t i = 0; i < n; ++i)
				this[i] = val;
		}
		template<class InputIterator>
		explicit vector(InputIterator first, InputIterator last, const allocator_type& alloc) :								// конструктор от двух итераторов
			m_size(last - first), m_alloc(alloc)
		{
			//  нужно добавить enable if
			m_begin = m_alloc.allocate(last - first);
			m_end = m_begin + m_size;
			for (size_t i = 0; i < m_size; ++i)
				this[i] = *(first + i);
			m_capacity = m_size;
		}
/*
 * конструктор копирования
 */
		vector(const vector<T, Alloc> &other) : m_size(other.m_size), m_alloc(other.m_alloc), m_capacity(other.capacity())
		{
			m_begin = m_alloc.allocate(m_size);
			m_end = m_begin + m_size;
			for (size_t i = 0; i < m_size; ++i)
				this[i] = other[i];
		}
/*
 * деструктор
 */
		~vector()
		{
			delete m_begin;
		}
/*
 * оператор присвоения
 */
		vector<T, Alloc> &operator=(const vector<T, Alloc> &other)
		{
			if (this != other)
			{
				this->m_size = other.m_size;
				this->m_begin = other.m_begin;
				this->m_end = other.m_end;
				this->m_alloc = other.m_alloc;
				this->m_capacity = other.m_capacity;
				for (size_t i = 0; i < m_size; ++i)
					this[i] = other[i];
			}
			return (*this);
		}
/*
 * итераторы
 */
		iterator				begin()
		{
				return (static_cast<iterator>(m_begin));
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

		unsigned				size() const
		{
			return (m_size);
		}
		unsigned				max_size() const
		{
			return (m_alloc.max_size());
		}
		void					resize(size_t n, const value_type& val = 0)													// позволяет увеличивать или уменьшать количество значений в контейнере
		{
			if (n < m_size)
			{
				while (m_size-- > n)
					this->pop_back();
			}
			else if (n > m_size)
			{
				if (n > m_capacity)
				{
					if (m_size * 2 > n)
						this->reserve(m_size * 2);
					else
						this->reserve(n);
				}
				while (m_size < n)
					this->push_back(val);
			}
		}
		unsigned				capacity() const																			// позволяет получить размер внутреннего буфера контейнера (включая не проинициализированные значения)
		{
			return (m_capacity);
		}
		bool					empty() const
		{
			return (m_size == 0);
		}
		void					reserve(size_t n)																			// позволяет увеличить размер capacity
		{
			if (n > this->max_size())
				throw std::length_error("Больше максимального размера");
			if (n > m_capacity)
			{
				pointer buf = m_alloc.allocate(n);
				for (size_t i = 0; i < m_size; ++i)
				{
					m_alloc.construct(&buf[i], m_begin[i]);
//					m_alloc.destroy(&m_begin[i]);
				}
				for (size_t i = 0; i < m_size; ++i)
				{
//					m_alloc.construct(&buf[i], m_begin[i]);
					m_alloc.destroy(&m_begin[i]);
				}
				m_capacity = n;
//				delete [] m_begin;
				m_begin = buf;
				m_end = m_begin + m_size;
			}
		}

		reference				operator[] (size_t n)																		// оператор доступа к элементу контейнера по индексу (нет проверок), в случае обращения к индексу больше m_size - undefined behaiviour
		{
			return (*(m_begin + n));
		}
		const_reference			operator[] (size_t n) const
		{
			return (*(m_begin + n));
		}

		bool operator==(const vector &rhs) const
		{
			return m_begin == rhs.m_begin &&
				   m_end == rhs.m_end &&
				   m_size == rhs.m_size &&
				   m_alloc == rhs.m_alloc &&
				   m_capacity = rhs.m_capacity;
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
			if (m_capacity < rhs.m_capacity)
				return true;
			if (rhs.m_capacity < m_capacity)
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
		reference				at(size_t n)																				// оператор доступа к элементу контейнера по индексу (есть проверки)
		{
			if (n > m_size)
				throw std::out_of_range("выход за пределы вектора");
			return (m_begin[n]);
		}
		const_reference			at(size_t n) const
		{
			if (n > m_size)
				throw std::out_of_range("выход за пределы вектора");
			return (m_begin + n);
		}
		reference				front()																						// метод доступа к началу - т.е. к первому элементу (возвращает не итератор, а прямую ссылку)
		{
			return (*(this->begin()));
		}
		const_reference			front() const
		{
			return (*(this->begin()));
		}
		reference				back()																						// метод доступа к концу
		{
			return (*(this->end() - 1));
		}
		const_reference			back() const
		{
			return (*(this->end() - 1));
		}
		pointer					data()																						// возвращает указатель на начало контейнера
		{
			return m_begin;
		}
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last)											// метод присвоения значений диапазону
		{
			// нужно добавить enable if
			this->clear();
			for (pointer p = first; p != last; ++p)
				push_back(*p);
		}
		void					assign (size_t n, const value_type& val)
		{
			this->clear();
			for (size_t i = 0; i < n; ++i)
				push_back(val);
		}
		void 					push_back(const value_type& val)															// добавляет элемент (уже существующий) в конец контейнера
		{
			if (m_size == m_capacity)
			{
				if (m_size != 0)
					reserve(m_size * 2);
				else
					reserve(2);
			}
			m_begin[m_size] = val;
			m_size++;
			m_end = m_begin + m_size;
		}
		void 					pop_back()																					// удаляет элементы из конца контейнера
		{
			erase(--m_end);
		}

		iterator				insert(iterator position, const value_type& val)											// добавляет элементы (уже существующие) в середину контейнера
		{
			// проверить, что это правильный итератор

			const ptrdiff_t n = position - m_begin;
			size_t pos = std::distance(m_begin, position);
			if (m_size == m_capacity)
				reserve(m_size + 1);
			_move(position, m_end, 1);
			m_begin[pos - 1] = val;
			m_size++;
			m_end = m_begin + m_size;
			return (m_begin + n);
		}

		void					insert(iterator position, size_t n, const value_type& val)
		{
			// проверить, что это правильный итератор

			const ptrdiff_t dist = position - m_begin;
			size_t pos = std::distance(m_begin, position);
			if (m_size == m_capacity)
				reserve(m_size + n);
			_move(position, m_end, n);
			for (size_t i = 0; i < n; ++i)
				m_begin[pos - 1 + i] = val;
			m_size += n;
			m_end = m_begin + m_size;
			return (m_begin + dist);
		}
		template <class InputIterator>
		void					insert (iterator position, InputIterator first, InputIterator last)
		{
			// нужно сделать enable if, что это  правильный итератор
		}

		iterator				erase(iterator position)																	// позволяет удалить один элемент из контейнера
		{
			// нужно менять размер и указатель на конец массива
		}
		iterator				erase(iterator first, iterator last)														// позволяет удалить последовательности элементов из контейнера
		{

		}
		void					swap(vector& other)
		{
			container_type temp(*this);
			*this = other;
			other = temp;
		}
		void					clear()
		{
			pointer start = m_begin;
			for (; start != m_end; start++)
				m_alloc.destroy(start);
			m_size = 0;
		}

	private:
		void 					_move(iterator start, iterator end, size_t count)
		{
			iterator end_b = end - 1;
			for (; end_b != start; --end_b)
				m_begin[end_b + count] = m_begin[end_b];																	// решить, нужно ли стирать элемент
		}
	};

}

#endif //VECTOR_HPP
