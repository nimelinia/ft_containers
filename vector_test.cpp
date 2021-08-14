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

void vector_test::start_vector_tests()
{
	std::cout << "=================start of vector's tests=================\n\n";
	std::cout << "my capacity_str: " << random_str_my.getMCapacity() << "   ||   standart capacity_str: " <<
			  random_str_.capacity() << std::endl;
	std::cout << "my size_str:     " << random_str_my.getMSize() << "   ||   standart size_str:     " <<
	random_str_.size() << std::endl;
	for (size_t i = 0; i < random_str_.size(); ++i)
	{
		std::cout << "my str:       " << random_str_my[i] << std::endl;
		std::cout << "standart str: " << random_str_[i] << std::endl;
	}
	random_str_.reserve(1000);
	random_str_my.reserve(1000);
	std::cout << "my capacity_str: " << random_str_my.getMCapacity() << "   ||   standart capacity_str: " <<
	random_str_.capacity() << std::endl;

	std::cout << "my capacity_int: " << random_int_my.getMCapacity() << "   ||   standart capacity_int: " <<
	random_int_.capacity() << std::endl;
	std::cout << "my size_int:     " << random_int_my.getMSize() << "   ||   standart size_int:     " <<
	random_int_.size() << std::endl;
	for (size_t i = 0; i < random_int_.size(); ++i)
	{
		std::cout << "my str:       " << random_int_my[i] << std::endl;
		std::cout << "standart str: " << random_int_[i] << std::endl;
	}

	std::vector<int>	vect1(10, 5);
	ft::vector<int>		vect2(10, 5);
	std::cout << "standart vector:      ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector:            ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	ft::vector<int>		vect3(vect2);
	std::cout << "\nmy vector after copy: ";
	for (size_t i = 0; i < vect3.size(); ++i)
		std::cout << vect3.at(i) << " ";
	ft::vector<int>		vect4;
	vect4 = vect3;
	std::cout << "\nmy vector after =:    ";
	for (size_t i = 0; i < vect4.size(); ++i)
		std::cout << vect4.at(i) << " ";

	vect1.insert(vect1.begin() + 7, 0);
	vect2.insert(vect2.begin() + 7, 0);
	std::cout << "\nstandart vector after insert: ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after insert:       ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";

	vect1.insert(vect1.begin() + 3, 5, 1);
	vect2.insert(vect2.begin() + 3, 5, 1);
	std::cout << "\nstandart vector after insert: ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after insert:       ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	std::vector<int>	vect5(5, 8);
	ft::vector<int>		vect6(5, 8);
	vect1.insert(vect1.begin() + 1, vect5.begin() + 1, vect5.begin() + 4);
	vect2.insert(vect2.begin() + 1, vect6.begin() + 1, vect6.begin() + 4);
	std::cout << "\nstandart vector after insert: ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after insert:       ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	vect1.erase(vect1.begin() + 1);
	vect2.erase(vect2.begin() + 1);
	std::cout << "\nstandart vector after erase:  ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after erase:        ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	vect1.erase(vect1.begin() + 2, vect1.begin() + 4);
	vect2.erase(vect2.begin() + 2, vect2.begin() + 4);
	std::cout << "\nstandart vector after erase:  ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after erase:        ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	vect1.clear();
	vect2.clear();
	std::cout << "\nstandart vector after clear:  ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after clear:        ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	vect1.swap(vect5);
	vect2.swap(vect6);
	std::cout << "\nstandart vector after swap:  ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after swap:        ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	vect1.assign(vect5.begin() + 1, vect5.begin() + 5);
	vect2.assign(vect6.begin() + 1, vect6.begin() + 5);
	std::cout << "\nstandart vector after assign:  ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after assign:        ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	vect1.assign(3, 4);
	vect2.assign(3, 4);
	std::cout << "\nstandart vector after assign:  ";
	for (size_t i = 0; i < vect1.size(); ++i)
		std::cout << vect1.at(i) << " ";
	std::cout << "\nmy vector after assign:        ";
	for (size_t i = 0; i < vect2.size(); ++i)
		std::cout << vect2.at(i) << " ";
	try
	{
//	vect1.at(12);
	vect2.at(12);
	}
	catch(std::exception &e)
	{
		std::cout << "\n" << e.what() << std::endl;
	}
}
