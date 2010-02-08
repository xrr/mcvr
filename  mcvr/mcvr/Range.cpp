#include "Range.h"
#include <iostream>

Range::Range(double lb, double ub, int s) : lbound(lb), ubound(ub), steps(s), current(ub) {}

Range::~Range(void) {}

double Range::Length() {
	return ubound-lbound;
}

double Range::StepSize() {
	double r = ubound-lbound;
	if (steps != 1) {r = (r/(steps-1));} //Tricky case where there is only one step in the range...
	return r;
}

double* Range::Bounds() {
	double* ret = new double[2];
	ret[0] = lbound;
	ret[1] = ubound;
	return ret;
}

double Range::Next() {
	double next = current + StepSize();
	current = (next>ubound)?lbound:next;
	return current;
}

std::ostream& operator<<(std::ostream& flux, Range& r) {
	return flux << "[" << r.lbound << ":" << r.ubound << "] (by " << r.StepSize() << ")";
}