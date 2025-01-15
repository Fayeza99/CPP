#include "include/Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal created " << std::endl;
}


Animal::Animal(std::string Type) : type(Type)
{
	std::cout << "Standard Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal& A)
{
	this->type = A.type;
	std::cout << "Animal constructed by copy constructor " << std::endl;
}

Animal& Animal::operator=(const Animal &A)
{
	if (this != &A)
	{
		this->type = A.type;
	}
	std::cout << "Animal assigned!" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

std::string	Animal::getType() const {
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal Sound " << std::endl;
}


