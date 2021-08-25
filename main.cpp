//
// Created by Streetmentioner Copycat on 7/9/21.
//

#include <iostream>
#include <string>
#include <deque>
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

	return (0);
}