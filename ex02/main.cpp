#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat jeff("Jeff", 5);
		Bureaucrat bob("Bob", 5);

		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm rob("asdas");
		PresidentialPardonForm par("pp");
		jeff.signForm(shrubbery);
		jeff.executeForm(shrubbery);
		jeff.signForm(rob);
		jeff.executeForm(rob);
		bob.signForm(par);
		bob.executeForm(par);

		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}