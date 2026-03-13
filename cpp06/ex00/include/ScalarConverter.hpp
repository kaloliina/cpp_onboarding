#pragma once

#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
private:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& copy) = delete;
	ScalarConverter& operator=(const ScalarConverter& src) = delete;
	~ScalarConverter() = delete;
public:
	static void	convert(std::string ToConvert);
};
