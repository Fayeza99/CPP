#include "include/Animal.hpp"
#include "include/Dog.hpp"

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

Dog::Dog(const Dog& A) : Animal(A)
{
	std::cout << "Dog copied!" << std::endl;
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
