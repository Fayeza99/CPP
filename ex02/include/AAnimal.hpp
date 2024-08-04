#ifndef AANIMAL_HPP
#define AANIMAL_HPP


#include <iostream>
#include <string>
#include "Brain.hpp"
class AAnimal
{
protected:
	std::string type;


public:
	AAnimal();
	AAnimal(std::string Type);
	AAnimal(const AAnimal& A);
	AAnimal& operator=(const AAnimal& A);
	virtual ~AAnimal();


	std::string getType() const;
	virtual void makeSound() const = 0;
	virtual Brain*	getBrain();


};



#endif