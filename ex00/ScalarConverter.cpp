#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &c)
{
	(void) c;
	*this = c;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &c)
{
	(void) c;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

#include <string>

std::string get_str(const std::string str) {
	size_t start = 0;
	size_t end = str.length() - 1;

	while (start < str.length() && str[start] == ' ') {
		start++;
	}
	while (end > start && str[end] == ' ') {
		end--;
	}
	if (start > end) {
		return "";
	}
	std::string trimmedStr = str.substr(start, end - start + 1);
	if (trimmedStr == "nan" || trimmedStr == "inf")
		return trimmedStr;
	size_t dotCount = 0;
	size_t pos = trimmedStr.find('.');

	while (pos != std::string::npos) {
		dotCount++;
		pos = trimmedStr.find('.', pos + 1);
	}
	if (dotCount > 1) {
		return "";
	}
	if (str.length() > 1)
	{
		for (unsigned int i = 0; i < trimmedStr.length(); i++)
		{
			if (std::isdigit(trimmedStr[i]) || trimmedStr[i] == '.' || trimmedStr[i] == 'e' || trimmedStr[i] == 'f' || trimmedStr[i] == 'F' || trimmedStr[i] == 'E')
				continue;
			else
				return "";
		}
	}
	return trimmedStr;
}

void print(char c, int i, double d, float f)
{
	if (c == '\0')
		std::cout << "Char: not possible" << std::endl;
	else
		std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Double: " << d << std::endl;
	std::cout << "Float: " << f << "f" << std::endl;
}

void converToChar(double result)
{
	if (std::isnan(result) || std::isinf(result) || result < std::numeric_limits<char>::min() || result > std::numeric_limits<char>::max()) {
		std::cerr << "Char: Not possible"<< std::endl ;
		
		return ;
	}
	int roundedResult = static_cast<int>(std::round(result));

	if (roundedResult >= 32 && roundedResult <= 126) {
		std::cout << "Char: " << static_cast<char>(roundedResult) << std::endl;
	}
	else {
		std::cerr << "Char: Non-displayable character"<< std::endl ;
		return ;
	}
}

void convertToInt(double result)
{
	if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max()) {
		std::cout << "Int: Overflow" << std::endl;
		return ;
	}
	std::cout << "Int: " << static_cast<int>(std::round(result)) << std::endl;
}

void convertToDouble(double result) {

	if (std::isnan(result)) {
		std::cerr << "Error: The value is NaN (Not a Number)." << std::endl;
		return  ;
	}
	if (std::isinf(result)) {
		std::cerr << "Error: The value is infinity." << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout <<"Double: " << result << std::endl;
}

void converToFloat(double result)
{
	float f;

	if (result < -std::numeric_limits<float>::max() || result > std::numeric_limits<float>::max()) {
		std::cout << "Float: Overflow\n";
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	f = static_cast<float>(result);
	std::cout << "Float: " << f << "f" << std::endl;
}

void formatPseudoLiterals(const std::string& literal) {
	std::cout << "char: Conversion not possible!" << std::endl;
	std::cout << "int: Conversion not possible!" << std::endl;

	if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf") {
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}

	if (literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")	{
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
}

void ScalarConverter::convert(const std::string s)
{
	if (s == "nan" || s == "-inf" || s == "+inf" || s == "inf" || s == "nanf" || s == "-inff" || s == "+inff" || s == "inff")
	{	formatPseudoLiterals(s);
		return;
	}
	std::string str = get_str(s);
	if (str[0] == '\0')
	{
		std::cerr << "invalid input" << std::endl;
		return ;
	}
	double	result;
	char	charV;
	int		intV;
	double	doubleV;
	float	floatV;


	if(str.length() == 1 && str[1] == '\0' && !isdigit(str[0]))
	{
		charV = str[0];
		intV = static_cast<int>(charV);
		floatV = static_cast<float>(charV);
		doubleV = static_cast<double>(charV);
		print(charV, intV, doubleV, floatV);
	}
	else
	{
		try{
			result = std::stod(str.c_str());
			converToChar(result);
			convertToInt(result);
			converToFloat(result);
			convertToDouble(result);
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		
	}

}
