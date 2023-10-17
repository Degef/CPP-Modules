# ifndef MutantStack_hpp
# define MutantStack_hpp


//color
# define RESET		"\033[0m"
# define B		"\033[30m"
# define R		"\033[31m"	
# define G		"\033[32m"		
# define Y		"\033[33m"		

#include <iostream>
#include <stack>
#include <algorithm>
#include <deque>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {	std::stack<T>::c = std::deque<T>();}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		~MutantStack() {}
		MutantStack &operator=(MutantStack const &other) {
			if (this != &other)
				this->c = other.c;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return std::stack<T>::c.begin(); };
		iterator end() { return std::stack<T>::c.end(); };

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return std::stack<T>::c.begin();	};
		const_iterator end() const { return std::stack<T>::c.end();	};

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); };
		reverse_iterator rend() { return std::stack<T>::c.rend(); };

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const {	return std::stack<T>::c.rbegin(); };
		const_reverse_iterator rend() const { return std::stack<T>::c.rend(); };

};

# endif