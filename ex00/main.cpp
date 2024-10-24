#include "Easyfind.hpp"

int main( void ) {
	std::list<int> intList;

	try
	{
		easyfind(intList, 5);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}

	for (int i = 0; i < 9; i++)
		intList.push_back(i);

	std::cout << intList << std::endl;
	try
	{
		easyfind(intList, 5);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
		try
	{
		easyfind(intList, 125);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	try
	{
		easyfind(intList, 8);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	try
	{
		intList.push_back(5);
		easyfind(intList, 5);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
}
