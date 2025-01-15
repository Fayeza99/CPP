#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class AForm;

class Intern {
private:
	AForm* shrubbery(const std::string& target);
	AForm* robotomy(const std::string& target);
	AForm* presidentialPardon(const std::string& target);
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);
};

typedef AForm* (Intern::*FormCreationFunc)(const std::string& target);
#endif



