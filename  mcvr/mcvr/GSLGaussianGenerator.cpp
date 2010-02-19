#include "GSLGaussianGenerator.h"
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

GSLGaussianGenerator::GSLGaussianGenerator(void) {
	_T = gsl_rng_env_setup();
	_r = gsl_rng_alloc(_T);
}

GSLGaussianGenerator::~GSLGaussianGenerator(void){
	gsl_rng_free(_r);
}

double GSLGaussianGenerator::Next(double mu, double sigma) {
	return mu+gsl_ran_gaussian(_r,sigma);
}