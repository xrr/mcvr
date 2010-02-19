#include "BlackScholesSDE.h"

BlackScholesSDE::BlackScholesSDE (double S0, double sigma,
								  double mu, GaussianGenerator* pGG) {
	this->S0 = S0;
	this->sigma = sigma;
	this->mu = mu;
	_pGG = pGG;
	BlackScholesSDE();
}

BlackScholesSDE::BlackScholesSDE (void) {
	Reset();
}

void BlackScholesSDE::Reset(void) {
	BlackScholes::Reset();
	_S = S0;
	_Wt=0;
}

BlackScholesSDE::~BlackScholesSDE (void) {}

double BlackScholesSDE::NextValue (double dt){
	_T += dt;
	double dWt=_pGG->Next(0,dt);
	_S *= 1+ mu*dt + sigma*dWt;
	return _S;
}