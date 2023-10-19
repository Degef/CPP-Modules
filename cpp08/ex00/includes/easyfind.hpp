#ifndef Easyfind_hpp
#define Easyfind_hpp

#define RESET "\033[0m"
#define R "\033[31m"
#define G "\033[32m"
#define Y "\033[33m"

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <list>
#include <iterator>
#include <deque>

template <typename T>
typename T::const_iterator easyfind(T &container, int element)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), element);
	if (it != container.end())
		return (it);
	std::cout << R << "Element [" << element << "] not found" << RESET << std::endl;
	throw std::exception();
}

#endif