cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(project
		main.cpp
		vector.hpp
        stack.hpp
		map.hpp
		Iterator.hpp
		vector_test.cpp
		vector_test.hpp
		enable_if.hpp
		pair.hpp
		map_test.cpp
		map_test.hpp
		stack_test.cpp
		stack_test.hpp
		redblacktree.hpp)
