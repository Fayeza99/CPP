#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150){

}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	isSigned = false;
	if (gradeToExecute < 1 || gradeToSign < 1)
	{
		throw GradeTooHighException();
	}
	if (gradeToExecute > 150 || gradeToSign > 150)
	{
		throw GradeTooLowException();
	}
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

void Form::beSigned(const Bureaucrat &b)
{
	// std::cout << "bureaucrat's grade: " << b.getGrade() << std::endl;
	// std::cout <<"form's grade " << gradeToSign << std::endl;
	if(b.getGrade() > gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	if (isSigned)
		std::cout << "form is already signed !" << std::endl;
	else
		isSigned = true;
}

const std::string& Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", isSigned: " << std::boolalpha << form.getIsSigned()
	   << ", gradeToSign: " << form.getGradeToSign() << ", gradeToExecute: " << form.getGradeToExecute();
	return os;
}

