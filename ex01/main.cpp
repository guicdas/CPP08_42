#include "Span.hpp"

int main( void ) {
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(-9);
		sp.addNumber(11);
		sp.addNumber(15);
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	sp.listSpan();
	std::cout << "\nshortest:\n" << sp.shortestSpan() << std::endl;
	std::cout << "\nLongest:\n" << sp.longestSpan() << std::endl;
}
