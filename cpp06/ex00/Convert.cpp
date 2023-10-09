#include "includes/Convert.hpp"

Converter::Converter() : _type(0), _asInt(0), _asFloat(0), _asDouble(0), _asChar(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Converter::Converter(const Converter& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Converter::~Converter() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Converter& Converter::operator=(const Converter& other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
		this->_asInt = other._asInt;
		this->_asFloat = other._asFloat;
		this->_asDouble = other._asDouble;
		this->_asChar = other._asChar;
	}
	return (*this);
}

int		Converter::getType() const {
	return (this->_type);
}

int		Converter::getAsInt() const {
	return (this->_asInt);
}

float	Converter::getAsFloat() const {
	return (this->_asFloat);
}

double	Converter::getAsDouble() const {
	return (this->_asDouble);
}

char	Converter::getAsChar() const {
	return (this->_asChar);
}

void	Converter::ExtractType(const std::string& input) {
	if (input.length() == 1 && !isdigit(input[0])) {
		this->_type = CHAR;
		this->_asChar = input[0];
	}
	else if (input == "nan" || input == "nanf") {
		this->_type = NAN_;
		this->_asFloat = std::numeric_limits<float>::quiet_NaN();
	}
	else if (input == "inf" || input == "inff") {
		this->_type = INF_;
		this->_asFloat = std::numeric_limits<float>::infinity();
	}
	else {
		std::stringstream ss(input);
		if (input.find('.') != std::string::npos) {
			if (input.find('f') != std::string::npos) {
				this->_type = FLOAT;
				ss >> this->_asFloat;
			}
			else {
				this->_type = DOUBLE;
				ss >> this->_asDouble;
			}
		}
		else {
			this->_type = INT;
			ss >> this->_asInt;
		}
	}
}

void Converter::FromChar(const std::string& input) {
	std::cout << "char: '" << this->_asChar << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(this->_asChar) << std::endl;
	std::cout << "float: " << static_cast<float>(this->_asChar) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_asChar) << ".0" << std::endl;
}

void Converter::FromInt(const std::string& input) {
	std::cout << "char: ";
	if (this->_asInt < 0 || this->_asInt > 127) {
		std::cout << "impossible" << std::endl;
	}
	else if (this->_asInt < 32 || this->_asInt == 127) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << "'" << static_cast<char>(this->_asInt) << "'" << std::endl;
	}
	std::cout << "int: " << this->_asInt << std::endl;
	std::cout << "float: " << static_cast<float>(this->_asInt) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_asInt) << ".0" << std::endl;
}

void Converter::FromFloat(const std::string& input) {
	std::cout << "char: ";
	if (this->_asFloat < 0 || this->_asFloat > 127) {
		std::cout << "impossible" << std::endl;
	}
	else if (this->_asFloat < 32 || this->_asFloat == 127) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << "'" << static_cast<char>(this->_asFloat) << "'" << std::endl;
	}
	std::cout << "int: ";
	if (this->_asFloat < std::numeric_limits<int>::min() || this->_asFloat > std::numeric_limits<int>::max()) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<int>(this->_asFloat) << std::endl;
	}
	std::cout << "float: " << this->_asFloat << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_asFloat) << std::endl;
}

void Converter::FromDouble(const std::string& input) {
	std::cout << "char: ";
	if (this->_asDouble < 0 || this->_asDouble > 127) {
		std::cout << "impossible" << std::endl;
	}
	else if (this->_asDouble < 32 || this->_asDouble == 127) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << "'" << static_cast<char>(this->_asDouble) << "'" << std::endl;
	}
	std::cout << "int: ";
	if (this->_asDouble < std::numeric_limits<int>::min() || this->_asDouble > std::numeric_limits<int>::max()) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<int>(this->_asDouble) << std::endl;
	}
	std::cout << "float: ";
	if (this->_asDouble < std::numeric_limits<float>::min() || this->_asDouble > std::numeric_limits<float>::max()) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << static_cast<float>(this->_asDouble) << "f" << std::endl;
	}
	std::cout << "double: " << this->_asDouble << std::endl;
}

Converter::Converter(const std::string& input) {
	this->ExtractType(input);
	if (this->_type == CHAR) {
		this->FromChar(input);
	}
	else if (this->_type == INT) {
		this->FromInt(input);
	}
	else if (this->_type == FLOAT) {
		this->FromFloat(input);
	}
	else if (this->_type == DOUBLE) {
		this->FromDouble(input);
	}
	else if (this->_type == NAN_) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (this->_type == INF_) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}