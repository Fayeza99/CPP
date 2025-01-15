#include "Span.hpp"
#include <iostream>
Span::Span() : _size(0) {}
Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span &c)
{
	_size = c._size;
	arr = c.arr;
}

Span& Span::operator=(const Span& c)
{
	if (this != &c)
	{
		_size = c._size;
		arr = c.arr;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int number)
{
	if (arr.size() >= _size) {
		throw std::out_of_range("Span is already full.");
	}
	arr.push_back(number);
}

unsigned int Span::shortestSpan()
{
	int min_span;
	if(arr.size() < 2)
		throw std::logic_error("Not enough number");
	std::vector<int> sorted_arr = arr;
	std::sort(sorted_arr.begin(), sorted_arr.end());
	min_span = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted_arr.size(); ++i)
	{
		int span = sorted_arr[i] - sorted_arr[i - 1];
		if (span < min_span) {
			min_span = span;
		}
	}
	return (min_span);
}

unsigned int Span::longestSpan()
{
	int max_span;
	if(arr.size() < 2)
		throw std::logic_error("Not enough number");
	std::vector<int> sorted_arr = arr;
	std::sort(sorted_arr.begin(), sorted_arr.end());
	int max_e =  *std::max_element(arr.begin(), arr.end());
	int min_e =  *std::min_element(arr.begin(), arr.end());

	max_span = max_e - min_e;
	return (max_span);
	
}