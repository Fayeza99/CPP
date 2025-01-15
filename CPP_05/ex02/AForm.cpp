#include "AForm.hpp"
#include"Bureaucrat.hpp"



AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150){

}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
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

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low!";
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}


void AForm::beSigned(const Bureaucrat &b)
{
	std::cout << "bureaucrat's grade: " << b.getGrade() << std::endl;
	std::cout <<"AForm's grade " << gradeToSign << std::endl;
	if(b.getGrade() > gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	if (isSigned)
		std::cout << "AForm is already signed !" << std::endl;
	else
		isSigned = true;
}

const std::string& AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << "AForm " << AForm.getName() << ", isSigned: " << std::boolalpha << AForm.getIsSigned()
	   << ", gradeToSign: " << AForm.getGradeToSign() << ", gradeToExecute: " << AForm.getGradeToExecute();
	return os;
}
