#include <iostream>
#include <string>

int main()
{

	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	ptr = &str;
	std::string &stringREF = str;
	
	std::cout << &str << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value of the ptr: " << *ptr << std::endl;
	std::cout << "Value of the stringREF: " << stringREF << std::endl;
	return (0);
}
