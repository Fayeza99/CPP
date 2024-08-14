#include "MutantStack.hpp"
#include <iostream>

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(25);
	mstack.push(11);

	// std::cout << "Top element: " << mstack.top() << std::endl;

	// mstack.pop();
	// std::cout << "After pop, top element: " << mstack.top() << std::endl;

	std::cout << "Stack elements:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "Stack elements (reverse):" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}

	return 0;
}
