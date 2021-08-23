//
// Created by Streetmentioner Copycat on 8/23/21.
//

#include "map_test.hpp"

map_test::map_test()
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
		random_str_.insert(std::make_pair(len_str, str_));
		random_str_my.insert(ft::make_pair(len_str, str_));
		random_int_.insert(std::make_pair(number, len_str));
		random_int_my.insert(ft::make_pair(number, len_str));
		if (std::find(keys.begin(), keys.end(), len_str) != keys.end())
			std::cout << "key repit " << std::to_string(len_str) << std::endl;
		keys.push_back(len_str);
	}
}

map_test::~map_test()
{
}

bool map_test::map_compare(std::map<size_t, std::string> &stan, ft::map<size_t, std::string> &mine)
{
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
			mistake = "differences in the elems with key ";
			mistake += std::to_string(i);
			mistake += ", my is ";
			mistake += mine[i];
			mistake += ", and standard is ";
			mistake += stan[i];
			return (false);
		}
	}
	return (true);
}

bool map_test::map_compare(int other)
{
	(void ) other;
	if (random_int_.size() != random_int_my.size())
		return (false);
	for (size_t i = 0; i < keys.size(); ++i)
	{
		if (random_int_my[keys[i]] != random_int_[keys[i]])
			return (false);
	}
	return (true);
}

bool map_test::map_compare(const std::string &other)
{
	(void ) other;
	if (random_str_.size() != random_str_my.size())
	{
		mistake += "size of mine is ";
		mistake += std::to_string(random_str_my.size());
		mistake += ", and size of standard is ";
		mistake += std::to_string(random_str_.size());
		return (false);
	}
	for (size_t i = 0; i < keys.size(); ++i)
	{
		if (random_str_my[keys[i]] != random_str_[keys[i]])
		{
			mistake += "problem with key ";
			mistake += std::to_string(keys[i]);
			mistake += ". my value is ";
			mistake += random_str_my[keys[i]];
			mistake += ". and standard is ";
			mistake += random_str_[keys[i]];
			return (false);
		}
	}
	return (true);
}

//bool map_test::compare_riterators(std::map<size_t, std::string> &vect1, ft::map<size_t, std::string> &vect2)
//{
//	ritmy b = vect2.rbegin();
//	for (rit a = vect1.rbegin(); a != vect1.rend(); ++a)
//	{
//		if (b == vect2.rend())
//		{
//			mistake += "find end of map before it is realy ends";
//			return (false);
//		}
//		if (*a != *b)
//		{
//			mistake += "element of my vect is ";
//			mistake += std::to_string(*b);
//			mistake += ", and standart is ";
//			mistake += std::to_string(*a);
//			return (false);
//		}
//		++b;
//	}
//	return (true);
//}

//bool map_test::compare_iterators(std::map<size_t, std::string> &vect1, ft::map<size_t, std::string> &vect2)
//{
//	itmy b = vect2.begin();
//	for (it a = vect1.begin(); a != vect1.end(); ++a)
//	{
//		if (b == vect2.end())
//		{
//			mistake += "find end of map before it is realy ends";
//			return (false);
//		}
//		if (*a != *b)
//		{
//			mistake += "element of my vect is ";
//			mistake += std::to_string(*b);
//			mistake += ", and standart is ";
//			mistake += std::to_string(*a);
//			return (false);
//		}
//		++b;
//	}
//	return (true);
//}

void	map_test::print_mistakes()
{
	std::cout << RED << "[FAILED]" << END << std::endl;
	std::cout << RED << mistake << END << std::endl;
	mistake.clear();
//	random_str_my.print_map();
}

void map_test::print_ok()
{
	std::cout << BLUE << "[  OK  ]" << END << std::endl;
}

