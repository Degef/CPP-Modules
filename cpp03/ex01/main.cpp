#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("SGT-TP");
    scav.guardGate();
    scav.attack("Enemy");
    scav.takeDamage(25);
    scav.beRepaired(10);
    return 0;
}
