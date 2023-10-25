#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <time.h>
#include <cstdlib>

//colors
#define RESET   "\033[0m"
#define R     	"\033[31m"      /* Red */
#define G   	"\033[32m"      /* Green */
#define Y  		"\033[33m"      /* Yellow */
#define B    	"\033[34m"      /* Blue */
#define M    	"\033[35m"      /* Magenta */
#define C   	"\033[36m"      /* Cyan */

class PmergeMe {
private:
	std::list<int>		_lst;
	std::vector<int>	_vec;
	clock_t				_lstDuration;
	clock_t				_vecDuration;

public:
	PmergeMe(char **argv, int argc);
	PmergeMe(PmergeMe const & src);
	~PmergeMe(void);
	PmergeMe & operator=(PmergeMe const & rhs);

	static int insertionThreshold;

	std::list<int>		getList(void);
	std::vector<int>	getVector(void);
	void 	testList(std::list<int> lst);
	void 	testVector(std::vector<int> vec);
	// void 	insertionSortList(std::list<int>::iterator left, std::list<int>::iterator right);
	// void 	insertionSortVector(std::vector<int>::iterator left, std::vector<int>::iterator right);
	// void 	mergeList(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right);
	// void 	mergeVector(std::vector<int>::iterator left, std::vector<int>::iterator middle, std::vector<int>::iterator right);
	template <typename Iterator>
	void insertionSort(Iterator left, Iterator right);
	
	template <typename Iterator>
	void 	mergeSort(Iterator left, Iterator middle, Iterator right);

	template <typename Iterator>
	void Sort(Iterator left, Iterator right);
	// void 	SortList(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right);
	// void 	SortVector(std::vector<int>& vec, std::vector<int>::iterator left, std::vector<int>::iterator right);
	void	printTime(void);
};

#endif