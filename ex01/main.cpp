#include "Serializer.hpp"
#include <iostream>

int main() {
	Data originalData(42);
	std::cout << "Original Data value: " << originalData.value << std::endl;
	uintptr_t serializedData = Serializer::serialize(&originalData);
	Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;
	
	return 0;
}
