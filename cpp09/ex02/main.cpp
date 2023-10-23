#include <iostream>
#include <vector>
#include <ctime>
#include <list>

void insertion_sort1(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge1(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

// void merge2(std::list<int>& arr, int left, int mid, int right)
// {
// 	std::list<int> temp;
// 	std::list<int>::iterator it1 = arr.begin();
// 	std::list<int>::iterator it2 = arr.begin();
// 	std::advance(it1, left);
// 	std::advance(it2, mid + 1);
// 	while (it1 != arr.begin() + mid + 1 && it2 != arr.begin() + right + 1) {
// 		if (*it1 <= *it2) {
// 			temp.push_back(*it1);
// 			it1++;
// 		}
// 		else {
// 			temp.push_back(*it2);
// 			it2++;
// 		}
// 	}
// 	while (it1 != arr.begin() + mid + 1) {
// 		temp.push_back(*it1);
// 		it1++;
// 	}
// 	while (it2 != arr.begin() + right + 1) {
// 		temp.push_back(*it2);
// 		it2++;
// 	}
// 	std::list<int>::iterator it = arr.begin();
// 	std::advance(it, left);
// 	for (std::list<int>::iterator it3 = temp.begin(); it3 != temp.end(); it3++) {
// 		*it = *it3;
// 		it++;
// 	}
// }

// void insertion_sort2(std::list<int>& arr, int left, int right)
// {

// }

void merge_insertion_sort1(std::vector<int>& arr, int left, int right)
{
    if (right - left + 1 <= 5) {
        insertion_sort1(arr, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    merge_insertion_sort1(arr, left, mid);
    merge_insertion_sort1(arr, mid + 1, right);
    merge1(arr, left, mid, right);
}

// void merge_insertion_sort2(std::list<int>& arr, int left, int right)
// {
// 	if (right - left + 1 <= 10) {
// 		insertion_sort(arr, left, right);
// 		return;
// 	}
// 	int mid = left + (right - left) / 2;
// 	merge_insertion_sort2(arr, left, mid);
// 	merge_insertion_sort2(arr, mid + 1, right);
// 	merge(arr, left, mid, right);
// }

int main()
{
    std::vector<int> arr;
    int arr2[] = { 5, 2, 4, 6, 1, 3, 8, 0 };
    for (int i = 0; i < (int)(sizeof(arr2)/sizeof(arr2[0])); i++)
        arr.push_back(arr2[i]);
    std::cout << "Unsorted array: ";
    for (int i = 0; i < (int)arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Measure the time taken by merge_insertion_sort
    clock_t start_time = clock();
    merge_insertion_sort1(arr, 0, (int)arr.size() - 1);
    clock_t end_time = clock();
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Sorted array: ";
    for (int i = 0; i < (int)arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::cout << "Time taken by merge_insertion_sort: " << duration << " us" << std::endl;
	

	// Using list
	std::list<int> arr3;
	for (int i = 0; i < (int)(sizeof(arr2)/sizeof(arr2[0])); i++)
		arr3.push_back(arr2[i]);
	std::cout << "Unsorted list: ";
	for (std::list<int>::iterator it = arr3.begin(); it != arr3.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Measure the time taken by merge_insertion_sort
	start_time = clock();
	arr3.sort();
	end_time = clock();
	duration = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Sorted list: ";
	for (std::list<int>::iterator it = arr3.begin(); it != arr3.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time taken by list::sort: " << duration << " us" << std::endl;
    return 0;
}

// int main()
// {
//     std::vector<int> arr;
// 	int arr2[] = { 5, 2, 4, 6, 1, 3, 8, 0 };
// 	for (int i = 0; i < (int)(sizeof(arr2)/sizeof(arr2[0])); i++)
// 		arr.push_back(arr2[i]);
// 	std::cout << "Unsorted array: ";
// 	for (int i = 0; i < (int)arr.size(); i++)
// 		std::cout << arr[i] << " ";
// 	std::cout << std::endl;
//     merge_insertion_sort(arr, 0, (int)arr.size() - 1);
// 	std::cout << "Sorted array: ";
//     for (int i = 0; i < (int)arr.size(); i++)
//         std::cout << arr[i] << " ";
//     std::cout << std::endl;
//     return 0;
// }
