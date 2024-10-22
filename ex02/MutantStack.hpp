#pragma once

#include <iostream>
#include <stack>

template <typename S>
class MutantStack : public std::stack<S>
{
	public:
		MutantStack( void );
		MutantStack( const MutantStack<S> &s );
		MutantStack<S>& operator=( const MutantStack<S> &s );
		~MutantStack( void );

		typedef typename std::stack<S>::container_type::iterator MutantIterator;
		typedef typename std::stack<S>::container_type::const_iterator cMutantIterator;
		typedef typename std::stack<S>::container_type::reverse_iterator MutantReverseIterator;
		typedef typename std::stack<S>::container_type::const_reverse_iterator cMutantReverseIterator;

	MutantIterator			begin( void );
	MutantIterator			end( void );
	cMutantIterator			cbegin( void )	const;
	cMutantIterator			cend( void )	const;
	MutantReverseIterator	rbegin( void );
	MutantReverseIterator	rend( void );
	cMutantReverseIterator	crbegin( void ) const;
	cMutantReverseIterator	crend( void )	const;

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

#include "MutantStack.tpp"