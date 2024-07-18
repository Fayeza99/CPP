#include "Zombie.hpp"



int main()
{
	int i = 0;
	int N = 5;
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
