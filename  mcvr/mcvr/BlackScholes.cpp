#include "BlackScholes.h"

BlackScholes::BlackScholes(double S0, double sigma,
						   double mu, GaussianGenerator* pGG)
{
	this->S0 = S0;
	this->sigma = sigma;
	this->mu = mu;
	_pGG = pGG;
	_T = 0;

	AdjustRates();
}

void BlackScholes::AdjustRates(void) {
	double const trading_days = 365;//252;
	//mu = pow(1+mu,1/(double)trading_days)-1;
	mu /= trading_days;
	sigma /= sqrt((double)trading_days);

}

BlackScholes::~BlackScholes(void) {}

double BlackScholes::GetT(void) {
	return _T;
}

void BlackScholes::Reset(void) {
	_T = 0;
}