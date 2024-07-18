#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout<< name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string zomb)
{
	name = zomb;
}

Zombie::~Zombie(){}