#include "low_pass_filter.h"

template <typename T>
LowPassFilter<T>::LowPassFilter(std::chrono::duration<double>time_contraint) :
	time_constant(time_constant),
	filtered_output(T()) {}

template<typename T>
LowPassFilter<T>::LowPassFilter(std::chrono::duration<double> time_contraint, T init_value):
	time_constant(time_constant),
	filtered_output(init_value) {}

template<typename T>
T LowPassFilter<T>::update(std::chrono::duration<double> time_delta, T new_input)
{
	double alpha = 1.0 - std::exp(-time_delta.count() / time_contraint.count());
	filtered_output += (new_input - filtered_output) * alpha;
	return filtered_output;
}


template<typename T>
void LowPassFilter<T>::set_time_constraint(std::chrono::duration<double> new_time_contraint)
{
	time_contraint = new_time_contraint;
}

template<typename T>
void LowPassFilter<T>::reset(T reset_value)
{
	filtered_output = reset_value;
}


