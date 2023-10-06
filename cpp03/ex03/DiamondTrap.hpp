#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

class DiamondTrap: public FragTrap, public ScavTrap 
{
private:
    std::string _name;

public:
    DiamondTrap( std::string name );
    ~DiamondTrap();

    using   ScavTrap::attack;
    void    whoAmI( void );
};

#endif