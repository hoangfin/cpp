#pragma once

#include <cstdint>
#include "Data.hpp"

class Serializer {
	public:
		Serializer() = default;
		Serializer(const Serializer&) = default;
		~Serializer() = default;

		Serializer& operator=(const Serializer&) = default;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
