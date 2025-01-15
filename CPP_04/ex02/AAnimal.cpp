#include "include/AAnimal.hpp"


AAnimal::AAnimal()
{
	this->type = "AAnimal";
	std::cout << "AAnimal created!" << std::endl;
}

AAnimal::AAnimal(std::string Type)
{
	this->type = Type;
	std::cout << "AAnimal created by parameterized constructor!" << std::endl;
}


AAnimal::AAnimal(const AAnimal& A) : type(A.type)
{
	std::cout << "AAnimal copied!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& A)
{
	if (this != &A)
	{
		type = A.type;
	}
	std::cout << "AAnimal assigned!" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed!" << std::endl;
}


std::string AAnimal::getType() const
{
	return type;
}


Brain*	AAnimal::getBrain()
{
	return (NULL);
}
