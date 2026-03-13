#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->isGuarding = false;
	std::cout << "ScavTrap Default Constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->isGuarding = false;
	std::cout << "ScavTrap Parameterized Constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	this->isGuarding = false;
	std::cout << "ScavTrap Copy Constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->isGuarding = false;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack because they are dead!" << std::endl;
		return ;
	}
	if (isGuarding == true)
	{
		std::cout << "ScavTrap " << name << " cannot attack when its sole focus is on guarding the gate!" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack because they ran out of energy!" << std::endl;
		return ;
	}
	energyPoints = energyPoints - 1;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cannot possibly guard the gate when already dead!" << std::endl;
		return ;
	}
	if (isGuarding == true)
	{
		std::cout << "ScavTrap " << name << " continues to guard the gate in honor!" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " does not have any energy left in order to guard the gate!" << std::endl;
		return ;
	}
	energyPoints = energyPoints - 1;
	isGuarding = true;
	std::cout << "ScavTrap " << name << " begins to guard the gate!" << std::endl;
}
