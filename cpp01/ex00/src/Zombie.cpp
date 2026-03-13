#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie()
{
	std::cout << name << " failed to find brains and ended its own existence." << std::endl;
}
void Zombie::announce () const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
