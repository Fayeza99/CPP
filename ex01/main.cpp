#include "phonebook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << GREEN << "Enter command (ADD, SEARCH, EXIT): " << RESET;
		std::getline(std::cin, command);
		if (std::cin.eof() == true)
		{
			break;
		}
		if (command == "ADD") {
			phonebook.add_contact();
		}
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command!\n";
	}

	return (0);
}
