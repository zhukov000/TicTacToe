#pragma once

#include <cassert>
#include <chrono>
#include <random>

namespace Rnd
{
	extern std::mt19937 generator;

	int genInt(int , int );

	double genDouble(int );
};