#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

PhoneBook::~PhoneBook() { }

void PhoneBook::addContact()
{
	std::string info[] = {FIRSTNAME, LASTNAME, NICKNAME, PHONENUMBER, DARKESTSECRET};
	std::string answer[INFO_AMOUNT];
	int i = 0;
	int new_index, oldest;
	time_t timestamp;
	while (i < INFO_AMOUNT)
	{
		while (true)
		{
			std::cout << info[i] << std::endl;
			std::getline(std::cin, answer[i]);
			if (std::cin.eof())
				exit(1);
			if (answer[i].size() != 0)
				break;
			else
				std::cout << EMPTY_INPUT << std::endl;
		}
		i++;
	}
	if (index < MAX_CONTACTS_AMOUNT)
	{
		arr[index] = Contact(index + 1, answer[0], answer[1], answer[2], answer[3], answer[4]);
		index++;
	}
	else
	{
		std::cout << MAX_CONTACTS << std::endl;
		new_index = 0;
		time(&timestamp);
		while (new_index < MAX_CONTACTS_AMOUNT)
		{
			if (arr[new_index].get_time() < timestamp)
			{
				timestamp = arr[new_index].get_time();
				oldest = new_index;
			}
			new_index++;
		}
		arr[oldest] = Contact(oldest + 1, answer[0], answer[1], answer[2], answer[3], answer[4]);
	}
}

void PhoneBook::searchContact() const
{
	int	search;
	int	i = 0;
	std::string input;
	if (index == 0)
	{
		std::cout << NO_CONTACTS << std::endl;
		return ;
	}
	std::cout << "|" << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME" << "|" << std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;
	while (i < index)
	{
		arr[i].show(1);
		i++;
	}
	std::cout << TYPEINDEX << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(1);
	if (input.size() != 1 || input[0] < '1' || input[0] > '8')
	{
		std::cout << SEARCH_INDEX << std::endl;
		return ;
	}
	search = std::stoi(input) - 1;
	if (search >= index)
	{
		std::cout << SEARCH_INDEX << std::endl;
		return ;
	}
	arr[search].show(2);
}
