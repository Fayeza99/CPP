#include "Replace.hpp"

Replace::Replace(const std::string& fileName, const std::string& searchStr, const std::string& replaceStr)
		: file_name(fileName), s1(searchStr), s2(replaceStr) {}

Replace::~Replace(){}

bool Replace::replaceInFile()
{
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Search and replace strings must not be empty" << std::endl;
		return false;
	}
	std::ifstream inputFile(file_name);
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file: " << file_name << std::endl;
		return false;
	}
	std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();

	size_t pos = 0;
	size_t last_pos = 0;
	std::string result;
	bool found = false;

	while ((pos = fileContent.find(s1, last_pos)) != std::string::npos)
	{
		result.append(fileContent, last_pos, pos - last_pos);
		result.append(s2);
		last_pos = pos + s1.length();
		found = true;
	}

	if (!found)
	{
		std::cerr << "String not found" << std::endl;
		return false;
	}

	result.append(fileContent, last_pos, fileContent.length() - last_pos);

	std::ofstream outputFile(file_name + ".replace");
	if (!outputFile.is_open())
	{
	    std::cerr << "Error opening file for writing: " << file_name << std::endl;
	    return false;
	}
	outputFile << result;
	outputFile.close();

	return true;
}