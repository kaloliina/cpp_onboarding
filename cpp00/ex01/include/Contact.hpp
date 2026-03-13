#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>

/*
Class is user-defined data type which holds its own data members and member functions that can be used by creating an instance of that class.
- Class does not exist until one is instantiated.
- Private and public are access specifiers which specify the access level. Meaning that if data members are marked to be private,
the elements can only be adjusted within the class.
- In addition classes have constructors and destructors. These class members are called by the compiler every time an object of that class is instantiated.
They construct the objects, allocate memory for them to be ready to be used. Destructor then deallocates all the memory used by the object and is called
when the scope ends. If not defined in class, the default "constructors" would exist by default.
But if one defines even one of them, the compiler expects that every required constructor is also defined.
*/
class Contact {
private:
int		index;
time_t timestamp;
std::string firstName;
std::string lastName;
std::string nickName;
std::string phoneNumber;
std::string darkestSecret;
public:
	Contact();
	Contact(int index, std::string& firstName, std::string& lastName, std::string& nickName, std::string& phoneNumber, std::string& darkestSecret);
	~Contact();

	void show(int mode) const;
	time_t get_time() const;
};
#endif
