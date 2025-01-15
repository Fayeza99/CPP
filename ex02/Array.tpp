#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T> Array<T>::Array() : arr(NULL), _size(0) {}

template <typename T> Array<T>::Array(size_t size) : _size(size)
{
	arr = new T[size]();
}
template <typename T> Array<T>::Array(const Array &c)
{
	if (c.arr != NULL && c._size > 0)
	{
		arr = new T[c._size]();
		_size = c._size;
		for (size_t i = 0; i < c._size; i++)
		{
			arr[i] = c.arr[i];
		}
	}
}

template <typename T> Array<T>& Array<T>::operator=(const Array &c)
{
	if (this != &c)
	{
		delete[] arr;
		if (c.arr != NULL && c._size > 0)
		{
			arr = new T[c._size]();
			_size = c._size;
			for (size_t i = 0; i < c._size; i++)
			{
				arr[i] = c.arr[i];
			}
		}
	}
	return (*this);
}

template <typename T> Array<T>::~Array(){
	delete[] arr;
}

template <typename T> T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("index out of range");
	else
		return arr[index];
}

template <typename T> size_t Array<T>::size() const
{
	return _size;
}

#endif