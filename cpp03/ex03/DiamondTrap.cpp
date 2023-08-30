#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	this->_name = name;
	FragTrap::_hit_point = 100;
	ScavTrap::_energy_point = 30;
	FragTrap::_attack_damage = 10;
std::cout << "Daimond constructor called for " << _name << std::endl;
std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " 
			  << _energy_point << " Attack Damage: " << _attack_damage << std::endl << std::endl;

}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
