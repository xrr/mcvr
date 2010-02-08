#pragma once
#include "Payoff.h"
#include <gsl/gsl_vector.h>

class Call :
	public Payoff
{
	double _K; //Strike
public:
	Call(double=0);
	~Call(void);
	double operator()(gsl_vector* Trajectory);

};
