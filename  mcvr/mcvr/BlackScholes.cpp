#include "BlackScholes.h"

BlackScholes::BlackScholes(double S0, double sigma, double mu, NormalGenerator* pNG) {
	this->S0 = S0;
	this->sigma = sigma;
	this->mu = mu;
	_pNG = pNG;
}

BlackScholes::~BlackScholes(void) {}

double BlackScholes::ClosedFormula(double t) {
	double Wt = _pNG->Next(0,t); // Wiener process: sigma = t;
	double St = S0 * exp((mu-0.5*sigma*sigma)*t+sigma*Wt);
	return St;
}
