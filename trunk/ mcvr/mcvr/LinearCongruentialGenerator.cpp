#include "LinearCongruentialGenerator.h"

LinearCongruentialGenerator::LinearCongruentialGenerator(long x, long a, long c, long m):
_x(x), _a(a), _c(c), _m(m) {}

LinearCongruentialGenerator::~LinearCongruentialGenerator(void) {}

double LinearCongruentialGenerator::Next(void) {
	_x = ((_a*_x)+_c)%_m;
	return (double) _x/(_m-1);
}