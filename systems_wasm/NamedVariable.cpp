#include "NamedVariable.h"

NamedVariable::NamedVariable(const std::string& name)
{
	m_name = name;
	m_id = register_named_variable(name.c_str());
}

template <typename T>
T NamedVariable::get_value() {
	double var = get_named_variable_value(m_id);
	return static_cast<T>(var);
}

template <typename T>
T NamedVariable::get_value() const {
	double var = get_named_variable_value(m_id);
	return static_cast<T>(var);
}

template<typename T>
void NamedVariable::set_value(T value)
{
	set_named_variable_value(m_id, static_cast<double>(value));
}
template<typename T>
void NamedVariable::set_value(T value) const 
{
	set_named_variable_value(m_id, static_cast<double>(value));
}
