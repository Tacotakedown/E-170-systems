#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include <iostream>
#include <cmath>
#include <chrono>

template <typename T>
class LowPassFilter {
public:
	LowPassFilter(std::chrono::duration<double> time_contraint);
	LowPassFilter(std::chrono::duration<double> time_contraint, T init_value);
	T update(std::chrono::duration<double> time_delta, T new_input);
	T output() const { return filtered_output; };

	void set_time_constraint(std::chrono::duration<double> new_time_contraint);
	void reset(T reset_value);


private:
	std::chrono::duration<double> time_contraint;
	T filtered_output;
};


#endif // !LOW_PASS_FILTER_H

