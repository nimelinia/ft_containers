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
	for (size_t i = 0; i < keys.size(); ++i)
	{
		if (stan[keys[i]] != mine[keys[i]])
		{
			mistake = "differences in the elems with key ";
			mistake += std::to_string(keys[i]);
			mistake += ", my is ";
			mistake += mine[keys[i]];
			mistake += ", and standard is ";
			mistake += stan[keys[i]];
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

bool map_test::compare_riterators(std::map<size_t, std::string> &map1, ft::map<size_t, std::string> &map2)
{
	mrit b = map2.rbegin();
	for (rit a = map1.rbegin(); a != map1.rend(); ++a)
	{
		if (a == map1.rbegin())
			continue;
		if (b == map2.rend())
		{
			mistake += "find end of map before it is realy ends";
			return (false);
		}
		if (a->first != b->first || a->second != b->second)
		{
			mistake += "element of my map with key ";
			mistake += std::to_string(b->first);
			mistake += " and value ";
			mistake += b->second;
			mistake += ", and standart with key ";
			mistake += std::to_string(a->first);
			mistake += " and value ";
			mistake += a->second;
			return (false);
		}
		++b;
	}
	return (true);
}

bool map_test::compare_iterators(std::map<size_t, std::string> &map1, ft::map<size_t, std::string> &map2)
{
	mit b = map2.begin();
	for (it a = map1.begin(); a != map1.end(); ++a)
	{
		if (b == map2.end())
		{
			mistake += "find end of map before it is realy ends";
			return (false);
		}
		if (a->first != b.GetNode()->value->first || a->second != b.GetNode()->value->second)
		{
			mistake += "element of my map with key ";
			mistake += std::to_string(b.GetNode()->value->first);
			mistake += " and value ";
			mistake += b.GetNode()->value->second;
			mistake += ", and standart with key ";
			mistake += std::to_string(a->first);
			mistake += " and value ";
			mistake += a->second;
			return (false);
		}
		++b;
	}
	return (true);
}

void	map_test::print_mistakes()
{
	std::cout << RED << "[FAILED]" << END << std::endl;
	std::cout << RED << mistake << END << std::endl;
	mistake.clear();
}

void map_test::print_ok()
{
	std::cout << BLUE << "[  OK  ]" << END << std::endl;
}

void map_test::start_map_tests()
{
	std::cout << MAGENTA << "===================================start of map's tests====================================\n\n" << END;
	std::cout << CYAN << "TEST OF CREATING MAP STRING--------------------------------------------------------" << END;
	map_compare("test") ? print_ok() : print_mistakes();
	std::cout << CYAN << "TEST OF CREATING MAP OF NUMBERS----------------------------------------------------" << END;
	map_compare(1) ? print_ok() : print_mistakes();

	ft::map<size_t, std::string> map_it(random_str_.begin(), random_str_.end());
	std::cout << CYAN << "TEST OF ITERATOR'S CONSTRUCTOR-----------------------------------------------------" << END;
	map_compare(random_str_, map_it) ? print_ok() : print_mistakes();

	ft::map<size_t, std::string> map_copy(map_it);
	std::cout << CYAN << "TEST OF COPY'S CONSTRUCTOR---------------------------------------------------------" << END;
	map_compare(random_str_, map_copy) ? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF [] ------------------------------------------------------------------------" << END;
	(random_str_[keys[0]] == random_str_my[keys[0]]) ? print_ok() : print_mistakes();

	random_str_[keys[0]] = "testtest";
	random_str_my[keys[0]] = "testtest";
	std::cout << CYAN << "TEST OF [] ASSIGNMENT--------------------------------------------------------------" << END;
	map_compare("test") ? print_ok() : print_mistakes();

	random_str_.insert(std::make_pair(0, "testovaya phraza"));
	random_str_my.insert(ft::make_pair(0, "testovaya phraza"));
	std::cout << CYAN << "TEST OF INSERT---------------------------------------------------------------------" << END;
	map_compare("test") ? print_ok() : print_mistakes();

	random_str_.erase(0);
	random_str_my.erase(0);
	std::cout << CYAN << "TEST OF ERASE----------------------------------------------------------------------" << END;
	map_compare("test") ? print_ok() : print_mistakes();

	size_t key;
	if (random_str_.lower_bound(0) != random_str_.end())
		key = random_str_.lower_bound(0)->first;
	random_str_.erase(random_str_.lower_bound(0));
	random_str_my.erase(random_str_my.lower_bound(0));
	if (random_str_.lower_bound(0) != random_str_.end())
		keys.erase(std::find(keys.begin(), keys.end(), key));
	std::cout << CYAN << "TEST OF ERASE BY ITERATOR----------------------------------------------------------" << END;
	map_compare("test") ? print_ok() : print_mistakes();

//	if (random_str_.lower_bound(14) != random_str_.end())
//		key = random_str_.lower_bound(14)->first;
//	random_str_.erase(random_str_.lower_bound(14));
//	random_str_my.erase(random_str_my.lower_bound(14));
//	if (random_str_.lower_bound(14) != random_str_.end())
//		keys.erase(std::find(keys.begin(), keys.end(), key));
//	std::cout << CYAN << "TEST OF ERASE BY ITERATOR_2--------------------------------------------------------" << END;
//	map_compare("test") ? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF COUNT----------------------------------------------------------------------" << END;
	(random_str_.count(12) == random_str_my.count(12)) ? print_ok() : print_mistakes();

	if (random_str_.lower_bound(20) != random_str_.end())
		key = random_str_.lower_bound(20)->first;
	random_str_.insert(random_str_.lower_bound(20), std::make_pair(21, "test_test_test"));
	random_str_my.insert(random_str_my.lower_bound(20), ft::make_pair(21, "test_test_test"));
	if (random_str_.lower_bound(20) != random_str_.end())
		keys.push_back(key);
	std::cout << CYAN << "TEST OF INSERT AND LOWER BOUND-----------------------------------------------------" << END;
	map_compare("test") ? print_ok() : print_mistakes();


	map_it.swap(random_str_my);
	std::cout << CYAN << "TEST OF SWAP-----------------------------------------------------------------------" << END;
	map_compare(random_str_, map_it)? print_ok() : print_mistakes();
	random_str_my.swap(map_it);

	std::cout << CYAN << "TEST OF EQUAL RANGE----------------------------------------------------------------" << END;
	(random_str_.equal_range(15).first->second == random_str_my.equal_range(15).first->second) ? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF ITERATORS------------------------------------------------------------------" << END;
	compare_iterators(random_str_, random_str_my)? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF REVERSE ITERATORS----------------------------------------------------------" << END;
	compare_riterators(random_str_, random_str_my)? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF EMPTY----------------------------------------------------------------------" << END;
	(random_str_.empty() == random_str_my.empty()) ? print_ok() : print_mistakes();

	random_str_.clear();
	random_str_my.clear();
	std::cout << CYAN << "TEST OF CLEAR----------------------------------------------------------------------" << END;
	(random_str_.empty() == random_str_my.empty()) ? print_ok() : print_mistakes();

	std::cout << CYAN << "TEST OF NON-EQUALITY---------------------------------------------------------------" << END;
	(map_it != random_str_my) ? print_ok() : print_mistakes();

	ft::map<size_t, std::string> map_2(map_it);
	std::cout << CYAN << "TEST OF EQUALITY-------------------------------------------------------------------" << END;
	(map_it == map_2) ? print_ok() : print_mistakes();

	map_it[0] = "a";
	std::cout << CYAN << "TEST OF LEXICOGRAPHICAL COMPARE----------------------------------------------------" << END;
	(map_it < map_2) ? print_ok() : print_mistakes();
	std::cout << std::endl;
}