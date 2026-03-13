#include "../include/Zombie.hpp"

Zombie::Zombie() { }

Zombie::~Zombie()
{
	std::cout << name << " failed to find brains and ended its own existence." << std::endl;
}
void Zombie::announce () const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
