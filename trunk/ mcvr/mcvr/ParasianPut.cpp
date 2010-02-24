#include "ParasianPut.h"

ParasianPut::ParasianPut(double K, double B, double L) {
	this->K = K;
	this->B = B;
	this->L = L;
}

ParasianPut::~ParasianPut(void) {}

double ParasianPut::operator ()(Trajectory* pT) {
	double S = pT->GetLast();
	double Payoff = K-S>0?K-S:0;
	bool cancel = 0;
	int c = 0;
	unsigned I = pT->Size();
	for (unsigned i=0; i<I; i++) {
		c+=pT->Get(i)<B;
		cancel = cancel || c>=L;
	}
	return c<L?Payoff:0;
}