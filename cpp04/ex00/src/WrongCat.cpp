#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat Constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy Constructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		WrongAnimal::operator=(src);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat makes a sound WUF" << std::endl;
}
