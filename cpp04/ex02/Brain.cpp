#include "Brain.hpp"
#include <sstream>
 
Brain::Brain( void )
{
	for (int i = 0; i < 100; ++i) {
		std::stringstream ss;
        ss << "Idea " << i;
        _ideas[i] = ss.str();
    }
    std::cout << "Brain Constructor Called." << std::endl;
}

Brain::~Brain( void )
{
    std::cout << "Brain Destructor Called." << std::endl;
}

Brain::Brain( const Brain& other )
{
    *this = other;
}

Brain& Brain::operator=( const Brain& other )
{
    std::cout << "<Brain.cpp:32> Brain copy called." << std::endl;
    if ( this != &other ) {
        for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return _ideas[index];
	}
	return "Invalid Index";
}
