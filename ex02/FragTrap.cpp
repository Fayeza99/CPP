#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap " << name << " created with default constructor!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	health = 100;
	energy = 100;
	damage = 30;
	this->name = name;
	std::cout << "FragTrap " << name << " created with parameterized constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->health = other.health;
	this->energy = other.energy;
	this->damage = other.damage;
	*this = other;
	std::cout << "copy constructor called " << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << name << " assigned with copy assignment operator!" << std::endl;
	return *this;
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}


void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}