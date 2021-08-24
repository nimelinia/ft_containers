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
	protected:
		typedef T											value_type;
		typedef Container									container_type;
		typedef size_t										size_type;

	public:
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
		{
		}

		bool empty() const
		{
			return (c.size() == 0);
		}

		size_type size() const
		{
			return (c.size());
		}

		value_type& top()
		{
			return (c.back());
		}

		const value_type& top() const
		{
			return (c.back());
		}

		void push (const value_type& val)
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_back();
		}

		container_type getMData() const
		{
			return c;
		}

	protected:
		container_type					c;
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
