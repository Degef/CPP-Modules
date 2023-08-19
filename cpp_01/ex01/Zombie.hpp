#include <iostream>
#include <string.h>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie {

private:
	std::string _name;

public:
	//default constructor
    Zombie();
	// destructor
    ~Zombie();

	void 	announce( void );
	void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
#endif