
#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}


RPN::RPN(const RPN& other)
{
	if (this != &other)
		*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

bool RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return false;
}

void RPN::calculate(const std::string &argv)
{
	std::stack<int> stack;
	std::stringstream iss(argv);
	std::string token;

	while (iss >> token)
	{
		int result;
		if (std::isdigit(token[0]) && token.length() == 1)
		{
			stack.push(token[0] - '0');
		}
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if (stack.size() < 2)
			{
				throw std::runtime_error("invalid");
			}
			int first = stack.top();
			stack.pop();
			int second = stack.top();
			stack.pop();
			switch (token[0])
			{
			case '+':
				result = second + first;
				stack.push(result);
				break;
			case '-':
				result = second - first;
				stack.push(result);
				break;
			case '*':
				result = second * first;
				stack.push(result);
				break;
			case '/':
				if (first == 0)
					throw std::runtime_error("Error: division by zero");
				result = second / first;
				stack.push(result);
				break;
			default:
				throw std::runtime_error("Error: unknown operation");
			}
		}
		else {
			throw std::runtime_error("Error: invalid token");
		}
	}
	if (stack.size() != 1) {
		throw std::runtime_error("Error: invalid expression");
	}
	std::cout << stack.top() << std::endl;
}