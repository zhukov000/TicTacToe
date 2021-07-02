#include "Tools.h"

std::mt19937 Rnd::generator(std::chrono::high_resolution_clock::now().time_since_epoch().count() ^ (size_t)(new char));

int Rnd::genInt(int a, int b) {
	assert(a < b && "Wrong using random generator!");
	return generator() % (b - a + 1) + a;
}

double Rnd::genDouble(int alpha) {
	double r = static_cast<double>(generator() % alpha + 1) / alpha;
	assert(r > 0 && r <= 1 && "Wrong random double generated!");
	return r;
}