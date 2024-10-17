#include "Span.hpp"

Span::Span( void ) : nMax(5){
	std::cout << "Span created by default!\n";
}

Span::Span( unsigned int num ) : nMax(num){
	std::cout << "Span created with a max of " << num << " integers" << std::endl;
}

Span::Span( const Span &s ){
	std::cout << "Span Copy created!\n";
	*this = s;
}

Span& Span::operator=( const Span &b ){
	std::cout << "Span Copy assigment called!\n";
	if (this != &b)
	{
		this->lst = b.lst;
		this->nMax = b.nMax;
	}

	return (*this);
}

Span::~Span( void ) {
	std::cout << "Span destroyed!\n";
}


void	Span::addNumber( int n ){
	if (this->lst.size() >= nMax)
		throw (FullListException());
	this->lst.push_back(n);
}

int	Span::shortestSpan( void ) const{
	std::vector<int> temp = this->lst;
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator itbefore;
	int	ret;

	if (this->lst.size() < 2)
		throw (NoSpanToBeFoundException());
	try
	{
		sort(temp.begin(), temp.end());
		it = temp.begin();
		itbefore = it++;
		ret = abs(*itbefore - *it);
		for (; it != temp.end(); it++)
		{
			if (ret > abs(*itbefore - *it))
			{
				std::cout << abs(*itbefore - *it)  << ": " << *itbefore << " - " << *it <<std::endl;
				ret = abs(*itbefore - *it);
			}
			itbefore = it;
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}

	return (ret);
}

int	Span::longestSpan( void ) const{
	std::vector<int> temp = this->lst;

	try
	{
		sort(temp.begin(), temp.end());
		// std::cout << "After sorting..." << std::endl;
		// listVector(temp);
		std::cout << temp.at(temp.size() - 1) << " - " << *temp.begin() << std::endl;
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	return (temp.at(temp.size() - 1) - *temp.begin());
}
