#include "include/MateriaSource.hpp"
#include "include/AMateria.hpp"

#include <iostream>

MateriaSource::MateriaSource( void ) : count(0)
{
	for(int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	// std::cout << "\x1B[2m[MateriaSource Default constructor called]\x1B[22m\n";
}


MateriaSource::MateriaSource( MateriaSource& c )
{
	for (int i = 0; i < 4; i++)
	{
		if (c.inventory[i])
			inventory[i] = c.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	// std::cout << "\x1B[2m[MateriaSource Copy constructor called]\x1B[22m\n";
	// *this = c;
}



MateriaSource& MateriaSource::operator=( const MateriaSource& c ) {

	// std::cout << "\x1B[2m[MateriaSource Copy assignment operator called]\x1B[22m\n";
	if (this != &c) {
		// for(int i = 0; i < count; i++)
		// {
		// 	inventory[i] = NULL;
		// }
		for(int i = 0; i < count; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (c.inventory[i])
				inventory[i] = c.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		count = c.count;
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	for(int i = 0; i < count; i++)
	{
		delete inventory[i];
	}
	// std::cout << "\x1B[2m[MateriaSource Destructor called]\x1B[22m\n";
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "no materia to equip " << std::endl;
		return;
	}
	if (count == 4)
	{
		std::cout << "no place to equip " << m->getType() << std::endl;
		delete m;
		// return;
	}
	else
	{
		inventory[count] = m;
		count++;
		
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < count && inventory[i]; i++)
	{
		if (inventory[i]->getType() == type)
		{
			return (inventory[i]->clone());
		}
	}
	return (0);
}

