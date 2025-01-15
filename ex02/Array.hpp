#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array
{
public:
	Array();
	Array(size_t size);
	Array(const Array &c);
	Array& operator=(const Array &c);
	~Array();

	T& operator[](size_t index);
	size_t size() const;

private:
	T*		arr;
	size_t	_size;


};

#include "Array.tpp"


#endif