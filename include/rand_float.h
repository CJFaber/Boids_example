#include <random>

#ifndef RAND_FLOAT_H
#define RAND_FLOAT_H

float rand_float()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<float> dis(0, 1);
	return dis(gen);
}

#endif
