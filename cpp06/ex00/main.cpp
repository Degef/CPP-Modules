
#include "includes/Convert.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string input(argv[1]);

    Converter::convert(input);

    return 0;
}
