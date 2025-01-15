#include "include/Character.hpp"
#include "include/AMateria.hpp"
#include "include/ICharacter.hpp"
#include <iostream>

Character::Character( void ) : name("Default"), count(0), g_count(0) , size(0) {
	for(int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	// std::cout << "\x1B[2m[Character Default constructor called]\x1B[22m\n";
}

Character::Character(std::string name) : name(name), count(0), g_count(0), size(0) {
	for(int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character( Character& c )
{
	for(int i = 0; i < 4; i++)
	{
		if (c.inventory[i])
			inventory[i] = c.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	count = c.count;
	name = c.getName();
	g_count = c.g_count;
	size = c.size;
	// std::cout << "\x1B[2m[Character Copy constructor called]\x1B[22m\n";
	// *this = c;
}

Character& Character::operator=( Character& c ) {
	// if (this != &c) {
		for(int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (c.inventory[i])
				inventory[i] = c.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		this->name = c.name;
		this->count = c.count;
		this->g_count = c.g_count;
		this->size = c.size;
	// }
	// std::cout << "\x1B[2m[Character Copy assignment operator called]\x1B[22m\n";
	return (*this);
}

Character::~Character( void ) {
	for(int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
		// inventory[i] = NULL;
	}
	for(int i = 0; i < g_count; i++)
	{
		if (bin[i])
			delete bin[i];
	}
	// std::cout << "[Character Destructor called]\n";
}

std::string const & Character::getName() const{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cerr << "no materia to equip " << std::endl;
		delete m;
		return;
	}
	if (count == 4)
	{
		std::cerr << "no place to equip " << m->getType() << std::endl;
		delete m;
		return;
	}
	if (size >= SIZE)
	{
		std::cerr << "Maximum inventory use have been reached! " << m->getType() << std::endl;
		delete m;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == m) {
			std::cout << name << " already equipped this Materia\n";
			delete m;
			return ;
		}
	}
	std::cout << name << " equipped "<< m->getType() << "\n";
	// if (inventory[count])
	// 	delete inventory[count];
	inventory[count] = m;
	count++;
	size++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= count)
	{
		std::cout << "slot is out of range " << std::endl;
		inventory[idx] = NULL;
		return ;
	}
	bin[g_count++] = inventory[idx];
	std::cout << name << " unequipped "<< inventory[idx]->getType() << "\n";
	while (idx < (count - 1))
	{
		inventory[idx] = inventory[idx + 1];
		idx++;
	}
	inventory[idx] = NULL;
	count--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= count)
	{
		std::cout << "slot is out of range " << std::endl;
		return;
	}
	inventory[idx]->use(target);
}
