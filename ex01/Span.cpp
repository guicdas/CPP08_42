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

Span& Span::operator=( const Span &s ){
	std::cout << "Span Copy assigment called!\n";
	if (this != &s)
	{
		this->lst = s.lst;
		this->nMax = s.nMax;
	}

	return (*this);
}

Span::~Span( void ) {
	std::cout << "Span destroyed!\n";
}


void	Span::addNumber( long long n ){
	if (this->lst.size() >= nMax)
		throw (FullListException());
	if (n > 2147483647 || n < -2147483648)
		throw (NotAnIntException());
	this->lst.push_back(n);
}

void	Span::addNumbers( std::vector<int> const &n ){
	if (n.size() > this->nMax)
		throw (NotEnoughSpaceException());
	this->lst.insert(this->lst.end(), n.begin(), n.end());
	this->nMax = this->lst.size();
}

long long	Span::shortestSpan( void ) const{
	std::vector<int>					temp = this->lst;
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	itbefore;
	long long							ret;

	if (this->lst.size() < 2)
		throw (NoSpanToBeFoundException());
	std::sort(temp.begin(), temp.end());
	it = temp.begin();
	itbefore = it++;
	ret = std::llabs(static_cast<long long> (*itbefore) - static_cast<long long>(*it));
	for (; it != temp.end(); it++)
	{
		if (ret > std::llabs(static_cast<long long> (*itbefore) - static_cast<long long>(*it)))
		{
			ret = std::llabs(static_cast<long long> (*itbefore) - static_cast<long long>(*it));
			std::cout << ret  << ": " << *itbefore << " - " << *it <<std::endl;
		}
		itbefore = it;
	}

	return (ret);
}

long long	Span::longestSpan( void ) const{
	std::vector<int>	temp = this->lst;
	long long			ret;

	if (this->lst.size() < 2)
		throw (NoSpanToBeFoundException());
	std::sort(temp.begin(), temp.end());
	std::cout << temp.at(temp.size() - 1) << " + " << std::llabs(*temp.begin()) << std::endl;
	ret = std::llabs(static_cast<long long>(temp.at(temp.size() - 1)) - static_cast<long long>(*temp.begin()));

	return (ret);
}

const char *Span::NoSpanToBeFoundException::what(void) const throw(){
	return ("Error: No span can be found in this list!");
}

const char *Span::FullListException::what(void) const throw(){
	return ("Error: The list is full and cannot take anymore arguments!");
}

const char *Span::NotAnIntException::what(void) const throw(){
	return ("Error: Argument is not an integer!");
}

const char *Span::NotEnoughSpaceException::what(void) const throw(){
	return ("Error: Span does not have suficient storage!");
}

std::ostream &operator<<(std::ostream & os, Span const &s){
	std::vector<int>::const_iterator it = s.lst.begin();

	for (int i = 0; it != s.lst.end() ; it++)
		os << i++ << ": " << *it << std::endl;
		
	return (os);
}