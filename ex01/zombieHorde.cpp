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
		std::ostringstream oss;
		oss << name << (i + 1);
		zombie_horde[i].setName(oss.str());
		i++;
	} 
	return (zombie_horde);
}

