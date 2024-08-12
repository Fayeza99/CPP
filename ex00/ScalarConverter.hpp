#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <stdexcept>
#include <limits>

class ScalarConverter
{

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &c);
	ScalarConverter& operator=(const ScalarConverter &c);
	~ScalarConverter();



public:
	static void convert(const std::string str);
};




#endif