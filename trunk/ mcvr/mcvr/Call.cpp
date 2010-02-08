#include "Call.h"
#include <algorithm>

Call::Call(double K) : _K(K) {}
Call::~Call(void) {}

double Call::operator ()(gsl_vector* Trajectory) {
	double S = gsl_vector_get(Trajectory, Trajectory->size -1);
	return std::max<double>(S-_K,0);
}