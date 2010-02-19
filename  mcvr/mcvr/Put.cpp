#include "Put.h"
#include <algorithm>

Put::Put(double K) {
	this->K = K;
}

Put::~Put(void) {}

double Put::operator ()(DegeneratedTrajectory* pDT) {
	double S = pDT->GetLast();
	return K-S>0?K-S:0;
}