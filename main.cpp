//
// Created by Streetmentioner Copycat on 7/9/21.
//

#include <iostream>
#include <string>
#include <deque>
//#include <vector.hpp>
//#if 1 //CREATE A REAL STL EXAMPLE
//#include <map>
//#include <stack>
//#include <vector>
#include "vector_test.hpp"
#include "map_test.hpp"
#include "stack_test.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <map>

#include <stdlib.h>

#define MAX_RAM 4294967296



#define COUNT (MAX_RAM / (int)sizeof(Buffer))



int main(int argc, char** argv) {
	vector_test Test1;
	Test1.start_vector_tests();
	map_test	Test2;
	Test2.start_map_tests();
	stack_test	Test3;
	Test3.start_stack_tests();



//	ft::stack<int> my_stack;
//	my_stack.push(3);
//	my_stack.push(24);
//	std::cout << my_stack.size() << std::endl;
//	std::cout << my_stack.top() << std::endl;
//	my_stack.push(100000000);
//	std::cout << my_stack.top() << std::endl;
//	my_stack.pop();
//	std::cout << my_stack.size() << std::endl;
//	ft::stack<int> my_stack_2;
//	my_stack_2.push(1000000);
//	std::cout << (my_stack < my_stack_2) << std::endl;
//	my_stack_2.pop();
//	std::cout << my_stack_2.empty() << std::endl;

	return (0);
}