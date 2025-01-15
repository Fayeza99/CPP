#include "include/WrongCat.hpp"


WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat created!" << std::endl;
}

WrongCat::WrongCat(std::string Type)
{
	this->type = Type;
	std::cout << "WrongCat created by parameterized constructor!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copied!" << std::endl;
}


WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat assigned!" << std::endl;
	return *this;
}


WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong meow!" << std::endl;
}