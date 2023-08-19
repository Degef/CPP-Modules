#include "Zombie.hpp"

int main() {
    int numZombies = 5;
    std::string zombieName = "HordeZombie";
    
    Zombie* horde = zombieHorde(numZombies, zombieName);
    
    for (int i = 0; i < numZombies; i++) {
        horde[i].announce();
    }
    
    delete[] horde; // Free the allocated memory
    
    return 0;
}