#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
	if (N <= 0)
	{
		std::cout << "Number of zombies is 0 or less!" << std::endl;
		return (nullptr);
	}
	Zombie *zombieHorde;
	zombieHorde = new Zombie[N];
	while (i < N)
	{
		zombieHorde[i].setName(name);
		i++;
	}
	return (zombieHorde);
}
