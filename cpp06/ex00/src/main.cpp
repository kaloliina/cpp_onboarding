#include "../include/ScalarConverter.hpp"

void tests()
{
	std::cout << "CHAR" << std::endl;
	std::cout << "Converting: a" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "\nConverting: *" << std::endl;
	ScalarConverter::convert("*");
	std::cout << "\nConverting: ~" << std::endl;
	ScalarConverter::convert("~");
	std::cout << "\nConverting: \\n" << std::endl;
	ScalarConverter::convert("\n");
	std::cout << "\n";
	std::cout << "INT" << std::endl;
	std::cout << "Converting: +48" << std::endl;
	ScalarConverter::convert("+48");
	std::cout << "\nConverting: 30" << std::endl;
	ScalarConverter::convert("30");
	std::cout << "\nConverting: 8" << std::endl;
	ScalarConverter::convert("8");
	std::cout << "\nConverting: 127" << std::endl;
	ScalarConverter::convert("127");
	std::cout << "\nConverting: -128" << std::endl;
	ScalarConverter::convert("-128");
	std::cout << "\nConverting: INT MAX" << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "\nConverting: INT MIN" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "\nConverting: INT MAX + 1" << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << "\n";
	std::cout << "FLOAT" << std::endl;
	std::cout << "Converting: 30.0f" << std::endl;
	ScalarConverter::convert("30.0f");
	std::cout << "\nConverting: -0.5f" << std::endl;
	ScalarConverter::convert("-0.5f");
	std::cout << "\nConverting: .5f" << std::endl;
	ScalarConverter::convert(".5f");
	std::cout << "\nConverting: 42.f" << std::endl;
	ScalarConverter::convert("42.f");
	std::cout << "\nConverting: FLOAT MIN" << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::lowest()));
	std::cout << "\nConverting: FLOAT MAX" << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::max()));
	std::cout << "\nConverting: FLOAT MIN * 1.5" << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::lowest() * 1.5));
	std::cout << "\nConverting: FLOAT MAX * 1.5" << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::max() * 1.5));
	std::cout << "\n";
	std::cout << "DOUBLE" << std::endl;
	std::cout << "Converting: 30.0" << std::endl;
	ScalarConverter::convert("30.0");
	std::cout << "\nConverting: -0.5" << std::endl;
	ScalarConverter::convert("-0.5");
	std::cout << "\nConverting: DOUBLE MIN" << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<double>::lowest()));
	std::cout << "\nConverting: DOUBLE MAX" << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<double>::max()));
	std::cout << "\n";
	std::cout << "PSEUDO" << std::endl;
	std::cout << "Converting: nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "\nConverting: nanf" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "\nConverting: +inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "\nConverting: -inff" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "\n";
	std::cout << "UNKNOWN" << std::endl;
	std::cout << "Converting: abc" << std::endl;
	ScalarConverter::convert("abc");
	std::cout << "\nConverting: 30..0" << std::endl;
	ScalarConverter::convert("30..0");
	std::cout << "\nConverting: ++30" << std::endl;
	ScalarConverter::convert("++30");
	std::cout << "\nConverting: 20.." << std::endl;
	ScalarConverter::convert("20..");
	std::cout << "\nConverting: 20.F" << std::endl;
	ScalarConverter::convert("20.F");
	std::cout << "\n";
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Expected format: ./ScalarConverter <String to Convert>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
//	(void)argc;
//	(void)argv;
//	tests();
	return 0;
}
