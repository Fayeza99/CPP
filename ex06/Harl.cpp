
#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::getLevel(std::string level)
{
	logLevel = 0;
	if (level == "DEBUG")
		logLevel = 1;
	if (level == "INFO")
		logLevel = 2;
	if (level == "WARNING")
		logLevel = 3;
	if (level == "ERROR")
		logLevel = 4;
}


void Harl::complain(std::string level)
{
	getLevel(level);
	switch (logLevel)
	{
	case 1:
		debug();
		info();
		warning();
		error();
		break;
	case 2:
		info();
		warning();
		error();
		break;
	case 3:
		warning();
		error();
		break;
	case 4:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
