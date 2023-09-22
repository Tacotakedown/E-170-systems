#include "pid.h"

PidController::PidController(double kp, double ki, double kd, double min_output, double max_output, double setpoint, double output_gain) :
	kp(kp),
	ki(ki),
	kd(kd),
	min_output(min_output),
	max_output(max_output),
	setpoint(setpoint),
	output_gain(output_gain),
	error_k_1(std::numeric_limits<double>::quiet_NaN()),
	error_k_2(std::numeric_limits<double>::quiet_NaN()),
	output(0.0) {}

void PidController::changeSetpoint(double new_setpoint)
{
	setpoint = new_setpoint;
}

void PidController::setMinOutput(double new_min)
{
	min_output = new_min;
}

void PidController::setMaxOutput(double new_max)
{
	max_output = new_max;
}


void PidController::reset()
{
	output = 0.0;
	resetError();
}

void PidController::resetWithOutput(double new_output)
{
	output = new_output;
	resetError();
}

double PidController::nextControlOutput(double measurement, std::chrono::duration<double> delta_time)
{
	double dt = delta_time.count();

	double error = setpoint - measurement;
	double p_term = (error - error_k_1) * kp;
	double i_term = error * ki * dt;

	double d_term = 0.0;
	if (!std::isnan(error_k_1) && !std::isnan(error_k_2)) {
		d_term = (error - 2.0 * error_k_1 + error_k_2) * kd / dt;
	}
	double unbound_output = output + (p_term + i_term + d_term) * output_gain;

	output = std::max(min_output, std::min(max_output, unbound_output));

	updateError(error);

	return output;
}

void PidController::setMin(double min)
{
	min_output = min;
}

void PidController::setMax(double max)
{
	max_output = max;
}

void PidController::setGains(double new_kp, double new_ki, double new_output_gain)
{
	kp = new_kp;
	ki = new_ki;
	output_gain = new_output_gain;
}

void PidController::updateError(double error)
{
	error_k_2 = error_k_1;
	error_k_1 = error;
}

void PidController::resetError()
{
	error_k_2 = std::numeric_limits<double>::quiet_NaN();
	error_k_2 = std::numeric_limits<double>::quiet_NaN();
}
