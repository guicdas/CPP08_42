#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <cmath>

class Span{
	public:
		std::vector<int>	lst;
		unsigned int		nMax;
		Span( void );
		Span( unsigned int n );
		Span( const Span &b );
		Span& operator=( const Span &s );
		~Span( void );

	class NoSpanToBeFoundException : public std::exception
	{
		public:
				virtual const char *what() const throw(){return ("Error: No span can be found in this list!");};
	};
	class FullListException : public std::exception
	{
		public:
				virtual const char *what() const throw(){return ("Error: The list is full and cannot take anymore arguments!");};
	};

	void	addNumber( int n );
	int		shortestSpan( void ) const;
	int		longestSpan( void ) const;
};

void	listVector( std::vector<int> const vec );
