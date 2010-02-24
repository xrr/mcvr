#include "BlackScholesSDE.h"
#include <math.h>

BlackScholesSDE::BlackScholesSDE (double S0, double sigma,
								  double mu, GaussianGenerator* pGG) :
BlackScholes(S0, sigma, mu, pGG) {
	Reset();
}

BlackScholesSDE::BlackScholesSDE (void) {
	Reset();
}

void BlackScholesSDE::Reset(void) {
	BlackScholes::Reset();
	_S = S0;
	_Wt = 0;
}

BlackScholesSDE::~BlackScholesSDE (void) {}
	
double BlackScholesSDE::NextValue (double dt){
	_T += dt;
	double dWt = _pGG->Next(0,sqrt(dt)); //écart-type, pas variance
	_S *= 1+mu*dt+sigma*dWt; //équation discrétisée
	return _S;
}
