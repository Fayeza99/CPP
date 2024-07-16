#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <string>
#include <iostream>
#include <iomanip>
#include <limits>


#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define YELLOW	"\x1b[33m"
#define BLUE	"\x1b[34m"
#define MAGENTA	"\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET	"\x1b[0m"


class Contact{
	public:
	void set_contact(const std::string &f_n, const std::string &l_n, const std::string &nick_n, const std::string &phone_n, const std::string &d_s );
	void display(int index) const;
	void display_all() const;

	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string darksecret;
	std::string phonenumber;

};

class PhoneBook{
	private:
	Contact contacts[8];
	int		contact_count;
	int		next_contact;

	public:
	PhoneBook() : contact_count(0), next_contact(0) {}
	void add_contact();
	void search_contact();
};

#endif