#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include <iostream>
#include <string>
#include "Brain.hpp"


class Dog : public AAnimal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(std::string Type);
	Dog(const Dog &A);
	Dog& operator=(const Dog &A);
	~Dog();

	void makeSound() const;
	Brain* getBrain();
};



#endif