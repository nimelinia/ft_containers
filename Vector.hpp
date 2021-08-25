//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Iterator.hpp"
#include "enable_if.hpp"
#include <stdexcept>
#include <limits>

namespace ft {

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T																	value_type;
		typedef vector<T, Alloc>													container_type;
		typedef Alloc																allocator_type;
		typedef T*																	pointer;
		typedef const T*															const_pointer;
		typedef T&																	reference;
		typedef const T&															const_reference;
		typedef vectIterator<T>														iterator;
		typedef const T*															const_iterator;
		typedef reverseIterator<iterator>											reverse_iterator;
		typedef reverseIterator<const_iterator>										const_reverse_iterator;
		typedef size_t																size_type;

	private:
		pointer																		m_begin;
		pointer																		m_end;
		size_type																	m_size;
		Alloc																		m_alloc;
		size_type																	m_capacity;

	public:
/*
 * конструкторы
 */
		vector() : m_begin(NULL), m_end(NULL), m_size(0), m_capacity(0) {}													// конструктор по умолчанию

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			m_size(n), m_alloc(alloc), m_capacity(n)																		// конструктор от количества элементов и элемента по умолчанию
		{
			m_begin = m_alloc.allocate(n);
			m_end = m_begin + n;
			for (size_type i = 0; i < n; ++i)
				m_begin[i] = val;
		}
		template<class InputIterator>
		explicit vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
						typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0) :				// конструктор от двух итераторов. enable if используется для того, чтобы отсечь станартные типы данных
			m_size(last - first), m_alloc(alloc)
		{
			m_begin = m_alloc.allocate(last - first);
			m_end = m_begin + m_size;
			for (size_type i = 0; i < m_size; ++i)
				m_begin[i] = *(first + i);
			m_capacity = m_size;
		}
/*
 * конструктор копирования
 */
		vector(const vector<T, Alloc> &other) : m_size(other.m_size), m_alloc(other.m_alloc), m_capacity(other.capacity())
		{
			m_begin = m_alloc.allocate(m_size);
			m_end = m_begin + m_size;
			for (size_type i = 0; i < m_size; ++i)
				m_begin[i] = other[i];
		}
/*
 * деструктор
 */
		~vector()
		{
			if (empty())
				return;
			for (size_type i = 0; i < m_size; ++i)
				m_alloc.destroy(&m_begin[i]);
			m_alloc.deallocate(m_begin, m_capacity);
		}
/*
 * оператор присвоения
 */
		vector<T, Alloc> &operator=(const vector<T, Alloc> &other)
		{
			vector<T, Alloc>	tmp(other);
			this->swap(tmp);
			return (*this);
		}
