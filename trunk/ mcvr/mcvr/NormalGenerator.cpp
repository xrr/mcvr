#include "NormalGenerator.h"
#include <math.h>

NormalGenerator::NormalGenerator(RandomGenerator* pRG) : _pRG(pRG) {
	_cached = 0;
}
NormalGenerator::~NormalGenerator(void) {}

double NormalGenerator::Next(void) {return Next(0,1);}

//http://en.wikipedia.org/wiki/Marsaglia_polar_method

double NormalGenerator::Next(double mu, double sigma) {
	double N01;
	if (!_cached) {
		double x=1, y=1;
		while (x*x+y*y >1) { //efficienty dead loss...
			x=(2*_pRG->Next())-1;
			y=(2*_pRG->Next())-1;
		}
		double s=x*x+y*y;
		N01 = (x*sqrt(-2*log(s)/s));
		_cache = y*sqrt(-2*log(s)/s);
	} else {
		N01 = _cache;
	}
	_cached = !_cached;
	return (mu+sigma*N01);
}
