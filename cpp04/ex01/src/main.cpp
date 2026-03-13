#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

int main(void)
{
	{
		std::cout << "----------Array of Animals----------" << std::endl;
		Animal *animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			std::cout << animals[i]->getType() << std::endl;
			animals[i]->makeSound();
		}
		for (int i = 0; i < 10; i++)
		{
			delete animals[i];
		}
	}
	{
		std::cout << "----------Regular Test----------" << std::endl;
		Dog doggie;
		doggie.getBrain()->setIdea(1, "party rock in the house tonight");
		std::cout << doggie.getBrain()->getIdea(0) << std::endl;
		std::cout << doggie.getBrain()->getIdea(1) << std::endl;
		std::cout << doggie.getBrain()->getIdea(2) << std::endl;
	}
	{
		std::cout << "----------Copy Assignment----------" << std::endl;
		Cat kitty;
		Cat kitti;
		kitty.getBrain()->setIdea(42, "we have a special thought");
		kitti = kitty;
		std::cout << kitty.getBrain()->getIdea(42) << std::endl;
		std::cout << kitti.getBrain()->getIdea(42) << std::endl;	
		kitty.getBrain()->setIdea(42, "we have a special thought");
		kitti.getBrain()->setIdea(42, "we have a special thought which is different!");
		std::cout << kitty.getBrain()->getIdea(42) << std::endl;
		std::cout << kitti.getBrain()->getIdea(42) << std::endl;
	}
	{
		std::cout << "----------Copy Constructor----------" << std::endl;
		Dog doge;
		Dog doug(doge);
		doge.getBrain()->setIdea(8, "we have a special thought");
		std::cout << doge.getBrain()->getIdea(8) << std::endl;
		std::cout << doug.getBrain()->getIdea(8) << std::endl;	
		doge.getBrain()->setIdea(8, "we have a special thought");
		doug.getBrain()->setIdea(8, "we have a special thought which is different!");
		std::cout << doge.getBrain()->getIdea(8) << std::endl;
		std::cout << doug.getBrain()->getIdea(8) << std::endl;
	}
	return 0;
}
