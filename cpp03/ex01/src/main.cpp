#include "../include/ScavTrap.hpp"

int main(void)
{
	std::cout << "\n=== ScavTrap Default Constructor test ===" << std::endl;
	ScavTrap s1;

	std::cout << "\n=== ScavTrap Parameterized Constructor test ===" << std::endl;
	ScavTrap s2("Tupu");

	std::cout << "\n=== ScavTrap Copy Constructor test ===" << std::endl;
	ScavTrap s3(s2);

	std::cout << "\n=== ScavTrap Assignment Operator test ===" << std::endl;
	s1 = s2;

	std::cout << "\n=== Attack test (normal) ===" << std::endl;
	s2.attack("Target A"); // should consume energy and print attack message

	std::cout << "\n=== Attack while guarding test ===" << std::endl;
	s2.guardGate();        // enters guard mode
	s2.attack("Target B"); // should refuse to attack (isGuarding = true)

	std::cout << "\n=== Guarding twice test ===" << std::endl;
	s2.guardGate();        // already guarding → should say "continues guarding"

	std::cout << "\n=== Guarding with no energy ===" << std::endl;
	ScavTrap s4("LowEnergy");
	for (int i = 0; i < 50; i++) {
		s4.attack("dummy"); // burn through all energy
	}
	s4.guardGate();        // should fail due to no energy

	std::cout << "\n=== Guarding when dead ===" << std::endl;
	s4.takeDamage(200);    // kill ScavTrap
	s4.guardGate();        // should say can't guard when dead

	std::cout << "\n=== Attack when dead ===" << std::endl;
	s4.attack("ghost");    // should fail because dead

	std::cout << "\n=== Repair test ===" << std::endl;
	s3.takeDamage(30);
	s3.beRepaired(20);
}
