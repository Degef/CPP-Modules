#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name),  _hit_point(10), 
	_energy_point(10), _attack_damage(0) {
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " 
			  << _energy_point << " Attack Damage: " << _attack_damage << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	this->_name = other._name;
	this->_hit_point = other._hit_point;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_point = other._hit_point;
		this->_energy_point = other._energy_point;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

// Member function definition to attack
void ClapTrap::attack(const std::string& target) {
    if (_hit_point > 0 && _energy_point > 0)
	{
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage 
				  << " points of damage!" << std::endl;
        _energy_point--;
    } 
	else
        std::cout << "ClapTrap " << _name << " can't attack due to lack of hit points or energy points."
				  << std::endl;
	std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " << _energy_point << " Attack Damage: " 
			  << _attack_damage << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_point > 0 && _hit_point > 0 )
	{
		_hit_point += amount;
		std::cout << "ClapTrap " << _name << " repaired with,"<< amount << " making it energy point " << _hit_point 
				  << std::endl;
		_energy_point--;
	}
	else
        std::cout << "ClapTrap " << _name << " can't be repaired due to lack of energy points or hit points." << std::endl;
	std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " << _energy_point << " Attack Damage: " 
			  << _attack_damage << std::endl << std::endl;
}

// Member function definition to take damage
void ClapTrap::takeDamage(unsigned int amount) {
    if (_hit_point > 0 && _energy_point > 0) {
        _hit_point = (amount > _hit_point) ? 0 : _hit_point - amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. Remaining hit points: " 
				  << _hit_point << std::endl;
    }
	else
        std::cout << "ClapTrap " << _name << " has no hit points left." << std::endl;
	std::cout << "::::Status Info:::: name: " << _name << "  Hit Points: " << _hit_point << "  Energy Points: " << _energy_point << " Attack Damage: " 
			  << _attack_damage << std::endl << std::endl;
}
