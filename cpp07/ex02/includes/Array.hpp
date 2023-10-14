#ifndef Array_hpp
#define Array_hpp

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	private:
		T*		_array;
		int		_size;
	public:
		Array() : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array& copy) : _array(new T[copy._size]), _size(copy._size)	{
			for (int i = 0; i < copy._size; i++)
				_array[i] = copy._array[i];
		}
		~Array() { delete [] _array; }
		Array& operator=(const Array& op) {
			if (this == &op)
				return (*this);
			delete [] _array;
			_array = new T[op._size];
			_size = op._size;
			for (int i = 0; i < op._size; i++)
				_array[i] = op._array[i];
			return (*this);
		}
		T& operator[](int i) {
			if (i < 0 || i >= _size)
				throw OutOfRangeException();
			return (_array[i]);
		}
		int size() const { return (_size); }
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw() {return ("Out of range");}
		};
};

#endif