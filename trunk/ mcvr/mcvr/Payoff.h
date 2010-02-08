#pragma once
#include <gsl/gsl_vector.h>

class Payoff
{
public:
	Payoff(void);
	~Payoff(void);
	virtual double operator()(gsl_vector*)=0;
};
