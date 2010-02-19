#include "Sample.h"

Sample::Sample(unsigned size) : V(size) {}
Sample::~Sample(void) {}

double Sample::Mean(void) {
	double result = 0;
	for (unsigned i=0; i<_size; i++)
		result+=Get(i);
	result/=_size;
	return result;
}

double Sample::Variance(void) {
	Sample S2(_size);
	for (unsigned i=0; i<_size; i++) {
		double s1 = Get(i);
		S2.Set(i,s1*s1);
	}
	double mean_sq = S2.Mean();
	double sq_mean = Mean()*Mean();
	return mean_sq-sq_mean;
}