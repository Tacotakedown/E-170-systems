#include "failures.h"

Failures::Failures(const NamedVariable& activate_sim_var, const NamedVariable& deactivate_sim_var) :
	m_activate_sim_var(activate_sim_var),
	m_deactivate_sim_var(deactivate_sim_var) {}

void Failures::add(uint64_t identifier, FailureType failure_type) {
	m_identifier_to_failure_type[identifier] = failure_type;
}

FailureType Failures::read_failure_activate() {
	return read_failure(m_activate_sim_var);
}

FailureType Failures::read_failure_deactivate() {
	return read_failure(m_deactivate_sim_var);
}

FailureType Failures::read_failure(const NamedVariable& from) {
	double identifier = from.get_value<double>();
	auto it = m_identifier_to_failure_type.find(static_cast<uint64_t>(identifier));
	if (it != m_identifier_to_failure_type.end()) {
		from.set_value(0.0);
			return it->second;
	}
	else {
		return FailureType::INVALID;
	}

}
