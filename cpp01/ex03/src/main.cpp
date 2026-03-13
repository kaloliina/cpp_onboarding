/* The assignment asked when it’s best to use a pointer vs a reference for a weapon. 
There are two main reasons: 

- HumanA takes the weapon in its constructor and will always have it. 
  References must be bound to an existing object at construction and cannot be NULL, 
  so a reference works here.

- HumanB does not always have a weapon. References cannot be changed to point to NULL 
  or reassigned, so a pointer is needed to represent an optional weapon.

So basically if we removed the weapon object creation on main, we wouldn't have the object
weapon and nothing to reference to.
*/
#include "../include/Weapon.hpp"
#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon club = Weapon("banana");
		HumanB karoliina("Karoliina");
		karoliina.attack();
		karoliina.setWeapon(club);
		karoliina.attack();
		club.setType("multiple bananas!");
		karoliina.attack();
	}
	return 0;
}
