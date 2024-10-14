#pragma once

#include <iostream>

class Bureaucrat{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat( void );
		Bureaucrat(std::string name, int grade);
		Bureaucrat( const Bureaucrat &b );
		Bureaucrat& operator=( const Bureaucrat &b );
		~Bureaucrat( void );

	std::string		getName( void ) const;
	int				getGrade( void ) const;
	void 			IncrementBureaucratGrade( void );
	void 			DecrementBureaucratGrade( void );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);
