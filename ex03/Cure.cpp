#include "include/Cure.hpp"
#include "include/ICharacter.hpp"
#include <iostream>

Cure::Cure( void ) : AMateria("cure") {
	// std::cout << "\x1B[2m[Cure Default constructor called]\x1B[22m\n";
}

Cure::Cure(const Cure& c ) : AMateria(c){
	// std::cout << "\x1B[2m[Cure Copy constructor called]\x1B[22m\n";
	*this = c;
}

Cure& Cure::operator=( const Cure& c ) {
	// std::cout << "\x1B[2m[Cure Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		AMateria::operator=(c);
	}
	return (*this);
}

Cure::~Cure( void ) {
	// std::cout << "\x1B[2m[Cure Destructor called]\x1B[22m\n";
}


AMateria* Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}

