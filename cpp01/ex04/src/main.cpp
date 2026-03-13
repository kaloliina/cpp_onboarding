
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Expected input: ./file_reading <FileName> <String> <StringReplacer>" << std::endl;
		return(1);
	}
	std::ifstream MyFile(argv[1]);
	if (MyFile.is_open() == false)
	{
		std::cerr << "Failed to open file" << std::endl;
		return (1);
	}
	std::string MyNewFileName = std::string(argv[1]).append(".replace");
	std::ofstream MyNewFile(MyNewFileName);
	if (MyNewFile.is_open() == false)
	{
		std::cerr << "Failed to open file" << std::endl;
		return (1);
	}
	size_t res = 0;
	std::string line;
	std::string s1 = argv[2], s2 = argv[3];
	while (std::getline(MyFile, line))
	{
		while (s1.size() != 0 && (res = line.find(s1, res)) != std::string::npos)
		{
			line.erase(res, s1.size());
			line.insert(res, s2);
			res = res + s2.size();
		}
		MyNewFile << line << std::endl;
		res = 0;
	}
	MyFile.close();
	MyNewFile.close();
	return (0);
}
