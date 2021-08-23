//
// Created by Streetmentioner Copycat on 8/13/21.
//

#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <ctime>

#define BUFFER_SIZE	4096
# define RED		"\x1b[31;1m"
# define GREEN		"\x1b[32;1m"
# define YELLOW		"\x1b[33;1m"
# define BLUE		"\x1b[34;1m"
# define MAGENTA	"\x1b[35;1m"
# define CYAN		"\x1b[36;1m"
# define WHITE		"\x1b[40;1m"
# define END		"\x1b[0m"

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

class vector_test
{
private:
	std::vector<std::string>					random_str_;
	ft::vector<std::string>						random_str_my;
	std::vector<int>							random_int_;
	ft::vector<int>								random_int_my;
	std::vector<Buffer>							random_buf_;
	ft::vector<Buffer>							random_buf_my;
	std::string									mistake;

	typedef std::vector<int>::iterator			it;
	typedef ft::vector<int>::iterator			itmy;
	typedef std::vector<int>::reverse_iterator	rit;
	typedef ft::vector<int>::reverse_iterator	ritmy;

public:
	vector_test();

	virtual ~vector_test();

	void										start_vector_tests();

private:
	bool										vector_compare(const std::string &other);
	bool										vector_compare(int other);
	bool 										vector_compare(std::vector<int> &stan, ft::vector<int> &mine);
	bool										compare_iterators(std::vector<int> &vect1, ft::vector<int> &vect2);
	bool										compare_riterators(std::vector<int> &vect1, ft::vector<int> &vect2);
	void										print_mistakes();
	void										print_ok();
};


#endif //VECTOR_TEST_HPP
