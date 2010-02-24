#include "BoxMullerGenerator.h"
#include <math.h>

BoxMullerGenerator::BoxMullerGenerator(UniformGenerator* pUG)
: GaussianGenerator(pUG) {
	Init();
}

BoxMullerGenerator::BoxMullerGenerator(void) {
	Init();
}

void BoxMullerGenerator::Init(void) {
	_cached = 0;
}

BoxMullerGenerator::~BoxMullerGenerator(void) {}

double BoxMullerGenerator::Next(double mu, double sigma) {
	double const m_pi = 2 * acos(0.0);
	double N01;
	if (!_cached) {
		double u1,u2,r,theta;
		u1=_pUG->Next();
		u2=_pUG->Next();
		r = sqrt(-2*log(u1));
		theta = 2*m_pi*u2;
		N01 = r*cos(theta);
		_cache = r*sin(theta);
	} else {
		N01 = _cache;
	}
	_cached = !_cached;
	return (mu+sigma*N01);
}