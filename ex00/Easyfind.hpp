#pragma once

#include <iostream>
#include <list>
#include <exception>
#include <algorithm>

class NoOccurrenceInContainerException : public std::exception
{
	public:
			virtual const char *what() const throw(){return ("Error: No occurence found in container!");};
};

template <typename T>
void	easyfind(T const & lst, int const n){
	std::list<int>::const_iterator it = lst.begin();
	std::list<int>::const_iterator ite = lst.end();
	std::list<int>::const_iterator itFound;

	itFound = find(it, ite, n);
	if (*itFound == *ite)
		throw (NoOccurrenceInContainerException());
	else	
		std::cout << "Found an occurrence inside container at place " << *itFound << std::endl;

}

