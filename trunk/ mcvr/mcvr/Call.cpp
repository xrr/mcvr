#include "Call.h"

Call::Call(double K){
	this->K = K;
}

Call::~Call(void) {}

double Call::operator ()(DegeneratedTrajectory* pDT) {
	double S = pDT->GetLast();
	return S-K>0?S-K:0;
	//return std::max<double>(S-K,0);
	//(#include <algorithm>)
}