#ifndef FragTRAP_HPP
#define FragTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap {
public:
    FragTrap(const std::string& name);
    ~FragTrap();

    void attack(const std::string& target); // Overriding attack function
    void highFivesGuys(void);
};
#endif