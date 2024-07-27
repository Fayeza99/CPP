#include "Cat.hpp"


Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(std::string Type)
{
	this->type = Type;
	std::cout << "Cat created ny parameterized constructor!" << std::endl;
}


Cat::Cat(const Cat &A)
{
	this->type = A.type;
	std::cout << "Cat created by copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Cat assigned!" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}


