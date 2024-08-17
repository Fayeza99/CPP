#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN
{
private:
	std::stack<int> stack;

public:
	RPN();
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);
	~RPN();
	bool isOperator(char c);
	void calculate(const std::string &argv);
};






#endif