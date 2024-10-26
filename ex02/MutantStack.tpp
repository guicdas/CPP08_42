#include "MutantStack.hpp"

template <typename S>
MutantStack<S>::MutantStack( void ) : std::stack<S>() {}

template <typename S>
MutantStack<S>::MutantStack( const MutantStack &s ) : std::stack<S>(s) {}

template <typename S>
MutantStack<S>& MutantStack<S>::operator=( const MutantStack<S> &s ){
	if (this == &s)
		return ;

	std::stack<S>::operator=(s);
	return (*this);
}

template <typename S>
MutantStack<S>::~MutantStack( void ) {
	std::cout << "Destroyed MutantStack with " << this->size() << " elements!" << std::endl;
}

template <typename S>
typename std::stack<S>::container_type::iterator			MutantStack<S>::begin( void )	{return (this->c.begin());}
template <typename S>
typename std::stack<S>::container_type::iterator			MutantStack<S>::end( void )		{return (this->c.end());}
template <typename S>
typename MutantStack<S>::cMutantIterator		MutantStack<S>::cbegin( void )	const{return (this->c.begin());}
template <typename S>
typename MutantStack<S>::cMutantIterator		MutantStack<S>::cend( void )	const{return (this->c.end());}
template <typename S>
typename MutantStack<S>::MutantReverseIterator	MutantStack<S>::rbegin( void )	{return (this->c.rbegin());}
template <typename S>
typename MutantStack<S>::MutantReverseIterator	MutantStack<S>::rend( void )	{return (this->c.rend());}
template <typename S>
typename MutantStack<S>::cMutantReverseIterator	MutantStack<S>::crbegin( void )	const{return (this->c.rbegin());}
template <typename S>
typename MutantStack<S>::cMutantReverseIterator	MutantStack<S>::crend( void )	const{return (this->c.rend());}