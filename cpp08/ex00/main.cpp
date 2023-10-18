#include "includes/easyfind.hpp"

int main()
{
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
	return (0);
}
