#ifndef serializer_hpp
#define serializer_hpp

#include <iostream>
#include <cstdint>

struct Data {
    int value1;
    Data(int v1) : value1(v1){}
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif