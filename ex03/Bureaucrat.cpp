#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade){

	if(grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& c) : name(c.name), grade(c.grade) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& c)
{
	if (this != &c)
	{
		grade = c.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1) {
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) {
		throw GradeTooLowException();
	}
	grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}


void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << "." <<std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() << "." << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}