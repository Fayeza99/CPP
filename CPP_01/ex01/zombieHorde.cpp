#include "Zombie.hpp"


void Zombie::setName(const std::string& name)
{
	this->name = name;
}

Zombie::Zombie() : name("") {}
Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombie_horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		// std::string zombie_name = name + std::to_string(i + 1);
		zombie_horde[i].setName(name);
		i++;
	} 
	return (zombie_horde);
}

