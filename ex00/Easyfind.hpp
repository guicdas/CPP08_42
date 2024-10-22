#pragma once

#include <iostream>
#include <list>
#include <exception>
#include <algorithm>

class NoOccurrenceInContainerException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

template <typename T>
void	easyfind(T const & lst, int const n){
	std::list<int>::const_iterator itFound = find(lst.begin(), lst.end(), n);

	if (*itFound == *lst.end())
		throw (NoOccurrenceInContainerException());
	else
		std::cout << "Found an occurrence inside list at place " << *itFound << std::endl;

}

std::ostream &operator<<(std::ostream &os, std::list<int> const &l);
