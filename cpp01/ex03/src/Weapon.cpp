#include "../include/Weapon.hpp"


Weapon::Weapon(std::string type) 
{
	setType(type);
}
Weapon::~Weapon(){}

std::string Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
