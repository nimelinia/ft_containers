//
// Created by Streetmentioner Copycat on 8/24/21.
//

#include "stack_test.hpp"

stack_test::stack_test()
{
	srand(time(0));
	size_t len = rand() % 15 + 3;
	for (size_t i = 0; i < len; ++i)
	{
		std::string 	str_;
		size_t 			len_str = rand() % 100 + 3;
		size_t			number = rand() % 10000;
		for (size_t i = 0; i < len_str; ++i) {
			str_ += static_cast<char>(rand() % 26 + 'a');
		}
		random_str_.push(str_);
		random_str_my.push(str_);
		random_int_.push(number);
		random_int_my.push(number);
	}
}

stack_test::~stack_test()
{
}

bool stack_test::stack_compare(std::stack<std::string> &stan, MutantStack<std::string> &mine)
{
	std::stack<std::string> tmp(stan);
	MutantStack<std::string> tmp_my(mine);
	if (stan.size() != mine.size())
	{
		mistake += "my size is ";
		mistake += std::to_string(mine.size());
		mistake += ", and standart size is ";
		mistake += std::to_string(stan.size());
		return (false);
	}
	while (!tmp.empty())
	{
		if (tmp.top() != tmp_my.top())
		{
			mistake = "differences in the elems: mine is ";
			mistake += tmp_my.top();
			mistake += ", and standard is ";
			mistake += tmp.top();
			return (false);
		}
		tmp.pop();
		tmp_my.pop();
	}
	return (true);
}

bool stack_test::stack_compare(int other)
{
	(void ) other;
	std::stack<size_t> tmp(random_int_);
	MutantStack<size_t> tmp_my(random_int_my);
	if (random_int_.size() != random_int_my.size())
	{
		mistake += "size of mine is ";
		mistake += std::to_string(random_int_my.size());
		mistake += ", and size of standard is ";
		mistake += std::to_string(random_int_.size());
		return (false);
	}
	while (!tmp.empty())
	{
		if (tmp.top() != tmp_my.top())
			return (false);
		tmp.pop();
		tmp_my.pop();
	}
	return (true);
}

bool stack_test::stack_compare(const std::string &other)
{
	(void ) other;
	std::stack<std::string> tmp(random_str_);
	MutantStack<std::string> tmp_my(random_str_my);
	if (random_str_.size() != random_str_my.size())
	{
		mistake += "size of mine is ";
		mistake += std::to_string(random_str_my.size());
		mistake += ", and size of standard is ";
		mistake += std::to_string(random_str_.size());
		return (false);
	}
	while (!tmp.empty())
	{
		if (tmp.top() != tmp_my.top())
		{
			mistake = "differences in the elems: mine is ";
			mistake += tmp_my.top();
			mistake += ", and standard is ";
			mistake += tmp.top();
			return (false);
		}
		tmp.pop();
		tmp_my.pop();
	}
	return (true);
}



void	stack_test::print_mistakes()
{
	std::cout << RED << "[FAILED]" << END << std::endl;
	std::cout << RED << mistake << END << std::endl;
	mistake.clear();
}

void stack_test::print_ok()
{
	std::cout << BLUE << "[  OK  ]" << END << std::endl;
}

void stack_test::start_stack_tests()
{
	std::cout << MAGENTA << "==================================start of stack's tests===================================\n\n" << END;
	std::cout << CYAN << "TEST OF CREATING stack STRING------------------------------------------------------" << END;
	stack_compare("test") ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF CREATING stack OF NUMBERS--------------------------------------------------" << END;
	stack_compare(1) ? print_ok() : print_mistakes();


	MutantStack<std::string> stack_copy(random_str_my);
	std::cout << CYAN << "TEST OF COPY'S CONSTRUCTOR---------------------------------------------------------" << END;
	stack_compare(random_str_, stack_copy) ? print_ok() : print_mistakes();

	random_str_.push("lalala");
	random_str_my.push("lalala");
	std::cout << CYAN << "TEST OF PUSH-----------------------------------------------------------------------" << END;
	(random_str_.top() == random_str_my.top() && random_str_.top() == "lalala") ? print_ok() : print_mistakes();

	random_str_.pop();
	random_str_my.pop();
	std::cout << CYAN << "TEST OF POP------------------------------------------------------------------------" << END;
	(random_str_.top() == random_str_my.top() && random_str_.top() != "lalala") ? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF SIZE-----------------------------------------------------------------------" << END;
	(random_str_.size() == random_str_my.size()) ? print_ok() : print_mistakes();

	while (random_str_.size() && random_str_my.size())
	{
		random_str_.pop();
		random_str_my.pop();
	}
	std::cout << CYAN << "TEST OF EMPTY----------------------------------------------------------------------" << END;
	(random_str_.empty() == random_str_my.empty() && random_str_.empty()) ? print_ok() : print_mistakes();


	MutantStack<std::string> tmp_stack(random_str_my);
	std::cout << CYAN << "TEST OF COMPARE--------------------------------------------------------------------" << END;
	(tmp_stack == random_str_my) ? print_ok() : print_mistakes();

	tmp_stack.push("bbbb");
	std::cout << CYAN << "TEST OF COMPARE_2------------------------------------------------------------------" << END;
	(tmp_stack > random_str_my) ? print_ok() : print_mistakes();

	random_str_my.push("aaaa");
	std::cout << CYAN << "TEST OF COMPARE_2------------------------------------------------------------------" << END;
	(tmp_stack > random_str_my) ? print_ok() : print_mistakes();

std::cout << MAGENTA << "\n=====================================end of all tests======================================\n\n" << END;
}