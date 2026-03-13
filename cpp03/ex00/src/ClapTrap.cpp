#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default Constructor called!" << std::endl;
}

/*Name could be in the initializer list*/
ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0)
{
	this->name = name;
	std::cout << "Parameterized Constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Copy Constructor called!" << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energyPoints = src.energyPoints;
		this->attackDamage = src.attackDamage;		
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;
}

/*
- Hit point refers to health
- Energy points is energy
*/
void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack because they are dead!" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack because they ran out of energy!" << std::endl;
		return ;
	}
	energyPoints = energyPoints - 1;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead and beaten to the ground!" << std::endl;
	}
	hitPoints = hitPoints - amount;
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot repair itself when dead!" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot repair itself because they don't have any energy left!" << std::endl;
		return ;
	}
	energyPoints = energyPoints - 1;
	hitPoints = hitPoints + amount;
	std::cout << "ClapTrap " << name << " returns to its den to licks its wounds, gaining " << amount << " health points back." << std::endl;
}
