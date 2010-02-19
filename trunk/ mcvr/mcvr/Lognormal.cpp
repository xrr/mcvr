#include "Lognormal.h"

Lognormal::Lognormal(void) {}
Lognormal::~Lognormal(void) {}

double Lognormal::Value(double T) {
	_T = T;
	double Wt = _pGG->Next(0,T); // Wiener process;
	return S0 * exp((mu-0.5*sigma*sigma)*T+sigma*Wt);
}

double Lognormal::NextValue(double dt) {
	_T += dt;
	return Value(_T);
}