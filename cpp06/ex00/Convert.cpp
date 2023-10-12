#include "includes/Convert.hpp"

int		ScalarConverter::_type = 0;
long	ScalarConverter::_asInt = 0;
float	ScalarConverter::_asFloat = 0.0f;
double	ScalarConverter::_asDouble = 0.0;
char	ScalarConverter::_asChar = '\0';

bool isdigit(const char& c) {
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool isOnlyDigits(const std::string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' 
			&& input[i] != '-' && input[i] != '+')
			return (false);
	}
	return (true);
}

void ScalarConverter::Identify_type(const std::string& input)
{
	if (input.length() == 1 && !isdigit(input[0])) {
		_type = CHAR;
		_asChar = input[0];
	}
	else if (input == "nan" || input == "nanf") {
		_type = NAN_;
		_asFloat = std::numeric_limits<float>::quiet_NaN();
		_asDouble = std::numeric_limits<double>::quiet_NaN();
	}
	else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff") {
		_type = INF_;
		_asFloat = std::numeric_limits<float>::infinity();
		_asDouble = std::numeric_limits<double>::infinity();
	}
	else if (input == "-inf" || input == "-inff") {
		_type = INF_;
		_asFloat = -std::numeric_limits<float>::infinity();
		_asDouble = -std::numeric_limits<double>::infinity();
	}
	else if (!isOnlyDigits(input)) {
		throw std::exception();
	}
	else {
		if (input.find('.') != std::string::npos) {
			if (input.find('f') != std::string::npos) {
				_type = FLOAT;
				_asFloat = std::strtof(input.c_str(), NULL);
			}
			else {
				_type = DOUBLE;
				_asDouble = std::strtod(input.c_str(), NULL);
			}
		}
		else {
			_type = INT;
			_asInt = std::strtol(input.c_str(), NULL, 10);
		}
	}
}

void ScalarConverter::DisplayFromChar(std::ostream& op) {
	op << "char:		'" << _asChar << "'" << std::endl;
	op << "int:		" << static_cast<int>(_asChar) << std::endl;
	op << "float:		" << static_cast<float>(_asChar) << ".0f" << std::endl;
	op << "double:		" << static_cast<double>(_asChar) << ".0" << std::endl;
}

void ScalarConverter::DisplayFromInt(std::ostream& op)  {
	op << "char:		";
	if (_asInt < 0 || _asInt > 127) {
		op << "impossible" << std::endl;
	}
	else if (_asInt < 32 || _asInt == 127) {
		op << "Non displayable" << std::endl;
	}
	else {
		op << "'" << static_cast<char>(_asInt) << "'" << std::endl;
	}
	op << "int:		";
	if (_asInt < std::numeric_limits<int>::min() || _asInt > std::numeric_limits<int>::max())
		op << "overflow" << std::endl;
	else
		op << _asInt << std::endl;
	op << "float:		" << static_cast<float>(_asInt) << ".0f" << std::endl;
	op << "double:		" << static_cast<double>(_asInt) << ".0" << std::endl;
}

void ScalarConverter::DisplayFromFloat(std::ostream& op)  {
	op << "char:		";
	if (_asFloat < 0 || _asFloat > 127)
		op << "impossible" << std::endl;
	else if (_asFloat < 32 || _asFloat == 127)
		op << "Non displayable" << std::endl;
	else
		op << "'" << static_cast<char>(_asFloat) << "'" << std::endl;
	
	op << "int:		";
	if (_asFloat < std::numeric_limits<int>::min() || _asFloat > std::numeric_limits<int>::max())
		op << "impossible" << std::endl;
	else
		op << static_cast<int>(_asFloat) << std::endl;
	
	op << "float:		";
	if (_asFloat == static_cast<int>(_asFloat))
		op << _asFloat << ".0f" << std::endl;
	else
		op << _asFloat << "f" << std::endl;
	
	op << "double:		";
	if (_asFloat == static_cast<int>(_asFloat))
		op << static_cast<double>(_asFloat) << ".0" << std::endl;
	else
		op << static_cast<double>(_asFloat) << std::endl;
}

void ScalarConverter::DisplayFromDouble(std::ostream& op)  {
	op << "char:		";
	if (_asDouble < 0 || _asDouble > 127)
		op << "impossible" << std::endl;
	else if (_asDouble < 32 || _asDouble == 127)
		op << "Non displayable" << std::endl;
	else
		op << "'" << static_cast<char>(_asDouble) << "'" << std::endl;

	op << "int:		";
	if (_asDouble < std::numeric_limits<int>::min() || _asDouble > std::numeric_limits<int>::max())
		op << "impossible" << std::endl;
	else 
		op << static_cast<int>(_asDouble) << std::endl;

	op << "float:		";
	if (_asDouble == static_cast<int>(_asDouble))
		op << static_cast<float>(_asDouble) << ".0f" << std::endl;
	else
		op << static_cast<float>(_asDouble) << "f" << std::endl;
	
	op << "double:		";
	if (_asDouble == static_cast<int>(_asDouble))
		op << _asDouble << ".0" << std::endl;
	else 
		op << _asDouble << std::endl;
}

void ScalarConverter::DisplayFromUnknown(std::ostream& op, int flag) {
	if (flag == NAN_)
	{
		op << "char:		impossible" << std::endl;
		op << "int:		impossible" << std::endl;
		op << "float:		" << _asFloat << "f" << std::endl;
		op << "double:		" << _asFloat <<  std::endl;
	}
	else if (flag == INF_) 
	{
		op << "char:		impossible" << std::endl;
		op << "int:		impossible" << std::endl;
		op << "float:		" << _asFloat << "f" << std::endl;
		op << "double:		" << _asFloat << std::endl;
	}
	else if (flag == UNKNOWN)
	{
		op << "char:		impossible" << std::endl;
		op << "int:		impossible" << std::endl;
		op << "float:		impossible" << std::endl;
		op << "double:		impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& input)
{
	Identify_type(input);
	switch (_type)
	{
		case CHAR:
			DisplayFromChar(std::cout);
			break;
		case INT:
			DisplayFromInt(std::cout);
			break;
		case FLOAT:
			DisplayFromFloat(std::cout);
			break;
		case DOUBLE:
			DisplayFromDouble(std::cout);
			break;
		case NAN_:
			DisplayFromUnknown(std::cout, NAN_);
			break;
		case INF_:
			DisplayFromUnknown(std::cout, INF_);
			break;
		default:
			DisplayFromUnknown(std::cout, UNKNOWN);
			break;
	}
}
