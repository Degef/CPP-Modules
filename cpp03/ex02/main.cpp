#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap frag("FR4G-TP");
	frag.highFivesGuys();
    frag.attack("Enemy");
    frag.takeDamage(25);
    frag.beRepaired(10);
    return 0;
}
