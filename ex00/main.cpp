#include "Bureaucrat.hpp"

int main( void ) {
	
	try
	{
		Bureaucrat first("faiza", 5);
		Bureaucrat second("fai", 150);

		std::cout << first << std::endl;
		std::cout << second << std::endl;

		// second.decrementGrade();
		for (int i = 0; i < 5; i++)
		{
			first.incrementGrade();
			std::cout << first << std::endl;	
		}
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

