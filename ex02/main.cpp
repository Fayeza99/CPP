#include "include/Dog.hpp"
#include "include/Cat.hpp"

int main(void)
{
	const int numAnimals = 12;
	AAnimal* animals[numAnimals];
	for (int i = 0; i < numAnimals; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	animals[0]->getBrain()->setIdea("Initial idea for Dog 0");
	std::cout << "Dog 0 Idea: " << animals[0]->getBrain()->getIdea(0) << std::endl;
	for (int i = 0; i < numAnimals; i++)
	{
		delete animals[i];
	}

	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();

	dog1->getBrain()->setIdea("Dog1 Idea 1");
	dog1->getBrain()->setIdea("Dog1 Idea 2");
	dog1->getBrain()->setIdea("Dog1 Idea 3");
	*dog2 = *dog1;
	dog1->getBrain()->setIdea("Dog1 Idea 4");
	dog1->getBrain()->setIdea("Dog1 Idea 5");
	dog2->getBrain()->setIdea("Dog2 Idea 1");
	std::cout << "dog1's Brain Ideas:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << dog1->getBrain()->getIdea(i) << std::endl;
	}

	std::cout << "dog2's Brain Ideas:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << dog2->getBrain()->getIdea(i) << std::endl;
	}
	delete dog2;
	delete dog1;

	return 0;
}
