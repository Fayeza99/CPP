#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
	target = "Default";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c) : AForm(c), target(c.target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& c)
{
	if (this != &c)
	{
		AForm::operator=(c);
		target = c.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

const std::string ShrubberyCreationForm::treePattern() const
{
	return
	"       *\n" \
      "      / \\\n" \
      "     / * \\\n" \
      "    / * * \\\n" \
      "   / * * * \\\n" \
      "  / * * * * \\\n" \
      " / * * * * * \\\n" \
      "/ * * * * * * \\\n" \
      "      |||\n" \
      "      |||\n";
}


void ShrubberyCreationForm::execute(Bureaucrat const & ex) const
{
	if (!getIsSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (ex.getGrade() > getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	else
	{
		const std::string filename = target + "_shrubbery";
		std::ofstream outfile(filename.c_str());
		if (!outfile)
		{
			std::cerr << "Error opening file for writing: " << filename << std::endl;
			exit (1);
		}
		outfile << ShrubberyCreationForm::treePattern();
		outfile.close();
	}
}
