#include "includes/serializer.hpp"

int main() {
    Data originalData(42);

    uintptr_t serializedPtr = Serializer::serialize(&originalData);

    Data* deserializedData = Serializer::deserialize(serializedPtr);
	// std::cout << "Deserialized data: " << deserializedData->value1 << std::endl;

    if (deserializedData == &originalData)
        std::cout << "Serialization and deserialization successful." << std::endl;
    else
        std::cerr << "Serialization and deserialization failed." << std::endl;

    return 0;
}
