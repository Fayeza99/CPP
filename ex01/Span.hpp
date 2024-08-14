#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
	std::vector<int>	arr;
	unsigned int		_size;

public:
		Span();
		Span(unsigned int N);
		Span(const Span &c);
		Span& operator=(const Span &c);
		~Span();

		void addNumber(int number);

		unsigned int		shortestSpan();
		unsigned int		longestSpan();
};


#endif