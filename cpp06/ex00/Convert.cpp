#include "includes/Convert.hpp"

Converter::Converter() : _type(0), _asInt(0), _asFloat(0), _asDouble(0), _asChar(0) {
	return ;
}

Converter::Converter(const Converter& copy) {
	*this = copy;
}

Converter::~Converter() {
	return ;
}

Converter& Converter::operator=(const Converter& other) {
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

Converter::Converter(const std::string& input) {
	if (input.length() == 1 && !isdigit(input[0])) {
		this->_type = CHAR;
		this->_asChar = input[0];
	}
	else if (input == "nan" || input == "nanf") {
		this->_type = NAN_;
		this->_asFloat = std::numeric_limits<float>::quiet_NaN();
		this->_asDouble = std::numeric_limits<double>::quiet_NaN();
	}
	else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff") {
		this->_type = INF_;
		this->_asFloat = std::numeric_limits<float>::infinity();
		this->_asDouble = std::numeric_limits<double>::infinity();
	}
	else if (input == "-inf" || input == "-inff") {
		this->_type = INF_;
		this->_asFloat = -std::numeric_limits<float>::infinity();
		this->_asDouble = -std::numeric_limits<double>::infinity();
	}
	else {
		if (input.find('.') != std::string::npos) {
			if (input.find('f') != std::string::npos) {
				this->_type = FLOAT;
				this->_asFloat = std::strtof(input.c_str(), NULL);
			}
			else {
				this->_type = DOUBLE;
				this->_asDouble = std::strtod(input.c_str(), NULL);
			}
		}
		else {
			this->_type = INT;
			this->_asInt = std::stoi(input);
		}
	}
}

void Converter::DisplayFromChar(std::ostream& out) const {
	out << "char:		'" << this->_asChar << "'" << std::endl;
	out << "int:		" << static_cast<int>(this->_asChar) << std::endl;
	out << "float:		" << static_cast<float>(this->_asChar) << ".0f" << std::endl;
	out << "double:		" << static_cast<double>(this->_asChar) << ".0" << std::endl;
}

void Converter::DisplayFromInt(std::ostream& out) const {
	out << "char:		";
	if (this->_asInt < 0 || this->_asInt > 127) {
		out << "impossible" << std::endl;
	}
	else if (this->_asInt < 32 || this->_asInt == 127) {
		out << "Non displayable" << std::endl;
	}
	else {
		out << "'" << static_cast<char>(this->_asInt) << "'" << std::endl;
	}
	out << "int:		" << this->_asInt << std::endl;
	out << "float:		" << static_cast<float>(this->_asInt) << ".0f" << std::endl;
	out << "double:		" << static_cast<double>(this->_asInt) << ".0" << std::endl;
}

void Converter::DisplayFromFloat(std::ostream& out) const {
	out << "char:		";
	if (this->_asFloat < 0 || this->_asFloat > 127)
		out << "impossible" << std::endl;
	else if (this->_asFloat < 32 || this->_asFloat == 127)
		out << "Non displayable" << std::endl;
	else
		out << "'" << static_cast<char>(this->_asFloat) << "'" << std::endl;
	
	out << "int:		";
	if (this->_asFloat < std::numeric_limits<int>::min() || this->_asFloat > std::numeric_limits<int>::max())
		out << "impossible" << std::endl;
	else
		out << static_cast<int>(this->_asFloat) << std::endl;
	
	out << "float:		";
	if (_asFloat == static_cast<int>(_asFloat))
		out << _asFloat << ".0f" << std::endl;
	else
		out << _asFloat << "f" << std::endl;
	
	out << "double:		";
	if (_asFloat == static_cast<int>(_asFloat))
		out << static_cast<double>(_asFloat) << ".0" << std::endl;
	else
		out << static_cast<double>(_asFloat) << std::endl;
}

void Converter::DisplayFromDouble(std::ostream& out) const {
	out << "char:		";
	if (this->_asDouble < 0 || this->_asDouble > 127)
		out << "impossible" << std::endl;
	else if (this->_asDouble < 32 || this->_asDouble == 127)
		out << "Non displayable" << std::endl;
	else
		out << "'" << static_cast<char>(this->_asDouble) << "'" << std::endl;

	out << "int:		";
	if (this->_asDouble < std::numeric_limits<int>::min() || this->_asDouble > std::numeric_limits<int>::max())
		out << "impossible" << std::endl;
	else 
		out << static_cast<int>(this->_asDouble) << std::endl;

	out << "float:		";
	if (_asDouble == static_cast<int>(_asDouble))
		out << static_cast<float>(this->_asDouble) << ".0f" << std::endl;
	else
		out << static_cast<float>(this->_asDouble) << "f" << std::endl;
	
	out << "double:		";
	if (_asDouble == static_cast<int>(_asDouble))
		out << _asDouble << ".0" << std::endl;
	else 
		out << _asDouble << std::endl;
}

void Converter::DisplayFromUnknown(std::ostream& out, int flag) const {
	if (flag == NAN_)
	{
		out << "char:		impossible" << std::endl;
		out << "int:		impossible" << std::endl;
		out << "float:		" << this->getAsFloat() << "f" << std::endl;
		out << "double:		" << this->getAsDouble() <<  std::endl;
	}
	else if (flag == INF_) 
	{
		out << "char:		impossible" << std::endl;
		out << "int:		impossible" << std::endl;
		out << "float:		" << getAsFloat() << "f" << std::endl;
		out << "double:		" << getAsDouble() << std::endl;
	}
	else if (flag == UNKNOWN)
	{
		out << "char:		impossible" << std::endl;
		out << "int:		impossible" << std::endl;
		out << "float:		impossible" << std::endl;
		out << "double:		impossible" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Converter& obj) {
	switch (obj.getType())
	{
		case CHAR:
			obj.DisplayFromChar(out);
			break;
		case INT:
			obj.DisplayFromInt(out);
			break;
		case FLOAT:
			obj.DisplayFromFloat(out);
			break;
		case DOUBLE:
			obj.DisplayFromDouble(out);
			break;
		case NAN_:
			obj.DisplayFromUnknown(out, NAN_);
			break;
		case INF_:
			obj.DisplayFromUnknown(out, INF_);
			break;
		default:
			obj.DisplayFromUnknown(out, UNKNOWN);
			break;
	}
	return (out);
}
