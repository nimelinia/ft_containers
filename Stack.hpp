//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace ft {

	template <class T, class Container = std::vector<T> >
	class stack
	{
		typedef T											value_type;
		typedef Container									container_type;
		typedef size_t										size_type;

	public:
		explicit stack (const container_type& ctnr = container_type()) : m_data(ctnr)
		{
		}

		bool empty() const
		{
			return (m_data.size() == 0);
		}

		size_type size() const
		{
			return (m_data.size());
		}

		value_type& top()
		{
			return (m_data.back());
		}

		const value_type& top() const
		{
			return (m_data.back());
		}

		void push (const value_type& val)
		{
			m_data.push_back(val);
		}

		void pop()
		{
			m_data.pop_back();
		}

		container_type getMData() const
		{
			return m_data;
		}

	private:
		container_type					m_data;
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.getMData() == rhs.getMData());
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.getMData() < rhs.getMData());
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs <= rhs);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif //STACK_HPP
