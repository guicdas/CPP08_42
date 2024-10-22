#include "Span.hpp"

int main( void ) {
	Span				sp(6);
	int					vecSize = 100000;

	try
	{
		sp.addNumber(2147483647);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	std::cout << sp;
	try
	{
		std::cout << "\nShortest:\n" << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	try
	{
		std::cout << "\nLongest:\n" << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}	
	std::cout << std::endl;
	
	std::vector<int> Vector;
	for(int i = 0; i < vecSize ;i++)
		Vector.push_back(std::rand() % 100 + 1);
	try
	{
		sp.addNumbers(Vector);
		std::cout << sp;
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	std::cout << std::endl;

	Span spa(vecSize);
	try
	{
		spa.addNumbers(Vector);
		// std::cout << spa;
		std::cout << "Span size: "<< spa.nMax << std::endl;
		spa.addNumber(2);
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}
	std::cout << std::endl;

}
