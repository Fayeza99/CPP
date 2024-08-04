#include "include/Dog.hpp"
#include "include/Cat.hpp"

int main()
{
	int num = 12;
	Animal* animals[num];

	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}
	animals[0]->getBrain()->setIdea("First idea for the Dog");
	std::cout << animals[0]->getBrain()->getIdea(0) << std::endl;

	for (int i = 0; i < num; i++) {
		delete animals[i];
	}

	Dog dogA;
	dogA.getBrain()->setIdea("Idea A1");
	dogA.getBrain()->setIdea("Idea A2");
	dogA.getBrain()->setIdea("Idea A3");

	Dog dogB = dogA;
	dogA.getBrain()->setIdea("Idea A4");
	dogA.getBrain()->setIdea("Idea A5");
	dogB.getBrain()->setIdea("Idea B1");

	std::cout << "dogA's Brain Ideas:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << dogA.getBrain()->getIdea(i) << std::endl;
	}

	std::cout << "dogB's Brain Ideas:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << dogB.getBrain()->getIdea(i) << std::endl;
	}
	return (0);
}
