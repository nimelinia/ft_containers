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
#include "map.hpp"
//namespace ft = std;
//#else
//#include <Map.hpp>
//#include <Stack.hpp>
//#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
//#define BUFFER_SIZE 4096
//
//struct Buffer
//{
//	int idx;
//	char buff[BUFFER_SIZE];
//};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

//template<typename T>
//class MutantStack : public ft::stack<T>
//{
//public:
//	MutantStack() {}
//	MutantStack(const MutantStack<T>& src) { *this = src; }
//	MutantStack<T>& operator=(const MutantStack<T>& rhs)
//	{
//		this->c = rhs.c;
//		return *this;
//	}
//	~MutantStack() {}
//
//	typedef typename ft::stack<T>::container_type::iterator iterator;
//
//	iterator begin() { return this->c.begin(); }
//	iterator end() { return this->c.end(); }
//};

int main(int argc, char** argv) {
	vector_test Test1;
	Test1.start_vector_tests();
	ft::map<int, std::string>	map_;
	ft::pair<int, std::string>	pair1 = ft::make_pair(1, "lalalla");
	map_.insert(pair1);
	map_.print_map();
	map_.insert(ft::make_pair(2, "hello"));
	map_.print_map();
	map_.insert(ft::make_pair(0, "hellfo"));
	map_.print_map();
	map_.insert(ft::make_pair(-1, "ahellfo"));
	map_.print_map();
	map_.insert(ft::make_pair(3, "hellfo"));
	map_.print_map();
//	map_.erase(0);
//	map_.print_map();
	map_.insert(ft::make_pair(3, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(8, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(4, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(-27, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(-11, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(115, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(5, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(22, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(13, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(23, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(24, "lala"));
	map_.print_map();
	map_.insert(ft::make_pair(25, "lala"));
	map_.print_map();

//	void print(treeNode* root, int deep) {
//		if (!ft_null(root)) {
//			print(root->_right, deep + 1);
//			if (root->_col == BLACK)
//				std::cout << "\e[34m";
//			else if (root->_col == RED)
//				std::cout << "\e[33m";
//			for (int i = 0; i < deep; i++)
//				std::cout << "    ";
//			if (!ft_null(root))
//				std::cout << root->_val.first << "\e[0m" << "\n";
//			print(root->_left, deep + 1);
//		}
//		std::cout << "\e[0m";

//	if (argc != 2)
//	{
//		std::cerr << "Usage: ./test seed" << std::endl;
//		std::cerr << "Provide a seed please" << std::endl;
//		std::cerr << "Count value:" << COUNT << std::endl;
//		return 1;
//	}
//	const int seed = atoi(argv[1]);
//	srand(10);
//
//	ft::vector<std::string> vector_str;
//	ft::vector<int> vector_int;
////	ft::stack<int> stack_int;
//	ft::vector<Buffer> vector_buffer;
//	ft::vector<int> vec1;
//	vec1.push_back(1);
//	ft::vector<int> vec2;
//	vec2.push_back(2);
//	vec1.swap(vec2);
//	std::vector<int> vec3;
//	vec3.push_back(1);
//	std::vector<int> vec4;
//	vec4.push_back(2);
//	vec3.swap(vec4);
//	std::cout << vec1[0] << " " << vec2[0] << " " << vec3[0] << " " << vec4[0] << std::endl;
////	std::cout << vec1.front() << std::endl;
////	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
////	ft::map<int, int> map_int;
//
//	vector_str.push_back("hello");
//	vector_str.push_back("world");
//	vector_str.push_back("lalala");
//	vector_str.pop_back();
//////	ft::vector<std::string>::iterator iter = vector_str.begin();
//////	vector_str.insert(iter, "vstavka posle hello");
////
//	for (size_t i = 0; i < vector_str.size(); ++i)
//		std::cout << vector_str.at(i) << std::endl;
//	std::cout << *(vector_str.begin()) << std::endl;
//	vector_str.clear();
//	for (size_t i = 0; i < vector_str.size(); ++i)
//		std::cout << " " << vector_str.at(i);
//	for (int i = 0; i < COUNT; i++)
//	{
//		vector_buffer.push_back(Buffer());
//	}
//
//	for (int i = 0; i < COUNT; i++)
//	{
//		const int idx = rand() % COUNT;
//		vector_buffer[idx].idx = 5;
//	}
//	ft::vector<Buffer>().swap(vector_buffer);
//
//	try
//	{
//		for (int i = 0; i < COUNT; i++)
//		{
//			const int idx = rand() % COUNT;
//			vector_buffer.at(idx);
//			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
//		}
//	}
//	catch(const std::exception& e)
//	{
//		//NORMAL ! :P
//	}

//	for (int i = 0; i < COUNT; ++i)
//	{
//		map_int.insert(ft::make_pair(rand(), rand()));
//	}

	int sum = 0;
//	for (int i = 0; i < 10000; i++)
//	{
//		int access = rand();
//		sum += map_int[access];
//	}
//	std::cout << "should be constant with the same seed: " << sum << std::endl;
//
//	{
//		ft::map<int, int> copy = map_int;
//	}
//	MutantStack<char> iterable_stack;
//	for (char letter = 'a'; letter <= 'z'; letter++)
//		iterable_stack.push(letter);
//	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
//	{
//		std::cout << *it;
//	}
//	std::cout << std::endl;
	return (0);
}