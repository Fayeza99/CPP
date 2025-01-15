
#include "phonebook.hpp"

void Contact::set_contact(const std::string &f_n, const std::string &l_n, const std::string &nick_n, const std::string &phone_n, const std::string &d_s )
{
	firstname = f_n;
	lastname = l_n;
	nickname = nick_n;
	phonenumber = phone_n;
	darksecret = d_s;
}

int is_valid(const std::string& phone_n)
{
	if (phone_n.empty())
		return (0);
	std::string::const_iterator it = phone_n.begin();
	if (*it == '+')
		++it;
	while (it != phone_n.end())
	{
		if (!std::isdigit(*it))
			return (0);
		++it;
	}
	return (1);
}

void PhoneBook::add_contact()
{
	int i;
	std::string f_n, l_n, nick_n, phone_n, d_s;
	std::cout << GREEN << "Enter First Name: "<< RESET;
	std::getline(std::cin, f_n);
	if (std::cin.eof() == true)
		return ;
	i = 1;
	while (i < 3 && f_n.empty())
	{
		std::cout << RED <<"All fields are required!\n" << RESET;
		std::cout << GREEN << "Enter First Name: "<< RESET;
		std::getline(std::cin, f_n);
		if (std::cin.eof() == true)
			break;
		i++;
	}
	if (i == 3 && f_n.empty())
		return ;
	std::cout << GREEN <<"Enter Last Name: "<< RESET;
	std::getline(std::cin, l_n);
	if (std::cin.eof() == true)
		return ;
	i = 1;
	while (i < 3 && l_n.empty())
	{
		std::cout << RED <<"All fields are required!\n" << RESET;
		std::cout << GREEN << "Enter Last Name: "<< RESET;
		std::getline(std::cin, l_n);
		if (std::cin.eof() == true)
			break;
		i++;
	}
	if (i == 3 && l_n.empty())
		return ;
	std::cout << GREEN <<"Enter Nickname: "<< RESET;
	std::getline(std::cin, nick_n);
	if (std::cin.eof() == true)
		return ;
	i = 1;
	while (i < 3 && nick_n.empty())
	{
		std::cout << RED <<"All fields are required!\n" << RESET;
		std::cout << GREEN << "Enter Nick Name: "<< RESET;
		std::getline(std::cin, nick_n);
		if (std::cin.eof() == true)
			break;
		i++;
	}
	if (i == 3 && nick_n.empty())
		return ;
	std::cout << GREEN <<"Enter Phone Number: "<< RESET;
	std::getline(std::cin, phone_n);
	if (std::cin.eof() == true)
		return ;
	i = 1;
	while (i < 3 && phone_n.empty())
	{
		std::cout << RED <<"All fields are required!\n" << RESET;
		std::cout << GREEN << "Enter Phone number: "<< RESET;
		std::getline(std::cin, phone_n);
		if (std::cin.eof() == true)
			break;
		i++;
	}
	if (i == 3 && phone_n.empty())
		return ;
	i = 1;
	while (i < 3 && !is_valid(phone_n))
	{
		std::cout << RED << "Invalid phone number! Phone number can only contain digits and an optional leading +.\n" << RESET;
		std::cout << GREEN <<"Enter Phone Number: "<< RESET;
		std::getline(std::cin, phone_n);
		if (std::cin.eof() == true)
			break;
		i++;
	}
	if (i == 3 && !is_valid(phone_n))
		return ;
	std::cout << GREEN <<"Enter Darkest Secret: "<< RESET;
	std::getline(std::cin, d_s);
	if (std::cin.eof() == true)
		return ;
	i = 1;
	while (i < 3 && d_s.empty())
	{
		std::cout << RED <<"All fields are required!\n" << RESET;
		std::cout << GREEN << "Enter Darkest Secret: "<< RESET;
		std::getline(std::cin, d_s);
		if (std::cin.eof() == true)
			break;
		i++;
	}
	if (i == 3 && d_s.empty())
		return ;
	contacts[next_contact].set_contact(f_n, l_n, nick_n, phone_n, d_s);
	next_contact = (next_contact + 1) % 8;
	if (contact_count < 8)
	{
		contact_count++;
	}
}

void Contact::display(int index) const
{
	std::cout << std::setw(10) << index + 1 << YELLOW "|" << RESET
			  << std::setw(10) << (firstname.length() > 10 ? firstname.substr(0, 9) + "." : firstname)<< YELLOW << "|"<< RESET
			  << std::setw(10) << (lastname.length() > 10 ? lastname.substr(0, 9) + "." : lastname)<< YELLOW << "|"<< RESET
			  << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "\n";
}

void Contact::display_all() const
{
	std::cout << BLUE << "First Name: " << RESET << MAGENTA << firstname << RESET<< "\n";
	std::cout << BLUE <<"Last Name: "<< RESET << MAGENTA << lastname << RESET<< "\n";
	std::cout << BLUE <<"Nickname: "<< RESET << MAGENTA << nickname<< RESET << "\n";
	std::cout << BLUE <<"Phone Number: "<< RESET << MAGENTA << phonenumber<< RESET << "\n";
	std::cout << BLUE <<"Darkest Secret: "<< RESET << MAGENTA <<darksecret<< RESET << std::endl;
}

void PhoneBook::search_contact()
{
	if (contact_count == 0)
	{
		std::cout << "No contacts to display.\n";
		return;
	}
	std::cout << std::setw(10) << "Index" << YELLOW << "|" << RESET;
	std::cout << std::setw(10) << "First Name" << YELLOW << "|"<< RESET;
	std::cout << std::setw(10) << "Last Name" << YELLOW << "|"<< RESET;
	std::cout << std::setw(10) << "Nickname" << std:: endl;
	std::cout << YELLOW << "-------------------------------------------"<< RESET << std:: endl;

	for (int i = 0; i < contact_count; ++i)
	{
		contacts[i].display(i);
	}
	std::cout << YELLOW << "-------------------------------------------"<< RESET << std:: endl;
	std::cout << "Enter index to display full contact: ";
	int index;
	std::cin >> index;
	if(std::cin.fail() || index <= 0 || index > contact_count)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index!\n";
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		contacts[index - 1].display_all();
	}
}
