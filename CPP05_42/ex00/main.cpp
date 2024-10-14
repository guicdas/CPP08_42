#include "Bureaucrat.hpp"

int main( void ){
	std::cout << "//\tTESTING EXCEPTIONS:\t\n\n";
	try
	{
		Bureaucrat tooHigh("tooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("tooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "//\tTESTING INCREMENT:\t\n//HIGHEST\n";
	try
	{
		Bureaucrat highest("highest", 1);
		std::cout << highest << std::endl;
		highest.IncrementBureaucratGrade();
		highest.DecrementBureaucratGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "//LOWEST\n";
	try
	{
		Bureaucrat lowest("lowest", 150);
		std::cout << lowest << std::endl;
		lowest.DecrementBureaucratGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "//NORMAL\n";
	try
	{
		Bureaucrat normal("normal", 100);
		std::cout << normal << std::endl;
		normal.DecrementBureaucratGrade();
		normal.IncrementBureaucratGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}