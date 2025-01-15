#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

int main()
{
	const Animal *sag = new Dog();
	const Animal *peshak = new Cat();
	const Animal *A = new Animal();


	std::cout << sag->getType() << " " << std::endl;
	std::cout << peshak->getType() << " " << std::endl;

	sag->makeSound();
	std::cout << "-------" << std::endl;
	peshak->makeSound();
	std::cout << "-------" << std::endl;
	A->makeSound();
	std::cout << "-------" << std::endl;
	delete A;
	delete sag;
	delete peshak;

	std::cout << std::endl;

	const WrongAnimal *B = new WrongAnimal();
	const WrongAnimal *C = new WrongCat();
	const WrongCat *D = new WrongCat();

	B->makeSound();
	std::cout << "-------" << std::endl;
	C->makeSound();
	std::cout << "-------" << std::endl;
	D->makeSound();
	std::cout << "-------" << std::endl;
	
	delete B;
	delete C;
	delete D;

	return (0);
}
