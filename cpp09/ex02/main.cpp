#include "includes/PmergeMe.hpp"

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
