#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *A = new Animal();
	const Animal *sag = new Dog();
	const Animal *peshak = new Cat();


	std::cout << sag->getType() << " " << std::endl;
	std::cout << peshak->getType() << " " << std::endl;

	sag->makeSound();
	peshak->makeSound();
	A->makeSound();
	delete A;
	delete sag;
	delete peshak;

	std::cout << std::endl;

	const WrongAnimal *B = new WrongAnimal();
	const WrongAnimal *C = new WrongCat();
	const WrongCat *D = new WrongCat();
	
	B->makeSound();
	C->makeSound();
	D->makeSound();
	
	delete B;
	delete C;
	delete D;

	return (0);
}
