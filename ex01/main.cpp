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
	std::deque<int> deque;
	try
	{
		clock_t start = clock();
		spa.addNumbers(Vector);
		start = clock() - start;
		// std::cout << spa;
		std::cout << "Span size: "<< spa.nMax << " elements in " <<  static_cast<float>(start) / CLOCKS_PER_SEC<< " seconds." << std::endl;
		//spa.addNumber(2);
		start = clock();
		for(int i = 0; i < vecSize ;i++)
			deque.push_back(std::rand() % 100 + 1);
		//deque.insert(deque.begin(), Vector.begin(), Vector.end());
		start = clock() - start;
		// std::cout << spa;
		std::cout << "deque size: "<< deque.size() << " elements in " <<  static_cast<float>(start) / CLOCKS_PER_SEC<< " seconds." << std::endl;
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}
	std::cout << std::endl;

}
