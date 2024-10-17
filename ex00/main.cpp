#include "Easyfind.hpp"

int main( void ) {
	std::list<int> intList;

	for (int i = 0; i < 9; i++)
		intList.push_back(i);

	std::list<int>::const_iterator it = intList.begin();
	std::list<int>::const_iterator ite = intList.end();

	for (int i = 0; it != ite; it++)
		std::cout << i++ << ": " << *it << std::endl;
	std::cout << std::endl;
	//e se tiver vazia
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
