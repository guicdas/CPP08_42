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
				virtual const char *what() const throw();
	};
	class FullListException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};
	class NotAnIntException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};
	class NotEnoughSpaceException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};

	void		addNumber( long long n );
	long long	shortestSpan( void ) const;
	long long	longestSpan( void ) const;
	void		addNumbers( std::vector<int> const &n );
};

std::ostream &operator<<(std::ostream & os, Span const &b);