#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	std::cout << _name << " attacks with their "
			  << this->_weapon->getType() << std::endl;
}
