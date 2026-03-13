#include "../include/Zombie.hpp"

void testZombies(int nbr_zombies, std::string name, std::string test_type)
{
	std::cout << test_type << std::endl;
	Zombie *Zombie = zombieHorde(nbr_zombies, name);	
	if (Zombie == nullptr)
	{
		return ;
	}
	for (int i = 0; i < nbr_zombies; i++)
	{
		Zombie[i].announce();		
	}
	delete[] Zombie;
	std::cout << "-----------------------------" << std::endl;	
}

int main(void)
{
	testZombies(10, "Karoliina", "10 zombies");
	testZombies(100, "Karoliina", "100 zombies");
	testZombies(10, "", "Zombies with no name");
	testZombies(-1, "Karoliina", "Negative amount of zombies");
	testZombies(0, "Karoliina", "Zero amount of zombies");
	return (0);
}
