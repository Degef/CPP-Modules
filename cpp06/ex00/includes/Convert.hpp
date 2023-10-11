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

class Converter {
public:
	Converter();
	Converter(const Converter& copy);
	~Converter();
	Converter& operator=(const Converter& op);

	int			getType() const;
	int			getAsInt() const;
	float		getAsFloat() const;
	double		getAsDouble() const;
	char		getAsChar() const;

    Converter(const std::string& input);
	void DisplayFromChar(std::ostream& out) const;
	void DisplayFromInt(std::ostream& out) const;
	void DisplayFromFloat(std::ostream& out) const;
	void DisplayFromDouble(std::ostream& out) const;
	void DisplayFromUnknown(std::ostream& out, int flag) const;

private:
	int			_type;
	int			_asInt;
	float		_asFloat;
	double 		_asDouble;
	char		_asChar;
};

std::ostream& operator<<(std::ostream& out, const Converter& op);
#endif