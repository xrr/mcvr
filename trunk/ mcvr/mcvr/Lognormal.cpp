#include "Lognormal.h"
#include <math.h>

Lognormal::Lognormal(double S0, double sigma,
					 double mu, GaussianGenerator* pGG) :
BlackScholes(S0, sigma, mu, pGG) {
	Reset();
}

Lognormal::Lognormal(void) {
	Reset();
}

Lognormal::~Lognormal(void) {}

double Lognormal::Value(double T) {
	_T = T;
	double Wt = _pGG->Next(0,sqrt(T));
	return S0 * exp((mu-0.5*sigma*sigma)*T+sigma*Wt);
}

double Lognormal::NextValue(double dt) {
	_T += dt;
	return Value(_T);
}