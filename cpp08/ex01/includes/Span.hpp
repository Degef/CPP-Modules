#ifndef Span_hpp
#define Span_hpp

//colors
#define RESET		"\033[0m"			
#define R			"\033[31m"
#define G		"\033[32m"		
#define Y		"\033[33m"

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <list>

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
		template <typename T>
		void addNumberRange(typename T::iterator begin, typename T::iterator end) {
			if (_v.size() + std::distance(begin, end) > _n)
				throw FullException();
			while (begin != end)
				_v.push_back(*begin++);
		}
		int shortestSpan();
		int longestSpan();
		std::vector<int> getVector() const;

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