#include "Weapon.hpp"

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType (std::string newtype)
{
	type = newtype;
}

Weapon::Weapon(const std::string& type) : type(type) {}
Weapon::~Weapon(){}