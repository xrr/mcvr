#include "LCGenerator.h"

LCGenerator::LCGenerator(long x, long a, long c, long m):
	_x(x), _a(a), _c(c), _m(m) {}

LCGenerator::~LCGenerator(void) {}

double LCGenerator::Next(void) {
	_x = ((_a*_x)+_c)%_m;
	return (double) _x/(_m-1);
}