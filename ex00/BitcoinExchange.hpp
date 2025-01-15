#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

class BitcoinExchange
{

private:
	std::map<std::string, double> exchangeRate;
	bool isValidDate(const std::string &date);
	std::map<std::string, double> readData(const std::string &data);
	std::pair<std::string, double> parseData(const std::string& data_line, char delimiter);

public:
	BitcoinExchange(const std::string& fileName);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	std::pair<double, double> getExchangeValue(const std::string& data_line);
	double getExchangeRate(const std::string& data_line);
};


void	processFile(const std::string& filename, BitcoinExchange& exchange);

#endif