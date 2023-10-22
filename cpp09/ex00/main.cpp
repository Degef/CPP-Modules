#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
    std::map<time_t, double> dataMap;

	if (argc != 2) {
		std::cerr << "Usage: ./a.out <filename>" << std::endl;
		return 1;
	}
    if (getData(dataMap) != 0)
		return 1;

	if (getInputValues(dataMap, argv) != 0)
		return 1;
	
    return 0;
}
