#include "ClapTrap.hpp"


int main()
{
	ClapTrap claptrap1("Clappy");
	ClapTrap claptrap2(claptrap1);
	ClapTrap claptrap3;
	claptrap3 = claptrap1;

	claptrap1.attack("target1");
	claptrap1.takeDamage(3);
	claptrap1.beRepaired(5);
	claptrap1.attack("target2");
	claptrap1.takeDamage(15);
	claptrap1.beRepaired(3);

	return 0;
}

