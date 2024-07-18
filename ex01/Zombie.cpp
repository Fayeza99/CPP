#include "Zombie.hpp"
void Zombie::announce(void)
{
	std::cout<< name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name)
{
	Zombie *zom = new Zombie(name);
	return (zom);
}
Zombie::Zombie(std::string zomb)
{
	name = zomb;
}

Zombie::~Zombie(){
	std::cout << name <<" is destroyed" << std::endl;
}
