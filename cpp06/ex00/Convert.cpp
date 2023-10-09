#include "includes/Convert.hpp"

void Converter::convert(const std::string& input) {
//  convert(const std::string& input) {
        std::istringstream iss(input);
        char c = '\0';
        // int i = 0;
        float f = 0.0f;
        double d = 0.0;

        // Try to extract values from the input
        if (!(iss >> c)) {
            std::cout << "char: Non displayable" << std::endl;
        } else if (!isprint(c)) {
            std::cout << "char: impossible" << std::endl;
        } else {
            std::cout << "char: '" << c << "'" << std::endl;
        }

        // iss.clear(); // Clear the error state
        // if (!(iss >> i)) {
        //     std::cout << "int: impossible" << std::endl;
        // } else {
        //     std::cout << "int: " << i << std::endl;
        // }
		try {
        int intValue = std::stoi(input);
        std::cout << "int: " << intValue << std::endl;
		} catch (const std::invalid_argument& e) {
			std::cerr << "int: impossible" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cerr << "int: out of range" << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "int: " << e.what() << std::endl;
		}

        iss.clear();
        iss.seekg(0);
        if (!(iss >> f)) {
            std::cout << "float: impossible" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
        }
		// try {
		// 	std::string const temp = input + ".0";
        // 	float floatValue = std::stof(temp);
        // 	std::cout << "float: " << floatValue << std::endl;
		// } catch (const std::invalid_argument& e) {
		// 	std::cerr << "float: impossible" << std::endl;
		// } catch (const std::out_of_range& e) {
		// 	std::cerr << "float: out of range" << std::endl;
		// }

        iss.clear();
        iss.seekg(0);
        if (!(iss >> d)) {
            std::cout << "double: impossible" << std::endl;
        } else {
            std::cout << "double: " << d << std::endl;
        }
    }
	