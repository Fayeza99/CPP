#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <sstream>
#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	
	public:
		void announce(void);
		void setName(const std::string& name);
		Zombie();
		Zombie(std::string zomb);
		~Zombie();
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif
