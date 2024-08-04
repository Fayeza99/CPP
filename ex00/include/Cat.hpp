#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &A);
	Cat &operator=(const Cat& A);
	~Cat();

	void makeSound() const;


};



#endif