#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string Type);
	Animal(const Animal& A);
	Animal& operator=(const Animal& A);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;






};




#endif