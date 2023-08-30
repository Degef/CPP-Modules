#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// virtual member function = "method"
// this makes the program to decide which method to use during the 
// execution (and not compilation)
class Animal {
protected:
    std::string _type;

public:
    Animal();
	Animal(std::string type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const;
};

#endif