#ifndef REPLACE_HPP
#define REPLACE_HPP


#include <iostream>
#include <fstream>
#include <string>


class Replace
{
public:
	Replace(const std::string& fileName, const std::string& searchStr, const std::string& replaceStr);
	~Replace();
	bool replaceInFile();

private:

	std::string file_name;
	std::string s1;
	std::string s2;

};




#endif