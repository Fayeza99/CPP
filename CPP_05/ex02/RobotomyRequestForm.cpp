#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}


void	RobotomyRequestForm::execute(Bureaucrat const & ex) const
{
	if (!getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (ex.getGrade() > getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "noises" << std::endl;
	std::srand(time(0));
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " robotomization failed" << std::endl;
}
