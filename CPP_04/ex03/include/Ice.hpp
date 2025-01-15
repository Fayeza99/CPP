#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice& c );
	Ice& operator=( const Ice& c);
	~Ice( void );
	AMateria* clone() const;
	void use(ICharacter& target);

private:

};

#endif
