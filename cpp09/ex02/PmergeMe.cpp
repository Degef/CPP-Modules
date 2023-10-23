#include <iostream>
#include <list>

void insertionSort(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right) {
    (void)lst;
	for (std::list<int>::iterator i = left; i != std::next(right); ++i) {
        std::list<int>::iterator j = i;
        while (j != left && *std::prev(j) > *j) {
            std::swap(*j, *std::prev(j));
            --j;
        }
    }
}

void merge(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right) {
    (void)lst;
	std::list<int> leftList(left, std::next(middle));
    std::list<int> rightList(std::next(middle), std::next(right));

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

void mergeInsertionSort(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right, int insertionThreshold) {
    if (std::distance(left, right) >= insertionThreshold) {
        std::list<int>::iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);
        mergeInsertionSort(lst, left, middle, insertionThreshold);
        mergeInsertionSort(lst, std::next(middle), right, insertionThreshold);
        merge(lst, left, middle, right);
    } else {
        insertionSort(lst, left, right);
    }
}

int main() {
    std::list<int> lst;
    lst.push_back(12);
    lst.push_back(11);
    lst.push_back(13);
    lst.push_back(5);
    lst.push_back(6);

    int insertionThreshold = 5;
    
	clock_t start_time = clock();
	std::cout << start_time << std::endl;

    mergeInsertionSort(lst, lst.begin(), --lst.end(), insertionThreshold);

	clock_t end_time = clock();
	std::cout << end_time << std::endl;

	double duration = (double)((end_time - start_time) / CLOCKS_PER_SEC) * 1000000;

    std::cout << "Sorted list: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
	std::cout << "Duration: " << duration << " us " << std::endl;
    return 0;
}
