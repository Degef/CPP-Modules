#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name) {
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	FragTrap::_hit_point = 100;
	ScavTrap::_energy_point = 30;
	FragTrap::_attack_damage = 10;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
