#include "../include/Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog Constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called!" << std::endl;
	brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "Dog Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete brain;
		brain = new Brain(*src.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called!" << std::endl;
	delete  brain;
}

void Dog::makeSound() const
{
	std::cout << "Dog makes a sound wuf" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (brain);
}
