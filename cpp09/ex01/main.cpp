#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char **argv)
{
	std::istringstream iss(argv[1]);
	std::vector<std::string> v;
	std::string s;
	while (std::getline(iss, s, ' '))
		v.push_back(s);
	int i = -1;
	while (++i < (int)v.size())
		std::cout << v[i] << std::endl;
	return (0);
}
