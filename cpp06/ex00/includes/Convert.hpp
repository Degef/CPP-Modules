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

enum error_type {
	NO_ERROR,
	IMPOSSIBLE,
	NON_DISPLAYABLE
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
	void ExtractType(const std::string& input);
	void FromChar(const std::string& input);
	void FromInt(const std::string& input);
	void FromFloat(const std::string& input);
	void FromDouble(const std::string& input);

private:
	int			_type;
	int			_asInt;
	float		_asFloat;
	double 		_asDouble;
	char		_asChar;
	int			_error[];
};

// std::ostream& operator<<(std::ostream& out, const Converter& op);
#endif