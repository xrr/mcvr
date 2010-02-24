#include "ParasianCall.h"

ParasianCall::ParasianCall(double K, double B, double L) {
	this->K = K;
	this->B = B;
	this->L = L;
}

ParasianCall::~ParasianCall(void) {}

double ParasianCall::operator ()(Trajectory* pT) {
	double S = pT->GetLast();
	double Payoff = S-K>0?S-K:0;
	bool cancel = 0;
	int c = 0;
	unsigned I = pT->Size();
	for (unsigned i=0; i<I; i++) {
		//étapes non consécutives: pas de RAZ
		c+=pT->Get(i)>B;
		cancel = cancel || c>=L;
	}
	return c<L?Payoff:0;
}