#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hit_point > 0 && _energy_point > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_point--;
    } else {
        std::cout << "ScavTrap " << _name << " can't attack due to lack of hit points or energy points." << std::endl;
    }
	std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " 
			  << _energy_point << " Attack Damage: " << _attack_damage << std::endl << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
