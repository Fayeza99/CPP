#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	this->health = 100;
	this->energy = 50;
	this->damage = 50;
	std::cout << "ScavTrap " << this->name << " created with default constructor!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->name = name;
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap " << this->name << " created with parameterized constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	this->name = other.name;
	this->health = other.health;
	this->damage = other.damage;
	this->energy = other.energy;
	*this = other;
	std::cout << "copy constructor has been called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->health =other.health;
		this->damage = other.damage;
		this->energy = other.energy;
	}
	return (*this);
}


void	ScavTrap::attack(const std::string &target)
{
	if(!health)
		std::cout << "ScavTrap " << name << " is not alive" << std::endl;
	if (!energy)
		std::cout << "ScavTrap " << name << " cannot attack because it has no energy" << std::endl;
	else
	{
		energy--;
		std::cout << "ScavTrap " << name << " attacks " << target 
		<< ", causing " << damage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}

