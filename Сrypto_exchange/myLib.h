#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>

template<typename T>
inline T randomRange(T min, T max)
{
	if (min > max) std::swap(min, max);
	static bool is_first = true;
	if (is_first)
	{
		srand(unsigned(time(0)));
		is_first = false;
	}
	if (typeid(T) == typeid(int) || typeid(T) == typeid(unsigned) || typeid(T) == typeid(char)
		|| typeid(T) == typeid(long) || typeid(T) == typeid(long long) || typeid(T) == typeid(unsigned char)
		|| typeid(T) == typeid(unsigned long) || typeid(T) == typeid(unsigned long long))
	{
		T rnd = rand();
		return min + rnd - (rnd / (max - min + 1)) * (max - min + 1);
	}
	else if (typeid(T) == typeid(float) || typeid(T) == typeid(double) || typeid(T) == typeid(long double))
	{
		T f = (T)rand() / RAND_MAX;
		return min + f * (max - min);
	}
	else return T{};
}
