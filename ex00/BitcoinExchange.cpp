
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& fileName) {
	this->exchangeRate = readData(fileName);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy) {
	exchangeRate = copy.exchangeRate;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double> BitcoinExchange::readData(const std::string &data)
{
	std::ifstream file(data);
	if (!file) {
		throw std::runtime_error("Could not open file: " + data);
	}
	std::map<std::string, double> db_content;
	std::string line;
	while (std::getline(file, line)) {
		try {
			std::pair<std::string, double> value = parseData(line, ',');
			db_content[value.first] = value.second;
		} catch (const std::exception& ) {

		}
	}
	return db_content;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return (false);
	}

	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (const std::exception&) {
		return (false);
	}

	if (year < 1)
		return (false);

	const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12)
		return (false);

	if (day < 1 || day > month_days[month - 1])
		return (false);

	return (true);
}



std::pair<std::string, double> BitcoinExchange::parseData(const std::string& data_line, char delimiter)
{
	// Find the position of the delimiter
	size_t del_pos = data_line.find(delimiter);
	if (del_pos == std::string::npos) {
		throw std::runtime_error("Format error: missing delimiter");
	}

	// Extract the date part
	std::string date = data_line.substr(0, 10);
	if (!isValidDate(date)) {
		throw std::invalid_argument("Invalid date: " + date);
	}
	std::string value_str = data_line.substr(del_pos + 1);
	std::string::size_type start = value_str.find_first_not_of(" \t");
	if (start == std::string::npos) {
		start = 0;
	}
	std::string::size_type end = value_str.find_last_not_of(" \t");
	if (end == std::string::npos) {
		end = value_str.length();
	}
	value_str = value_str.substr(start, end - start + 1);

	// Convert the trimmed value string to double using stringstream
	double value = 0.0;
	std::stringstream value_stream(value_str);
	value_stream >> value;

	if (value_stream.fail() || !value_stream.eof()) {
		throw std::invalid_argument("Invalid number format: " + value_str);
	}

	if (value < 0) {
		throw std::domain_error("Negative number not allowed");
	}
	std::pair<std::string, double> result;
	result.first = date;
	result.second = value;

	return result;
}

double BitcoinExchange::getExchangeRate(const std::string& data_line) {
	std::pair<std::string, double> value = parseData(data_line, '|');
	std::string date = value.first;

	std::map<std::string, double>::iterator it = exchangeRate.lower_bound(date);

	if (it == exchangeRate.end() || it->first != date) {
		if (it == exchangeRate.begin()) {
			throw std::runtime_error("No applicable exchange rate found");
		}
		--it;
	}

	return it->second;
}


std::pair<double, double> BitcoinExchange::getExchangeValue(const std::string& data_line) {
	std::pair<std::string, double> value = parseData(data_line, '|');

	if (value.second > 2147483647) {
		throw std::overflow_error("Value exceeds maximum allowed");
	}

	double rate = getExchangeRate(data_line);

	std::pair<double, double> result;
	result.first = value.second;
	result.second = rate;

	return result;
}


void processFile(const std::string& filename, BitcoinExchange& exchange) {
	std::ifstream file(filename);
	if (!file) {
		throw std::runtime_error("Error: could not open file");
	}

	std::string line;
	std::getline(file, line);
	if (line != "date | value") {
		std::cerr << "Error: Format Error: The file should have \"date | value\" as header" << std::endl;
		file.close();
		throw std::runtime_error("Invalid file format");
	}

	while (std::getline(file, line)) {
		try {
			std::pair<double, double> value = exchange.getExchangeValue(line);
			std::string date = line.substr(0, line.find('|'));
			std::cout << date << " => " << value.first << " = " << (value.first * value.second) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	file.close();
}