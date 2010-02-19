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
	//compteur d'�tapes de temps "over the barrier"
	int c = 0;
	unsigned I = pT->Size();
	for (unsigned i=0; i<I; i++)
		//�tapes non cons�cutives: RAZ
		c = pT->Get(i)>B?c+1:0;
	return c<L?Payoff:0;
}
