#include "BoxMullerGenerator.h"
#include <math.h>

BoxMullerGenerator::BoxMullerGenerator(void) {
	_cached = 0;
}

BoxMullerGenerator::BoxMullerGenerator(UniformGenerator* pUG) {
	_pUG = pUG;
	BoxMullerGenerator();
}

BoxMullerGenerator::~BoxMullerGenerator(void) {}

//http://en.wikipedia.org/wiki/Box–Muller_transform
double BoxMullerGenerator::Next(double mu, double sigma) {
	double const m_pi = 2 * acos(0.0);
	double N01;
	if (!_cached) {
		double u1,u2,r,theta;
		u1=_pUG->Next();
		u2=_pUG->Next();
		r = sqrt(-2*log(u1));
		theta = 2*m_pi*u2;
		N01 = r*cos(theta); //trigonometric function: relative slow down
		_cache = r*sin(theta); // ""
	} else {
		N01 = _cache;
	}
	_cached = !_cached;
	return (mu+sigma*N01);
}