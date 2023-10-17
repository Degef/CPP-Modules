#ifndef Easyfind_hpp
#define Easyfind_hpp

#include <iostream>
#include <algorithm>
#include <vector>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {return ("Not found");}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

	while (it != ite)
	{
		if (*it == n)
			return (it);
		it++;
	}
	throw NotFoundException();
}

#endif