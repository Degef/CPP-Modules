#include "includes/Span.hpp"

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	try 
// 	{
// 		sp.addNumber(12);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	return 0;
// }

int main()
{
	Span sp = Span(50000);
	std::vector<int> v(50000);
	std::generate(v.begin(), v.end(), std::rand);
	sp.addNumber(v.begin(), v.end()); 
	// for (int i = 0; i < 50000; i++)
	// 	std::cout << v[i] << " ";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try 
	{
		sp.addNumber(12);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
