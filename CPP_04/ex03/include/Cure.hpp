#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( const Cure& c );
	Cure& operator=( const Cure& c);
	~Cure( void );
	AMateria* clone() const;
	void use(ICharacter& target);

private:

};

#endif
