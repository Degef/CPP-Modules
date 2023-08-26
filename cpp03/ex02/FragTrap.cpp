#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hit_point = 100;
    _energy_point = 100;
    _attack_damage = 30;
    std::cout << "FragTrap constructor called for " << _name << std::endl;
	std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " 
			  << _energy_point << " Attack Damage: " << _attack_damage << std::endl << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_hit_point > 0 && _energy_point > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_point--;
    } else 
        std::cout << "FragTrap " << _name << " can't attack due to lack of hit points or energy points." << std::endl;
	std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " 
			  << _energy_point << " Attack Damage: " << _attack_damage << std::endl << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " hi fives everyone." << std::endl;
}
