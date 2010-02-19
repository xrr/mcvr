#include "Range.h"
#include <iostream>

Range::Range(double lb, double ub, int s) : lbound(lb), ubound(ub),
	steps(s), current(lb) {}

Range::~Range(void) {}

double Range::Length(void) {
	return ubound-lbound;
}

double Range::StepSize(void) {
	double r = ubound-lbound;
	r /= steps;
	return r;
}

double* Range::Bounds(void) {
	double* ret = new double[2];
	ret[0] = lbound;
	ret[1] = ubound;
	return ret;
}

double Range::Next(void) {
	current += StepSize();
	//current cumulates approximations on StepSize calculus
	//the condition to reset the carret is "overweighted"
	//by adding an ~espilon (1E-4)
	/*
	//desactivated for the moment
	current = (current>ubound+1E-4)?lbound:current;
	*/
	return current;
}

void Range::Reset() {
	current = lbound;
}
std::ostream& operator<<(std::ostream& flux, Range& r) {
	return flux << "[" << r.lbound << ":" << r.ubound << "] (by " << r.StepSize() << ")";
}