#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template< typename T>
typename T::iterator	easyfind(T& container, int nb)
{
	typename T::iterator it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw std::runtime_error("The value has not been found");
	return (it);
}
