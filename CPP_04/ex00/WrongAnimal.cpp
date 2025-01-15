#include "include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal created!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string Type) : type(Type)
{
	std::cout << "WrongAnimal created by parameterized constructor!" << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal& A)
{
	this->type = A.type;
	std::cout << "WrongAnimal copied!" << std::endl;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& A)
{
	if (this != &A)
	{
		this->type = A.type;
	}
	std::cout << "WrongAnimal assigned!" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound!" << std::endl;
}

