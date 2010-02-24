#include "LookbackCall.h"

LookbackCall::LookbackCall(double K){
	this->K = K;
}

LookbackCall::~LookbackCall(void) {}

double LookbackCall::operator ()(Trajectory* pT) {
	double S = K;
	for (unsigned i=0; i<pT->Size(); i++)
		S = (S<pT->Get(i))?pT->Get(i):S; //update S?
	return S-K>0?S-K:0;
}
