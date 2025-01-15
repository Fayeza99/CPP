#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& c);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& c);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
	const std::string treePattern() const ;

};


#endif