#include "Zombie.hpp"


//if the object is created on the heap it will not be destroyed by itself
// you should call the delete function to destroy the object 
int main() {
    // Allocating zombies on the stack
    randomChump("Stacky");

    // Allocating zombies on the heap
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;

    return 0;
}