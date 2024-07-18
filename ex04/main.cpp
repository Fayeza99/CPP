#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		size_t pos = 0;
		size_t last_pos = 0;
		std::string result;
		std::string file_name = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		
		std::ifstream inputFile;
		inputFile.open(file_name.c_str());
		if (!inputFile.is_open())
		{
			std::cerr << "Error opening file: " << file_name << std::endl;
			return (1);
		}
		std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
		inputFile.close();
		while ((pos = fileContent.find(s1, last_pos)) != std::string::npos)
		{
			result.append(fileContent, last_pos, pos - last_pos);
			result.append(s2);
			last_pos = pos + s1.length();
		}
		result.append(fileContent, last_pos, fileContent.length() - last_pos);
		
		std::ofstream outputFile;
		outputFile.open((file_name + ".replace").c_str());
		if (!outputFile.is_open())
		{
			std::cerr << "Error opening file for writing: " << file_name << std::endl;
			return (1);
		}
		outputFile << result;
		outputFile.close();
	}
	else
	{
		std::cerr << "program needs parameters" << std::endl;
		return (1);
	}
	return (0);
}
