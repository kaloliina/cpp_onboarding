#include "../include/Harl.hpp"

int main(void)
{
	Harl harl;
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("DIPPADIPPADAA");
	harl.complain("");
	harl.complain("123456789");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("WARNING");
	return (0);
}
