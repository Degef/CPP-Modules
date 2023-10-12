#ifndef Convert_hpp
#define Convert_hpp

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN,
	NAN_,
	INF_
};

class ScalarConverter {
public:

	// int			getType() const;
	// int			getAsInt() const;
	// float		getAsFloat() const;
	// double		getAsDouble() const;
	// char		getAsChar() const;

	static void Identify_type(const std::string& input);
	static void convert(const std::string& input);
	static void DisplayFromChar(std::ostream& out);
	static void DisplayFromInt(std::ostream& out);
	static void DisplayFromFloat(std::ostream& out);
	static void DisplayFromDouble(std::ostream& out);
	static void DisplayFromUnknown(std::ostream& out, int flag);

	static int			_type;
	static long			_asInt;
	static float		_asFloat;
	static double 		_asDouble;
	static char			_asChar;

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& op);
};

#endif