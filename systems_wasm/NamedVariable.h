#ifndef NAMED_VARIABLE_H
#define NAMED_VARIABLE_H

#include <MSFS/Legacy/gauges.h>
#include <string>

// ill decide on data type later
typedef  ID sysID;

class NamedVariable {
public:
	NamedVariable(const std::string& name);

	template<typename T>
	T get_value();

	template<typename T>
	T get_value() const;

	template<typename T>
	void set_value(T value);

	template<typename T>
	void set_value(T value) const;


private:
	std::string		m_name;
	sysID			m_id;
};


#endif // !NAMED_VARIABLE_H


