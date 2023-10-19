#include "includes/Span.hpp"
#include <time.h>

void testSingleAdd()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " <<  sp.longestSpan() << std::endl;
	try 
	{
		sp.addNumber(12);
	}
	catch (std::exception &e)
	{
		std::cout << R << e.what() << RESET << std::endl;
	}
	std::vector<int> temp;
	temp = sp.getVector();
	std::cout << "List: ";
	for (size_t i = 0; i < temp.size(); i++)
		std::cout << temp[i] << " ";
}

void testRangAddVector()
{
	Span sp = Span(50000);
	std::vector<int> v(50000);
	std::generate(v.begin(), v.end(), std::rand);
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();
	sp.addNumberRange<std::vector<int> >(it, ite);
	std::vector <int> temp;
	temp = sp.getVector();
	size_t i;
	for (i = 0; i < temp.size(); i++)
		if (temp[i] != v[i])
		{
			std::cout << R << "Error! Value not the same" << RESET << std::endl;
			break ;
		}
	if (i == temp.size())
		std::cout << G << "Success! Values are the same" << RESET << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void testRangAddList()
{
	Span sp = Span(50000);
	std::list<int> v(50000);
	std::generate(v.begin(), v.end(), std::rand);
	std::list<int>::iterator it = v.begin();
	std::list<int>::iterator ite = v.end();
	sp.addNumberRange<std::list<int> >(it, ite);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void Copytest()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	Span sp2 = sp;
	std::vector<int> temp;
	temp = sp2.getVector();
	std::cout << "List: ";
	for (size_t i = 0; i < temp.size(); i++)
		std::cout << temp[i] << " ";
	std::cout << std::endl;
}

int main()
{
	srand(time(0));
	std::cout << Y << "------------Single Add Test-------------" << RESET << std::endl;
	testSingleAdd();
	std::cout << Y << "\n------------Range Add Test1 Vector-------------" << RESET << std::endl;
	testRangAddVector();
	std::cout << Y << "\n------------Range Add Test2 List-------------" << RESET << std::endl;
	testRangAddList();
	std::cout << Y << "\n------------Copy Test-------------" << RESET << std::endl;
	Copytest();
	return 0;
}
