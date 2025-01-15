#include "include/Ice.hpp"
#include "include/ICharacter.hpp"
#include <iostream>

Ice::Ice( void ) : AMateria("ice") {
	// std::cout << "\x1B[2m[Ice Default constructor called]\x1B[22m\n";
}

Ice::Ice( const Ice& c ) : AMateria(c)
{
	// std::cout << "\x1B[2m[Ice Copy constructor called]\x1B[22m\n";
	*this = c;
}

Ice& Ice::operator=( const Ice& c ) {
	// std::cout << "\x1B[2m[Ice Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		AMateria::operator=(c);
	}
	
	return (*this);
}

Ice::~Ice( void ) {
	// std::cout << "\x1B[2m[Ice Destructor called]\x1B[22m\n";
}

AMateria* Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()  << " *"<< std::endl;
}
