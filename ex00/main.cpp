#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return (1);
	}

	try {
		BitcoinExchange exchange("data.csv");
		processFile(argv[1], exchange);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
