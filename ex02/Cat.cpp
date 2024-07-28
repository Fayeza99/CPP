#include "Cat.hpp"
#include "AAnimal.hpp"


Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(std::string Type)
{
	this->type = Type;
	this->brain = new Brain();
	std::cout << "Cat created ny parameterized constructor!" << std::endl;
}


Cat::Cat(const Cat& A) : AAnimal(A)
{
	brain = new Brain(*A.brain);
	std::cout << "Cat copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& A)
{
	if (this != &A)
	{
		AAnimal::operator=(A);
		*brain = *A.brain;
	}
	std::cout << "Cat assigned!" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}


Brain* Cat::getBrain()
{
	return (brain);
}

