#include "includes/MutantStack.hpp"

void testList()
{
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Back: " << lst.back() << std::endl;
	std::cout << "Size: " << lst.size() << std::endl;
	lst.pop_back();
	std::cout << "Back: " << lst.back() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	std::cout << G << "List: [";
	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
		if (it != ite)
			std::cout << ", ";
		else
			std::cout << "]" << RESET << std::endl;
	}
}

void testMutantStack()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << G << "MutantStack: [";
	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
		if (it != ite)
			std::cout << ", ";
		else
			std::cout << "]" << RESET << std::endl;
	}
	std::stack<int> s(mstack);
}

void testStringMutantStack()
{
	MutantStack<std::string> mstack;
	mstack.push("Hello!");
	mstack.push("World");
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.push("Here");
	mstack.push("Are");
	mstack.push("More");
	mstack.push("Words");
	mstack.push("To");
	mstack.push("Test");
	MutantStack<std::string>::const_iterator it = mstack.begin();
	MutantStack<std::string>::const_iterator ite = mstack.end();
	++it;
	--it;
	std::cout << G << "Strings: [";
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
		else
			std::cout << "]" << RESET << std::endl;
	}
	std::stack<std::string> s(mstack);
}

void testReverseIterator()
{
	MutantStack<int> mstack;
	mstack.push(4);
	mstack.push(2);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(37);
	mstack.push(0);
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	std::cout << G << "Reverse: ["; 
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
		else
			std::cout << "]" << RESET << std::endl;
	}
	std::stack<int> s(mstack);
}

int main()
{
	std::cout << Y << "--------------Test MutantStack-----------------" << RESET << std::endl;
	testMutantStack();
	std::cout << Y << "------------------Test List-------------------" << RESET << std::endl;
	testList();
	std::cout << Y << "----------Test String MutantStack-------------" << RESET << std::endl;
	testStringMutantStack();
	std::cout << Y << "--------------Test Reverse Iterator-------------" << RESET << std::endl;
	testReverseIterator();
	std::cout << Y << "---------------------End-------------------------" << RESET << std::endl;
	return 0;
}
