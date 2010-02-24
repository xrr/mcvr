#include "ParisianPut.h"

ParisianPut::ParisianPut(double K, double B, double L) {
	this->K = K;
	this->B = B;
	this->L = L;
}

ParisianPut::~ParisianPut(void) {}

double ParisianPut::operator ()(Trajectory* pT) {
	double S = pT->GetLast();
	double Payoff = K-S>0?K-S:0;
	bool cancel = 0;
	int c = 0;
	unsigned I = pT->Size();
	for (unsigned i=0; i<I; i++) {
		c = pT->Get(i)<B?c+1:0;
		cancel = cancel || c>=L;
	}
	return cancel?0:Payoff;
}