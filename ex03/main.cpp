#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


// int main() {
// 	try
// 	{
// 		Bureaucrat jeff("Jeff", 5);
// 		Bureaucrat bob("Bob", 150);
		
// 		ShrubberyCreationForm shrubbery("home");
// 		RobotomyRequestForm robotomy("Alice");
// 		PresidentialPardonForm pardon("Trillian");
		
// 		jeff.signForm(shrubbery);
// 		jeff.executeForm(shrubbery);
		
// 		bob.signForm(robotomy);
// 		bob.executeForm(robotomy);
		
// 		jeff.signForm(robotomy);
// 		jeff.executeForm(robotomy);
		
// 		jeff.signForm(pardon);
// 		jeff.executeForm(pardon);
		
// 	}
// 	catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// 	return 0;
// }


int main()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
			delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		if (rrf)
			delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Trillian");
		if (rrf)
			delete rrf;

		rrf = someRandomIntern.makeForm("unknown form", "unknown");
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
