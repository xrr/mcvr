#include "BlackScholes.h"

BlackScholes::BlackScholes(double S0, double sigma,
						   double mu, GaussianGenerator* pGG)
{
	this->S0 = S0;
	this->sigma = sigma;
	this->mu = mu;
	_pGG = pGG;
	_T = 0;
}

BlackScholes::~BlackScholes(void) {}

double BlackScholes::GetT(void) {
	return _T;
}

void BlackScholes::Reset(void) {
	_T = 0;
}