#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("DI4M-TP");
    diamond.whoAmI();
    diamond.attack("Enemy");
    diamond.takeDamage(25);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.whoAmI();
	diamond.highFivesGuys();
    return 0;
}
