#include "../include/Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat Constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "Cat Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes a sound miau" << std::endl;
}
