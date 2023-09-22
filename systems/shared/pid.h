#ifndef PID_H
#define PID_H

#include <iostream>
#include <chrono>
#include <cmath>
#include <limits>

class PidController {
public:
	PidController(double kp, double ki, double kd, double min_output, double max_output, double setpoint, double output_gain);

	void changeSetpoint(double new_setpoint);
	void setMinOutput(double new_min);
	void setMaxOutput(double new_max);
	double getSetpoint() const { return setpoint; };
	double getOutput() const { return output; };
	void reset();
	void resetWithOutput(double new_output);
	double nextControlOutput(double measurement, std::chrono::duration<double> delta_time = std::chrono::duration<double>(1.0));
	void setMin(double min);
	void setMax(double max);
	void setGains(double new_kp, double new_ki, double new_output_gain);


private:
	double		kp;
	double		ki;
	double		kd;
	double		min_output;
	double		max_output;
	double		setpoint;

	double		error_k_1;
	double		error_k_2;

	double		output;
	double		output_gain;

	void updateError(double error);
	void resetError();
};

#endif // !PID_H

