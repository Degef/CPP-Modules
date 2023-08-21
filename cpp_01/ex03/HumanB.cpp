#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {
	_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon != NULL && _weapon->getType() != "")
		std::cout << _name << " attacks with their "
				<< this->_weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't have any weapon yet "
				  << std::endl;
}
