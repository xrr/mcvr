#include "Range.h"
#include <iostream>

Range::Range(double lb, double ub) : lbound(lb), ubound(ub) {}

Range::~Range(void) {}

double* Range::GetBounds() {
	double* ret = new double[2];
	ret[0] = lbound;
	ret[1] = ubound;
	return ret;
}

double Range::GetLength() {
	return ubound-lbound;
}

std::ostream& operator<<(std::ostream& flux, Range& r) {
	return flux <<"[" << r.lbound << ":" << r.ubound << "]";
}