#ifndef Easyfind_hpp
#define Easyfind_hpp

# define RESET "\033[0m"
#define R "\033[31m"
#define G "\033[32m"
#define Y "\033[33m"

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = container.begin();
	std::cout << "iter begin address: " << &it << std::endl;
	typename T::iterator ite = container.end();
	std::cout << "iter end address: " << &ite << std::endl;

	while (it != ite)
	{
		if (*it == n)
			return (it);
		it++;
	}
	std::cout << R << "Element not found" << RESET << std::endl;
	throw std::exception();
}

#endif