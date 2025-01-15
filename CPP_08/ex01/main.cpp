#include "Span.hpp"
#include <iostream>

int main() {
	try {
		Span sp = Span(10000);

		for (int i = 0; i < 10000; i++) {
			sp.addNumber(i * 3);
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Span smallSpan(5);
		smallSpan.addNumber(5);
		smallSpan.addNumber(10);

		smallSpan.addNumber(15);
		smallSpan.addNumber(2);
		smallSpan.addNumber(25);
		std::cout << "Shortest Span: " << smallSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << smallSpan.longestSpan() << std::endl;

		smallSpan.addNumber(30);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
