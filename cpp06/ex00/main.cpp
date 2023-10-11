
#include "includes/Convert.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string input(argv[1]);
	try {
		Converter test(input);
		std::cout << test;
	} catch (std::exception& e) {
		std::cerr << "Input is not a literal scalar type (char, int, float or double)." << std::endl;
		return 1;
	}
    return 0;
}
