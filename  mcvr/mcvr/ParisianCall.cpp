#include "ParisianCall.h"

ParisianCall::ParisianCall(double K, double B, double L) {
	this->K = K;
	this->B = B;
	this->L = L;
}

ParisianCall::~ParisianCall(void) {}

double ParisianCall::operator ()(Trajectory* pT) {
	double S = pT->GetLast();
	double Payoff = S-K>0?S-K:0;
	//compteur d'étapes de temps "over the barrier"
	int c = 0;
	unsigned I = pT->Size();
	for (unsigned i=0; i<I; i++)
		//étapes non consécutives: RAZ
		c = pT->Get(i)>B?c+1:0;
	return c<L?Payoff:0;
}
