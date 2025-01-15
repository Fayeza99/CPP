#include "include/AMateria.hpp"
#include <iostream>
#include "include/ICharacter.hpp"
AMateria::AMateria( void ) : type ("(null)"){
	// std::cout << "\x1B[2m[AMateria Default constructor called]\x1B[22m\n";
}

AMateria::AMateria( const AMateria& c ) {
	// std::cout << "\x1B[2m[AMateria Copy constructor called]\x1B[22m\n";
	this->type = c.type;
	// *this = c;
}

AMateria& AMateria::operator=( const AMateria& c )
{
	// std::cout << "\x1B[2m[AMateria Copy assignment operator called]\x1B[22m\n";
	if (this != &c)
	{
		return (*this);
	}
	// (void) c;
	return (*this);
}

AMateria::~AMateria( void ) {
	// std::cout << "\x1B[2m[AMateria Destructor called]\x1B[22m\n";
}


AMateria::AMateria(std::string const & type) : type (type) {}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target){
	(void)target;
}