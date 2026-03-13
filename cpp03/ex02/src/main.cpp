#include "../include/FragTrap.hpp"

int main(void)
{
	std::cout << "=== FragTrap Tests ===" << std::endl;

	FragTrap f1;
	FragTrap f2("Rainbow Dash");
	FragTrap f3(f2);

	f1 = f2;

	std::cout << "\n--- Attack Tests ---" << std::endl;
	for (int i = 0; i < 105; i++) { // burn through energy
		f2.attack("Target B");
	}

	// Take damage & repair
	std::cout << "\n--- Damage & Repair Tests ---" << std::endl;
	f3.takeDamage(20);
	f3.beRepaired(15);
	f3.takeDamage(200);              // lethal
	f3.attack("Cannot attack");      // should fail because dead
	f3.beRepaired(10);               // should fail because dead

	std::cout << "\n--- High Fives Ability ---" << std::endl;
	f1.highFivesGuys();
	f2.highFivesGuys();
	f3.highFivesGuys();             // should not be able to high five when dead

	return 0;
}
