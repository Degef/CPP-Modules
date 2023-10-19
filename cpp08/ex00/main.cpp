#include "includes/easyfind.hpp"

int main()
{
	{
		std::cout << Y << "#Test 1: Vector" << RESET << std::endl;
		std::vector<int> v;
		for (int i = 0; i < 20; i++)
			v.push_back(i);
		try
		{
			std::cout << *easyfind(v, 15) << std::endl;
			std::cout << *easyfind(v, 2) << std::endl;
			std::cout << *easyfind(v, 100) << std::endl;
		}
		catch (std::exception &e){}
	}
	{
		std::cout << Y << "#Test 2: List" << RESET << std::endl;
		std::list<int> l;
		for (int i = 0; i < 20; i++)
			l.push_back(i);
		try
		{
			std::cout << *easyfind(l, 19) << std::endl;
			std::cout << *easyfind(l, 7) << std::endl;
			std::cout << *easyfind(l, -2) << std::endl;
		}
		catch (std::exception &e){}

	}
	{
		std::cout << Y << "#Test 3: Deque" << RESET << std::endl;
		std::deque<int> d;
		for (int i = 0; i < 20; i++)
			d.push_back(i);
		try {
			std::cout << *easyfind(d, 16) << std::endl;
			std::cout << *easyfind(d, 10) << std::endl;
			std::cout << *easyfind(d, 400) << std::endl;
		}
		catch (std::exception &e){}
	}
	return (0);
}
