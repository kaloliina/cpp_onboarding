#include "../include/HumanA.hpp"
/*Since weapon &weapon is a reference member, references cannot exist without being
bound to an object. So weapon must be initalized at the moment the HumanA object is created,
one cannot assign it to later. That's why we use initializer list here. So references
const members etc should be initalized. In HumanB situation, the member variables
are default constructed before the body runs and then you assign new values inside.
So when HumanA gets constructed, the weapon member in the HumanA class cannot exist unbound, there is no default
or NULL for it so it absolutely needs to have a valid reference.*/
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA() { }

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
