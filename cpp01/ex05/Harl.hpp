#include <iostream>
#include <fstream>      // std::ifstream

#ifndef HARL_HPP
#define HARL_HPP

class Harl {

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	Harl();
	~Harl();
	void complain( std::string level );

};

typedef void (Harl::*t_func) ( void );
#endif