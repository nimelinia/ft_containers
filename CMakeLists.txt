cmake_minimum_required(VERSION 3.19)
project(project)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(project
		main.cpp
		vector.hpp
		Stack.hpp
		Map.hpp
		Iterator.hpp
		vector_test.cpp
		vector_test.hpp enable_if.hpp)
