#include "ClapTrap.hpp"

#ifndef FragTRAP_HPP
#define FragTRAP_HPP

class FragTrap : virtual public ClapTrap {
public:
    FragTrap(const std::string& name);
    ~FragTrap();

    void attack(const std::string& target); // Overriding attack function
    void highFivesGuys(void);
};
#endif