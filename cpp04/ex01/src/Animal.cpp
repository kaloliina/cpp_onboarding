#include "../include/Animal.hpp"

Animal::Animal() : type("DefaultType")
{
	std::cout << "Default Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal Copy Constructor called!" << std::endl;
	this->type = copy.type;
}

Animal& Animal::operator=(const Animal &src)
{
	std::cout << "Animal Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called!" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes an animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
