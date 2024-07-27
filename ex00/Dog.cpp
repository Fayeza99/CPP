#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog created by default constructor" << std::endl;
}

Dog::Dog(std::string Type)
{
	this->type = Type;
	std::cout << "Dog created by parameterized constructor" << std::endl;
}

Dog::Dog(const Dog &A)
{
	this->type = A.type;
	std::cout << "Dog created by copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog &A)
{
	if (this != &A)
	{
		this->type = A.type;
	}
	std::cout << "Dog assigned!" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destroyed!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog barking!" << std::endl;
}
