#include "arinc825.h"

template <typename T>
Arinc825Word<T>::Arinc825Word(T value, LogicalCommunicationChannel lcc) : value(value) {
	status = static_cast<uint32_t>(lcc);
	status <<= 26;
}

template<typename T>
Arinc825Word<T>::Arinc825Word(T value, uint32_t status) : value(value), status(status) {}

template<typename T>
LogicalCommunicationChannel Arinc825Word<T>::getLogicalCommunicationChanel() const
{
	return static_cast<LogicalCommunicationChannel>((status >> 26) & 0x7);
}

template<typename T>
uint8_t Arinc825Word<T>::getClientFunctionId() const
{
	return static_cast<uint8_t>((status >> 19) & 0x7f);
}

template<typename T>
void Arinc825Word<T>::setClientFunctionId(uint8_t id)
{
	status &= 0xFC07FFFF;									//funny 
	status |= static_cast<uint32_t>(id & 0x7f) << 19;
}

template<typename T>
uint8_t Arinc825Word<T>::getSourceFunctionId() const
{
	return static_cast<uint8_t>((status >> 19) & 0x7f);
}

template<typename T>
void Arinc825Word<T>::setSourceFunctionId(uint8_t id)
{
	status &= 0xFC07FFFF;									// ok maybe not
	status |= static_cast<uint32_t>(id & 0x7f) << 19;
}

template<typename T>
bool Arinc825Word<T>::isServiceMessageType() const
{
	return ((status >> 18) & 0x1) != 0;
}

template<typename T>
void Arinc825Word<T>::setSericeMessageType(bool serviceType)
{
	if (serviceType) {
		status |= 1 << 18;
	}
	else {
		status &= 0xFFFBFFFF;								// bro
	}
}

template<typename T>
bool Arinc825Word<T>::isLocalBusOnly() const
{
	return ((status >> 17) & 0x1) != 0;
}

template<typename T>
void Arinc825Word<T>::setLocalBusOnly(bool local)
{
	if (local) {
		status |= 1 << 17;
	}
	else {
		status &= 0xFFFDFFFF;								//what the fuck
	}
}

template<typename T>
bool Arinc825Word<T>::isPrivateData() const
{
	return((status >> 16) & 0x1) != 0;
}

template<typename T>
void Arinc825Word<T>::setPrivateData(bool privateData)
{
	if (privateData) {
		status |= 1 << 16;
	}
	else {
		status &= 0xFFFEFFFF;								//yeah no there has to be a better way
	}
}

template<typename T>
uint16_t Arinc825Word<T>::getNodeId() const
{
	return static_cast<uint16_t>(status);
}

template<typename T>
void Arinc825Word<T>::setNodeId(uint16_t id)
{
	status &= 0xFFFF0000;
	status |= static_cast<uint8_t>((status >> 9) & 0x7F);
}

template<typename T>
uint8_t Arinc825Word<T>::getServerFunctionId() const
{
	return static_cast<uint8_t>((status >> 9) & 0x7F);
}

template<typename T>
void Arinc825Word<T>::setServerFunctionId(uint8_t id)
{
	status &= 0xFFFF01FF;
	status |= static_cast<uint32_t>(id & 0x7F) << 9;
}

template<typename T>
uint8_t Arinc825Word<T>::getServerId() const
{
	return static_cast<uint8_t>((status >> 2) & 0x7F);
}

template<typename T>
void Arinc825Word<T>::setServerId(uint8_t id)
{
	status &= 0xFFFFFE03;
	status |= static_cast<uint32_t>(id & 0x7F) << 2;
}

template<typename T>
uint16_t Arinc825Word<T>::getDataObjectCode() const
{
	return static_cast<uint16_t>((status >> 2) & 0x3FFF);
}

template<typename T>
void Arinc825Word<T>::setDataObjectCode(uint16_t code)
{
	status &= 0xFFFF0003;
	status |= static_cast<uint32_t>(code & 0x3FFF) << 2;
}

template<typename T>
uint8_t Arinc825Word<T>::getRedundancyChannelId() const
{
	return static_cast<uint8_t>(status & 0x03);
}

template<typename T>
void Arinc825Word<T>::setRecundancyChannelId(uint8_t channel)
{
	statis &= 0xFFFFFFFC;
	status |= static_cast<uint32_t>(chanel & 0x03);
}

Arinc825Word<uint32_t> double_to_arinc825(double value)
{
	uint64_t bits = std::bit_cast<uint64_t>(value);
	uint32_t valuePart = static_cast<uint32_t>(bits >> 32);
	uint32_t statusPart = static_cast<uint32_t>(bits);
	return Arinc825Word<uint32_t>(valuePart, statusPart);
}

double arinc825_to_double(const Arinc825Word<uint32_t>& word)
{
	uint64_t bits = (static_cast<uint64_t>(word.getValue()) << 32) | static_cast<uint64_t>(word.getStatus());
	return std::bit_cast<double>(bits); //data types can cope
}