/*
 * итераторы
 */
		iterator				begin()
		{
			return iterator(m_begin);
		};

		const_iterator			begin() const
		{
			return const_iterator(m_begin);
		};

		iterator				end()
		{
			return iterator(m_end);
		}

		const_iterator			end() const
		{
			return const_iterator(m_end);
		}

		reverse_iterator		rbegin()
		{
			return (reverse_iterator(end()));
		}

		reverse_iterator		rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rbegin() const
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator	rend() const
		{
			return (reverse_iterator(begin()));
		}

		unsigned				size() const
		{
			return (m_size);
		}
		unsigned				max_size() const
		{
			return (m_alloc.max_size());
		}
		void					resize(size_type n, const value_type& val = 0)													// позволяет увеличивать или уменьшать количество значений в контейнере
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
		void					reserve(size_type n)																			// позволяет увеличить размер capacity
		{
			if (n > this->max_size())
				throw std::length_error("Больше максимального размера");
			if (n > m_capacity)
			{
				pointer buf = m_alloc.allocate(n);
				for (size_type i = 0; i < m_size; ++i)
					m_alloc.construct(&buf[i], m_begin[i]);
				for (size_type i = 0; i < m_size; ++i)
					m_alloc.destroy(&m_begin[i]);
				m_alloc.deallocate(m_begin, m_capacity);
				m_capacity = n;
				m_begin = buf;
				m_end = m_begin + m_size;
			}
		}

		reference				operator[] (size_type n)																		// оператор доступа к элементу контейнера по индексу (нет проверок), в случае обращения к индексу больше m_size - undefined behaiviour
		{
			return (*(m_begin + n));
		}
		const_reference			operator[] (size_type n) const
		{
			return (*(m_begin + n));
		}

		bool operator==(const vector &rhs) const
		{
			return m_begin == rhs.m_begin &&
				   m_end == rhs.m_end &&
				   m_size == rhs.m_size &&
				   m_alloc == rhs.m_alloc &&
				   m_capacity == rhs.m_capacity;
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
		reference				at(size_type n)																				// оператор доступа к элементу контейнера по индексу (есть проверки)
		{
			if (n > m_size)
				throw std::out_of_range("выход за пределы вектора");
			return (m_begin[n]);
		}
		const_reference			at(size_type n) const
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
		void					assign(InputIterator first, InputIterator last,
									typename enable_if<!is_integral<InputIterator>::value>::type * = 0)						// метод присвоения значений диапазону
		{
			this->clear();
			for (iterator p = first; p != last; ++p)
				push_back(*p);
		}
		void					assign (size_type n, const value_type& val)
		{
			this->clear();
			for (size_type i = 0; i < n; ++i)
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
			m_alloc.construct(&m_begin[m_size],val);
			m_size++;
			m_end = m_begin + m_size;
		}
		void 					pop_back()																					// удаляет элементы из конца контейнера
		{
			if (this->empty())
				return;
			m_alloc.destroy(&(m_begin[m_size - 1]));
			m_size--;
		}

		iterator				insert(iterator position, const value_type& val)											// добавляет элементы (уже существующие) в середину контейнера
		{
			// проверить, что это правильный итератор

			const ptrdiff_t n = position - m_begin;
			if (m_size == m_capacity)
				reserve(m_size * 2);
			position = m_begin + n;
			_move(position, m_end, 1);
			m_alloc.construct(&m_begin[n], val);
			m_size++;
			m_end = m_begin + m_size;
			return (m_begin + n);
		}

		void					insert(iterator position, size_type n, const value_type& val)
		{
			const ptrdiff_t dist = position - m_begin;
			if (m_size + n > m_capacity)
				reserve(m_size + n);
			position = m_begin + n;
			_move(position, m_end, n);
			for (size_type i = 0; i < n; ++i)
				m_alloc.construct(&m_begin[dist + i], val);
			m_size += n;
			m_end = m_begin + m_size;
		}
		template <class InputIterator>
		void					insert (iterator position, InputIterator first, InputIterator last,
										typename enable_if<!is_integral<InputIterator>::value>::type * = 0)
		{
			const ptrdiff_t n = last - first;
			const ptrdiff_t pos = position - m_begin;
			if (m_size + n > m_capacity)
				reserve(m_size + n);
			position = m_begin + pos;
			_move(position - 1, m_end, n);
			for (size_type i = 0; i < n; ++i)
			{
				m_alloc.destroy(&m_begin[pos + i]);
				m_alloc.construct(&m_begin[pos + i],*first);																		// переписать тут через конструкт
				first++;
			}
			m_size += n;
			m_end = m_begin + m_size;
		}

		iterator				erase(iterator position)																	// позволяет удалить один элемент из контейнера
		{
			const ptrdiff_t n = position - m_begin;
			_move(position, m_end, -1);
			m_size--;
			m_end = m_begin + m_size;
			return (m_begin + n);
		}
		iterator				erase(iterator first, iterator last)														// позволяет удалить последовательности элементов из контейнера
		{
			const ptrdiff_t n = last - first;
			_move(first + 1, m_end, -1 * n);
			m_size -= n;
			m_end = m_begin + m_size;
			return (m_begin + n);
		}
		void					swap(vector& other)
		{
			std::swap(this->m_begin, other.m_begin);
			std::swap(this->m_size, other.m_size);
			std::swap(this->m_end, other.m_end);
			std::swap(this->m_capacity, other.m_capacity);
			std::swap(this->m_alloc, other.m_alloc);
		}
		void					clear()
		{
			pointer start = m_begin;
			for (; start != m_end; start++)
				m_alloc.destroy(start);
			m_size = 0;
		}

		size_type 				getMSize() const
		{
			return m_size;
		}

		size_type 				getMCapacity() const
		{
			return m_capacity;
		}

	private:
		void 					_move(iterator start, iterator end, long int count)
		{
			ptrdiff_t n = end - start;
			ptrdiff_t pos = start - m_begin;
			if (count > 0 )
			{
				for (; n > 0; --n)
				{
					m_alloc.construct(&m_begin[n + pos + count], m_begin[n + pos]);
					m_alloc.destroy(&m_begin[n + pos]);
				}
			} else
			{
				for (size_type i = 1; i < n; ++i)
				{
					m_alloc.construct(&m_begin[i + pos + count], m_begin[i + pos]);
					m_alloc.destroy(&m_begin[i + pos]);
				}
			}
		}
	};
}

#endif //VECTOR_HPP
