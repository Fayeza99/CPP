#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	std::vector<int> vect;
	std::list<int> list;

	for (int i = 0; i < 10000; i++) {
		vect.push_back(i);
		list.push_back(i);
	}

	try {
		std::vector<int>::iterator it_vect = easyfind(vect, 10000 - 1);
		std::cout << "Found in vector: " << *it_vect << std::endl;

		std::list<int>::iterator it_list = easyfind(list, 10005);
		std::cout << "Found in list: " << *it_list << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
