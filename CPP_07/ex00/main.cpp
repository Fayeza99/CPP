#include <iostream>
#include "Whatever.hpp"

int main() {
	int x = 10;
	int y = 20;

	std::cout << "Original values:" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	swap(x, y);
	std::cout << "After swap:" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "min(x, y) = " << min(x, y) << std::endl;
	std::cout << "max(x, y) = " << max(x, y) << std::endl;

	double a = 1.1;
	double b = 2.2;

	std::cout << "\nOriginal values:" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);
	std::cout << "After swap:" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	return 0;
}
