#ifndef Span_hpp
#define Span_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span {
	private:
		unsigned int _n;
		std::vector<int> _v;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		Span &operator=(const Span &assign);
		~Span();

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		int size() const;

		class FullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
#endif