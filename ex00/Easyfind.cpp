#include "Easyfind.hpp"

const char *NoOccurrenceInContainerException::what(void) const throw(){
	return ("Error: No occurence found in container!");
}

std::ostream &operator<<(std::ostream &os, std::list<int> const &l) {
	std::list<int>::const_iterator it = l.begin();

	os << "Printing list with " << l.size() << " elements:\n";
	for (int i = 0; it != l.end(); ++it)
		os << "i: " << i++ << "\t" << *it << "\n";

	return (os);
}