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

void PmergeMe::testList(std::list<int> lst) {

	std::cout << Y << "------ INSERTION-MERGE SORT WITH STD::LIST ------" << RESET << std::endl;
	std::cout << "Before Sort (list):		[ ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]"<< std::endl;

	clock_t start_time = clock();
    Sort(lst.begin(), --lst.end());

	clock_t end_time = clock();

	_lstDuration = end_time - start_time;

    std::cout << G <<  "After Sort (list):		[ ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]"<< RESET << std::endl;
}

void PmergeMe::testVector(std::vector<int> vec) {
	
	std::cout << Y << "------ INSERTION-MERGE SORT WITH STD::VECTOR ------" << RESET << std::endl;
	std::cout << "Before Sort (vector):		[ ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]"<< std::endl;

	clock_t start_time = clock();

	Sort(vec.begin(), --vec.end());

	clock_t end_time = clock();

	_vecDuration = (end_time - start_time);

	std::cout << G <<  "After Sort (vector):		[ ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]"<< RESET << std::endl;
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

template <typename Iterator>
void PmergeMe::mergeSort(Iterator left, Iterator middle, Iterator right) {
    std::list<typename std::iterator_traits<Iterator>::value_type> leftList(left, (++middle));
    std::list<typename std::iterator_traits<Iterator>::value_type> rightList((middle--), (++right--));

    typename std::list<typename std::iterator_traits<Iterator>::value_type>::iterator i = leftList.begin();
    typename std::list<typename std::iterator_traits<Iterator>::value_type>::iterator j = rightList.begin();
    Iterator k = left;

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

template <typename Iterator>
void PmergeMe::insertionSort(Iterator left, Iterator right) {
    Iterator temp = right;
    ++temp;
    for (Iterator i = left; i != temp; ++i) {
        Iterator j = i;
        while (j != left) {
            Iterator prev = j;
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

template <typename Iterator>
void PmergeMe::Sort(Iterator left, Iterator right) {
    if (std::distance(left, right) >= PmergeMe::insertionThreshold) {
        Iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);
        Sort(left, middle);
        ++middle;
        Sort(middle, right);
        --middle;
        mergeSort(left, middle, right);
    } else {
        insertionSort(left, right);
    }
}
