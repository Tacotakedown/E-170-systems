#ifndef ARINC825_H
#define ARINC825_H

#include <iostream>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <random>


enum class LogicalCommunicationChannel : uint32_t {
	ExceptionEventChanel = 0b000,
	NormalOperationChannel = 0b010,
	NodeServiceChannel = 0b100,
	UserDefinedChannel = 0b101,
	TestAndMaintenanceChannel = 0b110,
	CanBaseFrameMigrationChannel = 0b111,
};


template <typename T>
class Arinc825Word {
private:
	T value;
	uint32_t status;

public:
	Arinc825Word(T value, LogicalCommunical)
};


#endif // !ARINC825_H



