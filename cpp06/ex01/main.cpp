#include "includes/Serializer.hpp"

int main() {
    Data originalData(42);

    uintptr_t serializedPtr = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(serializedPtr);

    if (deserializedData == &originalData) {
        std::cout << G << "Serialization and deserialization successful." << reset << std::endl;
	}
    else {
        std::cerr << R << "Serialization and deserialization failed." << reset << std::endl;
	}
	
	std::cout << Y << "Original data: 	    " << originalData.value1 << std::endl;
	std::cout << Y << "Serialized pointer: " << serializedPtr << std::endl;
	std::cout << "Deserialized data:  " << deserializedData->value1 << std::endl;

    return 0;
}
