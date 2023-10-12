#include "includes/Classes.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(NULL)));

	for (int i = 0; i < 10; i++) {
		Base* p = generate();
		identify(p);
		identify(*p);
		delete p;
		std::cout << std::endl;
	}

    return 0;
}
