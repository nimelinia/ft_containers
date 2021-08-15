//
// Created by Streetmentioner Copycat on 8/13/21.
//

#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <time.h>

#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

class vector_test
{
private:
	std::vector<std::string>	random_str_;
	ft::vector<std::string>		random_str_my;
	std::vector<int>			random_int_;
	ft::vector<int>				random_int_my;
	std::vector<Buffer>			random_buf_;
	ft::vector<Buffer>			random_buf_my;

	template<class T>
			void						print_vectors(std::vector<T> &vect1, ft::vector<T> &vect2, std::string &method);

public:
	vector_test();

	virtual ~vector_test();

	void						start_vector_tests();

};


#endif //VECTOR_TEST_HPP
