#include "Simulation.h"

/*
this is completely shit and unreadable
*/

Simulation::VariableIdentifier::VariableIdentifier(size_t variable_type) :
	identifier_type_(variable_type),
	identifier_index_(0) {}

Simulation::VariableIdentifier::VariableIdentifier(size_t identifier_type, size_t identifier_index) :
	identifier_type_(identifier_type),
	identifier_index_(identifier_index) {} 

Simulation::VariableIdentifier Simulation::VariableIdentifier::next() const {
	return VariableIdentifier(identifier_type_, identifier_index_ + 1);
}

template <typename T>
Arinc429Word<T> Simulation::Reader<T>::read_arinc429(const VariableIdentifier& identifier, const Reader& reader) {
	double value = reader.read_f64(identifier);
	Arinc429Word<uint32_t> arinc429 = double_to_arinc429(value);
	return Arinc429Word<T>(arinc429.getValue(), arinc429.getSSM());
}

template<typename T>
Arinc825Word<T> Simulation::Reader<T>::read_arinc825(const VariableIdentifier& identifier, const Reader& reader)
{
	double value = reader.read_f64(identifier);
	Arinc825Word<uint32_t> arinc825 = double_to_arinc825(value);
	return Arinc825Word<T>(arinc825.getValue())
}
