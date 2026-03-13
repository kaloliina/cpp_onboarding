#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal Constructor called" << std::endl;
	type = "DefaultType";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal Copy Constructor called!" << std::endl;
	this->type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a non-cat sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
