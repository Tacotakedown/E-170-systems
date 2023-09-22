#pragma once


#include <chrono>
#include <cstdint>

#include "SI/acceleration.h"
#include "SI/angle.h"
#include "SI/length.h"
#include "SI/pressure.h"
#include "SI/time.h"
#include "SI/velocity.h"

#include "glm/vec3.hpp"

#include "..\shared\arinc429.h"
#include "..\shared\arinc825.h"

namespace Simulation {

	class VariableIdentifier {
	private:
		size_t identifier_type_;
		size_t identifier_index_;

	public:
		VariableIdentifier(size_t variable_type);
		VariableIdentifier(size_t identifier_type, size_t identifier_index);

		size_t identifier_type() const { return identifier_type_; }
		size_t identifier_index() const { return identifier_index_; }

		VariableIdentifier next() const;
	};

	template <typename T>
	class Reader {
	public:
		virtual ~Reader();

		double read_f64(const VariableIdentifier& identifier) = 0;

		Arinc429Word<T> read_arinc429(const VariableIdentifier& identifier, const Reader& reader);
		Arinc825Word<T> read_arinc825(const VariableIdentifier& identifier, const Reader& reader);

	};
	
}
