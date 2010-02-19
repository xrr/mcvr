#pragma once
#include "GaussianGenerator.h"
#include <gsl/gsl_rng.h>


//"faux" héritier de GaussianGenerator
//(n'utilise pas _pUG)
class GSLGaussianGenerator :
	public GaussianGenerator
{
	const gsl_rng_type * _T;
	gsl_rng* _r;
public:
	GSLGaussianGenerator(void);
	~GSLGaussianGenerator(void);
	double Next(double, double);
};
