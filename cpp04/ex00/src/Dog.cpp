#include "../include/Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog Constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "Dog Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog makes a sound wuf" << std::endl;
}
