#include "includes/Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &copy) {
		*this = copy;
}

Span &Span::operator=(const Span &assign) {
	_n = assign._n;
	_v = assign._v;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_v.size() >= _n)
		throw FullException();
	_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_v.size() + std::distance(begin, end) > _n)
		throw FullException();
	while (begin != end)
		_v.push_back(*begin++);
}

int Span::shortestSpan() {
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan() {
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

int Span::size() const {
	return _n;
}

const char *Span::FullException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Span is empty or contains only one element";
}