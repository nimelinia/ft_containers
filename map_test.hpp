//
// Created by Streetmentioner Copycat on 8/23/21.
//

#ifndef MAP_TEST_HPP
#define MAP_TEST_HPP

#include "map.hpp"
#include <map>
#include <vector>

# define RED		"\x1b[31;1m"
# define GREEN		"\x1b[32;1m"
# define YELLOW		"\x1b[33;1m"
# define BLUE		"\x1b[34;1m"
# define MAGENTA	"\x1b[35;1m"
# define CYAN		"\x1b[36;1m"
# define WHITE		"\x1b[40;1m"
# define END		"\x1b[0m"

class map_test
		{
		private:
			std::map<size_t, std::string>				random_str_;
			ft::map<size_t, std::string>				random_str_my;
			std::map<size_t, size_t>					random_int_;
			ft::map<size_t, size_t>						random_int_my;
			std::vector<size_t>							keys;

			std::string									mistake;

			typedef std::map<size_t, std::string>::iterator			it;
			typedef ft::map<size_t, std::string>::iterator			mit;
			typedef std::map<size_t, std::string>::reverse_iterator	rit;
			typedef ft::map<size_t, std::string>::reverse_iterator	mrit;

		public:
			map_test();

			virtual ~map_test();

			void								start_map_tests();

		private:
			bool								map_compare(const std::string &other);
			bool								map_compare(int other);
			bool 								map_compare(std::map<size_t, std::string> &stan, ft::map<size_t, std::string> &mine);
			bool								compare_iterators(std::map<size_t, std::string> &map1, ft::map<size_t, std::string> &map2);
			bool								compare_riterators(std::map<size_t, std::string> &map1, ft::map<size_t, std::string> &map2);
			void								print_mistakes();
			void								print_ok();
		};


#endif //MAP_TEST_HPP
