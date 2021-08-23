//
// Created by Streetmentioner Copycat on 8/13/21.
//

#include "vector_test.hpp"

vector_test::vector_test()
{
	srand(time(0));
	size_t len = rand() % 15 + 3;
	for (size_t i = 0; i < len; ++i)
	{
		std::string 	str_;
		size_t 			len_str = rand() % 100 + 3;
		int				number = rand() % 10000;
		for (size_t i = 0; i < len_str; ++i) {
			str_ += static_cast<char>(rand() % 26 + 'a');
		}
		random_str_.push_back(str_);
		random_str_my.push_back(str_);
		random_int_.push_back(number);
		random_int_my.push_back(number);
	}
	Buffer		buffer;
	buffer.idx = rand() % 4096;
	for (size_t i = 0; i < buffer.idx; ++i)
		buffer.buff[i] = static_cast<char>(rand() % 26 + 'a');
	random_buf_.push_back(buffer);
	random_buf_my.push_back(buffer);
}

vector_test::~vector_test()
{
}

bool vector_test::vector_compare(std::vector<int> &stan, ft::vector<int> &mine)
{
	if (stan.capacity() != mine.getMCapacity())
	{
		mistake += "my capasity is ";
		mistake += std::to_string(mine.getMCapacity());
		mistake += ", and standart capasity is ";
		mistake += std::to_string(stan.capacity());
		return (false);
	}
	if (stan.size() != mine.size())
	{
		mistake += "my size is ";
		mistake += std::to_string(mine.size());
		mistake += ", and standart size is ";
		mistake += std::to_string(stan.size());
		return (false);
	}
	for (size_t i = 0; i < stan.size(); ++i)
	{
		if (stan[i] != mine[i])
		{
			mistake = "differences in the elems";
			return (false);
		}
	}
	return (true);
}

bool vector_test::vector_compare(int other)
{
	(void ) other;
	if (random_int_.capacity() != random_int_my.getMCapacity())
		return (false);
	if (random_int_.size() != random_int_my.size())
		return (false);
	for (size_t i = 0; i < random_int_.size(); ++i)
	{
		if (random_int_my[i] != random_int_[i])
			return (false);
	}
	return (true);
}

bool vector_test::vector_compare(const std::string &other)
{
	(void ) other;
	if (random_str_.capacity() != random_str_my.getMCapacity())
		return (false);
	if (random_str_.size() != random_str_my.size())
		return (false);
	for (size_t i = 0; i < random_str_.size(); ++i)
	{
		if (random_str_my[i] != random_str_[i])
			return (false);
	}
	return (true);
}

bool vector_test::compare_riterators(std::vector<int> &vect1, ft::vector<int> &vect2)
{
	ritmy b = vect2.rbegin();
	for (rit a = vect1.rbegin(); a != vect1.rend(); ++a)
	{
		if (b == vect2.rend())
		{
			mistake += "find end of vector before it is realy ends";
			return (false);
		}
		if (*a != *b)
		{
			mistake += "element of my vect is ";
			mistake += std::to_string(*b);
			mistake += ", and standart is ";
			mistake += std::to_string(*a);
			return (false);
		}
		++b;
	}
	return (true);
}

bool vector_test::compare_iterators(std::vector<int> &vect1, ft::vector<int> &vect2)
{
	itmy b = vect2.begin();
	for (it a = vect1.begin(); a != vect1.end(); ++a)
	{
		if (b == vect2.end())
		{
			mistake += "find end of vector before it is realy ends";
			return (false);
		}
		if (*a != *b)
		{
			mistake += "element of my vect is ";
			mistake += std::to_string(*b);
			mistake += ", and standart is ";
			mistake += std::to_string(*a);
			return (false);
		}
		++b;
	}
	return (true);
}

void	vector_test::print_mistakes()
{
	std::cout << RED << "[FAILED]" << END << std::endl;
	std::cout << RED << mistake << END << std::endl;
	mistake.clear();
}

void vector_test::print_ok()
{
	std::cout << BLUE << "[  OK  ]" << END << std::endl;
}