void map_test::start_map_tests()
{
	std::cout << MAGENTA << "==================================start of map's tests==================================\n\n" << END;
	std::cout << CYAN << "TEST OF CREATING MAP STRING--------------------------------------------------------" << END;
	map_compare("test") ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF CREATING MAP OF NUMBERS----------------------------------------------------" << END;
	map_compare(1) ? print_ok() : print_mistakes();

//	random_str_.reserve(1000);
//	random_str_my.reserve(1000);
//	std::cout << CYAN << "TEST OF map RESERVE-------------------------------------------------------------" << END;
//	map_compare("test") ? print_ok() : print_mistakes();
//
//	std::map<int>	vect1(10, 5);
//	ft::map<int>		vect2(10, 5);
//	std::cout << CYAN << "TEST OF SECOND map CONSTRUCTOR--------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	ft::map<int>		vect3(vect2);
//	std::cout << CYAN << "TEST OF COPY CONSTRUCTOR-----------------------------------------------------------" << END;
//	map_compare(vect1, vect3) ? print_ok() : print_mistakes();
//
//	vect1.insert(vect1.begin() + 7, 0);
//	vect2.insert(vect2.begin() + 7, 0);
//	std::cout << CYAN << "TEST OF FIRST VARIANT OF INSERT----------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.insert(vect1.begin() + 3, 5, 1);
//	vect2.insert(vect2.begin() + 3, 5, 1);
//	std::cout << CYAN << "TEST OF SECOND VARIANT OF INSERT---------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	std::map<int>	vect5(5, 8);
//	ft::map<int>		vect6(5, 8);
//	vect1.insert(vect1.begin() + 1, vect5.begin() + 1, vect5.begin() + 4);
//	vect2.insert(vect2.begin() + 1, vect6.begin() + 1, vect6.begin() + 4);
//	std::cout << CYAN << "TEST OF THIRD VARIANT OF INSERT----------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.erase(vect1.begin() + 1);
//	vect2.erase(vect2.begin() + 1);
//	std::cout << CYAN << "TEST OF FIRST VARIANT OF ERASE-----------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.erase(vect1.begin() + 2, vect1.begin() + 4);
//	vect2.erase(vect2.begin() + 2, vect2.begin() + 4);
//	std::cout << CYAN << "TEST OF SECOND VARIANT OF ERASE----------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.clear();
//	vect2.clear();
//	std::cout << CYAN << "TEST OF CLEAR----------------------------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.swap(vect5);
//	vect2.swap(vect6);
//	std::cout << CYAN << "TEST OF SWAP-----------------------------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.assign(vect5.begin() + 1, vect5.begin() + 5);
//	vect2.assign(vect6.begin() + 1, vect6.begin() + 5);
//	std::cout << CYAN << "TEST OF ASSIGN_1-------------------------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.assign(3, 4);
//	vect2.assign(3, 4);
//
//	std::cout << CYAN << "TEST OF ASSIGN_2-------------------------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	std::cout << CYAN << "TEST OF EXCEPTION IN AT------------------------------------------------------------" << END;
//	try
//	{
//		vect2.at(12);
//	}
//	catch(std::exception &e)
//	{
//		print_ok();
//		std::cout << BLUE <<  "[---------------------------------" << e.what()  << "--------------------------------]" << END << std::endl;
//	}
//
//	vect1.resize(20);
//	vect2.resize(20);
//	std::cout << CYAN << "TEST OF RESIZE---------------------------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//
//	vect1.push_back(111);
//	vect2.push_back(111);
//	std::cout << CYAN << "TEST OF PUSH_BACK------------------------------------------------------------------" << END;
//	map_compare(vect1, vect2) ? print_ok() : print_mistakes();
//	std::cout << CYAN << "TEST OF FRONT----------------------------------------------------------------------" << END;
//	vect1.front() == vect2.front() ? print_ok() : print_mistakes();
//	std::cout << CYAN << "TEST OF BACK-----------------------------------------------------------------------" << END;
//	vect1.back() == vect2.back() ? print_ok() : print_mistakes();
//	std::cout << CYAN << "TEST OF ITERATORS------------------------------------------------------------------" << END;
//	compare_iterators(vect1, vect2) ? print_ok() : print_mistakes();
//	std::cout << CYAN << "TEST OF REVERSE ITERATORS----------------------------------------------------------" << END;
//	compare_riterators(vect1, vect2) ? print_ok() : print_mistakes();
//	std::cout << std::endl;
}