#include "Zombie.hpp"



int main()
{
	int i = 0;
	int N;

	std::cout << "Enter a Number ";
	while (true)
	{
		std::cin >> N;
		if (std::cin.fail() || N <= 0)
		{
			if (std::cin.eof())
			{
				std::cerr << "Input terminated by EOF (Ctrl+D)." << std::endl;
				return 1;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid input.\nPlease enter a positive number: ";
		}
		else
		{
			if (std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "Invalid input.\nPlease enter a positive number without any trailing characters: ";
			}
			else
				break;
		}
	}
	std::string name = "Zombie";
	Zombie *zombie_horde = zombieHorde(N, name);
	while (i < N)
	{
		zombie_horde[i].announce();
		i++;
	}
	delete[] zombie_horde;
	return (0);
}
