#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data {"Hoang", 36};

	uintptr_t serializedData = Serializer::serialize(&data);
	Data* deData = Serializer::deserialize(serializedData);

	std::cout
		<< "data[address=" << &data << ", name=" << data.name << ", age=" << data.age <<"]\n"
		<< "deData[address=" << deData << ", name=" << deData->name << ", age=" << deData->age <<"]"
		<< std::endl;

	deData->name = "Lucas";
	deData->age = 42;

	std::cout
		<< "data[address=" << &data << ", name=" << data.name << ", age=" << data.age <<"]\n"
		<< "deData[address=" << deData << ", name=" << deData->name << ", age=" << deData->age <<"]"
		<< std::endl;
	return 0;
}
