#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(std::string Type);
	WrongCat(const WrongCat &A);
	WrongCat &operator=(const WrongCat &A);
	~WrongCat();

	void makeSound()const;
};





#endif