#include "includes/PmergeMe.hpp"

void PmergeMe::testList(std::list<int> lst) {

	std::cout << Y << "------ INSERTION-MERGE SORT WITH STD::LIST ------" << RESET << std::endl;
	std::cout << "Before Sort (list):		[ ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]"<< std::endl;

	clock_t start_time = clock();
    SortList(lst, lst.begin(), --lst.end());

	clock_t end_time = clock();

	_lstDuration = end_time - start_time;

    std::cout << G <<  "After Sort (list):		[ ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]"<< RESET << std::endl;
	if (is_sorted(lst)) {
		std::cout << G << "OK! List is sorted" << RESET << std::endl;
	} else {
		std::cout << R << "List is not sorted" << RESET << std::endl;
	}
}

void PmergeMe::testVector(std::vector<int> vec) {
	
	std::cout << Y << "------ INSERTION-MERGE SORT WITH STD::VECTOR ------" << RESET << std::endl;
	std::cout << "Before Sort (vector):		[ ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]"<< std::endl;

	clock_t start_time = clock();

	SortVector(vec, vec.begin(), --vec.end());

	clock_t end_time = clock();

	_vecDuration = (end_time - start_time);

	std::cout << G <<  "After Sort (vector):		[ ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]"<< RESET << std::endl;
	if (is_sorted(vec)) {
		std::cout << G << "OK! Vector is sorted" << RESET << std::endl;
	} else {
		std::cout << R << "Vector is not sorted" << RESET << std::endl;
	}
}

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe <unsorted numbers>" << std::endl;
		return 1;
	}

	PmergeMe pmergeMe(argv, argc);
	pmergeMe.testList(pmergeMe.getList());
	pmergeMe.testVector(pmergeMe.getVector());
	pmergeMe.printTime();
    return 0;
}
