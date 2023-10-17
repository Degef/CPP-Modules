#include "includes/Span.hpp"

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

void testRangAdd()
{
	Span sp = Span(50000);
	std::vector<int> v(50000);
	std::generate(v.begin(), v.end(), std::rand);
	sp.addNumber(v.begin(), v.end()); 
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
	std::cout << Y << "------------Single Add Test-------------" << RESET << std::endl;
	testSingleAdd();
	std::cout << Y << "\n------------Range Add Test-------------" << RESET << std::endl;
	testRangAdd();
	std::cout << Y << "\n------------Copy Test-------------" << RESET << std::endl;
	Copytest();
	return 0;
}
