#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <iostream>
#include <cmath>



namespace wasm_random {
	

	class Random
	{
	public:
		static void initialize_random_generator();
		static uint8_t random_number();
		static double random_from_range(double from, double to);
		static double random_from_normal_distribution(double mean, double std_dev);

	private:
		static std::mt19937_64 rng;
	};


}

namespace native_random {

	class Random
	{
	public:
		static void initialize_random_generator();
		static uint8_t random_number();
		static double random_from_range(double from, double to);
		static double random_from_normal_distruibution(double mean, double std_dev);

	private:
		static std::mt19937_64 rng;

	};


}

#endif // !RANDOM_H




