#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("CL4P-TP");
    clap.attack("Enemy");
    clap.takeDamage(115);
    clap.beRepaired(3);
    return 0;
}
