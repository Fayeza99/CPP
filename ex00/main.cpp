
#include "Zombie.hpp"

int main(void)
{
	Zombie *zom;
	zom = newZombie("Foo");
	zom->announce();
	randomChump("Moo");
	delete zom;
	return (0);
}