void vector_test::start_vector_tests()
{
	std::cout << MAGENTA << "==================================start of vector's tests==================================\n\n" << END;
	std::cout << CYAN << "TEST OF CREATING VECTOR STRING-----------------------------------------------------" << END;
	vector_compare("test") ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF CREATING VECTOR OF INT-----------------------------------------------------" << END;
	vector_compare(1) ? print_ok() : print_mistakes();

	random_str_.reserve(1000);
	random_str_my.reserve(1000);
	std::cout << CYAN << "TEST OF VECTOR RESERVE-------------------------------------------------------------" << END;
	vector_compare("test") ? print_ok() : print_mistakes();

	std::vector<int>	vect1(10, 5);
	ft::vector<int>		vect2(10, 5);
	std::cout << CYAN << "TEST OF SECOND VECTOR CONSTRUCTOR--------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	ft::vector<int>		vect3(vect2);
	std::cout << CYAN << "TEST OF COPY CONSTRUCTOR-----------------------------------------------------------" << END;
	vector_compare(vect1, vect3) ? print_ok() : print_mistakes();

	vect1.insert(vect1.begin() + 7, 0);
	vect2.insert(vect2.begin() + 7, 0);
	std::cout << CYAN << "TEST OF FIRST VARIANT OF INSERT----------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.insert(vect1.begin() + 3, 5, 1);
	vect2.insert(vect2.begin() + 3, 5, 1);
	std::cout << CYAN << "TEST OF SECOND VARIANT OF INSERT---------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	std::vector<int>	vect5(5, 8);
	ft::vector<int>		vect6(5, 8);
	vect1.insert(vect1.begin() + 1, vect5.begin() + 1, vect5.begin() + 4);
	vect2.insert(vect2.begin() + 1, vect6.begin() + 1, vect6.begin() + 4);
	std::cout << CYAN << "TEST OF THIRD VARIANT OF INSERT----------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.erase(vect1.begin() + 1);
	vect2.erase(vect2.begin() + 1);
	std::cout << CYAN << "TEST OF FIRST VARIANT OF ERASE-----------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.erase(vect1.begin() + 2, vect1.begin() + 4);
	vect2.erase(vect2.begin() + 2, vect2.begin() + 4);
	std::cout << CYAN << "TEST OF SECOND VARIANT OF ERASE----------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.clear();
	vect2.clear();
	std::cout << CYAN << "TEST OF CLEAR----------------------------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.swap(vect5);
	vect2.swap(vect6);
	std::cout << CYAN << "TEST OF SWAP-----------------------------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.assign(vect5.begin() + 1, vect5.begin() + 5);
	vect2.assign(vect6.begin() + 1, vect6.begin() + 5);
	std::cout << CYAN << "TEST OF ASSIGN_1-------------------------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.assign(3, 4);
	vect2.assign(3, 4);

	std::cout << CYAN << "TEST OF ASSIGN_2-------------------------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF EXCEPTION IN AT------------------------------------------------------------" << END;
	try
	{
	vect2.at(12);
	}
	catch(std::exception &e)
	{
		print_ok();
		std::cout << BLUE <<  "[---------------------------------" << e.what()  << "--------------------------------]" << END << std::endl;
	}

	vect1.resize(20);
	vect2.resize(20);
	std::cout << CYAN << "TEST OF RESIZE---------------------------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();

	vect1.push_back(111);
	vect2.push_back(111);
	std::cout << CYAN << "TEST OF PUSH_BACK------------------------------------------------------------------" << END;
	vector_compare(vect1, vect2) ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF FRONT----------------------------------------------------------------------" << END;
	vect1.front() == vect2.front() ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF BACK-----------------------------------------------------------------------" << END;
	vect1.back() == vect2.back() ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF ITERATORS------------------------------------------------------------------" << END;
	compare_iterators(vect1, vect2) ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF REVERSE ITERATORS----------------------------------------------------------" << END;
	compare_riterators(vect1, vect2) ? print_ok() : print_mistakes();
	std::cout << std::endl;
}