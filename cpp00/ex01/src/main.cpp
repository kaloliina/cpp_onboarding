#include "../include/PhoneBook.hpp"

int main(void)
{
	PhoneBook PhoneBook;
	std::string command;
	while (1)
	{
	std::cout << INPUTOPTIONS << std::endl;
	std::getline(std::cin, command);
	if (std::cin.eof())
		break;
	if (command.compare("ADD") == 0)
		PhoneBook.addContact();
	if (command.compare("SEARCH") == 0)
		PhoneBook.searchContact();
	if (command.compare("EXIT") == 0)
		break;
	}
	return (0);
}
