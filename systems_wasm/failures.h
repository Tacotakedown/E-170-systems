#ifndef FAILURES_H
#define FAILURES_H

#include <MSFS/Legacy/gauges.h>
#include <string>
#include <unordered_map>

#include "NamedVariable.h"
#include "../systems/failures/failures_module.h"


class Failures {
public:
	Failures(const NamedVariable& activate_sim_var, const NamedVariable& deactivate_sim_var);
	void add(uint64_t identifier, FailureType failure_type);

	FailureType read_failure_activate();
	FailureType read_failure_deactivate();


private:
	NamedVariable									m_activate_sim_var;
	NamedVariable									m_deactivate_sim_var;
	std::unordered_map<uint64_t, FailureType>		m_identifier_to_failure_type;

	FailureType read_failure(const NamedVariable& from);

};


#endif // !FAILURES_H


