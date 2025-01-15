
#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with its weapon " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon" << std::endl;
}

HumanB::HumanB() : name("Default"), weapon(0) {}
HumanB::HumanB(const std::string& name) : name(name), weapon(0) {}
HumanB::HumanB(const std::string& name, Weapon *weapon) : name(name), weapon(weapon) {}
HumanB::~HumanB(){}
void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}