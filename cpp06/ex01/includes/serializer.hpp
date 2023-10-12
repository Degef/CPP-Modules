#ifndef serializer_hpp
#define serializer_hpp

#include <iostream>
#include <stdint.h>

//colors
#define reset		"\033[0m"
#define R			"\033[31m"
#define G			"\033[32m"
#define Y			"\033[33m"

struct Data {
    int value1;
    Data(int v1) : value1(v1){};
};

class Serializer {
private:
	Serializer();
	Serializer(const Serializer& copy);
	~Serializer();
	Serializer& operator=(const Serializer& op);

public:
    static uintptr_t	serialize(Data* ptr);
    static Data*		deserialize(uintptr_t raw);
};

#endif