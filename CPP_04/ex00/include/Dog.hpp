#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>



class Dog : public Animal
{
public:
	Dog();
	Dog(std::string Type);
	Dog(const Dog &A);
	Dog& operator=(const Dog &A);
	~Dog();

	void makeSound() const;

};



#endif