#include "includes/Array.hpp"
#include <cstdlib>
#include <time.h>

int main()
{
	Array<int> a;
	Array<int> b(5);
	for (int i = 0; i < b.size(); i++)
		b[i] = i;
	for (int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
	try
	{
		std::cout << "a[0] = " << a[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "b[-1] = " << b[-1] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Array<std::string> str(3);
	str[0] = "Hello";
	str[1] = "World";
	str[2] = "!";
	for (int i = 0; i < str.size(); i++)
		std::cout << "str[" << i << "] = " << str[i] << std::endl;
	return (0);
}

// intra main
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
