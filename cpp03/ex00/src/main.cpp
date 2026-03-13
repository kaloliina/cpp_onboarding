#include "../include/ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Default constructor test ===" << std::endl;
	ClapTrap a;  // should print "Default Constructor called!"

	std::cout << "\n=== Parameterized constructor test ===" << std::endl;
	ClapTrap b("Lupu"); // should print "Parameterized Constructor called!"

	std::cout << "\n=== Copy constructor test ===" << std::endl;
	ClapTrap c(b); // should print "Copy Constructor called!"

	std::cout << "\n=== Copy assignment operator test ===" << std::endl;
	a = b; // should print "Copy Assignment called!"

	std::cout << "\n=== Energy exhaustion test ===" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		b.attack("target");
	}

	std::cout << "\n=== Damage test ===" << std::endl;
	b.takeDamage(5);  // should reduce hitPoints
	b.takeDamage(20); // should drop below 0 (dead)

	std::cout << "\n=== Attack when dead test ===" << std::endl;
	b.attack("ghost"); // should say can't attack when dead

	std::cout << "\n=== Repair test ===" << std::endl;
	c.beRepaired(5);  // should consume energy, heal
	c.takeDamage(10);
	c.beRepaired(10);

	std::cout << "\n=== Repair when out of energy ===" << std::endl;
	for (int i = 0; i < 11; i++) {
		c.beRepaired(1);
	}

	std::cout << "\n=== Repair when dead test ===" << std::endl;
	c.takeDamage(999);  // kill it
	c.beRepaired(10);   // should say can't repair when dead

	return 0;
}
