#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;

	public:

	void setWeapon(Weapon& newWeapon);
	HumanB();
	HumanB(const std::string& name);
	HumanB(const std::string& name, Weapon *weapon);
	~HumanB();
	void attack() const;
};

#endif