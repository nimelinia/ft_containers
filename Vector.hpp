//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft {

	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
	public:
		typedef T																	value_type;
		typedef Vector<T, Alloc>													container_type;
		typedef Alloc																allocator_type;
		typedef T*																	pointer;
		typedef const T*															const_pointer;
		typedef T&																	reference;
		typedef const T&															const_reference;
		typedef typename Vector<T, Alloc>::container_type::iterator					iterator;
		typedef typename Vector<T, Alloc>::container_type::reverse_iterator			reverse_iterator;

	private:
		pointer																		m_begin;
		pointer																		m_end;
		size_t																		m_size;
		Alloc																		m_alloc;

	public:
/*
 * конструкторы
 */
		Vector() : m_begin(NULL), m_end(NULL), m_size(0) {}
		explicit Vector(size_t n, const value_type& val, const allocator_type& alloc) : m_size(n), m_alloc(alloc)
		{
			m_begin = m_alloc.allocate(n);
			m_end = m_begin + n;
		}
		template<class InputIterator>
		explicit Vector(InputIterator first, InputIterator last, const allocator_type& alloc);
/*
 * конструктор копирования
 */
		Vector(const Vector<T, Alloc> &other)
		{
//			*this = other;
		}
/*
 * деструктор
 */
		~Vector();
/*
 * оператор присвоения
 */
		Vector<T, Alloc> &operator=(const Vector<T, Alloc> &other)
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
		void					resize(size_t n, const value_type& val);
		unsigned				capacity() const;
		bool					empty() const;
		void					reserved(size_t n);


		reference				operator[] (size_t n);
		const_reference			operator[] (size_t n) const;
		reference				at(size_t n);
		const_reference			at(size_t n) const;
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;

		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign (size_t n, const value_type& val);
		void 					push_back(const value_type& val);
		void 					pop_back();

		iterator				insert(iterator position, const value_type& val);
		void					insert(iterator position, size_t n, const value_type& val);
		template <class InputIterator>
		void					insert (iterator position, InputIterator first, InputIterator last);

		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(Vector& other);
		void					clear();

	};

}

#endif //VECTOR_HPP
