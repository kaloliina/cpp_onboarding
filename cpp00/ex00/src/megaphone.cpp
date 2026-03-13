#include <iostream>
/*To upper only converts alphabetic letters to uppercase but otherwise the input
is returned unchanged.
- We cast the character to unsigned char because on some systems, char might be signed (and extended
ASCII characters are seen as negative) and if toupper gets a negative value, it might lead
to undefined behaviour. Unsigned char takes into consideration the extended ASCII values.*/
int main(int argc, char *argv[])
{
	int	i = 0;
	int	y = 1;
	std::string line = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (y < argc)
	{
		i = 0;
		while (argv[y][i] != '\0')
		{
			argv[y][i] = static_cast<char>(std::toupper(static_cast<unsigned char>(argv[y][i])));
			std::cout << argv[y][i];
			i++;
		}
		y++;
	}
	if (argc ==  1)
		std::cout << line << std::endl;
	else
		std::cout << std::endl;
	return (0);
}
