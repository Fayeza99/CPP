#ifndef EASYFIND_TPP
#define EASYFIND_TPP


#include "easyfind.hpp"

template<typename T> typename T::iterator easyfind(T& container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end()) {
		throw std::invalid_argument("not found");
	}
	return (it);
}


#endif