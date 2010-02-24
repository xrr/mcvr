#include "LookbackPut.h"

LookbackPut::LookbackPut(double K){
	this->K = K;
}

LookbackPut::~LookbackPut(void) {}

double LookbackPut::operator ()(Trajectory* pT) {
	double S = K;
	for (unsigned i=0; i<pT->Size(); i++)
		S = S>pT->Get(i)?pT->Get(i):S;
	return K-S>0?K-S:0;
}

