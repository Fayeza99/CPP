#include "MutantStack.hpp"
#include <iostream>

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}

// int main() {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);
// 	mstack.push(3);
// 	mstack.push(25);
// 	mstack.push(11);

// 	// std::cout << "Top element: " << mstack.top() << std::endl;

// 	// mstack.pop();
// 	// std::cout << "After pop, top element: " << mstack.top() << std::endl;

// 	std::cout << "Stack elements:" << std::endl;
// 	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
// 	{
// 		std::cout << *it << std::endl;
// 	}
// 	std::cout << "Stack elements (reverse):" << std::endl;
// 	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
// 		std::cout << *rit << std::endl;
// 	}

// 	return 0;
// }
