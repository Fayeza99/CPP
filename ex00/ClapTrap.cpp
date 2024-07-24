#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << this->name << " assigned with copy assignment operator!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{

}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << this->name << " assigned with copy assignment operator!" << std::endl;
	// return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
	}
	else if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points left to attack!" << std::endl;
	}
	else
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target 
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap" << name << "has no hit points left and cannot take more damage" << std::endl;
	}
	else
	{
		if (amount >= hitPoints)
			hitPoints = 0;
		else
			hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount 
 		<< " points of damage, hit points now " << hitPoints << "!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoints)
		std::cout << "ClapTrap " << name << " has no energy to repair!" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " has no hit points left and cannot be repaired!" << std::endl;
	else
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount 
		<< " hit points, hit points now " << hitPoints << "!" << std::endl;
	}
}