//
// Created by Streetmentioner Copycat on 8/24/21.
//

#ifndef STACK_TEST_HPP
#define STACK_TEST_HPP

#include <stack>
#include <iostream>
#include "stack.hpp"

# define RED		"\x1b[31;1m"
# define GREEN		"\x1b[32;1m"
# define YELLOW		"\x1b[33;1m"
# define BLUE		"\x1b[34;1m"
# define MAGENTA	"\x1b[35;1m"
# define CYAN		"\x1b[36;1m"
# define WHITE		"\x1b[40;1m"
# define END		"\x1b[0m"


class stack_test
{
	template<typename T>
	class MutantStack : public ft::stack<T>
	{
	public:
		MutantStack() {}
		MutantStack(const MutantStack<T>& src) { *this = src; }
		MutantStack<T>& operator=(const MutantStack<T>& rhs)
		{
			this->c = rhs.c;
			return *this;
		}
		~MutantStack() {}

		typedef typename ft::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
	};

private:
		std::stack<std::string>					random_str_;
		MutantStack<std::string>				random_str_my;
		std::stack<size_t>						random_int_;
		MutantStack<size_t>						random_int_my;
		std::string								mistake;


	public:
		stack_test();

		virtual ~stack_test();

		void									start_stack_tests();

	private:
		bool									stack_compare(const std::string &other);
		bool									stack_compare(int other);
		bool 									stack_compare(std::stack<std::string> &stan, MutantStack<std::string> &mine);
		void									print_mistakes();
		void									print_ok();


};


#endif //PROJECT_STACK_TEST_HPP
