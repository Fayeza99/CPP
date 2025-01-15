
#include "Zombie.hpp"

int main(void)
{
	Zombie *zom;
	zom = newZombie("Foo");
	zom->announce();
	delete zom;
	randomChump("Moo");
	return (0);
}
