#include "MarsagliaGenerator.h"
#include <math.h>


MarsagliaGenerator::MarsagliaGenerator(UniformGenerator* pUG)
: GaussianGenerator(pUG) {
	Init();
}

MarsagliaGenerator::MarsagliaGenerator(void) {
	Init();
}

void MarsagliaGenerator::Init(void) {
	_cached = 0;
}

MarsagliaGenerator::~MarsagliaGenerator(void) {}

double MarsagliaGenerator::Next(double mu, double sigma) {
	double N01;
	if (!_cached) {
		double x=1, y=1;
		while (x*x+y*y >1) {
			x = (2*_pUG->Next())-1;
			y = (2*_pUG->Next())-1;
		}
		double s=x*x+y*y;
		N01 = (x*sqrt(-2*log(s)/s));
		_cache = y*sqrt(-2*log(s)/s);
	} else {
		N01 = _cache;
	}
	//_cached = !_cached;
	return (mu+sigma*N01);
}