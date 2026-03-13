#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default Constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Parameterized Constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (hitPoints <= 0)
	{
		std::cout << "FragTrap " << name << " cannot high five from the grave" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " shares some high fives in the midst of a battle!" << std::endl;
}
