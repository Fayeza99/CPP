#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string Type);
	WrongAnimal(const WrongAnimal& A);
	WrongAnimal& operator=(const WrongAnimal &A);
	virtual ~WrongAnimal();

	std::string getType() const;
	void makeSound() const;

};




#endif