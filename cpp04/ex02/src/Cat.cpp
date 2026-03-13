#include "../include/Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat Constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called!" << std::endl;
	brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "Cat Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete brain;
		brain = new Brain(*src.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called!" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes a sound miau" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (brain);
}
