#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
public:
	MateriaSource( void );
	MateriaSource( MateriaSource& c );
	MateriaSource& operator=(const MateriaSource& c);
	~MateriaSource( void );

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);


private:
	AMateria *inventory[4];
	int 	 count;
};

#endif
