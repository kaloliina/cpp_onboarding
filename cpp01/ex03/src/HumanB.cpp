#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = nullptr;
}

HumanB::~HumanB() { }

void HumanB::attack() const
{
	if (weapon != nullptr)
		std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
	else
		std::cout << name << " unfortunately does not want to attack without a weapon!" << std::endl;		
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
