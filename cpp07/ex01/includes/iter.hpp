#ifndef iter_hpp
#define iter_hpp

#include <iostream>

template <typename T>
void print(T const& i) {
	std::cout << i << std::endl;
}

template <typename T, typename F>
void iter(T* array, size_t length, F f) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif