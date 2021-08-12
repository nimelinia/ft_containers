//
// Created by Streetmentioner Copycat on 7/18/21.
//

#ifndef STACK_HPP
#define STACK_HPP

namespace ft {
	class Stack {

	};

}


//template <class T, class Cont = std::deque<T> >
//class MutantStack : public std::stack<T, Cont>
//{
//public:
//	MutantStack() : std::stack<T, Cont>() {}
//	virtual ~MutantStack(){}
//	MutantStack (const MutantStack<T, Cont> &other)
//			: std::stack<T, Cont>()
//	{
//		*this = other;
//	}
//	MutantStack<T, Cont> &operator=(const MutantStack<T, Cont> &other)
//	{
//		this->c = other.c;
//		return (*this);
//	}
//
//
//	typedef typename std::stack<T, Cont>::container_type::iterator					iterator;
//	typedef typename std::stack<T, Cont>::container_type::const_iterator			const_iterator;
//	typedef typename std::stack<T, Cont>::container_type::reverse_iterator			reverse_iterator;
//	typedef typename std::stack<T, Cont>::container_type::const_reverse_iterator	const_reverse_iterator;
//
//	iterator				begin()
//	{
//		return (this->c.begin());
//	};
//
//	iterator				end()
//	{
//		return (this->c.end());
//	}
//
//	const_iterator			cbegin()
//	{
//		return (this->c.cbegin());
//	}
//
//	const_iterator			cend()
//	{
//		return (this->c.cend());
//	}
//
//	reverse_iterator		rbegin()
//	{
//		return (this->c.rbegin());
//	}
//
//	reverse_iterator		rend()
//	{
//		return (this->c.rend());
//	}
//
//	const_reverse_iterator	crbegin()
//	{
//		return (this->crbegin());
//	}
//
//	const_reverse_iterator	crend()
//	{
//		return (this->crend());
//	}
//};

#endif //STACK_HPP
