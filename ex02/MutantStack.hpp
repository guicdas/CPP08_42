#pragma once

#include <iostream>
#include <stack>

template <typename S>
class MutantStack
{
	private:
		S	lst;

	public:
		MutantStack( void ) : S(std::stack());
		MutantStack( const MutantStack &s ){this = s};
		MutantStack& operator=( const MutantStack &s ){{return (*this)};};
		~MutantStack( void ) {std::cout << "Destroyed MutantStack!" << std::endl};
};