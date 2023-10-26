#include "includes/PmergeMe.hpp"

int PmergeMe::insertionThreshold = 4;

PmergeMe::PmergeMe(char **argv, int argc): _lst(std::list<int>()), _vec(std::vector<int>()) {
    try {
        for (int i = 1; i < argc; ++i) {
            char *endptr;
            long value = std::strtol(argv[i], &endptr, 10);
            if (*endptr != '\0') {
                throw std::invalid_argument("Invalid input: " + std::string(argv[i]));
            }
            _lst.push_back(static_cast<int>(value));
        }
    } catch (std::exception& e) {
        std::cout << R << "Error: " << e.what() << RESET << std::endl;
        exit(1);
    }
    _vec = std::vector<int>(_lst.begin(), _lst.end());
}

PmergeMe::PmergeMe(PmergeMe const & src): _lst(src._lst), _vec(src._vec) {
	*this = src;
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	if (this != &rhs) {
		_lst = rhs._lst;
		_vec = rhs._vec;
	}
	return *this;
}

void PmergeMe::insertionSortVector(std::vector<int>::iterator left, std::vector<int>::iterator right) {
    for (std::vector<int>::iterator i = left; i != right + 1; ++i) {
        std::vector<int>::iterator j = i;
        while (j != left) {
            std::vector<int>::iterator prev = j;
            --prev;
            if (*j < *prev) {
                std::swap(*j, *prev);
                j = prev;
            } else {
                break;
            }
        }
    }
}

void PmergeMe::insertionSortList(std::list<int>::iterator left, std::list<int>::iterator right) {
    std::list<int>::iterator temp = right;
    ++temp;
    for (std::list<int>::iterator i = left; i != temp; ++i) {
        std::list<int>::iterator j = i;
        while (j != left) {
            std::list<int>::iterator prev = j;
            --prev;
            if (*j < *prev) {
                std::swap(*j, *prev);
                j = prev;
            } else {
                break;
            }
        }
    }
}

void PmergeMe::mergeList(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right) {
	std::list<int> leftList(left, ++middle);
    std::list<int> rightList(middle--, (++right--));

    std::list<int>::iterator i = leftList.begin();
    std::list<int>::iterator j = rightList.begin();
    std::list<int>::iterator k = left;

    while (i != leftList.end() && j != rightList.end()) {
        if (*i <= *j) {
            *k = *i;
            ++i;
        } else {
            *k = *j;
            ++j;
        }
        ++k;
    }

    while (i != leftList.end()) {
        *k = *i;
        ++i;
        ++k;
    }

    while (j != rightList.end()) {
        *k = *j;
        ++j;
        ++k;
    }
}

void PmergeMe::mergeVector(std::vector<int>::iterator left, std::vector<int>::iterator middle, std::vector<int>::iterator right) {
	std::vector<int> leftList(left, (middle + 1));
	std::vector<int> rightList((middle + 1), (right + 1));

	std::vector<int>::iterator i = leftList.begin();
	std::vector<int>::iterator j = rightList.begin();
	std::vector<int>::iterator k = left;

	while (i != leftList.end() && j != rightList.end()) {
		if (*i <= *j) {
			*k = *i;
			++i;
		} else {
			*k = *j;
			++j;
		}
		++k;
	}

	while (i != leftList.end()) {
		*k = *i;
		++i;
		++k;
	}

	while (j != rightList.end()) {
		*k = *j;
		++j;
		++k;
	}
}

void PmergeMe::SortList(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right) {
    if (std::distance(left, right) >= PmergeMe::insertionThreshold) {
        std::list<int>::iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);
        SortList(lst, left, middle);
		++middle;
        SortList(lst, middle, right);
		--middle;
        mergeList(left, middle, right);
    } else {
        insertionSortList(left, right);
    }
}

void PmergeMe::SortVector(std::vector<int>& vec, std::vector<int>::iterator left, std::vector<int>::iterator right) {
	if (std::distance(left, right) >= PmergeMe::insertionThreshold) {
		std::vector<int>::iterator middle = left;
		std::advance(middle, std::distance(left, right) / 2);
		SortVector(vec, left, middle);
		SortVector(vec, (middle + 1), right);
		mergeVector(left, middle, right);
	} else {
		insertionSortVector(left, right);
	}
}

std::list<int> PmergeMe::getList(void) {
	return _lst;
}

std::vector<int> PmergeMe::getVector(void) {
	return _vec;
}

void PmergeMe::printTime(void) {
	std::cout << C << "Time to process a range of " << _lst.size() << " elements with std::list: " 
	<< (double)_lstDuration / CLOCKS_PER_SEC * 1000 << " ms (" << _lstDuration << " clock ticks)" << RESET << std::endl;
	
	std::cout << C << "Time to process a range of " << _vec.size() << " elements with std::vector: " 
	<< (double) _vecDuration / CLOCKS_PER_SEC * 1000 << " ms (" << _vecDuration << " clock ticks)" << RESET << std::endl;
}
