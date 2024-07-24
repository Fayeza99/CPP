#include "ScavTrap.hpp"

int main()
{
	std::cout << "Creating ClapTrap objects..." << std::endl;
	ClapTrap claptrap1("wallee");
	ClapTrap claptrap2(claptrap1);
	ClapTrap claptrap3; 
	claptrap3 = claptrap1;
	
	claptrap1.attack("target1");
	claptrap1.takeDamage(3);
	claptrap1.beRepaired(5);
	claptrap1.attack("target2");
	claptrap1.takeDamage(15);
	claptrap1.beRepaired(3);
	
	std::cout << "\nCreating ScavTrap objects..." << std::endl;
	ScavTrap scavtrap1("hero");
	ScavTrap scavtrap2(scavtrap1);
	ScavTrap scavtrap3;
	scavtrap3 = scavtrap1;
	
	scavtrap1.attack("target1");
	scavtrap1.takeDamage(30);
	scavtrap1.beRepaired(20);
	scavtrap1.guardGate();
	scavtrap1.attack("target2");
	scavtrap1.takeDamage(120);
	scavtrap1.beRepaired(50);
	
	return 0;
}