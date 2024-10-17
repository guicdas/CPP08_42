#include "Span.hpp"

void	listVector( std::vector<int> const vec ){
	std::vector<int>::const_iterator it = vec.begin();
	std::vector<int>::const_iterator ite = vec.end();

	for (int i = 0; it != ite ; it++)
		std::cout << i++ << ": " << *it << std::endl;
}

int main( void ) {
	Span sp(6);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(-9);
		sp.addNumber(11);
		sp.addNumber(15);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	listVector(sp.lst);
	std::cout << "\nShortest:\n" << sp.shortestSpan() << std::endl;
	std::cout << "\nLongest:\n" << sp.longestSpan() << std::endl;
}
