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
	Zombie(std::string name);
	// destructor
    ~Zombie();

	void 	announce( void );
};

Zombie*	newZombie( std::string name);
void	randomChump( std::string name );

#endif