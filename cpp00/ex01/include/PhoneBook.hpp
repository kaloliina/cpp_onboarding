
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#define FIRSTNAME "Type first name: "
#define LASTNAME "Type last name: "
#define NICKNAME "Type nickname: "
#define PHONENUMBER "Type phone number: "
#define DARKESTSECRET "Type darkest secret: "
#define INPUTOPTIONS "Type either <ADD>, <SEARCH> or <EXIT>."
#define TYPEINDEX "Type the index of the contact you wish to see."
#define MAX_CONTACTS "Maximum amount of contacts reached, overwriting the oldest."
#define SEARCH_INDEX "This phonebook does not accept indexes that do not belong to any current contact."
#define EMPTY_INPUT "I'm sorry but this crappy phonebook will not accept empty input."
#define NO_CONTACTS "This phonebook has no contacts whatsoever."
#define MAX_CONTACTS_AMOUNT 8
#define INFO_AMOUNT 5

class PhoneBook {
private:
Contact arr[8];
int index;
public:
PhoneBook();
~PhoneBook();

void addContact();
void searchContact() const;
};
#endif
