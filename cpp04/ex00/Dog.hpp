#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    ~Dog();

    void makeSound() const;
};
#endif