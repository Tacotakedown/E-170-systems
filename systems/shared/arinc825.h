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
	Arinc825Word(T value, LogicalCommunicationChannel lcc);

	Arinc825Word(T value, uint32_t status);

	T getValue() const { return value; }
	uint32_t getStatus() const { return status; }
	LogicalCommunicationChannel getLogicalCommunicationChanel() const;

	uint8_t getClientFunctionId() const;
	void setClientFunctionId(uint8_t id);

	uint8_t getSourceFunctionId() const;
	void setSourceFunctionId(uint8_t id);

	bool isServiceMessageType() const;
	void setSericeMessageType(bool serviceType);

	bool isLocalBusOnly() const;
	void setLocalBusOnly(bool local);

	bool isPrivateData() const;
	void setPrivateData(bool privateData);

	uint16_t getNodeId() const;
	void setNodeId(uint16_t id);

	uint8_t getServerFunctionId() const;
	void setServerFunctionId(uint8_t id);

	uint8_t getServerId() const;
	void setServerId(uint8_t id);

	uint16_t getDataObjectCode() const;
	void setDataObjectCode(uint16_t code);

	uint8_t getRedundancyChannelId() const;
	void setRecundancyChannelId(uint8_t channel);

};

Arinc825Word<uint32_t> double_to_arinc825(double value);
double arinc825_to_double(const Arinc825Word<uint32_t>& word);


#endif // !ARINC825_H



