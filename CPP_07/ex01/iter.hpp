#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T* arr, size_t length, void(*func)(T&))
{
	for(size_t i = 0; i < length; i++)
	{
		func(arr[i]);
	}
}


template <typename T> void increment(T &n) {
	n += 1;
}

template <typename T> void toUppercase(T &c) {
	if (c >= 'a' && c <= 'z') {
		c = c - ('a' - 'A');
	}
}

template <typename T> void print(T element)
{
	std::cout << element << std::endl;
}

#endif
