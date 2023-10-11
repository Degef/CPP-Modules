#include "includes/Classes.hpp"

// Function to generate a random instance of A, B, or C and return as a Base pointer
Base* generate() {
    int choice = rand() % 3;
    switch (choice) {
        case 0: 
			std::cout << "Instance generated is	 : A" << std::endl;
			return new A();
        case 1:
			std::cout << "Instance generated is	 : B" << std::endl;
			return new B();
        case 2:
			std::cout << "Instance generated is	 : C" << std::endl;
			return new C();
        default: return nullptr;
    }
}

// Function to identify and print the type of the object pointed to by p
void identify(Base* p) {
	std::cout << "Instance pointed by p is : ";
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}
 
// Function to identify and print the type of the object referred to by p
void identify(Base& p) {
	std::cout << "Instance pointed by p is : ";
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast& e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast& e) {}
	std::cout << "Unknown" << std::endl;
}
