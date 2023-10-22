#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <cstring>

int do_op(int *first_num, int *second_num, char *&op)
{
	std::cout << first_num << " " << second_num << " " << op << std::endl;
	if ( first_num && second_num && op)	{
		if (*op == '+')
			*first_num += *second_num;
		else if (*op == '-')
			*first_num -= *second_num;
		else if (*op == '*')
			*first_num *= *second_num;
		else if (*op == '/')
			*first_num /= *second_num;
		else {
			std::cout << "Error in do_op" << std::endl;
			return (1);
		}
	}
	else {
		std::cout << "Error! Wrong Sequence" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::istringstream iss(argv[1]);
	std::vector<std::string> v;
	std::string s;
	while (std::getline(iss, s, ' '))
		v.push_back(s);
	int i = -1;
	while (++i < (int)v.size())
		std::cout << v[i] << "  ";
	std::cout << std::endl;
	int *first_num = NULL;
	int *second_num = NULL;
	char *op = NULL;
	i = -1;
	while (++i < (int)v.size())
	{
		std::cout << "i: " << i << " " << v[i] << " Size: " << v.size() << std::endl;
		if (first_num == NULL && i < (int)v.size())
		{
			try
			{
				first_num = new int;
				*first_num = std::atoi(v[i++].c_str());
				// std::cout << v[i] << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Exception Caught: " << std::endl;
				delete first_num;
				return (1);
			}
		}

		if (i < (int)v.size())
		{
			try
			{
				second_num = new int;
				*second_num = std::atoi(v[i++].c_str());
			}
			catch (std::exception &e)
			{
				std::cout << "Exception Caught: " << std::endl;
				delete second_num;
				delete first_num;
				return (1);
			}
		}

		if (i < (int)v.size())
		{
			if (v[i].size() != 1 && v[i][0] != '+' && v[i][0] != '-' && v[i][0] != '*' && v[i][0] != '/')
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			op = new char;
			std::strcpy(op, v[i].c_str());
			// op[1] = '\0';
			// *op = v[i++][0];
		}
		std::cout << *first_num << " " << *second_num << " " << op << std::endl;
		if (do_op(first_num, second_num, op))
			return (1);
		delete second_num;
		delete op;
		// second_num = NULL;
		// op = NULL;
	}
	std::cout << "result: " << *first_num << std::endl;
	delete first_num;
	return (0);
}
