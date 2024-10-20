#include "Span.hpp"

int main( void ) {
	Span sp(6);

	try
	{
		sp.addNumber(-2147483647);
		sp.addNumber(-2147483647);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	std::cout << sp;
	try
	{
		std::cout << "\nShortest:\n" << sp.shortestSpan() << std::endl;
		std::cout << "\nLongest:\n" << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}	
	
	int				vecSize = 100000;
	std::vector<int> Vector(vecSize, std::rand() % 5 + 1);
	try
	{
		sp.addNumbers(Vector);
		// std::cout << sp;
		std::cout << sp;
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}
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

/*
Test your Span at least with a minimum of 10 000 numbers. More would be
even better.
to fill your Span using a range of iterators.
Implement a member function to add many numbers to your Span in one call.
*/