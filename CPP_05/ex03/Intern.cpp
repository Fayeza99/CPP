
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
}


AForm* Intern::shrubbery(const std::string& target){
	return (new ShrubberyCreationForm(target));
}


AForm* Intern::robotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}



AForm* Intern::presidentialPardon(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	struct FormPair {
		std::string formName;
		FormCreationFunc createFunc;
	};

	FormPair formPairs[] = {
		{"shrubbery creation", &Intern::shrubbery},
		{"robotomy request", &Intern::robotomy},
		{"presidential pardon", &Intern::presidentialPardon}
	};

	AForm* form = NULL;

	for (int i = 0; i < 3; i++) {
		if (formPairs[i].formName == name) {
			form = (this->*(formPairs[i].createFunc))(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cout << "Error: Intern could not create form with name '" << name << "'" << std::endl;
	return (0);
}

