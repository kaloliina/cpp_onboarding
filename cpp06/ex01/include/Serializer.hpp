#pragma once
#include "Data.hpp"
#include <stdint.h>

/*
uintptr is guaranteed to hold any object's address. It enhances the safety of code.
*/
class Serializer
{
private:
	Serializer() = delete;
	Serializer(const Serializer& copy) = delete;
	Serializer& operator=(const Serializer& src) = delete;
	~Serializer() = delete;
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
