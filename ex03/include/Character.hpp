#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

#define SIZE 1000

class Character : public ICharacter
{
public:
	Character( void );
	Character(std::string name);
	Character( Character& c );
	Character& operator=( Character& c);
	~Character( void );

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);


private:
	std::string name;
	AMateria *inventory[4];
	AMateria *bin[SIZE];
	int	count;
	int	g_count;
	int		size;

};

#endif
