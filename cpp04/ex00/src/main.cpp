#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main(void)
{
	{
		std::cout << "----------Regular Test----------" << std::endl;	
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "----------Wrong Cat Test----------" << std::endl;		
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongCat;
		meta->makeSound();
		j->makeSound();
	}
	return 0;
}
