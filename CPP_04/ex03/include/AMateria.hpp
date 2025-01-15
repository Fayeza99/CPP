#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
public:
	AMateria( void );
	AMateria( const AMateria& c );
	AMateria& operator=(const AMateria& c);
	virtual ~AMateria( void );

	AMateria(std::string const & type);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;

};

#endif
