#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->health = 10;
	this->energy = 10;
	this->damage = 10;
	std::cout << "ClapTrap " << this->name << " created with default constructor!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->health = 10;
	this->energy = 10;
	this->damage = 10;
	std::cout << "ClapTrap " << this->name << " created with parameterized constructor!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		health = other.health;
		energy = other.energy;
		damage = other.damage;
	}
	std::cout << "ClapTrap " << this->name << " assigned with copy assignment operator!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		health = other.health;
		energy = other.energy;
		damage = other.damage;
	}
	std::cout << "ClapTrap " << this->name << " assigned with copy assignment operator!" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (energy == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
	}
	else if (health == 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points left to attack!" << std::endl;
	}
	else
	{
		energy--;
		std::cout << "ClapTrap " << name << " attacks " << target 
		<< ", causing " << damage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (health == 0)
	{
		std::cout << "ClapTrap" << name << "has no hit points left and cannot take more damage" << std::endl;
	}
	else
	{
		if (amount >= health)
			health = 0;
		else
			health -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount 
 		<< " points of damage, hit points now " << health << "!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!energy)
		std::cout << "ClapTrap " << name << " has no energy to repair!" << std::endl;
	else if (health == 0)
		std::cout << "ClapTrap " << name << " has no hit points left and cannot be repaired!" << std::endl;
	else
	{
		energy--;
		health += amount;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount 
		<< " hit points, hit points now " << health << "!" << std::endl;
	}
}