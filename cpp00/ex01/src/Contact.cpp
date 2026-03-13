#include "../include/PhoneBook.hpp"

/*When class gets instantiated, we are creating an object (an instance of that class)
- It allocates memory for that object and calls the constructor.
- One could say that Class is like a blueprint/recipe and object is the actual thing built from that recipe.
*/
Contact::Contact() { }

/*When the program ends, we automatically call the destructor which frees the allocated space*/
Contact::~Contact() { }

/*If setw is set first, the text will be right-aligned*/
void Contact::show(int mode) const
{
	std::string name, last, nick;
	if (mode == 1)
	{
		name = firstName;
		last = lastName;
		nick = nickName;
		if (firstName.size() > 10)
		{
			name.resize(9);
			name.append(".");
		}
		if (lastName.size() > 10)
		{
			last.resize(9);
			last.append(".");
		}
		if (nickName.size() > 10)
		{
			nick.resize(9);
			nick.append(".");
		}
		std::cout << "|" << std::setw(10) << index << "|" << std::setw(10) << name << "|" << std::setw(10) << last << "|" << std::setw(10) << nick << "|" << std::endl;
	}
	else
		std::cout << firstName << std::endl << lastName << std::endl << nickName << std::endl << phoneNumber << std::endl << darkestSecret << std::endl;
}

/*This uses references to existing strings. If we did not have references, each argument would be copied into the constructor parameter which
is unnecessary because we already have strings to point towards*/
Contact::Contact(int index, std::string& firstName, std::string& lastName, std::string& nickName, std::string& phoneNumber, std::string& darkestSecret)
{
	this->index = index;
	this->timestamp = time(&this->timestamp);
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret; 
}

time_t Contact::get_time() const
{
	return timestamp;
}

