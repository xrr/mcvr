#pragma once
#include <math.h>

class FunctorD1 {
public:
	double operator() (double d) {
		return(-2*d);
	}
};

class FunctorGauss {
double _mu, _sigma;
public:
	FunctorGauss(double mu, double sigma): _mu(mu), _sigma(sigma) {}
	double operator() (double x) {
		return ((1/(_sigma*sqrt(2*3.14)))*exp(-((x-_mu)*(x-_mu))/(2*_sigma*_sigma)));
	}
};