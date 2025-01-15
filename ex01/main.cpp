
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
	Bureaucrat a("Jeff", 5);
	Bureaucrat b("Tom", 40);
	Bureaucrat c("Bob", 1);

	Form f1("Form1", 130, 100);
	Form f2("Form2", 1, 1);

	// a.signForm(f1);
	b.signForm(f1);
	// c.signForm(f1);
	}
	catch (std::exception& e)
	{
		std::cout <<"dasdsf";
		std::cerr << e.what() << '\n';
	}
	return 0;
}
