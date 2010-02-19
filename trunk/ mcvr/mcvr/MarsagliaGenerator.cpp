#include "MarsagliaGenerator.h"
#include <math.h>


MarsagliaGenerator::MarsagliaGenerator(UniformGenerator* pUG) {
	// ": _pUG(pUG) {" ne marche pas car  "class GaussianGenerator { protected: _pUG ..."
	// _pUG est un membre (protected) de la classe mère
	_pUG = pUG;
	MarsagliaGenerator();
}

MarsagliaGenerator::MarsagliaGenerator(void) {
	_cached = 0;
}

MarsagliaGenerator::~MarsagliaGenerator(void) {}

//http://en.wikipedia.org/wiki/Marsaglia_polar_method
double MarsagliaGenerator::Next(double mu, double sigma) {
	double N01;
	if (!_cached) {
		double x=1, y=1;
		while (x*x+y*y >1) { //efficienty dead loss...: draws number *= 4/pi
			x=(2*_pUG->Next())-1;
			y=(2*_pUG->Next())-1;
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