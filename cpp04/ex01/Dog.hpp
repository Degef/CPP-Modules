#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
	Brain *_brain;
public:
    Dog();
	Dog( const Dog& src );
    Dog& operator=( const Dog& src );
    ~Dog();
    void makeSound() const;
	Brain& getBrain();
};
#endif