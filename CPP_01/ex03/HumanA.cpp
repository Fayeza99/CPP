#include "Weapon.hpp"
#include "HumanA.hpp"

void HumanA::attack() const
{
	std::cout << name << " attacks with its weapon " << weapon.getType() << std::endl;
}
HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon){}
HumanA::~HumanA(){}