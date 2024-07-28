#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog created by default constructor" << std::endl;
}

Dog::Dog(std::string Type)
{
	this->type = Type;
	this->brain = new Brain();
	std::cout << "Dog created by parameterized constructor" << std::endl;
}

Dog::Dog(const Dog& A) : Animal(A)
{
	this->brain = new Brain(*A.brain);
	std::cout << "Dog copied!" << std::endl;
}

Dog& Dog::operator=(const Dog &A)
{
	if (this != &A)
	{
		this->type = A.type;
		*brain = *A.brain;
	}
	std::cout << "Dog assigned!" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destroyed!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog barking!" << std::endl;
}

Brain* Dog::getBrain()
{
	return (brain);
}