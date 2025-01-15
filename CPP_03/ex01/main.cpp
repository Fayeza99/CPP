#include "ScavTrap.hpp"

int main ( void )
{

	ScavTrap scavyy;

	ScavTrap x("wallE");

	scavyy = x;
	scavyy.attack("Heroo");
	scavyy.beRepaired(1);
	scavyy.guardGate();
	scavyy.takeDamage(120);
	scavyy.guardGate();

	return (0);
}
