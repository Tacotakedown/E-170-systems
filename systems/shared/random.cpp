#include "random.h"


/*
We need to generate random numbers in a single threaded nature since WASM doesnt suport c++ threads
*/

void wasm_random::Random::initialize_random_generator() {
	rng.seed(std::random_device()());
}

uint8_t wasm_random::Random::random_number() {
	return static_cast<uint8_t>(rng() % 256);
}

double wasm_random::Random::random_from_range(double from, double to) {
	std::uniform_real_distribution<double> dist(from, to);
	return dist(rng);
}

double wasm_random::Random::random_from_normal_distribution(double mean, double std_dev) {
	std::normal_distribution<double> dist(mean, std_dev);
	double value;
	do {
		value = dist(rng);
	} while (std::abs(value - mean) > 4.0 * std_dev);
		return value;
}

//#ifdef EXTERNAL_BUILD

void native_random::Random::initialize_random_generator() {
	rng.seed(std::random_device()());
}

uint8_t native_random::Random::random_number() {
	return static_cast<uint8_t>(rng() % 256);
}

double native_random::Random::random_from_range(double from, double to) {
	std::uniform_real_distribution<double> dist(from, to);
	return dist(rng);
}

double native_random::Random::random_from_normal_distruibution(double mean, double std_dev) {
	std::normal_distribution<double> dist(mean, std_dev);
	double value;
	do {
		value = dist(rng);
	} while (std::abs(value - mean) > 4.0 * std_dev);
	return value;
}
//#endif // EXTERNAL_BUILD


