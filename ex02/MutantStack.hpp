#pragma once

#include <iostream>
#include <stack>

template <typename S>
class MutantStack : public std::stack<S>
{
	public:
		MutantStack( void ) : std::stack<S>() {};
		MutantStack( const MutantStack &s ) : std::stack<S>(s) {};
		MutantStack& operator=( const MutantStack &s ){
			if (this != &s)
				std::stack<S>::operator=(s);
			return (*this);
		};
		~MutantStack( void ) {std::cout << "Destroyed MutantStack with " << this->size() << " elements!" << std::endl;};

		typedef typename std::stack<S>::container_type::iterator MutantIterator;
		typedef typename std::stack<S>::container_type::const_iterator cMutantIterator;
		typedef typename std::stack<S>::container_type::reverse_iterator MutantReverseIterator;
		typedef typename std::stack<S>::container_type::const_reverse_iterator cMutantReverseIterator;

		MutantIterator			begin( void )		{return (this->c.begin());};
		MutantIterator			end( void )			{return (this->c.end());};
		cMutantIterator			begin( void ) const	{return (this->c.begin());};
		cMutantIterator			end( void )	const	{return (this->c.end());};
		MutantReverseIterator	rbegin( void )		{return (this->c.rbegin());};
		MutantReverseIterator	rend( void )		{return (this->c.rend());};
		cMutantReverseIterator	rbegin( void ) const{return (this->c.rbegin());};
		cMutantReverseIterator	rend( void ) const	{return (this->c.rend());};

};

template <typename S>
std::ostream &operator<<(std::ostream &os, MutantStack<S> &s) {
	typename MutantStack<S>::MutantIterator it = s.begin();
	typename MutantStack<S>::cMutantIterator constIt = s.begin();
	typename MutantStack<S>::MutantReverseIterator Rit = s.rbegin();
	typename MutantStack<S>::cMutantReverseIterator RconstIt = s.rbegin();

	os << "Printing MutantStack with " << s.size() << " elements:\n";
	for (int i = 0; it != s.end(); ++it)
		os << "i: " << i++ << "\t" << *it << "\n";
	os << "Printing const MutantStack with " << s.size() << " elements:\n";
	for (int i = 0; constIt != s.end(); ++constIt)
		os << "i: " << i++ << "\t" << *constIt << "\n";
	os << "Printing MutantStack in reverse with " << s.size() << " elements:\n";
	for (int i = 0; Rit != s.rend(); ++Rit)
		os << "i: " << i++ << "\t" << *Rit << "\n";
	os << "Printing const MutantStack in reverse with " << s.size() << " elements:\n";
	for (int i = 0; RconstIt != s.rend(); ++RconstIt)
		os << "i: " << i++ << "\t" << *RconstIt << "\n";

	return (os);
}